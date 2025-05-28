#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List
from typing import Iterator, Optional

from tools.project import (
    Library,
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = ["G4QE01"]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20250520"
config.dtk_tag = "v1.5.1"
config.objdiff_tag = "v3.0.0-beta.8"
config.sjiswrap_tag = "v1.2.1"
config.wibo_tag = "0.6.16"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    "-I src",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-warn off",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Progress
config.progress_use_fancy = True
config.progress_code_fancy_frac = 293
config.progress_code_fancy_item = "Trophies"
config.progress_data_fancy_frac = 51
config.progress_data_fancy_item = "Event Matches"

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.

cflags_base = [
    "-nowraplines",
    "-cwd source",
    "-Cpp_exceptions off",
    "-proc gekko",
    "-fp hardware",
    "-align powerpc",
    "-nosyspath",
    "-fp_contract on",
    "-O4,p",
    "-multibyte",
    "-enum int",
    "-nodefaults",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-RTTI off",
    "-str reuse",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,readonly",
    # "-gccinc",
    "-common off",
    "-inline auto",
]

cflags_musyx = [
    "-proc gekko",
    "-nodefaults",
    "-nosyspath",
    "-i include",
    "-i extern/musyx/include",
    "-i libc",
    "-inline auto,depth=4",
    "-O4,p",
    "-fp hard",
    "-enum int",
    "-sym on",
    "-Cpp_exceptions off",
    "-str reuse,pool,readonly",
    "-fp_contract off",
    "-DMUSY_TARGET=MUSY_TARGET_DOLPHIN",
]

cflags_musyx_debug = [
    "-proc gecko",
    "-fp hard",
    "-nodefaults",
    "-nosyspath",
    "-i include",
    "-i extern/musyx/include",
    "-i libc",
    "-g",
    "-sym on",
    "-D_DEBUG=1",
    "-fp hard",
    "-enum int",
    "-Cpp_exceptions off",
    "-DMUSY_TARGET=MUSY_TARGET_DOLPHIN",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

cflags_nl = [
    *cflags_base,
    "-proc gekko",
    "-nodefaults",
    "-nosyspath",
    "-i include",
]

cflags_odemuexi = [
    *cflags_base,
    "-inline deferred"
]

cflags_trk_minnow_dolphin = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-i include",
    "-multibyte",
    "-use_lmw_stmw on",
    "-str reuse,readonly",
    "-common off",
    "-sdata 0",
    "-sdata2 0",
    "-inline auto,deferred",
    "-enum min",
    "-sdatathreshold 0",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# includes_base = ["src"]
includes_base = [
    "include",
    "include/libc",
]

system_includes_base = [
    "include",
    # "include/LIBC",
    f"build/{config.version}/include",
]

config.linker_version = "GC/1.3.2"

Objects = List[Object]


def Lib(
    lib_name: str,
    objects: Objects,
    mw_version: str = config.linker_version,
    cflags=cflags_base,
    fix_epilogue=True,
    fix_trk=False,
    includes: List[str] = includes_base,
    system_includes: List[str] = system_includes_base,
    src_dir: Optional[str] = None,
    category: Optional[str] = None,
) -> Library:
    def make_includes(includes: List[str]) -> Iterator[str]:
        return map(lambda s: f"-i {s}", includes)

    lib = {
        "lib": lib_name,
        # "mw_version": f"GC/1.2.5{'n' if fix_epilogue else ''}",
        "mw_version": mw_version, 
        "cflags": [
            *cflags,
            *make_includes(includes),
            "-I-",
            *make_includes(system_includes),
        ],
        "host": False,
        "progress_category": category,
        "objects": objects,
    }

    if fix_trk:
        lib["mw_version"] = "GC/1.1p1"

    if src_dir is not None:
        lib["src_dir"] = src_dir

    return lib


def RuntimeLib(lib_name: str, objects: Objects) -> Library:
    return Lib(
        lib_name,
        objects,
        cflags=cflags_runtime,
        fix_epilogue=False,
        category="runtime",
    )


def GameLib(lib_name: str, objects: Objects) -> Library:
    return Lib(
        lib_name,
        objects,
        includes=[
            *includes_base,
        ],
        system_includes=[
            *system_includes_base,
        ],
        category="game",
    )


def DolphinLib(
    lib_name: str, objects: Objects, cflags=cflags_base, fix_epilogue=False, extern=False
) -> Library:
    if extern:
        cflags = [
            "-c",
            "-O4,p",
            "-inline auto",
            "-sym on",
            # TODO charflags
            "-nodefaults",
            "-proc gekko",
            "-fp hard",
            "-Cpp_exceptions off",
            "-enum int",
            "-warn pragmas",
            "-requireprotos",
            '-pragma "cats off"',
            "-I-",
            "-Iextern/dolphin/include",
            "-Iextern/dolphin/include/libc",
            "-ir extern/dolphin/src",
            "-DRELEASE",
        ]
        src_dir = "extern/dolphin/src"
        includes = []
        system_includes = []
    else:
        src_dir = None
        includes = includes_base
        system_includes = system_includes_base

    return Lib(
        lib_name,
        objects,
        mw_version="GC/1.2.5n",
        fix_epilogue=fix_epilogue,
        src_dir=src_dir,
        cflags=cflags,
        includes=includes,
        system_includes=system_includes,
        category="sdk",
    )


def DolphinTrkLib(
    lib_name: str, objects: Objects, cflags=cflags_trk_minnow_dolphin, fix_epilogue=False, extern=False
) -> Library:
    src_dir = None
    includes = includes_base
    system_includes = system_includes_base
    return Lib(
        lib_name,
        objects,
        mw_version="GC/1.3",
        fix_epilogue=fix_epilogue,
        src_dir=src_dir,
        cflags=cflags,
        includes=includes,
        system_includes=system_includes,
        category="sdk",
    )


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False


config.libs = [
    RuntimeLib(
        "Gekko runtime",
        [
            Object(Matching, "PowerPC_EABI_Support/Runtime/__init_cpp_exceptions.cpp"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/__mem.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/__va_arg.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/global_destructor_chain.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/ptmf.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/runtime.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/Gecko_ExceptionPPC.cpp"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/NMWException.cpp"),
        ],
    ),
    GameLib(
        "SMS (Super Mario Strikers)",
        [
            Object(NonMatching, "Game/main.cpp"),
            Object(NonMatching, "Game/rotation.c"),
        ],
    ),
    GameLib(
        "NL (Next Level Library)",
        [
            Object(NonMatching, "NL/nlMath.cpp"),
        ],
    ),
    DolphinLib(
        "amcstubs",
        [
            Object(Matching, "Dolphin/AmcStub/AmcExi2Stubs.c"),
        ],
    ),    
    DolphinLib(
        "OdemuExi2",
        [
            Object(NonMatching, "Dolphin/OdemuExi2/DebuggerDriver.c"),
        ],
        cflags=cflags_odemuexi,
    ),
    DolphinLib(
        "OdenotStub",
        [
            Object(Matching, "Dolphin/OdenotStub/odenotstub.c"),
        ],
    ),        
    DolphinTrkLib(
        "TRK_MINNOW_DOLPHIN",
        [
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/mainloop.c"),
        ]
    ),  
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects

# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "Dolphin SDK Code"),
    ProgressCategory("third_party", "Third Party"),
    ProgressCategory("runtime", "Gekko Runtime Code"),
]
config.print_progress_categories = args.verbose
config.progress_each_module = args.verbose

# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)

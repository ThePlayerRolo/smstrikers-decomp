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
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-cwd source",
    "-Cpp_exceptions off",
    "-fp_contract on",
    "-nosyspath",
    "-O4,p",
    "-multibyte",
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

cflags_runtime_MSL_C = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    "-maxerrors 1",
    "-nosyspath",
    "-fp_contract off",
    "-multibyte",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-RTTI off",
    "-str reuse",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

cflags_dolphin = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-char signed",
    "-O4,p",
    "-sym on",
    "-inline auto",
    f"-DVERSION={version_num}",
    "-D__GEKKO__",
    "-DSDK_REVISION=2",
    # "-DSDK_REVISION=1",
]

cflags_musyx = [
    "-proc gekko",
    "-nodefaults",
    "-nosyspath",
    "-i include",
    "-i extern/musyx/include",
    # "-i libc",
    "-inline auto,depth=4",
    # "-inline auto",
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
    # "-i libc",
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
    *cflags_base,
    "-use_lmw_stmw on",
    "-rostr",
    "-str reuse",
    "-gccinc",
    "-common off",
    "-inline deferred",
    "-char signed",
    "-sdata 0",
    "-sdata2 0",   
    "-sdatathreshold 0",
]

includes_base = [
    "include",
    # "include/libc",
    "include/PowerPC_EABI_Support/MSL_C/MSL_Common/", #instead of libc, which is a copy of it...
]

system_includes_base = [
    "include",
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


def RuntimeLib_MSL_C(lib_name: str, objects: Objects) -> Library:
    return Lib(
        lib_name,
        objects,
        # mw_version="GC/1.3",
        cflags=[
            *cflags_runtime_MSL_C,
            "-fp_contract on", 
            "-inline auto,deferred", 
            "-str pool,readonly"
        ],
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


def DolphinLib(lib_name: str, objects: Objects, cflags=cflags_dolphin) -> Library:
    return Lib (
        lib_name,
        objects,
        includes=[
            *includes_base,
            "src/Dolphin",
        ],
        system_includes=[
            *system_includes_base,
            "include/Dolphin",
        ],
        mw_version="GC/1.2.5n",
        cflags=cflags,
        category="sdk",
    )


def DolphinTrkLib(lib_name: str, objects: Objects, cflags=cflags_trk_minnow_dolphin) -> Library:
    src_dir = None
    includes = includes_base
    system_includes = system_includes_base
    return Lib(
        lib_name,
        objects,
        mw_version="GC/1.3.2",
        src_dir=src_dir,
        cflags=cflags,
        includes=includes,
        system_includes=system_includes,
        category="sdk",
    )

def MusyxLib(lib_name: str, objects: Objects, debug=False, major=2, minor=0, patch=3) -> Library:
    cflags = cflags_musyx if not debug else cflags_musyx_debug
    return Lib (
        lib_name,
        objects,
        src_dir="extern/musyx/src",
        includes=[
            *includes_base,
            "src/Dolphin",
        ],
        mw_version="GC/1.3.2",
        cflags=[
            *cflags,
            f"-DMUSY_VERSION_MAJOR={major}",
            f"-DMUSY_VERSION_MINOR={minor}",
            f"-DMUSY_VERSION_PATCH={patch}",
        ],
        category="third_party",
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
        "Runtime.PPCEABI.H",
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
    RuntimeLib_MSL_C(
        "MSL_C.PPCEABI.bare.H",
        [
            # Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/alloc.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/ansi_files.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/abort_exit.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/errno.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/ansi_fp.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/arith.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/buffer_io.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/critical_regions.ppc_eabi.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/ctype.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/locale.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/direct_io.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/mbstring.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/mem.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/mem_funcs.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/misc_io.c"),
            # Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/printf.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/rand.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/scanf.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/string.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/strtold.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/strtoul.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/uart_console_io.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/wchar_io.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/float.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/e_asin.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/e_atan2.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/e_pow.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/fminmaxdim.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/s_atan.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/s_copysign.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/s_frexp.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/s_ldexp.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/w_atan2.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/w_pow.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/hyperbolicsf.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/inverse_trig.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/trigf.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/math_inlines.c"),
            # Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/common_float_tables.c"),
        ],
    ),
    GameLib(
        "SMS (Super Mario Strikers)",
        [
            Object(NonMatching, "Game/main.cpp"),
            Object(NonMatching, "Game/Ball.cpp"),
            Object(NonMatching, "Game/Math/rotation.c"),
            Object(NonMatching, "Game/Team.cpp")
        ],
    ),
    GameLib(
        "NL (Next Level Library)",
        [
            Object(NonMatching, "NL/nlMath.cpp"),
        ],
    ),

    DolphinLib(
        "Dolfin SDK",
        [
            # Dolphin/OS
            Object(NonMatching, "Dolphin/os/OS.c"),
            Object(Matching, "Dolphin/os/OSAlarm.c"),
            Object(Matching, "Dolphin/os/OSAlloc.c"),
            Object(Matching, "Dolphin/os/OSArena.c"),
            Object(Matching, "Dolphin/os/OSAudioSystem.c"),
            Object(Matching, "Dolphin/os/OSCache.c"),
            Object(Matching, "Dolphin/os/OSContext.c"),
            Object(Matching, "Dolphin/os/OSError.c"),
            Object(Matching, "Dolphin/os/OSExec.c"),
            Object(Matching, "Dolphin/os/OSFont.c", extra_cflags=["-char unsigned"]),
            Object(Matching, "Dolphin/os/OSInterrupt.c"),
            Object(Matching, "Dolphin/os/OSLink.c"),
            Object(Matching, "Dolphin/os/OSMemory.c"),
            Object(Matching, "Dolphin/os/OSMutex.c"),
            Object(Matching, "Dolphin/os/OSReboot.c"),
            Object(Matching, "Dolphin/os/OSReset.c"),
            Object(Matching, "Dolphin/os/OSResetSW.c"),
            Object(Matching, "Dolphin/os/OSRtc.c"),
            Object(Matching, "Dolphin/os/OSSync.c"),
            Object(Matching, "Dolphin/os/OSThread.c"),
            Object(Matching, "Dolphin/os/OSTime.c"),
            Object(Matching, "Dolphin/os/__start.c"),
            Object(Matching, "Dolphin/os/__ppc_eabi_init.cpp"),

            # Dolfin/AI
            Object(Matching, "Dolphin/ai/ai.c"),
            
            # Dolfin/AR
            Object(Matching, "Dolphin/ar/ar.c"),
            Object(Matching, "Dolphin/ar/arq.c"),

            # Dolphin/BASE
            Object(Matching, "Dolphin/base/PPCArch.c"),

            # Dolphin/CARD
            Object(Matching, "Dolphin/card/CARDBios.c"),
            Object(Matching, "Dolphin/card/CARDUnlock.c"),
            Object(Matching, "Dolphin/card/CARDRdwr.c"),
            Object(Matching, "Dolphin/card/CARDBlock.c"),
            Object(Matching, "Dolphin/card/CARDDir.c"),
            Object(Matching, "Dolphin/card/CARDCheck.c"),
            Object(Matching, "Dolphin/card/CARDMount.c"),
            Object(Matching, "Dolphin/card/CARDFormat.c"),
            Object(Matching, "Dolphin/card/CARDOpen.c"),
            Object(Matching, "Dolphin/card/CARDCreate.c"),
            Object(Matching, "Dolphin/card/CARDRead.c"),
            Object(Matching, "Dolphin/card/CARDWrite.c"),
            Object(Matching, "Dolphin/card/CARDDelete.c"),
            Object(Matching, "Dolphin/card/CARDStat.c"),
            Object(Matching, "Dolphin/card/CARDNet.c"), 

            # Dolfin/DB
            Object(Matching, "Dolphin/db/db.c"),

            # Dolfin/DSP
            Object(Matching, "Dolphin/dsp/dsp.c"),
            Object(Matching, "Dolphin/dsp/dsp_debug.c"),
            Object(Matching, "Dolphin/dsp/dsp_task.c"),

            # Dolphin/DVD
            Object(Matching, "Dolphin/dvd/dvdlow.c"),
            Object(Matching, "Dolphin/dvd/dvdfs.c"),
            Object(Matching, "Dolphin/dvd/dvd.c"),
            Object(Matching, "Dolphin/dvd/dvdqueue.c"),
            Object(Matching, "Dolphin/dvd/dvderror.c"),
            Object(Matching, "Dolphin/dvd/dvdidutils.c"),
            Object(Matching, "Dolphin/dvd/dvdFatal.c"),
            Object(Matching, "Dolphin/dvd/fstload.c"),         

            # Dolphin/EXI
            Object(NonMatching, "Dolphin/exi/EXIBios.c", extra_cflags=["-O3,p"]),
            Object(Matching, "Dolphin/exi/EXIUart.c"),

            # Dolphin/GX
            Object(Matching, "Dolphin/gx/GXInit.c", extra_cflags=["-opt nopeephole"]),
            Object(Matching, "Dolphin/gx/GXFifo.c"),
            Object(Matching, "Dolphin/gx/GXAttr.c"),
            Object(Matching, "Dolphin/gx/GXMisc.c"),
            Object(Matching, "Dolphin/gx/GXGeometry.c"),
            Object(Matching, "Dolphin/gx/GXFrameBuf.c"),
            Object(Matching, "Dolphin/gx/GXLight.c", extra_cflags=["-fp_contract off"]),
            Object(Matching, "Dolphin/gx/GXTexture.c"),
            Object(Matching, "Dolphin/gx/GXBump.c"),
            Object(Matching, "Dolphin/gx/GXTev.c"),
            Object(Matching, "Dolphin/gx/GXPixel.c"),
            Object(Matching, "Dolphin/gx/GXDisplayList.c"),
            Object(Matching, "Dolphin/gx/GXTransform.c", extra_cflags=["-fp_contract off"]),
            Object(Matching, "Dolphin/gx/GXPerf.c"),

            # Dolphin/MTX
            Object(Matching, "Dolphin/mtx/mtx.c", extra_cflags=["-char signed"]),
            Object(NonMatching, "Dolphin/mtx/mtx44.c", extra_cflags=["-char signed"]),
            Object(NonMatching, "Dolphin/mtx/quat.c", extra_cflags=["-char signed", "-fp_contract off"]),

            # Dolphin/PAD
            Object(Matching, "Dolphin/pad/Padclamp.c"),
            Object(Matching, "Dolphin/pad/Pad.c"),

            # Dolphin/SI
            Object(Matching, "Dolphin/si/SIBios.c"),
            Object(Matching, "Dolphin/si/SISamplingRate.c"),

            # Dolphin/VI
            Object(Matching, "Dolphin/vi/vi.c"),
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
            Object(Matching, "Dolphin/OdemuExi2/DebuggerDriver.c"),
        ],
        cflags=cflags_odemuexi,
    ),

    DolphinLib(
        "OdenotStub",
        [
            Object(Matching, "Dolphin/OdenotStub/odenotstub.c"),
        ],
    ),        
    MusyxLib(
        "Musyx",
        [
            Object(Matching, "musyx/runtime/seq.c"),
            Object(Matching, "musyx/runtime/synth.c"),
            Object(Matching, "musyx/runtime/seq_api.c"),
            Object(Matching, "musyx/runtime/snd_synthapi.c"),
            Object(NonMatching, "musyx/runtime/stream.c"),
            Object(Matching, "musyx/runtime/synthdata.c"),
            Object(NonMatching, "musyx/runtime/synthmacros.c"),
            Object(NonMatching, "musyx/runtime/synthvoice.c"),
            Object(Matching, "musyx/runtime/synth_ac.c"),
            Object(Matching, "musyx/runtime/synth_dbtab.c"),
            Object(Matching, "musyx/runtime/synth_adsr.c"),
            Object(NonMatching, "musyx/runtime/synth_vsamples.c"),
            Object(NonMatching, "musyx/runtime/s_data.c"),
            Object(NonMatching, "musyx/runtime/hw_dspctrl.c"),
            Object(Matching, "musyx/runtime/hw_volconv.c"),
            Object(Matching, "musyx/runtime/snd3d.c"),
            Object(Matching, "musyx/runtime/snd_init.c"),
            Object(Matching, "musyx/runtime/snd_math.c"),
            Object(Matching, "musyx/runtime/snd_midictrl.c"),
            Object(Matching, "musyx/runtime/snd_service.c"),
            Object(Matching, "musyx/runtime/hardware.c"),
            Object(Matching, "musyx/runtime/dsp_import.c"),
            Object(Matching, "musyx/runtime/hw_aramdma.c"),
            Object(Matching, "musyx/runtime/hw_dolphin.c"),
            Object(Matching, "musyx/runtime/hw_memory.c"),
            Object(Matching, "musyx/runtime/CheapReverb/creverb_fx.c"),
            Object(Matching, "musyx/runtime/CheapReverb/creverb.c"),
            Object(Matching, "musyx/runtime/StdReverb/reverb_fx.c"),
            Object(Matching, "musyx/runtime/StdReverb/reverb.c"),
            Object(Matching, "musyx/runtime/Delay/delay_fx.c"),
            Object(Matching, "musyx/runtime/Chorus/chorus_fx.c"),
        ]
    ),        
    DolphinTrkLib(
        "TRK_MINNOW_DOLPHIN",
        [
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/main_TRK.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/mutex_TRK.c"),      
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/mem_TRK.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/CircleBuffer.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/dolphin_trk.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
            
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/target_options.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/targcont.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/targsupp.c"),
            
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/notify.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/flush_cache.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/dispatch.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/serpoll.c", extra_cflags=["-sdata 8"]),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/mainloop.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/nubevent.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/nubinit.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/usr_put.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/support.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/UDP_Stubs.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/msg.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/msgbuf.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/msghndlr.c"),

            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/MWTrace.c"),
            Object(Matching, "SDK/TRK_MINNOW_DOLPHIN/MWCriticalSection_gc.cpp"),

            # NonMatchin...
            Object(NonMatching, "SDK/TRK_MINNOW_DOLPHIN/main.c"),
            Object(NonMatching, "SDK/TRK_MINNOW_DOLPHIN/main_gdev.c"),
            Object(NonMatching, "SDK/TRK_MINNOW_DOLPHIN/__exception.s"),

            Object(NonMatching, "SDK/TRK_MINNOW_DOLPHIN/targimpl.c"),
            Object(NonMatching, "SDK/TRK_MINNOW_DOLPHIN/mslsupp.c", extra_cflags=["-enum int"]),
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

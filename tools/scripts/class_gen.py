import os
import re
import sys
import argparse

print("Script started")

def parse_function_metadata(comment_line):
    # Parse: # .text:0x0 | 0x801FFCFC | size: 0x70
    pattern = r"\.text:(0x[0-9A-Fa-f]+) \| (0x[0-9A-Fa-f]+) \| size: (0x[0-9A-Fa-f]+)"
    match = re.search(pattern, comment_line)
    if match:
        return {
            'offset': match.group(1),
            'address': match.group(2),
            'size': match.group(3)
        }
    return None


def parse_function_declaration(comment_line):
    # Remove the leading # and strip whitespace
    decl = comment_line.lstrip('#').strip()
    return decl


def is_class_method(declaration):
    return '::' in declaration


def get_class_name(declaration):
    if is_class_method(declaration):
        return declaration.split('::')[0]
    return None


def generate_cpp_content(filename, functions):
    content = []
    content.append(f"#include \"{filename}.h\"\n")
    
    for func in functions:
        content.append("/**")
        content.append(f" * Offset/Address/Size: {func['offset']} | {func['address']} | size: {func['size']}")
        content.append(" */")
        content.append(f"{func['declaration']}")
        content.append("{")
        content.append("}\n")
    
    return '\n'.join(content)


def generate_header_content(filename, functions):
    # Convert filename to uppercase for include guard
    guard_name = filename.upper().replace('.', '_')
    
    content = []
    content.append(f"#ifndef _{guard_name}_H_")
    content.append(f"#define _{guard_name}_H_\n")
    
    # Group functions by class
    class_methods = {}
    standalone_functions = []
    
    for func in functions:
        if is_class_method(func['declaration']):
            class_name = get_class_name(func['declaration'])
            if class_name not in class_methods:
                class_methods[class_name] = []
            class_methods[class_name].append(func)
        else:
            standalone_functions.append(func)
    
    # Add forward declarations for standalone functions
    for func in standalone_functions:
        content.append(f"{func['declaration']};")
    
    # Add class declarations with their methods
    for class_name, methods in class_methods.items():
        content.append(f"\nclass {class_name}")
        content.append("{")
        content.append("public:")
        for method in methods:
            content.append(f"    {method['declaration']};")
        content.append("};\n")
    
    content.append(f"#endif // _{guard_name}_H_")
    
    return '\n'.join(content)


def process_s_file(s_file_path):
    functions = []
    current_function = None
    
    try:
        with open(s_file_path, 'r') as f:
            lines = f.readlines()
            
            for line in lines:
                line = line.strip()
                
                if line.startswith('# .text:'):
                    # Start of function metadata
                    metadata = parse_function_metadata(line)
                    if metadata:
                        current_function = metadata
                
                elif line.startswith('# ') and current_function:
                    # Function declaration
                    declaration = parse_function_declaration(line)
                    current_function['declaration'] = declaration
                    functions.append(current_function)
                    current_function = None
                
    except FileNotFoundError:
        print(f"Error: Could not find {s_file_path}")
        return None
    
    return functions


def find_s_file(obj_filename, search_dir):
    # Get just the filename without path and extension
    base_name = os.path.splitext(os.path.basename(obj_filename))[0]
    s_filename = f"{base_name}.s"
    
    # Use the provided search directory
    search_path = os.path.join(search_dir, s_filename)
    
    print("Looking for .s file:")
    print(f"  Base name: {base_name}")
    print(f"  Search dir: {search_dir}")
    print(f"  Full path: {search_path}")
    print(f"  Path exists: {os.path.exists(search_path)}")
    
    if os.path.exists(search_path):
        return search_path
    return None


def process_single_file(obj_file, output_dir, search_dir):
    s_file = find_s_file(obj_file, search_dir)
    if s_file:
        print(f"Processing {s_file}...")
        
        # Process the .s file
        functions = process_s_file(s_file)
        if functions:
            # Generate output files
            base_name = os.path.splitext(os.path.basename(s_file))[0]
            
            # Generate .cpp file
            cpp_content = generate_cpp_content(base_name, functions)
            cpp_path = os.path.join(output_dir, f"{base_name}.cpp")
            with open(cpp_path, 'w') as f:
                f.write(cpp_content)
            
            # Generate .h file
            h_content = generate_header_content(base_name, functions)
            h_path = os.path.join(output_dir, f"{base_name}.h")
            with open(h_path, 'w') as f:
                f.write(h_content)
            
            print(f"Generated {cpp_path} and {h_path}")
            return True
    else:
        print(f"No .s file found for {obj_file}")
    return False


def process_class_file(class_file, output_dir, search_dir):
    try:
        with open(class_file, "r") as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"Error: {class_file} not found")
        return False

    success = True
    for line in lines:
        line = line.strip()
        if not line:
            continue
            
        if not process_single_file(line, output_dir, search_dir):
            success = False
            
    return success


def main():
    parser = argparse.ArgumentParser(description='Generate C++ files from assembly files')
    parser.add_argument('--class-file', help='Path to class.txt containing list of object files')
    parser.add_argument('--obj-file', help='Path to a single object file to process')
    parser.add_argument('--output-dir', default='src/_class_gen', help='Output directory for generated files')
    parser.add_argument('--search-dir', default='build/G4QE01/asm', help='Directory to search for .s files')
    
    args = parser.parse_args()
    
    # Create output directory if it doesn't exist
    os.makedirs(args.output_dir, exist_ok=True)
    
    if args.class_file:
        if not process_class_file(args.class_file, args.output_dir, args.search_dir):
            sys.exit(1)
    elif args.obj_file:
        if not process_single_file(args.obj_file, args.output_dir, args.search_dir):
            sys.exit(1)
    else:
        print("Error: Either --class-file or --obj-file must be specified")
        parser.print_help()
        sys.exit(1)


if __name__ == "__main__":
    main() 

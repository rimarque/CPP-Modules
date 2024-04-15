import os
import sys

def generate_class_files(class_names):
    # Create 'includes' directory if it doesn't exist
    includes_dir = 'includes'
    os.makedirs(includes_dir, exist_ok=True)

    first_template_hpp = """\
#ifndef {guard}
# define {guard}

# include <iostream>
# include <string.h>
# include <unistd.h>
# define RED "\\033[1;31m"
# define GREEN "\\033[1;32m"
# define PURPLE "\\033[1;35m"
# define YELLOW "\\033[1;33m"
# define WHITE 	"\\033[1;37m"
# define CYAN "\\033[1;36m"
# define RESET "\\033[0m"

class {class_name} {{
public:
    {class_name}(); // Constructor
    {class_name}(const {class_name}& copy);//Copy constructor
    {class_name}& operator= (const {class_name}& copy); //Copy assignment constructor
    ~{class_name}(); // Destructor

private:
    // Add private members here
}};

#endif // {guard}
"""

    template_hpp = """\
#ifndef {guard}
# define {guard}

# include "{last_class_name}.hpp"

class {class_name} {{
public:
    {class_name}(); // Constructor
    {class_name}(const {class_name}& copy);//Copy constructor
    {class_name}& operator= (const {class_name}& copy); //Copy assignment constructor
    ~{class_name}(); // Destructor

private:
    // Add private members here
}};

#endif // {guard}
"""

    template_cpp = """\
#include "{includes_dir}/{class_name}.hpp"

{class_name}::{class_name}() {{
    std::cout << WHITE << "{class_name}" << RESET 
    << " default constructor called" << std::endl;
}}

// Copy constructor
{class_name}::{class_name}(const {class_name}& copy) {{
    // Copy stuff
    std::cout << WHITE << "{class_name}" << RESET 
    << " copy constructor called" << std::endl;
}}

// Copy assignment operator overload
{class_name}& {class_name}::operator= (const {class_name}& copy) {{
    // Self-assignment check
    if (this == &copy)
        return *this;
    // Copy stuff
    std::cout << WHITE << "{class_name}" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}}

{class_name}::~{class_name}() {{
    std::cout << WHITE << "{class_name}" << RESET 
    << " destructor called" << std::endl;
}}
    """

    last_class_name = None
    for index, class_name in enumerate(class_names):
        # Prepare file names and content
        header_filename = os.path.join(includes_dir, f"{class_name}.hpp")
        cpp_filename = f"{class_name}.cpp"
        guard_name = f"{class_name.upper()}_H"  # Header guard name

        if index == 0:
            header_content = first_template_hpp.format(class_name=class_name, guard=guard_name)
        else:
            header_content = template_hpp.format(
                class_name=class_name,
                guard=guard_name, 
                last_class_name=last_class_name if last_class_name else'')
        
        cpp_content = template_cpp.format(class_name=class_name, includes_dir=includes_dir)

        # Write header file into 'includes' directory
        with open(header_filename, "w") as header_file:
            header_file.write(header_content)

        print(f"Generated {header_filename}")

        # Write cpp file (not in 'includes' directory)
        with open(cpp_filename, "w") as cpp_file:
            cpp_file.write(cpp_content)

        print(f"Generated {cpp_filename}")
        last_class_name = class_name

    print("All files generated successfully.")

if __name__ == "__main__":
    # Read class names from command-line arguments
    class_names = sys.argv[1:]

    if len(class_names) < 1:
        print("Usage: python3 cppClassGenerator.py ClassName1 ClassName2 ...")
        sys.exit(1)

    generate_class_files(class_names)

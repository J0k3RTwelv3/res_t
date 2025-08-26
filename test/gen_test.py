import os
import sys
from pathlib import Path

'''
This script is responsible for generating a fresh test executable. It does the following:
1. Creates a new directory for the test
2. Creates a new main.c file in that directory and fills it with an empty main function
3. Copies properly modified meson.build.template to the test directory
4. Adds the test to the top-level test meson.build file
'''
def main():

    cwd = Path(os.getcwd())
    test_name = sys.argv[1]

    test_dir = cwd / test_name
    test_dir.mkdir()

    with open((test_dir / 'main.c'), 'w') as f:
        f.write('#include <stdlib.h>\n\nint main(int argc, char** argv)\n{\n\treturn EXIT_SUCCESS;\n}')

    with open((cwd / 'meson.build.template'), 'r') as f:
        template = f.read()
        template = template.replace("YOUR_TEST", f"{test_name}_test")

        with open((test_dir / 'meson.build'), 'w') as f:
            f.write(template)

    with open((cwd / 'meson.build'), 'a') as f:
        f.write(f"\nsubdir('{test_name}')")

    print(f"Generated test '{test_name}' successfully.")

if __name__ == '__main__':
    main()
"""
 ****************************************************************************
 * Copyright 2025 O_X                                                       *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *   http://www.apache.org/licenses/LICENSE-2.0                             *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ****************************************************************************
"""

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

        with open((test_dir / 'meson.build'), 'w') as m:
            m.write(template)

    with open((cwd / 'meson.build'), 'a') as f:
        f.write(f"\nsubdir('{test_name}')")

    print(f"Generated test '{test_name}' successfully.")

if __name__ == '__main__':
    main()
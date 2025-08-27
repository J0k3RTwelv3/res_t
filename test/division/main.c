//
// Created by O_X on 26.08.2025.
//

/****************************************************************************
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
 ****************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <rest/rest.h>

RES_MAKE(divide, double, char*)
RES_T(divide) divide(const double a, const double b)
{
    if (b == 0)
    {
        return RES_ERR(divide, strdup("Division by zero error!"));
    }

    return RES_OK(divide, a / b);
}

int main()
{
    RES_T(divide) res = divide(10, 2);

    assert(res.is_ok == 1);
    assert(res.ok_val == 5);

    res = divide(10, 0);

    assert(res.is_ok == 0);
    assert(strcmp(res.err_val, "Division by zero error!") == 0);

    return EXIT_SUCCESS;
}
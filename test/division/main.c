//
// Created by O_X on 26.08.2025.
//

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
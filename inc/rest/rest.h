//
// Created by O_X on 26.08.2025.
//

#pragma once

#define __RESULT_NAME_S(name) res_##name

#define __RESULT_NAME(name) res_##name##_t

#define __MAKE_RESULT_TYPE(name, ok_t, err_t)               \
    typedef struct __RESULT_NAME_S(name) {                  \
        unsigned char is_ok;                                \
        union {                                             \
            ok_t ok_val;                                    \
            err_t err_val;                                  \
        };                                                  \
    } __RESULT_NAME(name);

#define RES_MAKE(name, ok_t, err_t)                         \
    __MAKE_RESULT_TYPE(name, ok_t, err_t)

#define RES_T(name) __RESULT_NAME(name)

#define RES_OK(name, ok)                                    \
    ((__RESULT_NAME(name)) {                                \
        .is_ok = (unsigned char)(1),                        \
        .ok_val = (ok)                                      \
    })

#define RES_ERR(name, err)                                  \
    ((__RESULT_NAME(name)) {                                \
        .is_ok = (unsigned char)(0),                        \
        .err_val = (err)                                    \
    })

#define RES_FUNC(name, ok_t, err_t, ...)                    \
    __MAKE_RESULT_TYPE(name, ok_t, err_t)                   \
    __RESULT_NAME(name) name(__VA_ARGS__)
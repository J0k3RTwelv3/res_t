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
/* ********************************************************************
 *                                                                    *
 *    (C) Copyright Paul Fultz II 2012.                               *
 *                                                                    *
 *    Distributed under the Boost Software License, Version 1.0.      *
 *    (See accompanying file LICENSE).                                *
 *                                                                    *
 *    See http://github.com/pfultz2/Ripple for most recent version.   *
 *                                                                    *
 ******************************************************************** */

#ifndef RIPPLE_PREPROCESSOR_CAT_H
#define RIPPLE_PREPROCESSOR_CAT_H
#include <ripple/config.h>

#define RPP_PRIMITIVE_CAT(x, ...) x ## __VA_ARGS__

#define RPP_CAT(x, ...) RPP_PRIMITIVE_CAT(x, __VA_ARGS__)

#define RPP_CAT_ALL(...) DETAIL_RPP_CAT_ALL_I(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,)

#define DETAIL_RPP_CAT_ALL_I(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) \
        a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## n ## o ## p ## q ## r ## s ## t ## u ## v ## w ## x ## y

#define RPP_CAT_HEAD(x, ...) RPP_CAT(x, DETAIL_RPP_CAT_HEAD(__VA_ARGS__,))
#define DETAIL_RPP_CAT_HEAD(x, ...) x

#endif
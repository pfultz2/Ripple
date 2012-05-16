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

#ifndef RIPPLE_PREPROCESSOR_REPETITION_H
#define RIPPLE_PREPROCESSOR_REPETITION_H
#include <ripple/config.h>

#define RPP_REPEAT_S(s, n, m, ...) DETAIL_RPP_REPEAT_I(OBSTRUCT(), INC(s), n, m, __VA_ARGS__)
        
#define DETAIL_RPP_REPEAT_INDIRECT() DETAIL_RPP_REPEAT_I
#define DETAIL_RPP_REPEAT_I(_, s, n, m, ...) \
WHEN _(n)(EXPR_S _(s) \
( \
    DETAIL_RPP_REPEAT_INDIRECT _()(OBSTRUCT _(), INC _(s), DEC _(n), m, __VA_ARGS__) \
))\
m _(s, n, __VA_ARGS__)

#endif
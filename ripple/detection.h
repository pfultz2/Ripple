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

#ifndef RIPPLE_PREPROCESSOR_DETECTION_H
#define RIPPLE_PREPROCESSOR_DETECTION_H
#include <ripple/config.h>
#include <ripple/cat.h>

#define DETAIL_RPP_CHECK_N(x, n, ...) n
#define RPP_CHECK(...) DETAIL_RPP_CHECK_N(__VA_ARGS__, 0,)

#define RPP_PROBE(x) x, 1,

#define RPP_IS_1(...) CHECK(RPP_CAT_HEAD(DETAIL_RPP_IS_1_, __VA_ARGS__))
#define DETAIL_RPP_IS_1_1 RPP_PROBE(~)

#define DETAIL_RPP_EMPTY_PROBE_DETAIL_RPP_EMPTY_PROBE RPP_PROBE(~)
#define RPP_IS_EMPTY(x) RPP_CHECK(RPP_CAT(DETAIL_RPP_EMPTY_PROBE_, x  DETAIL_RPP_EMPTY_PROBE))

#define DETAIL_RPP_PAREN_PROBE(...) RPP_PROBE(~)
#define DETAIL_RPP_IS_PAREN_HEAD(x, ...) x
#define RPP_IS_PAREN(...) CHECK(DETAIL_RPP_PAREN_PROBE DETAIL_RPP_IS_PAREN_HEAD(__VA_ARGS__,))


#endif
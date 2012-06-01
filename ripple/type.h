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

#ifndef RIPPLE_PREPROCESSOR_TYPE_H
#define RIPPLE_PREPROCESSOR_TYPE_H
#include <ripple/config.h>
#include <ripple/basic.h>

#define RPP_TYPEOF(...) DETAIL_RPP_TYPEOF(DETAIL_RPP_TYPEOF_PROBE __VA_ARGS__,)

#define DETAIL_RPP_TYPEOF(...) DETAIL_RPP_TYPEOF_HEAD(__VA_ARGS__)
#define DETAIL_RPP_TYPEOF_HEAD(x, ...) x
#define DETAIL_RPP_TYPEOF_PROBE(x) x, 

#define RPP_STRIP(...) RPP_EAT __VA_ARGS__

#define RPP_GENERIC(m, ...) RPP_CAT_ALL(RPP_TYPEOF(__VA_ARGS__), _, m)

#define RPP_PAIR(...) RPP_REM __VA_ARGS__

#endif
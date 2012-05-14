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

#ifndef RIPPLE_PREPROCESSOR_RECURSION_H
#define RIPPLE_PREPROCESSOR_RECURSION_H
#include <ripple/config.h>
#include <ripple/ops.h>
#include <ripple/detection.h>
#include <ripple/search.h>

#define RPP_NEXT(s) RPP_INC(s)

#define RPP_PREV(s) RPP_PREV(s)

#define RPP_IS_VALID(s) RPP_IS_PAREN(RPP_PRIMITIVE_CAT(DETAIL_RPP_EXPR_, s)(()))

#define RPP_STATE() RPP_SEARCH(RPP_IS_VALID, RIPPLE_AUTO_LIMIT)

#define RPP_EXPR_S(s) RPP_PRIMITIVE_CAT(DETAIL_RPP_EXPR_, s)

$for i in range(65537)
{
#define DETAIL_RPP_EXPR_$(i)(...) __VA_ARGS__
}

#endif
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

#ifndef RIPPLE_PREPROCESSOR_LOGIC_H
#define RIPPLE_PREPROCESSOR_LOGIC_H
#include <ripple/config.h>
#include <ripple/cat.h>
#include <ripple/detection.h>


#define RPP_COMPL(b) RPP_PRIMITIVE_CAT(DETAIL_RPP_COMPL_, b)
#define DETAIL_RPP_COMPL_0 1
#define DETAIL_RPP_COMPL_1 0

#define RPP_BITAND(x, y) RPP_CAT(DETAIL_RPP_BITAND_, RPP_CAT(x, y))
#define DETAIL_RPP_BITAND_00 0
#define DETAIL_RPP_BITAND_01 0
#define DETAIL_RPP_BITAND_10 0
#define DETAIL_RPP_BITAND_11 1

#define RPP_BITOR(x, y) RPP_CAT(DETAIL_RPP_BITOR_, RPP_CAT(x, y))
#define DETAIL_RPP_BITOR_00 0
#define DETAIL_RPP_BITOR_01 1
#define DETAIL_RPP_BITOR_10 1
#define DETAIL_RPP_BITOR_11 1

#define RPP_NOT(x) RPP_CHECK(RPP_PRIMITIVE_CAT(DETAIL_RPP_NOT_PROBE_, x))
#define DETAIL_RPP_NOT_PROBE_0 RPP_PROBE(~)

#define RPP_BOOL(x) RPP_COMPL(RPP_NOT(x))

#define RPP_AND(x, y) RPP_BITAND(RPP_BOOL(x), RPP_BOOL(y))
#define RPP_OR(x, y) RPP_BITOR(RPP_BOOL(x), RPP_BOOL(y))

#define RPP_IIF(c) RPP_PRIMITIVE_CAT(DETAIL_RPP_IIF_, c)
#define DETAIL_RPP_IIF_0(t, ...) __VA_ARGS__
#define DETAIL_RPP_IIF_1(t, ...) t

#define RPP_IF(c) RPP_IIF(RPP_BOOL(c))

#define RPP_INLINE_WHEN(c) RPP_PRIMITIVE_CAT(DETAIL_RPP_INLINE_WHEN_, c)
#define DETAIL_RPP_INLINE_WHEN_0(...) 
#define DETAIL_RPP_INLINE_WHEN_1(...) __VA_ARGS__

#define RPP_WHEN(c) RPP_INLINE_WHEN(RPP_BOOL(c))


#endif
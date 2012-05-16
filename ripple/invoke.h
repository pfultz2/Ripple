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

#ifndef RIPPLE_PREPROCESSOR_INVOKE_H
#define RIPPLE_PREPROCESSOR_INVOKE_H
#include <ripple/config.h>
#include <ripple/type.h>
#include <ripple/detection.h>

#define DETAIL_RPP_INVOKER_0(e) RPP_MACRO_INVOKE
#define DETAIL_RPP_INVOKER_1(e) RPP_GENERIC(INVOKE, e)
#define RPP_INVOKER(e) RPP_CAT(DETAIL_RPP_INVOKER_, RPP_IS_PAREN(e))(e)

#define RPP_INVOKE(e, ...) RPP_INVOKE_S(RPP_STATE(), e, __VA_ARGS__)

#define RPP_INVOKE_S(s, e, ...) RPP_INVOKER(e)()(s, e, __VA_ARGS__)

#define RPP_MACRO_INVOKE() DETAIL_RPP_MACRO_INVOKE
#define DETAIL_RPP_MACRO_INVOKE(s, m, ...) RPP_EXPR_S(s)(m RPP_OBSTRUCT()(__VA_ARGS__))




#endif
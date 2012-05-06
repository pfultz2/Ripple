# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides, Paul Fultz II 2003-2012.         *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://github.com/pfultz2/Ripple for most recent version.   *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef RIPPLE_PREPROCESSOR_INVOKE_H
# define RIPPLE_PREPROCESSOR_INVOKE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/generics/typeof.h>
# include <ripple/generics/strip.h>
#
# define DETAIL_RPP_INVOKE_MACRO_TYPE(x) RPP_MACRO
# define DETAIL_RPP_INVOKER_DISPATCH_CAT(x) x ## _INVOKE
# define DETAIL_RPP_INVOKER_DISPATCH(x) DETAIL_RPP_INVOKER_DISPATCH_CAT(x)
# define DETAIL_RPP_INVOKER(x) RPP_IIF_SHADOW(RPP_IS_VARIADIC(x))(RPP_TYPEOF, DETAIL_RPP_INVOKE_MACRO_TYPE)(x)
# define RPP_INVOKER(x) DETAIL_RPP_INVOKER_DISPATCH(DETAIL_RPP_INVOKER(x))
#
# define RPP_INVOKE(e, ...) RPP_INVOKE_S(RPP_STATE(), e, __VA_ARGS__)
#
# define RPP_INVOKE_S(s, e, ...) RPP_INVOKER(e)()(s, e, __VA_ARGS__)
#
#
# define RPP_INVOKE_ID() RPP_INVOKE
# define RPP_INVOKE_S_ID() RPP_INVOKE_S
#
#
# define RPP_MACRO_INVOKE() DETAIL_RPP_MACRO_INVOKE
# define DETAIL_RPP_MACRO_INVOKE(s, m, ...) RPP_EXPR_S(s)(m RPP_OBSTRUCT()(__VA_ARGS__))
#
# endif
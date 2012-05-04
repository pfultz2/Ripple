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
# define RPP_INVOKE(e, ...) RPP_INVOKER(e)(e, __VA_ARGS__)
#
# define DETAIL_RPP_MACRO_INVOKE_X(x) x
# define DETAIL_RPP_MACRO_INVOKE_P(n) \
    RPP_IS_NULLARY(RPP_PRIMITIVE_CAT(RPP_MACRO_INVOKE_, n)(DETAIL_RPP_MACRO_INVOKE_X, ()))
# define DETAIL_RPP_MACRO_INVOKE_STATE() RPP_AUTO_REC(DETAIL_RPP_MACRO_INVOKE_P, 8)
# define RPP_MACRO_INVOKE RPP_MACRO_INVOKE_S(DETAIL_RPP_MACRO_INVOKE_STATE())
//# define RPP_MACRO_INVOKE(m, ...) m(__VA_ARGS__)
#
# define RPP_MACRO_INVOKE_S(s) RPP_PRIMITIVE_CAT(RPP_MACRO_INVOKE_, s)
# define RPP_MACRO_INVOKE_1(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_2(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_3(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_4(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_5(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_6(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_7(m, ...) m(__VA_ARGS__)
# define RPP_MACRO_INVOKE_8(m, ...) m(__VA_ARGS__)
#
# endif
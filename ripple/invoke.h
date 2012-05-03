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
# define DETAIL_RPP_INVOKE(n, ...) RPP_CAT(RPP_CAT(DETAIL_RPP_INVOKE_, RPP_IS_VARIADIC(__VA_ARGS__)), n)
# define DETAIL_RPP_INVOKE_0_1(m, ...) m(__VA_ARGS__)
# define DETAIL_RPP_INVOKE_1_1(e, ...) 
#
# define RPP_INVOKER(x) RPP_CAT(RPP_IIF(RPP_IS_VARIADIC(x))(RPP_TYPEOF(x), RPP_MACRO), _INVOKE)
# define RPP_INVOKE(e, ...) RPP_INVOKER(e)(e, __VA_ARGS__)
#
# define DETAIL_RPP_MACRO_INVOKE_X(x) x
# define DETAIL_RPP_MACRO_INVOKE_P(n) RPP_IS_NULLARY(RPP_MACRO_INVOKE_ ## n(()))
# define RPP_MACRO_INVOKE RPP_AUTO_REC(DETAIL_RPP_MACRO_INVOKE_P, 8)
#
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
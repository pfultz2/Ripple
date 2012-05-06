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
# ifndef RIPPLE_PREPROCESSOR_BIND_H
# define RIPPLE_PREPROCESSOR_BIND_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/generics/typeof.h>
# include <ripple/generics/strip.h>
# include <ripple/facilities/optional.h>
#
# define RPP_BIND_DATA(m, ...) (RPP_BIND_DATA)(m, __VA_ARGS__)
#
# define DETAIL_RPP_BIND_DATA_MACRO_RES(x) x
# define DETAIL_RPP_BIND_DATA_MACRO_REM(m, ...) m
# define DETAIL_RPP_BIND_DATA_MACRO(e) DETAIL_RPP_BIND_DATA_MACRO_RES(DETAIL_RPP_BIND_DATA_MACRO_REM RPP_STRIP(e))
#
# define DETAIL_RPP_BIND_DATA_ARGS_REM(m, ...) __VA_ARGS__
# define DETAIL_RPP_BIND_DATA_ARGS_RES(x) x
# define DETAIL_RPP_BIND_DATA_ARGS(e, ...) DETAIL_RPP_BIND_DATA_ARGS_RES((__VA_ARGS__, DETAIL_RPP_BIND_DATA_ARGS_REM RPP_STRIP(e)))
# 
#
# define RPP_BIND_DATA_INVOKE() DETAIL_RPP_BIND_DATA_INVOKE
# define DETAIL_RPP_BIND_DATA_INVOKE_I(s, m, args) RPP_EXPR_S(s)(m RPP_OBSTRUCT() args)
# define DETAIL_RPP_BIND_DATA_INVOKE(s, e, ...) \
    DETAIL_RPP_BIND_DATA_INVOKE_I(s, DETAIL_RPP_BIND_DATA_MACRO(e), \
        DETAIL_RPP_BIND_DATA_ARGS(e, __VA_ARGS__))
#
#
# endif
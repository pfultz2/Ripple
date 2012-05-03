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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_OVERLOAD_H
# define RIPPLE_PREPROCESSOR_FACILITIES_OVERLOAD_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/limits.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/size.h>
#
# /* RPP_QUICK_OVERLOAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_QUICK_OVERLOAD(pre, ...) RPP_CAT(pre, RPP_TUPLE_QUICK_SIZE((__VA_ARGS__)))
#    define RPP_QUICK_OVERLOAD_ID() RPP_QUICK_OVERLOAD
# endif
#
# /* RPP_OVERLOAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_OVERLOAD(pre, ...) RPP_OVERLOAD_BYPASS(RPP_LIMIT_EXPR, pre, __VA_ARGS__)
#    define RPP_OVERLOAD_ID() RPP_OVERLOAD
# endif
#
# /* RPP_OVERLOAD_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_OVERLOAD_BYPASS(s, pre, ...) \
        RPP_CAT(pre, RPP_TUPLE_SIZE_BYPASS(s, (__VA_ARGS__))) \
        /**/
#    define RPP_OVERLOAD_BYPASS_ID() RPP_OVERLOAD_BYPASS
# endif
#
# endif

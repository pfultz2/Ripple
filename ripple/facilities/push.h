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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_PUSH_H
# define RIPPLE_PREPROCESSOR_FACILITIES_PUSH_H
#
# include <ripple/config.h>
# include <ripple/facilities/whitespace.h>
#
# /* RPP_PUSH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PUSH(a, ...) RPP_CLEAN(a)RPP_CLEAN(__VA_ARGS__)
# else
#    define RPP_PUSH(a, b) DETAIL_RPP_PUSH_I(a)DETAIL_RPP_PUSH_I(b)
# endif
#
# if !CONFIG_RIPPLE_STD
#    define DETAIL_RPP_PUSH_I(x) x
# endif
#
# define RPP_PUSH_ID() RPP_PUSH
#
# endif

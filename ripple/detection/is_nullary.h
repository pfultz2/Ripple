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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_NULLARY_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_NULLARY_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/facilities/split.h>
#
# /* RPP_IS_NULLARY */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_NULLARY(...) RPP_SPLIT_SHADOW(0, RPP_CAT_SHADOW(DETAIL_RPP_IS_NULLARY_R_, DETAIL_RPP_IS_NULLARY_C __VA_ARGS__))
# else
#    define RPP_IS_NULLARY(x) RPP_SPLIT_SHADOW(0, RPP_CAT_SHADOW(DETAIL_RPP_IS_NULLARY_R_, DETAIL_RPP_IS_NULLARY_C x))
# endif
#
# define RPP_IS_NULLARY_ID() RPP_IS_NULLARY
#
# define DETAIL_RPP_IS_NULLARY_C() 1
# define DETAIL_RPP_IS_NULLARY_R_1 1, ~
# define DETAIL_RPP_IS_NULLARY_R_DETAIL_RPP_IS_NULLARY_C 0, ~
#
# endif

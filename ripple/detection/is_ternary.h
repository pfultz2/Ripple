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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_TERNARY_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_TERNARY_H
#
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
#
# /* RPP_IS_TERNARY */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_TERNARY(...) RPP_IS_NULLARY(DETAIL_RPP_IS_TERNARY_C __VA_ARGS__)
# else
#    define RPP_IS_TERNARY(x) RPP_IS_NULLARY(DETAIL_RPP_IS_TERNARY_C x)
# endif
#
# define RPP_IS_TERNARY_ID() RPP_IS_TERNARY
#
# define DETAIL_RPP_IS_TERNARY_C(a, b, c) ()
#
# endif

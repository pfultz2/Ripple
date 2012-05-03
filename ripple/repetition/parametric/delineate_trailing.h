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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_TRAILING_H
#
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/parametric/delineate.h>
#
# /* RPP_DELINEATE_TRAILING_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING_PARAMETRIC(count, sep, ...) RPP_DELINEATE_TRAILING_PARAMETRIC_S(RPP_STATE(), count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_TRAILING_PARAMETRIC(count, sep, macro, data) RPP_DELINEATE_TRAILING_PARAMETRIC_S(RPP_STATE(), count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_TRAILING_PARAMETRIC_ID() RPP_DELINEATE_TRAILING_PARAMETRIC
#
# /* RPP_DELINEATE_TRAILING_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING_PARAMETRIC_S(s, count, sep, ...) RPP_WHEN(count)(sep()) RPP_DELINEATE_PARAMETRIC_S(s, count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_TRAILING_PARAMETRIC_S(s, count, sep, macro, data) RPP_WHEN(count)(sep()) RPP_DELINEATE_PARAMETRIC_S(s, count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_TRAILING_PARAMETRIC_S_ID() RPP_DELINEATE_TRAILING_PARAMETRIC_S
#
# endif

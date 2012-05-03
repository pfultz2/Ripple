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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_H
#
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/delineate.h>
#
# /* RPP_DELINEATE_TRAILING */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING(count, sep, ...) RPP_DELINEATE_TRAILING_S(RPP_STATE(), count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_TRAILING(count, sep, macro, data) RPP_DELINEATE_TRAILING_S(RPP_STATE(), count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_TRAILING_ID() RPP_DELINEATE_TRAILING
#
# /* RPP_DELINEATE_TRAILING_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING_S(s, count, sep, ...) RPP_WHEN(count)(sep()) RPP_DELINEATE_S(s, count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_TRAILING_S(s, count, sep, macro, data) RPP_WHEN(count)(sep()) RPP_DELINEATE_S(s, count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_TRAILING_S_ID() RPP_DELINEATE_TRAILING_S
#
# endif

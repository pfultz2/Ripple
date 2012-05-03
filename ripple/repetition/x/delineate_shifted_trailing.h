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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_DELINEATE_SHIFTED_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_DELINEATE_SHIFTED_TRAILING_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/x/delineate_shifted.h>
#
# /* RPP_DELINEATE_SHIFTED_TRAILING_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED_TRAILING_X(size, count, sep, ...) RPP_DELINEATE_SHIFTED_TRAILING_X_S(RPP_STATE(), size, count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_SHIFTED_TRAILING_X(size, count, sep, macro, data) RPP_DELINEATE_SHIFTED_TRAILING_X_S(RPP_STATE(), size, count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_SHIFTED_TRAILING_X_ID() RPP_DELINEATE_SHIFTED_TRAILING_X
#
# /* RPP_DELINEATE_SHIFTED_TRAILING_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED_TRAILING_X_S(s, size, count, sep, ...) RPP_WHEN(RPP_DEC(count))(sep()) RPP_DELINEATE_SHIFTED_X_S(s, size, count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_SHIFTED_TRAILING_X_S(s, size, count, sep, macro, data) RPP_WHEN(RPP_DEC(count))(sep()) RPP_DELINEATE_SHIFTED_X_S(s, size, count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_SHIFTED_TRAILING_X_S_ID() RPP_DELINEATE_SHIFTED_TRAILING_X_S
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_REPEAT_SHIFTED_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_REPEAT_SHIFTED_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/x/delineate_shifted.h>
#
# /* RPP_REPEAT_SHIFTED_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_SHIFTED_X(size, count, ...) RPP_REPEAT_SHIFTED_X_S(RPP_STATE(), size, count, __VA_ARGS__)
# else
#    define RPP_REPEAT_SHIFTED_X(size, count, macro, data) RPP_REPEAT_SHIFTED_X_S(RPP_STATE(), size, count, macro, data)
# endif
#
# define RPP_REPEAT_SHIFTED_X_ID() RPP_REPEAT_SHIFTED_X
#
# /* RPP_REPEAT_SHIFTED_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_SHIFTED_X_S(s, size, count, ...) RPP_DELINEATE_SHIFTED_X_S(s, size, count, RPP_EMPTY, __VA_ARGS__)
# else
#    define RPP_REPEAT_SHIFTED_X_S(s, size, count, macro, data) RPP_DELINEATE_SHIFTED_X_S(s, size, count, RPP_EMPTY, macro, data)
# endif
#
# define RPP_REPEAT_SHIFTED_X_S_ID() RPP_REPEAT_SHIFTED_X_S
#
# endif

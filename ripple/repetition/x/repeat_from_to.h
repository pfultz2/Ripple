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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_REPEAT_FROM_TO_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_REPEAT_FROM_TO_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/x/delineate_from_to.h>
#
# /* RPP_REPEAT_FROM_TO_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_FROM_TO_X(size, from, to, ...) RPP_REPEAT_FROM_TO_X_S(RPP_STATE(), size, from, to, __VA_ARGS__)
# else
#    define RPP_REPEAT_FROM_TO_X(size, from, to, macro, data) RPP_REPEAT_FROM_TO_X_S(RPP_STATE(), size, from, to, macro, data)
# endif
#
# define RPP_REPEAT_FROM_TO_X_ID() RPP_REPEAT_FROM_TO_X
#
# /* RPP_REPEAT_FROM_TO_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_FROM_TO_X_S(s, size, from, to, ...) RPP_DELINEATE_FROM_TO_X_S(s, size, from, to, RPP_EMPTY, __VA_ARGS__)
# else
#    define RPP_REPEAT_FROM_TO_X_S(s, size, from, to, macro, data) RPP_DELINEATE_FROM_TO_X_S(s, size, from, to, RPP_EMPTY, macro, data)
# endif
#
# define RPP_REPEAT_FROM_TO_X_S_ID() RPP_REPEAT_FROM_TO_X_S
#
# endif

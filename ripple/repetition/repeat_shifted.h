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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_REPEAT_SHIFTED_H
# define RIPPLE_PREPROCESSOR_REPETITION_REPEAT_SHIFTED_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/repetition/delineate_shifted.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_REPEAT_SHIFTED */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_SHIFTED(count, ...) RPP_REPEAT_SHIFTED_S(RPP_STATE(), count, __VA_ARGS__)
# else
#    define RPP_REPEAT_SHIFTED(count, macro, data) RPP_REPEAT_SHIFTED_S(RPP_STATE(), count, macro, data)
# endif
#
# define RPP_REPEAT_SHIFTED_ID() RPP_REPEAT_SHIFTED
#
# /* RPP_REPEAT_SHIFTED_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPEAT_SHIFTED_S(s, count, ...) RPP_DELINEATE_SHIFTED_S(s, count, RPP_EMPTY, __VA_ARGS__)
# else
#    define RPP_REPEAT_SHIFTED_S(s, count, macro, data) RPP_DELINEATE_SHIFTED_S(s, count, RPP_EMPTY, macro, data)
# endif
#
# define RPP_REPEAT_SHIFTED_S_ID() RPP_REPEAT_SHIFTED_S
#
# endif

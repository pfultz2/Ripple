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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FOLD_LEFT_H
# define RIPPLE_PREPROCESSOR_SEQ_FOLD_LEFT_H
#
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/fold_right.h>
# include <ripple/seq/reverse.h>
#
# /* RPP_SEQ_FOLD_LEFT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_LEFT(op, seq, ...) RPP_SEQ_FOLD_LEFT_S(RPP_STATE(), op, seq, __VA_ARGS__)
# else
#    define RPP_SEQ_FOLD_LEFT(op, seq, state) RPP_SEQ_FOLD_LEFT_S(RPP_STATE(), op, seq, state)
# endif
#
# define RPP_SEQ_FOLD_LEFT_ID() RPP_SEQ_FOLD_LEFT
#
# /* RPP_SEQ_FOLD_LEFT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_LEFT_S(s, op, seq, ...) RPP_SEQ_FOLD_RIGHT_S(s, op, RPP_SEQ_REVERSE(seq), __VA_ARGS__)
# else
#    define RPP_SEQ_FOLD_LEFT_S(s, op, seq, state) RPP_SEQ_FOLD_RIGHT_S(s, op, RPP_SEQ_REVERSE(seq), state)
# endif
#
# define RPP_SEQ_FOLD_LEFT_S_ID() RPP_SEQ_FOLD_LEFT_S
#
# endif

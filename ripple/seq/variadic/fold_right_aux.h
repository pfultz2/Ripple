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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_AUX_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_AUX_H
#
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/fold_right_aux.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX(op, seq, data, ...) RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S(RPP_STATE(), op, seq, data, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_ID() RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX
# endif
#
# /* RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, ...) RPP_SEQ_FOLD_RIGHT_AUX_S(s, op, RPP_SEQ_ZIP(seq), data, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S_ID() RPP_VARIADIC_SEQ_FOLD_RIGHT_AUX_S
# endif
#
# endif

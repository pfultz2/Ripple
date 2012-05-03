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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOLD_RIGHT_H
#
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/fold_right.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_FOLD_RIGHT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT(op, seq, ...) RPP_VARIADIC_SEQ_FOLD_RIGHT_S(RPP_STATE(), op, seq, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_ID() RPP_VARIADIC_SEQ_FOLD_RIGHT
# endif
#
# /* RPP_VARIADIC_SEQ_FOLD_RIGHT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_S(s, op, seq, ...) RPP_SEQ_FOLD_RIGHT_S(s, op, RPP_SEQ_ZIP(seq), __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOLD_RIGHT_S_ID() RPP_VARIADIC_SEQ_FOLD_RIGHT_S
# endif
#
# endif

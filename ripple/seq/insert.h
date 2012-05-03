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
# ifndef RIPPLE_PREPROCESSOR_SEQ_INSERT_H
# define RIPPLE_PREPROCESSOR_SEQ_INSERT_H
#
# include <ripple/config.h>
# include <ripple/seq/drop.h>
# include <ripple/seq/take.h>
#
# /* RPP_SEQ_INSERT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_INSERT(i, seq, ...) RPP_SEQ_TAKE(i, seq)(__VA_ARGS__) RPP_SEQ_DROP(i, seq)
# else
#    define RPP_SEQ_INSERT(i, seq, x) RPP_SEQ_TAKE(i, seq)(x) RPP_SEQ_DROP(i, seq)
# endif
#
# define RPP_SEQ_INSERT_ID() RPP_SEQ_INSERT
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_ELEM_H
# define RIPPLE_PREPROCESSOR_SEQ_ELEM_H
#
# include <ripple/config.h>
# include <ripple/seq/core.h>
# include <ripple/seq/drop.h>
#
# /* RPP_SEQ_ELEM */
#
# define RPP_SEQ_ELEM(i, seq) RPP_SEQ_HEAD(RPP_SEQ_DROP(i, seq))
# define RPP_SEQ_ELEM_ID() RPP_SEQ_ELEM
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_TO_TUPLE_H
# define RIPPLE_PREPROCESSOR_SEQ_TO_TUPLE_H
#
# include <ripple/config.h>
# include <ripple/seq/enumerate.h>
#
# /* RPP_SEQ_TO_TUPLE */
#
# define RPP_SEQ_TO_TUPLE(seq) (RPP_SEQ_ENUMERATE(seq))
# define RPP_SEQ_TO_TUPLE_ID() RPP_SEQ_TO_TUPLE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

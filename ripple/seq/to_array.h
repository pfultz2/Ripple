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
# ifndef RIPPLE_PREPROCESSOR_SEQ_TO_ARRAY_H
# define RIPPLE_PREPROCESSOR_SEQ_TO_ARRAY_H
#
# include <ripple/config.h>
# include <ripple/seq/size.h>
# include <ripple/seq/to_tuple.h>
#
# /* RPP_SEQ_TO_ARRAY */
#
# define RPP_SEQ_TO_ARRAY(seq) (RPP_SEQ_SIZE(seq), RPP_SEQ_TO_TUPLE(seq))
# define RPP_SEQ_TO_ARRAY_ID() RPP_SEQ_TO_ARRAY
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

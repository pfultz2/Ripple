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
# ifndef RIPPLE_PREPROCESSOR_SEQ_RANGE_H
# define RIPPLE_PREPROCESSOR_SEQ_RANGE_H
#
# include <ripple/config.h>
# include <ripple/seq/drop.h>
# include <ripple/seq/take.h>
#
# /* RPP_SEQ_RANGE */
#
# define RPP_SEQ_RANGE(i, len, seq) \
    RPP_SEQ_TAKE(len, RPP_SEQ_DROP(i, seq)) \
    /**/
# define RPP_SEQ_RANGE_ID() RPP_SEQ_RANGE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_DROP_H
# define RIPPLE_PREPROCESSOR_SEQ_DROP_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/seq/take.h>
#
# /* RPP_SEQ_DROP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_DROP(n, seq) \
        RPP_SPLIT(1, RPP_PRIMITIVE_CAT(DETAIL_RPP_SEQ_TAKE_, n) seq) \
        /**/
# else
#    define RPP_SEQ_DROP(n, seq) \
        RPP_SPLIT(1, ~ RPP_PRIMITIVE_CAT(DETAIL_RPP_SEQ_TAKE_, n) seq RPP_EMPTY)() \
        /**/
# endif
#
# define RPP_SEQ_DROP_ID() RPP_SEQ_DROP
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_TO_STRING_H
# define RIPPLE_PREPROCESSOR_SEQ_TO_STRING_H
#
# include <ripple/config.h>
# include <ripple/facilities/expand.h>
# include <ripple/seq/binary_transform.h>
#
# /* RPP_SEQ_TO_STRING */
#
# define RPP_SEQ_TO_STRING(seq) \
    RPP_EXPAND(DETAIL_RPP_SEQ_TO_STRING_I RPP_SEQ_BINARY_TRANSFORM(seq, ~)) \
    /**/
# define RPP_SEQ_TO_STRING_ID() RPP_SEQ_TO_STRING
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SEQ_TO_STRING_INDIRECT() DETAIL_RPP_SEQ_TO_STRING_I
# define DETAIL_RPP_SEQ_TO_STRING_I(m, x) m(1)(x DETAIL_RPP_SEQ_TO_STRING_INDIRECT)
#
# endif

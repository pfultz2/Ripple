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
# ifndef RIPPLE_PREPROCESSOR_SEQ_ENUMERATE_H
# define RIPPLE_PREPROCESSOR_SEQ_ENUMERATE_H
#
# include <ripple/config.h>
# include <ripple/facilities/expand.h>
# include <ripple/punctuation/comma.h>
# include <ripple/seq/binary_transform.h>
#
# /* RPP_SEQ_ENUMERATE */
#
# define RPP_SEQ_ENUMERATE(seq) \
    RPP_EXPAND(DETAIL_RPP_SEQ_ENUMERATE_A RPP_SEQ_BINARY_TRANSFORM(seq, ~)) \
    /**/
# define RPP_SEQ_ENUMERATE_ID() RPP_SEQ_ENUMERATE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SEQ_ENUMERATE_B_ID() DETAIL_RPP_SEQ_ENUMERATE_B
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_ENUMERATE_A(m, ...) m(?)(__VA_ARGS__ DETAIL_RPP_SEQ_ENUMERATE_B_ID)
#    define DETAIL_RPP_SEQ_ENUMERATE_B(m, ...) m(?)(, __VA_ARGS__ DETAIL_RPP_SEQ_ENUMERATE_B_ID)
# else
#    define DETAIL_RPP_SEQ_ENUMERATE_A(m, x) m(1)(x DETAIL_RPP_SEQ_ENUMERATE_B_ID)
#    define DETAIL_RPP_SEQ_ENUMERATE_B(m, x) m(1)(RPP_COMMA() x DETAIL_RPP_SEQ_ENUMERATE_B_ID)
# endif
#
# endif

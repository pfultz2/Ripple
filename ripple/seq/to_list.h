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
# ifndef RIPPLE_PREPROCESSOR_SEQ_TO_LIST_H
# define RIPPLE_PREPROCESSOR_SEQ_TO_LIST_H
#
# include <ripple/config.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/detail/close.h>
#
# /* RPP_SEQ_TO_LIST */
#
# define RPP_SEQ_TO_LIST(seq) DETAIL_RPP_SEQ_TO_LIST_I(RPP_SEQ_BINARY_TRANSFORM(seq, ~))
# define RPP_SEQ_TO_LIST_ID() RPP_SEQ_TO_LIST
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SEQ_TO_LIST_I(bin) DETAIL_RPP_SEQ_TO_LIST_II bin ... RPP_SEQ_CLOSE(bin)
# define DETAIL_RPP_SEQ_TO_LIST_INDIRECT() DETAIL_RPP_SEQ_TO_LIST_II
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_TO_LIST_II(m, ...) m(?)(RPP_LPAREN() __VA_ARGS__, DETAIL_RPP_SEQ_TO_LIST_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_TO_LIST_II(m, x) m(1)(RPP_LPAREN() x RPP_COMMA() DETAIL_RPP_SEQ_TO_LIST_INDIRECT)
# endif
#
# endif

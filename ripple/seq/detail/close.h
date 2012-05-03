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
# ifndef RIPPLE_PREPROCESSOR_SEQ_DETAIL_CLOSE_H
# define RIPPLE_PREPROCESSOR_SEQ_DETAIL_CLOSE_H
#
# include <ripple/config.h>
# include <ripple/punctuation/paren.h>
#
# /* RPP_SEQ_CLOSE */
#
# define RPP_SEQ_CLOSE(bin) DETAIL_RPP_SEQ_CLOSE_I bin
#
# define DETAIL_RPP_SEQ_CLOSE_I_ID() DETAIL_RPP_SEQ_CLOSE_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_CLOSE_I(m, ...) m(?)(RPP_RPAREN() DETAIL_RPP_SEQ_CLOSE_I_ID)
# else
#    define DETAIL_RPP_SEQ_CLOSE_I(m, x) m(1)(RPP_RPAREN() DETAIL_RPP_SEQ_CLOSE_I_ID)
# endif
#
# endif

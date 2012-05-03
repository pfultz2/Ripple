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
# ifndef RIPPLE_PREPROCESSOR_SEQ_CONCAT_H
# define RIPPLE_PREPROCESSOR_SEQ_CONCAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/facilities/expand.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/core.h>
# include <ripple/seq/detail/close.h>
#
# /* RPP_SEQ_CONCAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_CONCAT(seq) RPP_EXPAND(DETAIL_RPP_SEQ_CONCAT_I(RPP_SEQ_BINARY_TRANSFORM(seq,)))
# else
#    define RPP_SEQ_CONCAT(seq) \
        RPP_IIF(RPP_SEQ_IS_CONS(RPP_SEQ_TAIL(seq)))( \
            RPP_EXPAND(DETAIL_RPP_SEQ_CONCAT_I( \
                RPP_SEQ_BINARY_TRANSFORM(RPP_SEQ_TAIL(seq), ~), RPP_SEQ_HEAD(seq) \
            )), \
            RPP_SEQ_HEAD(seq) \
        ) \
        /**/
# endif
#
# define RPP_SEQ_CONCAT_ID() RPP_SEQ_CONCAT
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_CONCAT_I(bin) DETAIL_RPP_SEQ_CONCAT_II bin RPP_SEQ_CLOSE(bin)
#    define DETAIL_RPP_SEQ_CONCAT_INDIRECT() DETAIL_RPP_SEQ_CONCAT_II
#    define DETAIL_RPP_SEQ_CONCAT_II(m, ...) m(?)(RPP_VARIADIC_CAT RPP_DEFER(RPP_LPAREN)() __VA_ARGS__, DETAIL_RPP_SEQ_CONCAT_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_CONCAT_I(bin, init) DETAIL_RPP_SEQ_CONCAT_A bin init DETAIL_RPP_SEQ_CONCAT_B bin
#    define DETAIL_RPP_SEQ_CONCAT_A_INDIRECT() DETAIL_RPP_SEQ_CONCAT_A
#    define DETAIL_RPP_SEQ_CONCAT_A(m, x) m(1)(RPP_CAT RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_SEQ_CONCAT_A_INDIRECT)
#    define DETAIL_RPP_SEQ_CONCAT_B_INDIRECT() DETAIL_RPP_SEQ_CONCAT_B
#    define DETAIL_RPP_SEQ_CONCAT_B(m, x) m(1)(RPP_COMMA() x RPP_RPAREN() DETAIL_RPP_SEQ_CONCAT_B_INDIRECT)
# endif
#
# endif

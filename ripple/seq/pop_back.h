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
# ifndef RIPPLE_PREPROCESSOR_SEQ_POP_BACK_H
# define RIPPLE_PREPROCESSOR_SEQ_POP_BACK_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/expand.h>
# include <ripple/punctuation/paren.h>
# include <ripple/seq/binary_transform.h>
#
# /* RPP_SEQ_POP_BACK */
#
# define RPP_SEQ_POP_BACK(seq) \
    RPP_EXPAND( \
        DETAIL_RPP_SEQ_POP_BACK_C RPP_EXPAND( \
            DETAIL_RPP_SEQ_POP_BACK_A RPP_SEQ_BINARY_TRANSFORM(seq, ~) \
        ) \
    ) \
    /**/
# define RPP_SEQ_POP_BACK_ID() RPP_SEQ_POP_BACK
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_POP_BACK_A(m, ...) ((__VA_ARGS__) DETAIL_RPP_SEQ_POP_BACK_INDIRECT_1ST
#    define DETAIL_RPP_SEQ_POP_BACK_B(m, ...) \
        , m) m(?)(() RPP_LPAREN() (__VA_ARGS__) DETAIL_RPP_SEQ_POP_BACK_INDIRECT_1ST) \
        /**/
# else
#    define DETAIL_RPP_SEQ_POP_BACK_A(m, x) ((x) DETAIL_RPP_SEQ_POP_BACK_INDIRECT_1ST
#    define DETAIL_RPP_SEQ_POP_BACK_B(m, x) \
        , m) m(1)(() RPP_LPAREN() (x) DETAIL_RPP_SEQ_POP_BACK_INDIRECT_1ST) \
        /**/
# endif
#
# define DETAIL_RPP_SEQ_POP_BACK_C(e, m) m(1)(e DETAIL_RPP_SEQ_POP_BACK_INDIRECT_2ND)
#
# define DETAIL_RPP_SEQ_POP_BACK_INDIRECT_1ST() DETAIL_RPP_SEQ_POP_BACK_B
# define DETAIL_RPP_SEQ_POP_BACK_INDIRECT_2ND() DETAIL_RPP_SEQ_POP_BACK_C
#
# endif

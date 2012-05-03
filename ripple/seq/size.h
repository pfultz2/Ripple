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
# ifndef RIPPLE_PREPROCESSOR_SEQ_SIZE_H
# define RIPPLE_PREPROCESSOR_SEQ_SIZE_H
#
# include <ripple/arbitrary/demote.h>
# include <ripple/arbitrary/greater.h>
# include <ripple/arbitrary/promote.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/expand.h>
# include <ripple/limits.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/core.h>
# include <ripple/seq/detail/close.h>
#
# /* RPP_SEQ_SIZE */
#
# define RPP_SEQ_SIZE(seq) RPP_EXPAND(DETAIL_RPP_SEQ_SIZE_I(RPP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define RPP_SEQ_SIZE_ID() RPP_SEQ_SIZE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SEQ_SIZE_I(bin) DETAIL_RPP_SEQ_SIZE_II bin 0 RPP_SEQ_CLOSE(bin)
# define DETAIL_RPP_SEQ_SIZE_INDIRECT() DETAIL_RPP_SEQ_SIZE_II
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_SIZE_II(m, ...) m(?)(RPP_INC RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_SEQ_SIZE_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_SIZE_II(m, x) m(1)(RPP_INC RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_SEQ_SIZE_INDIRECT)
# endif
#
# /* RPP_SEQ_SIZE_ALT */
#
# define RPP_SEQ_SIZE_ALT(seq) RPP_SEQ_SIZE_ALT_BYPASS(RPP_LIMIT_EXPR, seq)
# define RPP_SEQ_SIZE_ALT_ID() RPP_SEQ_SIZE_ALT
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_SEQ_SIZE_ALT_BYPASS */
#
# define RPP_SEQ_SIZE_ALT_BYPASS(s, seq) \
    DETAIL_RPP_SEQ_SIZE_ALT_II( \
        RPP_EXPR_S(s)(RPP_EXPR_S(s)( \
            RPP_DEFER(DETAIL_RPP_SEQ_SIZE_ALT_I)( \
                RPP_DEFER(RPP_OBSTRUCT)(), RPP_PREV(RPP_PREV(s)), RPP_CAT(DETAIL_RPP_SEQ_SIZE_ALT_0 seq, 0) RPP_EMPTY \
            ) \
        )) \
    ) \
    /**/
# define RPP_SEQ_SIZE_ALT_BYPASS_ID() RPP_SEQ_SIZE_ALT_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SEQ_SIZE_ALT_INDIRECT() DETAIL_RPP_SEQ_SIZE_ALT_I
# define DETAIL_RPP_SEQ_SIZE_ALT_I(_, s, seq, r) \
    RPP_IIF _(RPP_SEQ_IS_CONS(seq()~))( \
        RPP_EXPR_S _(s)(DETAIL_RPP_SEQ_SIZE_ALT_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_CAT(DETAIL_RPP_SEQ_SIZE_ALT_0 seq(), 0) r \
        )), \
        r() \
    ) \
    /**/
# define DETAIL_RPP_SEQ_SIZE_ALT_II(x) \
    RPP_IIF(RPP_ARBITRARY_GREATER(x, RPP_ARBITRARY_PROMOTE(RPP_LIMIT_MAG)))( \
        RPP_LIMIT_MAG, RPP_ARBITRARY_DEMOTE(x) \
    ) \
    /**/
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_SIZE_ALT_0(...) DETAIL_RPP_SEQ_SIZE_ALT_1
#    define DETAIL_RPP_SEQ_SIZE_ALT_1(...) DETAIL_RPP_SEQ_SIZE_ALT_2
#    define DETAIL_RPP_SEQ_SIZE_ALT_2(...) DETAIL_RPP_SEQ_SIZE_ALT_3
#    define DETAIL_RPP_SEQ_SIZE_ALT_3(...) DETAIL_RPP_SEQ_SIZE_ALT_4
#    define DETAIL_RPP_SEQ_SIZE_ALT_4(...) DETAIL_RPP_SEQ_SIZE_ALT_5
#    define DETAIL_RPP_SEQ_SIZE_ALT_5(...) DETAIL_RPP_SEQ_SIZE_ALT_6
#    define DETAIL_RPP_SEQ_SIZE_ALT_6(...) DETAIL_RPP_SEQ_SIZE_ALT_7
#    define DETAIL_RPP_SEQ_SIZE_ALT_7(...) DETAIL_RPP_SEQ_SIZE_ALT_8
#    define DETAIL_RPP_SEQ_SIZE_ALT_8(...) DETAIL_RPP_SEQ_SIZE_ALT_9
#    define DETAIL_RPP_SEQ_SIZE_ALT_9(...) () DETAIL_RPP_SEQ_SIZE_ALT_0
# else
#    define DETAIL_RPP_SEQ_SIZE_ALT_0(x) DETAIL_RPP_SEQ_SIZE_ALT_1
#    define DETAIL_RPP_SEQ_SIZE_ALT_1(x) DETAIL_RPP_SEQ_SIZE_ALT_2
#    define DETAIL_RPP_SEQ_SIZE_ALT_2(x) DETAIL_RPP_SEQ_SIZE_ALT_3
#    define DETAIL_RPP_SEQ_SIZE_ALT_3(x) DETAIL_RPP_SEQ_SIZE_ALT_4
#    define DETAIL_RPP_SEQ_SIZE_ALT_4(x) DETAIL_RPP_SEQ_SIZE_ALT_5
#    define DETAIL_RPP_SEQ_SIZE_ALT_5(x) DETAIL_RPP_SEQ_SIZE_ALT_6
#    define DETAIL_RPP_SEQ_SIZE_ALT_6(x) DETAIL_RPP_SEQ_SIZE_ALT_7
#    define DETAIL_RPP_SEQ_SIZE_ALT_7(x) DETAIL_RPP_SEQ_SIZE_ALT_8
#    define DETAIL_RPP_SEQ_SIZE_ALT_8(x) DETAIL_RPP_SEQ_SIZE_ALT_9
#    define DETAIL_RPP_SEQ_SIZE_ALT_9(x) (~) DETAIL_RPP_SEQ_SIZE_ALT_0
# endif
#
# define DETAIL_RPP_SEQ_SIZE_ALT_00 RPP_EMPTY, (0)
# define DETAIL_RPP_SEQ_SIZE_ALT_10 RPP_EMPTY, (1)
# define DETAIL_RPP_SEQ_SIZE_ALT_20 RPP_EMPTY, (2)
# define DETAIL_RPP_SEQ_SIZE_ALT_30 RPP_EMPTY, (3)
# define DETAIL_RPP_SEQ_SIZE_ALT_40 RPP_EMPTY, (4)
# define DETAIL_RPP_SEQ_SIZE_ALT_50 RPP_EMPTY, (5)
# define DETAIL_RPP_SEQ_SIZE_ALT_60 RPP_EMPTY, (6)
# define DETAIL_RPP_SEQ_SIZE_ALT_70 RPP_EMPTY, (7)
# define DETAIL_RPP_SEQ_SIZE_ALT_80 RPP_EMPTY, (8)
# define DETAIL_RPP_SEQ_SIZE_ALT_90 RPP_EMPTY, (9)
#
# endif

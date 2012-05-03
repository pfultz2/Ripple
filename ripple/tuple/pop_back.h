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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_POP_BACK_H
# define RIPPLE_PREPROCESSOR_TUPLE_POP_BACK_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_POP_BACK */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_POP_BACK(tuple) RPP_TUPLE_POP_BACK_BYPASS(RPP_LIMIT_EXPR, tuple)
#    define RPP_TUPLE_POP_BACK_ID() RPP_TUPLE_POP_BACK
# endif
#
# /* RPP_TUPLE_POP_BACK_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_POP_BACK_BYPASS(s, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_POP_BACK_1( \
            RPP_PREV(s), tuple \
        )) \
        /**/
#    define RPP_TUPLE_POP_BACK_BYPASS_ID() RPP_TUPLE_POP_BACK_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_POP_BACK_INDIRECT(n) DETAIL_RPP_TUPLE_POP_BACK_ ## n
#    define DETAIL_RPP_TUPLE_POP_BACK_1(s, tuple) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(11, tuple))( \
            DETAIL_RPP_TUPLE_POP_BACK_1_I, DETAIL_RPP_TUPLE_POP_BACK_2 \
        )(s, tuple) \
        /**/
#    define DETAIL_RPP_TUPLE_POP_BACK_1_I(s, tuple) \
        DETAIL_RPP_TUPLE_POP_BACK_1_II(s, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple)) \
        /**/
#    define DETAIL_RPP_TUPLE_POP_BACK_1_II(...) DETAIL_RPP_TUPLE_POP_BACK_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_POP_BACK_1_III(_, s, a, b, c, d, e, f, g, h, i, j, tuple) \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_POP_BACK_INDIRECT _(1)( \
                RPP_PREV(s), tuple \
            )), \
            j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define DETAIL_RPP_TUPLE_POP_BACK_2(s, tuple) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(2, tuple))( \
            DETAIL_RPP_TUPLE_POP_BACK_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, tuple) \
        /**/
#    define DETAIL_RPP_TUPLE_POP_BACK_2_I(_, s, tuple) \
        RPP_TUPLE_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_POP_BACK_INDIRECT _(2)( \
                RPP_PREV(s), RPP_TUPLE_TAIL(tuple) \
            )), \
            RPP_TUPLE_HEAD(tuple) \
        ) \
        /**/
# endif
#
# endif

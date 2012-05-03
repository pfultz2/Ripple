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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_INSERT_H
# define RIPPLE_PREPROCESSOR_TUPLE_INSERT_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/greater.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_INSERT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_INSERT(i, tuple, x) RPP_TUPLE_INSERT_BYPASS(RPP_LIMIT_EXPR, i, tuple, x)
#    define RPP_TUPLE_INSERT_ID() RPP_TUPLE_INSERT
# endif
#
# /* RPP_TUPLE_INSERT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_INSERT_BYPASS(s, i, tuple, x) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_INSERT_1( \
            RPP_PREV(s), i, tuple, x \
        )) \
        /**/
#    define RPP_TUPLE_INSERT_BYPASS_ID() RPP_TUPLE_INSERT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_INSERT_INDIRECT(n) DETAIL_RPP_TUPLE_INSERT_ ## n
#    define DETAIL_RPP_TUPLE_INSERT_1(s, n, tuple, x) \
        RPP_IIF(RPP_GREATER(n, 9))( \
            DETAIL_RPP_TUPLE_INSERT_1_I, DETAIL_RPP_TUPLE_INSERT_2 \
        )(s, n, tuple, x) \
        /**/
#    define DETAIL_RPP_TUPLE_INSERT_1_I(s, n, tuple, x) \
        DETAIL_RPP_TUPLE_INSERT_1_II( \
            s, \
            RPP_DEC(RPP_DEC(RPP_DEC(RPP_DEC(RPP_DEC( \
                RPP_DEC(RPP_DEC(RPP_DEC(RPP_DEC(RPP_DEC( \
                    n \
                ))))) \
            ))))), \
            RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), x \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_INSERT_1_II(...) DETAIL_RPP_TUPLE_INSERT_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_INSERT_1_III(_, s, n, a, b, c, d, e, f, g, h, i, j, tuple, x) \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_INSERT_INDIRECT _(1)( \
                RPP_PREV(s), n, tuple, x \
            )), \
            j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define DETAIL_RPP_TUPLE_INSERT_2(s, n, tuple, x) \
        RPP_IF(n)( \
            DETAIL_RPP_TUPLE_INSERT_2_I, RPP_TUPLE_CONS(tuple, x) RPP_EAT \
        )(RPP_OBSTRUCT(), s, n, tuple, x) \
        /**/
#    define DETAIL_RPP_TUPLE_INSERT_2_I(_, s, n, tuple, x) \
        RPP_TUPLE_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_INSERT_INDIRECT _(2)( \
                RPP_PREV(s), RPP_DEC(n), RPP_TUPLE_TAIL(tuple), x \
            )), \
            RPP_TUPLE_HEAD(tuple) \
        ) \
        /**/
# endif
#
# endif

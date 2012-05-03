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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_DROP_H
# define RIPPLE_PREPROCESSOR_TUPLE_DROP_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/greater.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/if.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
#
# /* RPP_TUPLE_DROP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_DROP(n, tuple) RPP_TUPLE_DROP_BYPASS(RPP_LIMIT_EXPR, n, tuple)
#    define RPP_TUPLE_DROP_ID() RPP_TUPLE_DROP
# endif
#
# /* RPP_TUPLE_DROP_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_DROP_BYPASS(s, n, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_DROP_0( \
            RPP_OBSTRUCT(), RPP_PREV(s), n, tuple \
        )) \
        /**/
#    define RPP_TUPLE_DROP_BYPASS_ID() RPP_TUPLE_DROP_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_DROP_INDIRECT(n) DETAIL_RPP_TUPLE_DROP_ ## n
#    define DETAIL_RPP_TUPLE_DROP_0(_, s, n, tuple) \
        RPP_IIF _(RPP_GREATER(n, 9))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_DROP_INDIRECT _(0)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), \
                RPP_DEC _(RPP_DEC _(RPP_DEC _(RPP_DEC _(RPP_DEC _( \
                    RPP_DEC _(RPP_DEC _(RPP_DEC _(RPP_DEC _(RPP_DEC _( \
                        n \
                    ))))) \
                ))))), \
                RPP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_DROP_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), n, tuple \
            )) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_DROP_1(_, s, n, tuple) \
        RPP_IF _(n)( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_DROP_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(n), RPP_TUPLE_TAIL _(tuple) \
            )), \
            tuple \
        ) \
        /**/
# endif
#
# endif

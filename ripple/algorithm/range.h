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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_RANGE_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_RANGE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_RANGE */
#
# define RPP_RANGE(i, len, g) RPP_RANGE_BYPASS(RPP_LIMIT_EXPR, i, len, g)
# define RPP_RANGE_ID() RPP_RANGE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RANGE_BYPASS */
#
# define RPP_RANGE_BYPASS(s, i, len, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_RANGE_1(RPP_PREV(s), i, len, g)) \
    /**/
# define RPP_RANGE_BYPASS_ID() RPP_RANGE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_RANGE_INDIRECT(n) DETAIL_RPP_RANGE_ ## n
# define DETAIL_RPP_RANGE_1(s, i, len, g) \
    RPP_IF(i)( \
        DETAIL_RPP_RANGE_1_I, DETAIL_RPP_RANGE_2 \
    )(RPP_OBSTRUCT(), s, i, len, g) \
    /**/
# define DETAIL_RPP_RANGE_1_I(_, s, i, len, g) \
    RPP_EXPR_S(s) _(DETAIL_RPP_RANGE_INDIRECT _(1)( \
        RPP_PREV(s), RPP_DEC(i), len, RPP_TAIL(g) \
    )) \
    /**/
# define DETAIL_RPP_RANGE_2(_, s, i, len, g) \
    RPP_IF _(len)( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_RANGE_INDIRECT _(2)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), i, RPP_DEC(len), RPP_TAIL _(g) \
            )), \
            RPP_HEAD _(g) \
        ), \
        RPP_NIL _(RPP_TYPEOF _(g)) \
    ) \
    /**/
#
# endif

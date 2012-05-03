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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_BUBBLESORT_H
# define RIPPLE_PREPROCESSOR_SANDBOX_BUBBLESORT_H
#
# include <ripple/algorithm/size.h>
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_BUBBLESORT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_BUBBLESORT(pred, ...) RPP_BUBBLESORT_S(RPP_STATE(), pred, __VA_ARGS__)
# else
#    define RPP_BUBBLESORT(pred, g, data) RPP_BUBBLESORT_S(RPP_STATE(), pred, g, data)
# endif
#
# define RPP_BUBBLESORT_ID() RPP_BUBBLESORT
#
# /* RPP_BUBBLESORT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_BUBBLESORT_S(s, pred, ...) \
        DETAIL_RPP_BUBBLESORT_U(s, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_BUBBLESORT_S(s, pred, g, data) DETAIL_RPP_BUBBLESORT_U(s, pred, g, (data))
# endif
#
# define RPP_BUBBLESORT_S_ID() RPP_BUBBLESORT_S
#
# define DETAIL_RPP_BUBBLESORT_U(s, pred, g, pd) \
    DETAIL_RPP_BUBBLESORT_1( \
        RPP_OBSTRUCT(), RPP_NEXT(s), pred, RPP_CALL(pred), \
        RPP_TYPEOF(g), g, RPP_SIZE(g), pd \
    ) \
    /**/
# define DETAIL_RPP_BUBBLESORT_INDIRECT(n) DETAIL_RPP_BUBBLESORT_ ## n
# define DETAIL_RPP_BUBBLESORT_1(_, s, pred, _p, type, g, size, pd) \
    RPP_IF _(size)( \
        RPP_EXPR_S _(s)(DETAIL_RPP_BUBBLESORT_INDIRECT _(1)( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), pred, _p, type, \
            RPP_EXPR_S _(s)(DETAIL_RPP_BUBBLESORT_2 _( \
                RPP_NEXT(s), pred, _p, type, g, RPP_DEC(size), pd \
            )), \
            RPP_DEC(size), pd \
        )), \
        g \
    ) \
    /**/
# define DETAIL_RPP_BUBBLESORT_2(s, pred, _p, type, g, size, pd) \
    RPP_IF(size)( \
        DETAIL_RPP_BUBBLESORT_3, g RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), s, pred, _p, type, (RPP_HEAD(g)), RPP_TAIL(g), RPP_DEC(size), pd) \
    /**/
# define DETAIL_RPP_BUBBLESORT_3(_, s, pred, _p, type, first, rest, size, pd) \
    RPP_IIF _(_p()(s, pred, RPP_ITEM(type, RPP_REM first) RPP_COMMA() RPP_ITEM(type, RPP_HEAD(rest)) RPP_EXPOSE(pd)))( \
        RPP_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_BUBBLESORT_INDIRECT _(2)( \
                RPP_NEXT(s), pred, _p, type, rest, size, pd \
            )), \
            RPP_REM first \
        ), \
        RPP_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_BUBBLESORT_INDIRECT _(2)( \
                RPP_NEXT(s), pred, _p, type, RPP_CONS _(RPP_TAIL _(rest), RPP_REM first), size, pd \
            )), \
            RPP_HEAD _(rest) \
        ) \
    ) \
    /**/
#
# endif

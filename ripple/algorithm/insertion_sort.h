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
# ifndef RIPPLE_PREPROCESSOR_INSERTION_SORT_H
# define RIPPLE_PREPROCESSOR_INSERTION_SORT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_INSERTION_SORT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSERTION_SORT(pred, ...) RPP_INSERTION_SORT_S(RPP_STATE(), pred, __VA_ARGS__)
# else
#    define RPP_INSERTION_SORT(pred, g, data) RPP_INSERTION_SORT_S(RPP_STATE(), pred, g, (data))
# endif
#
# define RPP_INSERTION_SORT_ID() RPP_INSERTION_SORT
#
# /* RPP_INSERTION_SORT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSERTION_SORT_S(s, pred, ...) \
        DETAIL_RPP_INSERTION_SORT_U(s, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_INSERTION_SORT_S(s, pred, g, data) DETAIL_RPP_INSERTION_SORT_U(s, pred, g, data)
# endif
#
# define RPP_INSERTION_SORT_S_ID() RPP_INSERTION_SORT_S
#
# define DETAIL_RPP_INSERTION_SORT_U(s, pred, g, pd) \
    DETAIL_RPP_INSERTION_SORT_1( \
        RPP_OBSTRUCT(), RPP_NEXT(s), pred, RPP_CALL(pred), \
        RPP_NIL(RPP_TYPEOF(g)), RPP_TYPEOF(g), g, pd \
    ) \
    /**/
# define DETAIL_RPP_INSERTION_SORT_INDIRECT(n) DETAIL_RPP_INSERTION_SORT_ ## n
# define DETAIL_RPP_INSERTION_SORT_1(_, s, pred, _p, sorted, type, g, pd) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_EXPR_S _(s)(DETAIL_RPP_INSERTION_SORT_INDIRECT _(1)( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), pred, _p, \
            RPP_EXPR_S _(s)(DETAIL_RPP_INSERTION_SORT_2 _( \
                RPP_NEXT(s), pred, _p, sorted, type, (RPP_HEAD _(g)), pd \
            )), \
            type, RPP_TAIL _(g), pd \
        )), \
        sorted \
    ) \
    /**/
# define DETAIL_RPP_INSERTION_SORT_2(s, pred, _p, sorted, type, key, pd) \
    RPP_IIF(RPP_IS_CONS(sorted))( \
        DETAIL_RPP_INSERTION_SORT_3, RPP_CONS(RPP_NIL(type), RPP_REM key) RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, pred, _p, sorted, type, key, pd) \
    /**/
# define DETAIL_RPP_INSERTION_SORT_3(_, s, pred, _p, sorted, type, key, pd) \
    RPP_IIF _( \
        _p()(s, pred, RPP_ITEM(type, RPP_REM key) RPP_COMMA() RPP_ITEM(type, RPP_HEAD(sorted)) RPP_EXPOSE(pd)) \
    )( \
        RPP_CONS _(sorted, RPP_REM _ key), \
        RPP_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_INSERTION_SORT_INDIRECT _(2)( \
                RPP_NEXT(s), pred, _p, RPP_TAIL _(sorted), type, key, pd \
            )), \
            RPP_HEAD _(sorted) \
        ) \
    ) \
    /**/
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_MERGE_SORT_H
# define RIPPLE_PREPROCESSOR_SANDBOX_MERGE_SORT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/logical/bitand.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_MERGE_SORT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_MERGE_SORT(pred, ...) RPP_MERGE_SORT_S(RPP_STATE(), pred, __VA_ARGS__)
# else
#    define RPP_MERGE_SORT(pred, g, data) RPP_MERGE_SORT_S(RPP_STATE(), pred, g, data)
# endif
#
# define RPP_MERGE_SORT_ID() RPP_MERGE_SORT
#
# /* RPP_MERGE_SORT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_MERGE_SORT_S(s, pred, ...) \
        DETAIL_RPP_MERGE_SORT_U(s, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_MERGE_SORT_S(s, pred, g, data) DETAIL_RPP_MERGE_SORT_U(s, pred, g, (data))
# endif
#
# define RPP_MERGE_SORT_S_ID() RPP_MERGE_SORT_S
#
# define DETAIL_RPP_MERGE_SORT_U(s, pred, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_MERGE_SORT_1( \
        RPP_NEXT(s), RPP_NEXT(s), pred, RPP_CALL(pred), RPP_TYPEOF(g), g, pd \
    )) \
    /**/
# define DETAIL_RPP_MERGE_SORT_INDIRECT(n) DETAIL_RPP_MERGE_SORT_ ## n
# define DETAIL_RPP_MERGE_SORT_1(s, o, pred, _p, type, g, pd) \
    RPP_IIF( \
        RPP_BITAND \
            (RPP_IS_CONS(g))(RPP_IS_CONS(RPP_TAIL(g))) \
    )( \
        DETAIL_RPP_MERGE_SORT_3, g RPP_TUPLE_EAT(8) \
    )( \
        RPP_OBSTRUCT(), s, o, pred, _p, type, \
        RPP_EXPR_S(s)(DETAIL_RPP_MERGE_SORT_2( \
            RPP_OBSTRUCT(), RPP_NEXT(s), g, RPP_NIL(type), RPP_NIL(type) \
        )), \
        pd \
    ) \
    /**/
# define DETAIL_RPP_MERGE_SORT_2(_, s, g, r1, r2) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_EXPR_S _(s)(DETAIL_RPP_MERGE_SORT_INDIRECT _(2)( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TAIL _(g), r2, RPP_CONS _(r1, RPP_HEAD _(g)) \
        )), \
        (r1, r2) \
    ) \
    /**/
# define DETAIL_RPP_MERGE_SORT_3(_, s, o, pred, _p, type, bin, pd) \
    RPP_EXPR_S RPP_OBSTRUCT()(o)(DETAIL_RPP_MERGE_SORT_4 RPP_OBSTRUCT()( \
        RPP_NEXT(o), pred, _p, type, \
        RPP_EXPR_S _(s)(DETAIL_RPP_MERGE_SORT_INDIRECT _(1)( \
            RPP_NEXT(s), o, pred, _p, type, RPP_BINARY(0) bin, pd \
        )), \
        RPP_EXPR_S _(s)(DETAIL_RPP_MERGE_SORT_INDIRECT _(1)( \
            RPP_NEXT(s), o, pred, _p, type, RPP_BINARY(1) bin, pd \
        )), \
        pd \
    )) \
    /**/
# define DETAIL_RPP_MERGE_SORT_4(s, pred, _p, type, r1, r2, pd) \
    RPP_IIF(RPP_IS_CONS(r1))( \
        RPP_IIF(RPP_IS_CONS(r2))( \
            DETAIL_RPP_MERGE_SORT_5, r1 RPP_TUPLE_EAT(8) \
        ), \
        r2 RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, pred, _p, type, r1, r2, pd) \
    /**/
# define DETAIL_RPP_MERGE_SORT_5(_, s, pred, _p, type, r1, r2, pd) \
    RPP_IIF _(_p()(s, pred, RPP_ITEM(type, RPP_HEAD(r1)) RPP_COMMA() RPP_ITEM(type, RPP_HEAD(r2)) RPP_EXPOSE(pd)))( \
        RPP_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_MERGE_SORT_INDIRECT _(4)( \
                RPP_NEXT(s), pred, _p, type, RPP_TAIL _(r1), r2, pd \
            )), \
            RPP_HEAD _(r1) \
        ), \
        RPP_CONS _( \
            RPP_EXPR_S _(s)(DETAIL_RPP_MERGE_SORT_INDIRECT _(4)( \
                RPP_NEXT(s), pred, _p, type, r1, RPP_TAIL _(r2), pd \
            )), \
            RPP_HEAD _(r2) \
        ) \
    ) \
    /**/
#
# endif

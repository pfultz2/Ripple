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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FILTER_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FILTER_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FILTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FILTER(pred, ...) RPP_FILTER_S(RPP_STATE(), pred, __VA_ARGS__)
# else
#    define RPP_FILTER(pred, g, data) RPP_FILTER_S(RPP_STATE(), pred, g, data)
# endif
#
# define RPP_FILTER_ID() RPP_FILTER
#
# /* RPP_FILTER_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FILTER_S(s, pred, ...) DETAIL_RPP_FILTER_U(s, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
# else
#    define RPP_FILTER_S(s, pred, g, data) DETAIL_RPP_FILTER_U(s, pred, g, (data))
# endif
#
# define RPP_FILTER_S_ID() RPP_FILTER_S
#
# define DETAIL_RPP_FILTER_U(s, pred, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_FILTER_I( \
        RPP_NEXT(s), RPP_NEXT(s), pred, RPP_TRAMPOLINE(pred), RPP_TYPEOF(g), g, pd \
    )) \
    /**/
# define DETAIL_RPP_FILTER_INDIRECT() DETAIL_RPP_FILTER_I
# define DETAIL_RPP_FILTER_I(s, o, pred, _p, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FILTER_II, g RPP_TUPLE_EAT(8) \
    )(RPP_DEFER(RPP_OBSTRUCT)(), s, o, pred, _p, type, g, pd) \
    /**/
# define DETAIL_RPP_FILTER_II(_, s, o, pred, _p, type, g, pd) \
    RPP_IIF _(_p()(o, pred, RPP_ITEM(type, RPP_HEAD(g)) RPP_EXPOSE(pd)))( \
        RPP_CONS, RPP_BINARY(0) \
    )( \
        RPP_DEFER(RPP_EXPR_S(s))(RPP_DEFER(DETAIL_RPP_FILTER_INDIRECT)()( \
            RPP_NEXT(s), o, pred, _p, type, RPP_TAIL(g), pd \
        )), \
        RPP_HEAD(g) \
    ) \
    /**/
#
# endif

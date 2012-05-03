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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_TRANSFORM_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TRANSFORM(op, ...) RPP_TRANSFORM_S(RPP_STATE(), op, __VA_ARGS__)
# else
#    define RPP_TRANSFORM(op, g, data) RPP_TRANSFORM_S(RPP_STATE(), op, g, data)
# endif
#
# define RPP_TRANSFORM_ID() RPP_TRANSFORM
#
# /* RPP_TRANSFORM_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TRANSFORM_S(s, op, ...) DETAIL_RPP_TRANSFORM_U(s, op, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
# else
#    define RPP_TRANSFORM_S(s, op, g, data) DETAIL_RPP_TRANSFORM_U(s, op, g, (data))
# endif
#
# define RPP_TRANSFORM_S_ID() RPP_TRANSFORM_S
#
# define DETAIL_RPP_TRANSFORM_U(s, op, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_TRANSFORM_I(RPP_NEXT(s), RPP_NEXT(s), op, RPP_TRAMPOLINE(op), RPP_TYPEOF(g), g, pd)) \
    /**/
# define DETAIL_RPP_TRANSFORM_INDIRECT() DETAIL_RPP_TRANSFORM_I
# define DETAIL_RPP_TRANSFORM_I(s, o, op, _o, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_TRANSFORM_II, \
        g RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, o, op, _o, type, g, pd) \
    /**/
# define DETAIL_RPP_TRANSFORM_II(_, s, o, op, _o, type, g, pd) \
    RPP_CONS RPP_OBSTRUCT()( \
        RPP_EXPR_S(s) _(DETAIL_RPP_TRANSFORM_INDIRECT _()( \
            RPP_NEXT(s), o, op, _o, type, RPP_TAIL(g), pd \
        )), \
        _o()(o, op, RPP_ITEM(type, RPP_HEAD(g)) RPP_EXPOSE(pd)) \
    ) \
    /**/
#
# endif

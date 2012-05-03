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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_TUPLE_TRANSFORM_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TRANSFORM(op, ...) RPP_TUPLE_TRANSFORM_S(RPP_STATE(), op, __VA_ARGS__)
#    define RPP_TUPLE_TRANSFORM_ID() RPP_TUPLE_TRANSFORM
# endif
#
# /* RPP_TUPLE_TRANSFORM_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TRANSFORM_S(s, op, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_TRANSFORM_1( \
            RPP_NEXT(s), RPP_NEXT(s), op, RPP_TRAMPOLINE(op), RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__) \
        )) \
        /**/
#    define RPP_TUPLE_TRANSFORM_S_ID() RPP_TUPLE_TRANSFORM_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_TRANSFORM_INDIRECT(n) DETAIL_RPP_TUPLE_TRANSFORM_ ## n
#    define DETAIL_RPP_TUPLE_TRANSFORM_1(s, o, op, _o, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_TRANSFORM_1_I, DETAIL_RPP_TUPLE_TRANSFORM_2 \
        )(s, o, op, _o, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_TRANSFORM_1_I(s, o, op, _o, tuple, pd) \
        DETAIL_RPP_TUPLE_TRANSFORM_1_II(s, o, op, _o, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), pd) \
        /**/
#    define DETAIL_RPP_TUPLE_TRANSFORM_1_II(...) DETAIL_RPP_TUPLE_TRANSFORM_1_III(RPP_DEFER(RPP_OBSTRUCT)(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_TRANSFORM_1_III(_, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, pd) \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
        RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _(RPP_TUPLE_CONS _( \
            RPP_DEFER(RPP_EXPR_S)(s)(RPP_DEFER(DETAIL_RPP_TUPLE_TRANSFORM_INDIRECT)(1)( \
                RPP_NEXT(s), o, op, _o, tuple, pd \
            )), \
            _o()(o, op, j RPP_EXPOSE(pd))), _o()(o, op, i RPP_EXPOSE(pd))), _o()(o, op, h RPP_EXPOSE(pd))), _o()(o, op, g RPP_EXPOSE(pd))), _o()(o, op, f RPP_EXPOSE(pd))), \
            _o()(o, op, e RPP_EXPOSE(pd))), _o()(o, op, d RPP_EXPOSE(pd))), _o()(o, op, c RPP_EXPOSE(pd))), _o()(o, op, b RPP_EXPOSE(pd))), _o()(o, op, a RPP_EXPOSE(pd))) \
        /**/
#    define DETAIL_RPP_TUPLE_TRANSFORM_2(s, o, op, _o, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_TRANSFORM_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, op, _o, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_TRANSFORM_2_I(_, s, o, op, _o, tuple, pd) \
        RPP_OBSTRUCT(RPP_TUPLE_CONS)( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_TRANSFORM_INDIRECT _(1)( \
                RPP_NEXT(s), o, op, _o, RPP_TUPLE_TAIL(tuple), pd \
            )), \
            _o()(o, op, RPP_TUPLE_HEAD(tuple) RPP_EXPOSE(pd)) \
        ) \
        /**/
# endif
#
# endif

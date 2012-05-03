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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FILTER_H
# define RIPPLE_PREPROCESSOR_TUPLE_FILTER_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_FILTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FILTER(pred, ...) RPP_TUPLE_FILTER_S(RPP_STATE(), pred, __VA_ARGS__)
#    define RPP_TUPLE_FILTER_ID() RPP_TUPLE_FILTER
# endif
#
# /* RPP_TUPLE_FILTER_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FILTER_S(s, pred, ...) DETAIL_RPP_TUPLE_FILTER_I(s, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
#    define RPP_TUPLE_FILTER_S_ID() RPP_TUPLE_FILTER_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FILTER_I(s, pred, tuple, pd) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FILTER_1( \
            RPP_NEXT(s), RPP_NEXT(s), pred, RPP_TRAMPOLINE(pred), tuple, pd \
        )) \
        /**/
#    define DETAIL_RPP_TUPLE_FILTER_INDIRECT(n) DETAIL_RPP_TUPLE_FILTER_ ## n
#    define DETAIL_RPP_TUPLE_FILTER_1(s, o, pred, _p, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FILTER_1_I, DETAIL_RPP_TUPLE_FILTER_2 \
        )(s, o, pred, _p, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FILTER_1_I(s, o, pred, _p, tuple, pd) \
        DETAIL_RPP_TUPLE_FILTER_1_II(s, o, pred, _p, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FILTER_1_II(...) DETAIL_RPP_TUPLE_FILTER_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FILTER_1_III(_, s, o, pred, _p, a, b, c, d, e, f, g, h, i, j, tuple, pd) \
        RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, a RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, b RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, c RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, d RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, e RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, f RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, g RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, h RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, i RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, j RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )(RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FILTER_INDIRECT _(1)( \
            RPP_NEXT(s), o, pred, _p, tuple, pd \
        )), j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define DETAIL_RPP_TUPLE_FILTER_2(s, o, pred, _p, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FILTER_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, pred, _p, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FILTER_2_I(_, s, o, pred, _p, tuple, pd) \
        RPP_OBSTRUCT(RPP_IIF)(_p()(o, pred, RPP_TUPLE_HEAD(tuple) RPP_EXPOSE(pd)))( \
            RPP_TUPLE_CONS, RPP_BINARY(0) \
        )( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FILTER_INDIRECT _(2)( \
                RPP_NEXT(s), o, pred, _p, RPP_TUPLE_TAIL(tuple), pd \
            )), \
            RPP_TUPLE_HEAD(tuple) \
        ) \
        /**/
# endif
#
# endif

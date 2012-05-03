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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FOLD_LEFT_H
# define RIPPLE_PREPROCESSOR_TUPLE_FOLD_LEFT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_FOLD_LEFT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_LEFT(op, tuple, ...) RPP_TUPLE_FOLD_LEFT_S(RPP_STATE(), op, tuple, __VA_ARGS__)
#    define RPP_TUPLE_FOLD_LEFT_ID() RPP_TUPLE_FOLD_LEFT
# endif
#
# /* RPP_TUPLE_FOLD_LEFT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_LEFT_S(s, op, tuple, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_1( \
            RPP_NEXT(s), RPP_NEXT(s), op, RPP_PLANAR(op), tuple \
        ) __VA_ARGS__ DETAIL_RPP_TUPLE_FOLD_LEFT_3(RPP_OBSTRUCT(), RPP_NEXT(s), tuple)) \
        /**/
#    define RPP_TUPLE_FOLD_LEFT_S_ID() RPP_TUPLE_FOLD_LEFT_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT(n) DETAIL_RPP_TUPLE_FOLD_LEFT_ ## n
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_1(s, o, op, _o, tuple) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FOLD_LEFT_1_I, DETAIL_RPP_TUPLE_FOLD_LEFT_2 \
        )(s, o, op, _o, tuple) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_1_I(s, o, op, _o, tuple) \
        DETAIL_RPP_TUPLE_FOLD_LEFT_1_II(s, o, op, _o, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple)) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_1_II(...) DETAIL_RPP_TUPLE_FOLD_LEFT_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_1_III(_, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT _(1)( \
            RPP_NEXT(s), o, op, _o, tuple \
        )) \
        _o()(o, op) j, _o()(o, op) i, _o()(o, op) h, _o()(o, op) g, _o()(o, op) f, \
        _o()(o, op) e, _o()(o, op) d, _o()(o, op) c, _o()(o, op) b, _o()(o, op) a, \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_2(s, o, op, _o, tuple) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FOLD_LEFT_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, op, _o, tuple) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_2_I(_, s, o, op, _o, tuple) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT _(2)( \
            RPP_NEXT(s), o, op, _o, RPP_TUPLE_TAIL(tuple) \
        )) \
        _o()(o, op) RPP_TUPLE_HEAD(tuple), \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_3(_, s, tuple) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(10, tuple))( \
            RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() \
            RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT _(3)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT _(4)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), tuple \
            )) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_4(_, s, tuple) \
        RPP_INLINE_WHEN _(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_PLANAR_CLOSE _() \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_INDIRECT _(4)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TUPLE_TAIL _(tuple) \
            )) \
        ) \
        /**/
# endif
#
# endif

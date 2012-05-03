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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FOLD_LEFT_AUX_H
# define RIPPLE_PREPROCESSOR_TUPLE_FOLD_LEFT_AUX_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_FOLD_LEFT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_LEFT_AUX(op, tuple, data, ...) RPP_TUPLE_FOLD_LEFT_AUX_S(RPP_STATE(), op, tuple, data, __VA_ARGS__)
#    define RPP_TUPLE_FOLD_LEFT_AUX_ID() RPP_TUPLE_FOLD_LEFT_AUX
# endif
#
# /* RPP_TUPLE_FOLD_LEFT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_LEFT_AUX_S(s, op, tuple, data, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1( \
            RPP_NEXT(s), RPP_NEXT(s), op, RPP_PLANAR(op), tuple, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM) data \
        ) __VA_ARGS__ DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_3(RPP_OBSTRUCT(), RPP_NEXT(s), tuple)) \
        /**/
#    define RPP_TUPLE_FOLD_LEFT_AUX_S_ID() RPP_TUPLE_FOLD_LEFT_AUX_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT(n) DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_ ## n
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1(s, o, op, _o, tuple, ...) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_I, DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_2 \
        )(s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_I(s, o, op, _o, tuple, ...) \
        DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_II(s, o, op, _o, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_II(...) DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_1_III(_, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, ...) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(1)( \
            RPP_NEXT(s), o, op, _o, tuple, __VA_ARGS__ \
        )) \
        _o()(o, op) j, __VA_ARGS__, _o()(o, op) i, __VA_ARGS__, _o()(o, op) h, __VA_ARGS__, _o()(o, op) g, __VA_ARGS__, _o()(o, op) f, __VA_ARGS__, \
        _o()(o, op) e, __VA_ARGS__, _o()(o, op) d, __VA_ARGS__, _o()(o, op) c, __VA_ARGS__, _o()(o, op) b, __VA_ARGS__, _o()(o, op) a, __VA_ARGS__, \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_2(s, o, op, _o, tuple, ...) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, op, _o, tuple, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_2_I(_, s, o, op, _o, tuple, ...) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(2)( \
            RPP_NEXT(s), o, op, _o, RPP_TUPLE_TAIL(tuple), __VA_ARGS__ \
        )) \
        _o()(o, op) RPP_TUPLE_HEAD(tuple), __VA_ARGS__, \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_3(_, s, tuple) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(10, tuple))( \
            RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() \
            RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() RPP_PLANAR_CLOSE _() \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(3)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TUPLE_SANS_BATCH _(10, tuple) \
            )), \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(4)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), tuple \
            )) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_4(_, s, tuple) \
        RPP_INLINE_WHEN _(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_PLANAR_CLOSE _() \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_LEFT_AUX_INDIRECT _(4)( \
                RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TUPLE_TAIL _(tuple) \
            )) \
        ) \
        /**/
# endif
#
# endif

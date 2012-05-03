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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FOLD_RIGHT_AUX_AUX_H
# define RIPPLE_PREPROCESSOR_TUPLE_FOLD_RIGHT_AUX_AUX_H
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
# /* RPP_TUPLE_FOLD_RIGHT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_RIGHT_AUX(op, tuple, data, ...) RPP_TUPLE_FOLD_RIGHT_AUX_S(RPP_STATE(), op, tuple, data, __VA_ARGS__)
#    define RPP_TUPLE_FOLD_RIGHT_AUX_ID() RPP_TUPLE_FOLD_RIGHT_AUX
# endif
#
# /* RPP_TUPLE_FOLD_RIGHT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOLD_RIGHT_AUX_S(s, op, tuple, data, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1( \
            RPP_NEXT(s), RPP_NEXT(s), op, RPP_PLANAR(op), tuple, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), __VA_ARGS__ \
        )) \
        /**/
#    define RPP_TUPLE_FOLD_RIGHT_AUX_S_ID() RPP_TUPLE_FOLD_RIGHT_AUX_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_INDIRECT(n) DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_ ## n
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1(s, o, op, _o, tuple, pd, ...) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_I, DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_2 \
        )(s, o, op, _o, tuple, pd, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_I(s, o, op, _o, tuple, pd, ...) \
        DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_II(s, o, op, _o, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), pd, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_II(...) DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_III(RPP_OBSTRUCT(), RPP_PLANAR_CLOSE, __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_1_III(_, cl, s, o, op, _o, a, b, c, d, e, f, g, h, i, j, tuple, pd, ...) \
        _o()(o, op) a, RPP_REM pd, _o()(o, op) b, RPP_REM pd, _o()(o, op) c, RPP_REM pd, _o()(o, op) d, RPP_REM pd, _o()(o, op) e, RPP_REM pd, \
        _o()(o, op) f, RPP_REM pd, _o()(o, op) g, RPP_REM pd, _o()(o, op) h, RPP_REM pd, _o()(o, op) i, RPP_REM pd, _o()(o, op) j, RPP_REM pd, \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_INDIRECT _(1)( \
            RPP_NEXT(s), o, op, _o, tuple, pd, __VA_ARGS__ \
        )) \
        cl() cl() cl() cl() cl() cl() cl() cl() cl() cl()
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_2(s, o, op, _o, tuple, pd, ...) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_2_I, __VA_ARGS__ RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, op, _o, tuple, pd, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_2_I(_, s, o, op, _o, tuple, pd, ...) \
        _o()(o, op) RPP_TUPLE_HEAD(tuple), RPP_REM pd, \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOLD_RIGHT_AUX_INDIRECT _(2)( \
            RPP_NEXT(s), o, op, _o, RPP_TUPLE_TAIL(tuple), pd, __VA_ARGS__ \
        )) \
        RPP_PLANAR_CLOSE() \
        /**/
# endif
#
# endif

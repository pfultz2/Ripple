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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_LEFT_AUX_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_LEFT_AUX_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOLD_LEFT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_LEFT_AUX(op, g, data, ...) RPP_FOLD_LEFT_AUX_S(RPP_STATE(), op, g, data, __VA_ARGS__)
# else
#    define RPP_FOLD_LEFT_AUX(op, g, data, state) RPP_FOLD_LEFT_AUX_S(RPP_STATE(), op, g, data, state)
# endif
#
# define RPP_FOLD_LEFT_AUX_ID() RPP_FOLD_LEFT_AUX
#
# /* RPP_FOLD_LEFT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_LEFT_AUX_S(s, op, g, data, ...) \
        DETAIL_RPP_FOLD_LEFT_AUX_U(s, op, g, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOLD_LEFT_AUX_S(s, op, g, data, state) \
        DETAIL_RPP_FOLD_LEFT_AUX_U(s, op, g, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_FOLD_LEFT_AUX_S_ID() RPP_FOLD_LEFT_AUX_S
#
# define DETAIL_RPP_FOLD_LEFT_AUX_U(s, op, g, data, ps) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOLD_LEFT_AUX_1( \
        RPP_NEXT(s), RPP_NEXT(s), \
        op, RPP_PLANAR(op), RPP_TYPEOF(g), g, data \
    ) RPP_REM ps DETAIL_RPP_FOLD_LEFT_AUX_2(RPP_OBSTRUCT(), RPP_NEXT(s), g)) \
    /**/
# define DETAIL_RPP_FOLD_LEFT_AUX_INDIRECT(n) DETAIL_RPP_FOLD_LEFT_AUX_ ## n
# define DETAIL_RPP_FOLD_LEFT_AUX_1(s, o, op, _o, type, g, data) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOLD_LEFT_AUX_1_I, RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, o, op, _o, type, g, data) \
    /**/
# define DETAIL_RPP_FOLD_LEFT_AUX_1_I(_, s, o, op, _o, type, g, data) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_LEFT_AUX_INDIRECT _(1)( \
        RPP_NEXT(s), o, op, _o, type, RPP_TAIL(g), data \
    )) \
    _o()(o, op) RPP_ITEM(type, RPP_HEAD(g)), RPP_REM data, \
    /**/
# define DETAIL_RPP_FOLD_LEFT_AUX_2(_, s, g) \
    RPP_INLINE_WHEN _(RPP_IS_CONS(g))( \
        RPP_PLANAR_CLOSE _() \
        RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_LEFT_AUX_INDIRECT _(2)( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TAIL _(g) \
        )) \
    ) \
    /**/
#
# endif

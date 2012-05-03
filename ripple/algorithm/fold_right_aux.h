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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_AUX_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_AUX_H
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
# /* RPP_FOLD_RIGHT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT_AUX(op, g, data, ...) RPP_FOLD_RIGHT_AUX_S(RPP_STATE(), op, g, data, __VA_ARGS__)
# else
#    define RPP_FOLD_RIGHT_AUX(op, g, data, state) RPP_FOLD_RIGHT_AUX_S(RPP_STATE(), op, g, data, state)
# endif
#
# define RPP_FOLD_RIGHT_AUX_ID() RPP_FOLD_RIGHT_AUX
#
# /* RPP_FOLD_RIGHT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT_AUX_S(s, op, g, data, ...) \
        DETAIL_RPP_FOLD_RIGHT_AUX_U(s, op, g, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOLD_RIGHT_AUX_S(s, op, g, data, state) \
        DETAIL_RPP_FOLD_RIGHT_AUX_U(s, op, g, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_FOLD_RIGHT_AUX_S_ID() RPP_FOLD_RIGHT_AUX_S
#
# define DETAIL_RPP_FOLD_RIGHT_AUX_U(s, op, g, data, ps) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOLD_RIGHT_AUX_I( \
        RPP_NEXT(s), RPP_NEXT(s), \
        op, RPP_PLANAR(op), RPP_TYPEOF(g), g, data, ps \
    )) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_INDIRECT() DETAIL_RPP_FOLD_RIGHT_AUX_I
# define DETAIL_RPP_FOLD_RIGHT_AUX_I(s, o, op, _o, type, g, data, ps) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOLD_RIGHT_AUX_II, RPP_REM ps RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), s, o, op, _o, type, g, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_II(_, s, o, op, _o, type, g, data, ps) \
    _o()(o, op) \
        RPP_ITEM(type, RPP_HEAD(g)), RPP_REM data, \
        RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_RIGHT_AUX_INDIRECT _()( \
            RPP_NEXT(s), o, op, _o, type, RPP_TAIL(g), data, ps \
        )) \
    RPP_PLANAR_CLOSE() \
    /**/
#
# endif

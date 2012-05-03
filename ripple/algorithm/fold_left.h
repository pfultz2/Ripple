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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_LEFT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOLD_LEFT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_LEFT(op, g, ...) RPP_FOLD_LEFT_S(RPP_STATE(), op, g, __VA_ARGS__)
# else
#    define RPP_FOLD_LEFT(op, g, state) RPP_FOLD_LEFT_S(RPP_STATE(), op, g, state)
# endif
#
# define RPP_FOLD_LEFT_ID() RPP_FOLD_LEFT
#
# /* RPP_FOLD_LEFT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_LEFT_S(s, op, g, ...) DETAIL_RPP_FOLD_LEFT_U(s, op, g, (__VA_ARGS__))
# else
#    define RPP_FOLD_LEFT_S(s, op, g, state) DETAIL_RPP_FOLD_LEFT_U(s, op, g, (state))
# endif
#
# define RPP_FOLD_LEFT_S_ID() RPP_FOLD_LEFT_S
#
# define DETAIL_RPP_FOLD_LEFT_U(s, op, g, ps) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOLD_LEFT_1( \
        RPP_NEXT(s), RPP_NEXT(s), \
        op, RPP_PLANAR(op), RPP_TYPEOF(g), g \
    ) RPP_REM ps DETAIL_RPP_FOLD_LEFT_2(RPP_OBSTRUCT(), RPP_NEXT(s), g)) \
    /**/
# define DETAIL_RPP_FOLD_LEFT_INDIRECT(n) DETAIL_RPP_FOLD_LEFT_ ## n
# define DETAIL_RPP_FOLD_LEFT_1(s, o, op, _o, type, g) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOLD_LEFT_1_I, RPP_TUPLE_EAT(7) \
    )(RPP_OBSTRUCT(), s, o, op, _o, type, g) \
    /**/
# define DETAIL_RPP_FOLD_LEFT_1_I(_, s, o, op, _o, type, g) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_LEFT_INDIRECT _(1)( \
        RPP_NEXT(s), o, op, _o, type, RPP_TAIL(g) \
    )) \
    _o()(o, op) RPP_ITEM(type, RPP_HEAD(g)), \
    /**/
# define DETAIL_RPP_FOLD_LEFT_2(_, s, g) \
    RPP_INLINE_WHEN _(RPP_IS_CONS(g))( \
        RPP_PLANAR_CLOSE _() \
        RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_LEFT_INDIRECT _(2)( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_TAIL _(g) \
        )) \
    ) \
    /**/
#
# endif

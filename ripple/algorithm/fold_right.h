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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOLD_RIGHT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT(op, g, ...) RPP_FOLD_RIGHT_S(RPP_STATE(), op, g, __VA_ARGS__)
# else
#    define RPP_FOLD_RIGHT(op, g, state) RPP_FOLD_RIGHT_S(RPP_STATE(), op, g, state)
# endif
#
# define RPP_FOLD_RIGHT_ID() RPP_FOLD_RIGHT
#
# /* RPP_FOLD_RIGHT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT_S(s, op, g, ...) DETAIL_RPP_FOLD_RIGHT_U(s, op, g, (__VA_ARGS__))
# else
#    define RPP_FOLD_RIGHT_S(s, op, g, state) DETAIL_RPP_FOLD_RIGHT_U(s, op, g, (state))
# endif
#
# define RPP_FOLD_RIGHT_S_ID() RPP_FOLD_RIGHT_S
#
# define DETAIL_RPP_FOLD_RIGHT_U(s, op, g, ps) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOLD_RIGHT_I( \
        RPP_NEXT(s), RPP_NEXT(s), \
        op, RPP_PLANAR(op), RPP_TYPEOF(g), g, ps \
    )) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_INDIRECT() DETAIL_RPP_FOLD_RIGHT_I
# define DETAIL_RPP_FOLD_RIGHT_I(s, o, op, _o, type, g, ps) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOLD_RIGHT_II, RPP_REM ps RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, o, op, _o, type, g, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_II(_, s, o, op, _o, type, g, ps) \
    _o()(o, op) \
        RPP_ITEM(type, RPP_HEAD(g)), \
        RPP_EXPR_S(s) _(DETAIL_RPP_FOLD_RIGHT_INDIRECT _()( \
            RPP_NEXT(s), o, op, _o, type, RPP_TAIL(g), ps \
        )) \
    RPP_PLANAR_CLOSE() \
    /**/
#
# endif

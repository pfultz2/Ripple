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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_WHILE_AUX_H
# define RIPPLE_PREPROCESSOR_CONTROL_WHILE_AUX_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_WHILE_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE_AUX(pred, op, data, ...) RPP_WHILE_AUX_S(RPP_STATE(), pred, op, data, __VA_ARGS__)
# else
#    define RPP_WHILE_AUX(pred, op, data, state) RPP_WHILE_AUX_S(RPP_STATE(), pred, op, data, state)
# endif
#
# define RPP_WHILE_AUX_ID() RPP_WHILE_AUX
#
# /* RPP_WHILE_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE_AUX_S(s, pred, op, data, ...) \
        DETAIL_RPP_WHILE_AUX_U(s, pred, op, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_WHILE_AUX_S(s, pred, op, data, state) \
        DETAIL_RPP_WHILE_AUX_U(s, pred, op, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_WHILE_AUX_S_ID() RPP_WHILE_AUX_S
#
# define DETAIL_RPP_WHILE_AUX_U(s, pred, op, data, ps) \
    DETAIL_RPP_WHILE_AUX_I(RPP_OBSTRUCT(), RPP_NEXT(s), pred, RPP_CALL(pred), op, RPP_CALL(op), data, ps) \
    /**/
# define DETAIL_RPP_WHILE_AUX_INDIRECT() DETAIL_RPP_WHILE_AUX_I
# define DETAIL_RPP_WHILE_AUX_I(_, s, pred, _p, op, _o, data, ps) \
    RPP_IIF _(_p()(s, pred, RPP_REM data RPP_COMMA() RPP_REM ps))( \
        RPP_EXPR_S(s) _(DETAIL_RPP_WHILE_AUX_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), pred, _p, op, _o, data, (_o()(s, op, RPP_REM data RPP_COMMA() RPP_REM ps)) \
        )), \
        RPP_REM ps \
    ) \
    /**/
#
# endif

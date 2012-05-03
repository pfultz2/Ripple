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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_WHILE_H
# define RIPPLE_PREPROCESSOR_CONTROL_WHILE_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_WHILE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE(pred, op, ...) RPP_WHILE_S(RPP_STATE(), pred, op, __VA_ARGS__)
# else
#    define RPP_WHILE(pred, op, state) RPP_WHILE_S(RPP_STATE(), pred, op, state)
# endif
#
# define RPP_WHILE_ID() RPP_WHILE
#
# /* RPP_WHILE_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE_S(s, pred, op, ...) DETAIL_RPP_WHILE_U(s, pred, op, (__VA_ARGS__))
# else
#    define RPP_WHILE_S(s, pred, op, state) DETAIL_RPP_WHILE_U(s, pred, op, (state))
# endif
#
# define RPP_WHILE_S_ID() RPP_WHILE_S
#
# define DETAIL_RPP_WHILE_U(s, pred, op, ps) \
    DETAIL_RPP_WHILE_I(RPP_OBSTRUCT(), RPP_NEXT(s), pred, RPP_CALL(pred), op, RPP_CALL(op), ps) \
    /**/
# define DETAIL_RPP_WHILE_INDIRECT() DETAIL_RPP_WHILE_I
# define DETAIL_RPP_WHILE_I(_, s, pred, _p, op, _o, ps) \
    RPP_IIF _(_p()(s, pred, RPP_REM ps))( \
        RPP_EXPR_S(s) _(DETAIL_RPP_WHILE_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), pred, _p, op, _o, (_o()(s, op, RPP_REM ps)) \
        )), \
        RPP_REM ps \
    ) \
    /**/
#
# endif

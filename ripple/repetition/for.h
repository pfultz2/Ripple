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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_FOR_H
# define RIPPLE_PREPROCESSOR_REPETITION_FOR_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOR */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR(pred, op, macro, ...) RPP_FOR_S(RPP_STATE(), pred, op, macro, __VA_ARGS__)
# else
#    define RPP_FOR(pred, op, macro, state) RPP_FOR_S(RPP_STATE(), pred, op, macro, state)
# endif
#
# define RPP_FOR_ID() RPP_FOR
#
# /* RPP_FOR_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_S(s, pred, op, macro, ...) DETAIL_RPP_FOR_U(s, pred, op, macro, (__VA_ARGS__))
# else
#    define RPP_FOR_S(s, pred, op, macro, state) DETAIL_RPP_FOR_U(s, pred, op, macro, (state))
# endif
#
# define RPP_FOR_S_ID() RPP_FOR_S
#
# define DETAIL_RPP_FOR_U(s, pred, op, macro, ps) DETAIL_RPP_FOR_I(RPP_NEXT(s), pred, op, macro, ps)
# define DETAIL_RPP_FOR_I(s, pred, op, macro, ps) \
    RPP_DEFER(RPP_EXPR_S)(s)(DETAIL_RPP_FOR_II( \
        RPP_OBSTRUCT(), s, RPP_NEXT(s), \
        pred, RPP_CALL(pred), op, RPP_CALL(op), \
        macro, RPP_TRAMPOLINE(macro), ps \
    )) \
    /**/
# define DETAIL_RPP_FOR_INDIRECT() DETAIL_RPP_FOR_II
# define DETAIL_RPP_FOR_II(_, s, o, pred, _p, op, _o, macro, _m, ps) \
    RPP_IIF _(_p()(s, pred, RPP_REM ps))( \
        RPP_EXPR_S(s), RPP_EAT \
    )( \
        _m _()(o, macro, RPP_REM ps) \
        DETAIL_RPP_FOR_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), o, pred, _p, op, _o, macro, _m, (_o()(s, op, RPP_REM ps)) \
        ) \
    ) \
    /**/
#
# endif

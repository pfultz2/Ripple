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
# include <ripple/invoke.h>
#
# /* RPP_FOR */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR(pred, op, macro, ...) RPP_FOR_S(RPP_STATE(), pred, op, macro, __VA_ARGS__)
# else
#    define RPP_FOR_MSVC(pred, op, macro, ...) DETAIL_RPP_FOR_U(RPP_STATE(), pred, op, macro, (__VA_ARGS__))
#    define RPP_FOR_MSVC_REM(x) RPP_FOR_S_MSVC x
#    define RPP_FOR(...) RPP_FOR_S_MSVC_REM((__VA_ARGS__))
# endif
#
# define RPP_FOR_ID() RPP_FOR
#
# /* RPP_FOR_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_S(s, pred, op, macro, ...) DETAIL_RPP_FOR_U(s, pred, op, macro, (__VA_ARGS__))
# else
#    define RPP_FOR_S_MSVC(s, pred, op, macro, ...) DETAIL_RPP_FOR_U(s, pred, op, macro, (__VA_ARGS__))
#    define RPP_FOR_S_MSVC_REM(x) RPP_FOR_S_MSVC x
#    define RPP_FOR_S(...) RPP_FOR_S_MSVC_REM((__VA_ARGS__))
# endif
#
# define RPP_FOR_S_ID() RPP_FOR_S
#
# define DETAIL_RPP_FOR_U(s, pred, op, macro, ps) DETAIL_RPP_FOR_I(RPP_NEXT(s), pred, op, macro, ps)
# define DETAIL_RPP_FOR_I(s, pred, op, macro, ps) \
    RPP_DEFER(RPP_EXPR_S)(s)(DETAIL_RPP_FOR_II( \
        RPP_OBSTRUCT(), RPP_NEXT(s), \
        pred, RPP_INVOKER(pred), op, RPP_INVOKER(op), \
        macro, RPP_INVOKER(macro), ps \
    )) \
    /**/
# define DETAIL_RPP_FOR_INDIRECT() DETAIL_RPP_FOR_II
# define DETAIL_RPP_FOR_II(_, s, pred, _p, op, _o, macro, _m, ps) \
    RPP_IIF _(_p()(s, pred, s, RPP_REM ps))( \
        RPP_EXPR_S(s), RPP_EAT \
    )( \
        _m _()(s, macro, s, RPP_REM ps) \
        DETAIL_RPP_FOR_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), pred, _p, op, _o, macro, _m, (_o _()(s, op, s, RPP_REM ps)) \
        ) \
    ) \
    /**/
#
# endif

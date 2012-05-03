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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_FOR_AUX_H
# define RIPPLE_PREPROCESSOR_REPETITION_FOR_AUX_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOR_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_AUX(pred, op, macro, data, ...) RPP_FOR_AUX_S(RPP_STATE(), pred, op, macro, data, __VA_ARGS__)
# else
#    define RPP_FOR_AUX(pred, op, macro, data, state) RPP_FOR_AUX_S(RPP_STATE(), pred, op, macro, data, state)
# endif
#
# define RPP_FOR_AUX_ID() RPP_FOR_AUX
#
# /* RPP_FOR_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_AUX_S(s, pred, op, macro, data, ...) \
        DETAIL_RPP_FOR_AUX_U(s, pred, op, macro, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_AUX_S(s, pred, op, macro, data, state) \
        DETAIL_RPP_FOR_AUX_U(s, pred, op, macro, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_FOR_AUX_S_ID() RPP_FOR_AUX_S
#
# define DETAIL_RPP_FOR_AUX_U(s, pred, op, macro, data, ps) DETAIL_RPP_FOR_AUX_I(RPP_NEXT(s), pred, op, macro, data, ps)
# define DETAIL_RPP_FOR_AUX_I(s, pred, op, macro, data, ps) \
    RPP_DEFER(RPP_EXPR_S)(s)(DETAIL_RPP_FOR_AUX_II( \
        RPP_OBSTRUCT(), s, RPP_NEXT(s), \
        pred, RPP_CALL(pred), op, RPP_CALL(op), \
        macro, RPP_TRAMPOLINE(macro), data, ps \
    )) \
    /**/
# define DETAIL_RPP_FOR_AUX_INDIRECT() DETAIL_RPP_FOR_AUX_II
# define DETAIL_RPP_FOR_AUX_II(_, s, o, pred, _p, op, _o, macro, _m, data, ps) \
    RPP_IIF _(_p()(s, pred, RPP_REM data RPP_COMMA() RPP_REM ps))( \
        RPP_EXPR_S(s), RPP_EAT \
    )( \
        _m _()(o, macro, RPP_REM data RPP_COMMA _() RPP_REM ps) \
        DETAIL_RPP_FOR_AUX_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), o, pred, _p, op, _o, macro, _m, data, (_o()(s, op, RPP_REM data RPP_COMMA() RPP_REM ps)) \
        ) \
    ) \
    /**/
#
# endif

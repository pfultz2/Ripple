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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_FOR_AUX_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_FOR_AUX_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOR_AUX_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_AUX_X(size, pred, op, macro, data, ...) RPP_FOR_AUX_X_S(RPP_STATE(), size, pred, op, macro, data, __VA_ARGS__)
# else
#    define RPP_FOR_AUX_X(size, pred, op, macro, data, state) RPP_FOR_AUX_X_S(RPP_STATE(), size, pred, op, macro, data, state)
# endif
#
# define RPP_FOR_AUX_X_ID() RPP_FOR_AUX_X
#
# /* RPP_FOR_AUX_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_AUX_X_S(s, size, pred, op, macro, data, ...) \
        DETAIL_RPP_FOR_AUX_X_U(s, size, pred, op, macro, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_AUX_X_S(s, size, pred, op, macro, data, state) \
        DETAIL_RPP_FOR_AUX_X_U(s, size, pred, op, macro, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_FOR_AUX_X_S_ID() RPP_FOR_AUX_X_S
#
# define DETAIL_RPP_FOR_AUX_X_U(s, size, pred, op, macro, data, ps) \
    DETAIL_RPP_FOR_AUX_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), 0, \
        pred, RPP_CALL(pred), op, RPP_CALL(op), macro, RPP_CALL(macro), data, ps \
    ) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_INDIRECT() DETAIL_RPP_FOR_AUX_X_I
# define DETAIL_RPP_FOR_AUX_X_I(s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_FOR_AUX_X_II, DETAIL_RPP_FOR_AUX_X_ ## mode \
        ), \
        DETAIL_RPP_FOR_AUX_X_III \
    )(RPP_PHASE(0), s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_II(_, s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_FOR_AUX_X_ ## mode(_, s, (RPP_NEXT(s)) jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    ) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_0(_, s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    _(1, RPP_IIF)(_(0, _p)()(s, pred, RPP_REM data _(0, RPP_COMMA)() RPP_REM ps))( \
        _(1, RPP_EXPR_S)(s), RPP_EAT \
    )( \
        _(1, DETAIL_RPP_FOR_AUX_X_INDIRECT)()( \
            RPP_NEXT(s), jump, fix, 1, pred, _p, op, _o, macro, _m, data, ps \
        ) \
    ) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_1(_, s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    _(0, _m)()(s, macro, RPP_REM data _(0, RPP_COMMA)() RPP_REM ps) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_AUX_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, 0, pred, _p, op, _o, macro, _m, data, (_(0, _o)()(s, op, RPP_REM data _(0, RPP_COMMA)() RPP_REM ps)) \
    )) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_III(_, s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    DETAIL_RPP_FOR_AUX_X_IV(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    /**/
# define DETAIL_RPP_FOR_AUX_X_IV(s, jump, fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_FOR_AUX_X_II, DETAIL_RPP_FOR_AUX_X_ ## mode \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, mode, pred, _p, op, _o, macro, _m, data, ps) \
    /**/
#
# endif

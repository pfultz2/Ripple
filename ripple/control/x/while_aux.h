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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_X_WHILE_AUX_H
# define RIPPLE_PREPROCESSOR_CONTROL_X_WHILE_AUX_H
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
# /* WHILE_AUX_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE_AUX_X(size, pred, op, data, ...) RPP_WHILE_AUX_X_S(RPP_STATE(), size, pred, op, data, __VA_ARGS__)
# else
#    define RPP_WHILE_AUX_X(size, pred, op, data, state) RPP_WHILE_AUX_X_S(RPP_STATE(), size, pred, op, data, state)
# endif
#
# define RPP_WHILE_AUX_X_ID() RPP_WHILE_AUX_X
#
# /* RPP_WHILE_AUX_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WHILE_AUX_X_S(s, size, pred, op, data, ...) \
        DETAIL_RPP_WHILE_AUX_X_U(s, size, pred, op, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_WHILE_AUX_X_S(s, size, pred, op, data, state) \
        DETAIL_RPP_WHILE_AUX_X_U(s, size, pred, op, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_WHILE_AUX_X_S_ID() RPP_WHILE_AUX_X_S
#
# define DETAIL_RPP_WHILE_AUX_X_U(s, size, pred, op, data, ps) \
    DETAIL_RPP_WHILE_AUX_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), \
        pred, RPP_CALL(pred), op, RPP_CALL(op), data, ps \
    ) \
    /**/
# define DETAIL_RPP_WHILE_AUX_X_INDIRECT() DETAIL_RPP_WHILE_AUX_X_I
# define DETAIL_RPP_WHILE_AUX_X_I(s, jump, fix, pred, _p, op, _o, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_WHILE_AUX_X_II, DETAIL_RPP_WHILE_AUX_X_III \
        ), \
        DETAIL_RPP_WHILE_AUX_X_IV \
    )(RPP_PHASE(0), s, jump, fix, pred, _p, op, _o, data, ps) \
    /**/
# define DETAIL_RPP_WHILE_AUX_X_II(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_WHILE_AUX_X_III(_, s, (RPP_NEXT(s)) jump, fix, pred, _p, op, _o, data, ps) \
    ) \
    /**/
# define DETAIL_RPP_WHILE_AUX_X_III(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    _(1, RPP_IIF)(_(0, _p)()(s, pred, RPP_REM data _(0, RPP_COMMA)() RPP_REM ps))( \
        _(1, RPP_EXPR_S)(s), RPP_REM ps RPP_EAT \
    )( \
        _(1, DETAIL_RPP_WHILE_AUX_X_INDIRECT)()( \
            RPP_NEXT(s), jump, fix, pred, _p, op, _o, data, \
            (_(0, _o)()(s, op, RPP_REM data _(0, RPP_COMMA)() RPP_REM ps)) \
        ) \
    ) \
    /**/
# define DETAIL_RPP_WHILE_AUX_X_IV(_, s, jump, fix, pred, _p, op, _o, data, ps) \
    DETAIL_RPP_WHILE_AUX_X_V(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, pred, _p, op, _o, data, ps) \
    /**/
# define DETAIL_RPP_WHILE_AUX_X_V(s, jump, fix, pred, _p, op, _o, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_WHILE_AUX_X_II, DETAIL_RPP_WHILE_AUX_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, pred, _p, op, _o, data, ps) \
    /**/
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_X_FOLD_RIGHT_AUX_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_X_FOLD_RIGHT_AUX_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOLD_RIGHT_AUX_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT_AUX_X(size, op, g, data, ...) RPP_FOLD_RIGHT_AUX_X_S(RPP_STATE(), size, op, g, data, __VA_ARGS__)
# else
#    define RPP_FOLD_RIGHT_AUX_X(size, op, g, data, state) RPP_FOLD_RIGHT_AUX_X_S(RPP_STATE(), size, op, g, data, state)
# endif
#
# define RPP_FOLD_RIGHT_AUX_X_ID() RPP_FOLD_RIGHT_AUX_X
#
# /* RPP_FOLD_RIGHT_AUX_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOLD_RIGHT_AUX_X_S(s, size, op, g, data, ...) \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_U(s, size, op, g, RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data), (__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOLD_RIGHT_AUX_X_S(s, size, op, g, data, state) \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_U(s, size, op, g, RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data), (state)) \
        /**/
# endif
#
# define RPP_FOLD_RIGHT_AUX_X_S_ID() RPP_FOLD_RIGHT_AUX_X_S
#
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_U(s, size, op, g, data, ps) \
    DETAIL_RPP_FOLD_RIGHT_AUX_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), \
        0, op, RPP_CALL(op), RPP_TYPEOF(g), g, RPP_NIL(RPP_TYPEOF(g)), data, ps \
    ) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_INDIRECT() DETAIL_RPP_FOLD_RIGHT_AUX_X_I
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_I(s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_FOLD_RIGHT_AUX_X_II, DETAIL_RPP_FOLD_RIGHT_AUX_X_III \
        ), \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_V \
    )(RPP_PHASE(0), s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_II(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_III(_, s, (RPP_NEXT(s)) jump, fix, mode, op, _o, type, g, res, data, ps) \
    ) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_III(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_ ## mode, \
        RPP_IIF(mode)( \
            RPP_REM ps RPP_TUPLE_EAT(12), \
            DETAIL_RPP_FOLD_RIGHT_AUX_X_IV \
        ) \
    )(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_IV(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    RPP_IIF(RPP_IS_CONS(res))( \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_1, RPP_REM ps RPP_TUPLE_EAT(12) \
    )(_, s, jump, fix, 1, op, _o, type, res, g, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_V(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    DETAIL_RPP_FOLD_RIGHT_AUX_X_VI(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, mode, op, _o, type, g, res, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_VI(s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_FOLD_RIGHT_AUX_X_II, DETAIL_RPP_FOLD_RIGHT_AUX_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, mode, op, _o, type, g, res, data, ps) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_0(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOLD_RIGHT_AUX_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, mode, op, _o, type, RPP_TAIL(g), RPP_CONS(res, RPP_HEAD(g)), data, ps \
    )) \
    /**/
# define DETAIL_RPP_FOLD_RIGHT_AUX_X_1(_, s, jump, fix, mode, op, _o, type, g, res, data, ps) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOLD_RIGHT_AUX_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, mode, op, _o, type, RPP_TAIL(g), res, data, (_(0, _o)()(s, op, RPP_ITEM(type, RPP_HEAD(g)) _(0, RPP_COMMA)() RPP_REM data _(0, RPP_COMMA)() RPP_REM ps)) \
    )) \
    /**/
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_FOR_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_FOR_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_PARAMETRIC(size, pred, op, macro, ...) RPP_FOR_PARAMETRIC_S(RPP_STATE(), size, pred, op, macro, __VA_ARGS__)
# else
#    define RPP_FOR_PARAMETRIC(size, pred, op, macro, state) RPP_FOR_PARAMETRIC_S(RPP_STATE(), size, pred, op, macro, state)
# endif
#
# define RPP_FOR_PARAMETRIC_ID() RPP_FOR_PARAMETRIC
#
# /* RPP_FOR_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_PARAMETRIC_S(s, size, pred, op, macro, ...) DETAIL_RPP_FOR_PARAMETRIC_U(s, size, pred, op, macro, (__VA_ARGS__))
# else
#    define RPP_FOR_PARAMETRIC_S(s, size, pred, op, macro, state) DETAIL_RPP_FOR_PARAMETRIC_U(s, size, pred, op, macro, (state))
# endif
#
# define RPP_FOR_PARAMETRIC_S_ID() RPP_FOR_PARAMETRIC_S
#
# define DETAIL_RPP_FOR_PARAMETRIC_U(s, size, pred, op, macro, ps) DETAIL_RPP_FOR_PARAMETRIC_I(RPP_NEXT(s), RPP_BUFFER_S(s, size), pred, op, macro, ps)
# define DETAIL_RPP_FOR_PARAMETRIC_I(s, buffer, pred, op, macro, ps) \
    RPP_DEFER(RPP_EXPR_S)(s)(DETAIL_RPP_FOR_PARAMETRIC_II( \
        s, s, buffer, buffer, \
        pred, RPP_CALL(pred), op, RPP_CALL(op), \
        macro, RPP_TRAMPOLINE(macro), ps \
    )) \
    /**/
# define DETAIL_RPP_FOR_PARAMETRIC_INDIRECT() DETAIL_RPP_FOR_PARAMETRIC_II
# define DETAIL_RPP_FOR_PARAMETRIC_II(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    RPP_IIF(RPP_NOT_EQUAL(buffer, RPP_LIMIT_EXPR))( \
        DETAIL_RPP_FOR_PARAMETRIC_III, DETAIL_RPP_FOR_PARAMETRIC_IV \
    )(RPP_PHASE(0), s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    /**/
# define DETAIL_RPP_FOR_PARAMETRIC_III(_, s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    _(1, RPP_IIF)(_(0, _p)()(s, pred, RPP_REM ps))( \
        _(1, RPP_EXPR_S)(s), RPP_EAT \
    )( \
        _(1, _m)()(RPP_NEXT(o), macro, RPP_REM ps) \
        _(1, DETAIL_RPP_FOR_PARAMETRIC_INDIRECT)()( \
            RPP_NEXT(s), o, RPP_NEXT(buffer), shelf, pred, _p, op, _o, macro, _m, (_(0, _o)()(s, op, RPP_REM ps)) \
        ) \
    ) \
    /**/
# define DETAIL_RPP_FOR_PARAMETRIC_IV(_, s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    _(3, RPP_EXPR_S)(o)(DETAIL_RPP_FOR_PARAMETRIC_III( \
        RPP_PHASE(2), o, o, shelf, shelf, pred, _p, op, _o, macro, _m, ps \
    )) \
    /**/
#
# endif

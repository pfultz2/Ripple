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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_SUB_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_SUB_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/logical/and.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_SUB */
#
# define RPP_SUB(x, y) RPP_SUB_BYPASS(RPP_LIMIT_EXPR, x, y)
# define RPP_SUB_ID() RPP_SUB
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_SUB_BYPASS */
#
# define RPP_SUB_BYPASS(s, x, y) \
    RPP_EXPR_S(s)(DETAIL_RPP_SUB_I(RPP_PREV(s), (RPP_PREV(s)), x, y)) \
    /**/
# define RPP_SUB_BYPASS_ID() RPP_SUB_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SUB_INDIRECT() DETAIL_RPP_SUB_I
# define DETAIL_RPP_SUB_I(s, jump, x, y) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(RPP_PREV(s))))( \
        RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
            DETAIL_RPP_SUB_II, DETAIL_RPP_SUB_III \
        ), \
        DETAIL_RPP_SUB_IV \
    )(RPP_PHASE(0), s, jump, x, y) \
    /**/
# define DETAIL_RPP_SUB_II(_, s, jump, x, y) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_SUB_III(_, s, (RPP_PREV(s)) jump, x, y) \
    ) \
    /**/
# define DETAIL_RPP_SUB_III(_, s, jump, x, y) \
    _(1, RPP_IIF)(RPP_AND(x)(y))( \
        _(1, RPP_EXPR_S)(s), x RPP_EAT \
    )( \
        _(1, DETAIL_RPP_SUB_INDIRECT)()( \
            RPP_PREV(s), jump, RPP_DEC(x), RPP_DEC(y) \
        ) \
    ) \
    /**/
# define DETAIL_RPP_SUB_IV(_, s, jump, x, y) DETAIL_RPP_SUB_V(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), x, y)
# define DETAIL_RPP_SUB_V(s, jump, x, y) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
        DETAIL_RPP_SUB_II, DETAIL_RPP_SUB_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), x, y) \
    /**/
#
# endif

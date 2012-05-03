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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_ADD_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_ADD_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/logical/bitand.h>
# include <ripple/logical/bool.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_ADD */
#
# define RPP_ADD(x, y) RPP_ADD_BYPASS(RPP_LIMIT_EXPR, x, y)
# define RPP_ADD_ID() RPP_ADD
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ADD_BYPASS */
#
# define RPP_ADD_BYPASS(s, x, y) \
    RPP_EXPR_S(s)(DETAIL_RPP_ADD_I(RPP_PREV(s), (RPP_PREV(s)), x, y)) \
    /**/
# define RPP_ADD_BYPASS_ID() RPP_ADD_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ADD_INDIRECT() DETAIL_RPP_ADD_I
# define DETAIL_RPP_ADD_I(s, jump, x, y) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(RPP_PREV(s))))( \
        RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
            DETAIL_RPP_ADD_II, DETAIL_RPP_ADD_III \
        ), \
        DETAIL_RPP_ADD_IV \
    )(RPP_PHASE(0), s, jump, x, y) \
    /**/
# define DETAIL_RPP_ADD_II(_, s, jump, x, y) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_ADD_III(_, s, (RPP_PREV(s)) jump, x, y) \
    ) \
    /**/
# define DETAIL_RPP_ADD_III(_, s, jump, x, y) \
    _(1, RPP_IIF)( \
        RPP_BITAND(RPP_NOT_EQUAL(x, RPP_LIMIT_MAG))(RPP_BOOL(y)) \
    )( \
        _(1, RPP_EXPR_S)(s), x RPP_EAT \
    )( \
        _(1, DETAIL_RPP_ADD_INDIRECT)()( \
            RPP_PREV(s), jump, RPP_INC(x), RPP_DEC(y) \
        ) \
    ) \
    /**/
# define DETAIL_RPP_ADD_IV(_, s, jump, x, y) DETAIL_RPP_ADD_V(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), x, y)
# define DETAIL_RPP_ADD_V(s, jump, x, y) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
        DETAIL_RPP_ADD_II, DETAIL_RPP_ADD_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), x, y) \
    /**/
#
# endif

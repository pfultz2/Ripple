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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MUL_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MUL_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_MUL */
#
# define RPP_MUL(x, y) RPP_MUL_BYPASS(RPP_LIMIT_EXPR, x, y)
# define RPP_MUL_ID() RPP_MUL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_MUL_BYPASS */
#
# define RPP_MUL_BYPASS(s, x, y) \
    RPP_EXPR_S(s)(DETAIL_RPP_MUL_I(RPP_PREV(s), (RPP_PREV(s)), 0, 0, x, y, 0)) \
    /**/
# define RPP_MUL_BYPASS_ID() RPP_MUL_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_MUL_INDIRECT() DETAIL_RPP_MUL_I
# define DETAIL_RPP_MUL_I(s, jump, mode, r, x, y, z) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(RPP_PREV(s))))( \
        RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
            DETAIL_RPP_MUL_II, DETAIL_RPP_MUL_ ## mode \
        ), \
        DETAIL_RPP_MUL_III \
    )(RPP_PHASE(0), s, jump, mode, r, x, y, z) \
    /**/
# define DETAIL_RPP_MUL_II(_, s, jump, mode, r, x, y, z) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_MUL_ ## mode(_, s, (RPP_PREV(s)) jump, mode, r, x, y, z) \
    ) \
    /**/
# define DETAIL_RPP_MUL_III(_, s, jump, mode, r, x, y, z) \
    DETAIL_RPP_MUL_IV(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), mode, r, x, y, z) \
    /**/
# define DETAIL_RPP_MUL_IV(s, jump, mode, r, x, y, z) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
        DETAIL_RPP_MUL_II, DETAIL_RPP_MUL_ ## mode \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), mode, r, x, y, z) \
    /**/
# define DETAIL_RPP_MUL_0(_, s, jump, mode, r, x, y, z) \
    RPP_IF(y)( \
        DETAIL_RPP_MUL_1, r RPP_TUPLE_EAT(6) \
    )(_, s, jump, mode, r, x, RPP_DEC(y), x) \
    /**/
# define DETAIL_RPP_MUL_1(_, s, jump, mode, r, x, y, z) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_MUL_INDIRECT)()( \
        RPP_PREV(s), jump, \
        RPP_TUPLE_REM_CTOR(5, RPP_IF(z)( \
            (1, RPP_INC(r), x, y, RPP_DEC(z)), \
            (0, r, x, y, 0) \
        )) \
    )) \
    /**/
#
# endif

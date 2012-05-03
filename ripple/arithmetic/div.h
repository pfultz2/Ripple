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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_DIV_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_DIV_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/less.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/debug/failure.h>
# include <ripple/facilities/binary.h>
# include <ripple/limits.h>
# include <ripple/logical/not.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_DIV */
#
# define RPP_DIV(x, y) RPP_DIV_BYPASS(RPP_LIMIT_EXPR, x, y)
# define RPP_DIV_ID() RPP_DIV
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_DIV_BYPASS */
#
# define RPP_DIV_BYPASS(s, x, y) \
    RPP_INLINE_WHEN(RPP_NOT(y))(RPP_FAILURE()) \
    RPP_EXPR_S(s)(DETAIL_RPP_DIV_I(RPP_PREV(s), (RPP_PREV(s)), 0, 0, x, y, 0, 0)) \
    /**/
# define RPP_DIV_BYPASS_ID() RPP_DIV_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_DIV_INDIRECT() DETAIL_RPP_DIV_I
# define DETAIL_RPP_DIV_I(s, jump, mode, r, x, y, z, ex) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(RPP_PREV(s))))( \
        RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
            DETAIL_RPP_DIV_II, DETAIL_RPP_DIV_ ## mode \
        ), \
        DETAIL_RPP_DIV_III \
    )(RPP_PHASE(0), s, jump, mode, r, x, y, z, ex) \
    /**/
# define DETAIL_RPP_DIV_II(_, s, jump, mode, r, x, y, z, ex) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_DIV_ ## mode(_, s, (RPP_PREV(s)) jump, mode, r, x, y, z, ex) \
    ) \
    /**/
# define DETAIL_RPP_DIV_III(_, s, jump, mode, r, x, y, z, ex) \
    DETAIL_RPP_DIV_IV(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), mode, r, x, y, z, ex) \
    /**/
# define DETAIL_RPP_DIV_IV(s, jump, mode, r, x, y, z, ex) \
    RPP_IIF(RPP_IS_VALID(RPP_PREV(s)))( \
        DETAIL_RPP_DIV_II, DETAIL_RPP_DIV_ ## mode \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), mode, r, x, y, z, ex) \
    /**/
# define DETAIL_RPP_DIV_0(_, s, jump, mode, r, x, y, z, ex) \
    RPP_IIF(RPP_LESS(x, y))( \
        RPP_BINARY(ex)(r, x) RPP_TUPLE_EAT(9), DETAIL_RPP_DIV_1 \
    )(_, s, jump, mode, RPP_INC(r), x, y, y, ex) \
    /**/
# define DETAIL_RPP_DIV_1(_, s, jump, mode, r, x, y, z, ex) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_DIV_INDIRECT)()( \
        RPP_PREV(s), jump, \
        RPP_TUPLE_REM_CTOR(5, RPP_IF(z)( \
            (1, r, RPP_DEC(x), y, RPP_DEC(z)), \
            (0, r, x, y, 0) \
        )), \
        ex \
    )) \
    /**/
#
# endif

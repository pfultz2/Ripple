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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_LITERAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_LITERAL_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/string/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_ARBITRARY_LITERAL */
#
# define RPP_ARBITRARY_LITERAL(literal) RPP_ARBITRARY_LITERAL_BYPASS(RPP_LIMIT_EXPR, literal)
# define RPP_ARBITRARY_LITERAL_ID() RPP_ARBITRARY_LITERAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARBITRARY_LITERAL_BYPASS */
#
# define RPP_ARBITRARY_LITERAL_BYPASS(s, literal) \
    RPP_IIF(RPP_IS_UNARY(literal))( \
        RPP_ARBITRARY_FIX((RPP_EXPR_S(s)(DETAIL_RPP_ARBITRARY_LITERAL_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), RPP_EAT literal \
        )))), \
        RPP_EXPR_S(s)(DETAIL_RPP_ARBITRARY_LITERAL_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), literal \
        )) \
    ) \
    /**/
# define RPP_ARBITRARY_LITERAL_BYPASS_ID() RPP_ARBITRARY_LITERAL_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_LITERAL_INDIRECT() DETAIL_RPP_ARBITRARY_LITERAL_I
# define DETAIL_RPP_ARBITRARY_LITERAL_I(_, s, literal) \
    RPP_INLINE_WHEN _(RPP_STRING_IS_CONS(literal))( \
        (RPP_STRING_HEAD _(literal)) \
        RPP_EXPR_S _(s)(DETAIL_RPP_ARBITRARY_LITERAL_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_STRING_TAIL _(literal) \
        )) \
    ) \
    /**/
#
# endif

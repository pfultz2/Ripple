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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_ENUMERATE_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_ENUMERATE_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/empty.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_ENUMERATE */
#
# define RPP_ENUMERATE(g) RPP_ENUMERATE_BYPASS(RPP_LIMIT_EXPR, g)
# define RPP_ENUMERATE_ID() RPP_ENUMERATE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ENUMERATE_BYPASS */
#
# define RPP_ENUMERATE_BYPASS(s, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_ENUMERATE_I(RPP_OBSTRUCT(), RPP_PREV(s), RPP_EMPTY, RPP_COMMA, g)) \
    /**/
# define RPP_ENUMERATE_BYPASS_ID() RPP_ENUMERATE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ENUMERATE_INDIRECT() DETAIL_RPP_ENUMERATE_I
# define DETAIL_RPP_ENUMERATE_I(_, s, sep, ss, g) \
    RPP_INLINE_WHEN _(RPP_IS_CONS(g))( \
        sep _() RPP_HEAD _(g) \
        RPP_EXPR_S(s) _(DETAIL_RPP_ENUMERATE_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), ss, ss, RPP_TAIL _(g) \
        )) \
    ) \
    /**/
#
# endif

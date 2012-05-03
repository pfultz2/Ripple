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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_REVERSE_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_REVERSE_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_REVERSE */
#
# define RPP_REVERSE(g) RPP_REVERSE_BYPASS(RPP_LIMIT_EXPR, g)
# define RPP_REVERSE_ID() RPP_REVERSE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_REVERSE_BYPASS */
#
# define RPP_REVERSE_BYPASS(s, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_REVERSE_I(RPP_OBSTRUCT(), RPP_PREV(s), RPP_NIL(RPP_TYPEOF(g)), g)) \
    /**/
# define RPP_REVERSE_BYPASS_ID() RPP_REVERSE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_REVERSE_INDIRECT() DETAIL_RPP_REVERSE_I
# define DETAIL_RPP_REVERSE_I(_, s, r, g) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_EXPR_S(s) _(DETAIL_RPP_REVERSE_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_CONS _(r, RPP_HEAD _(g)), RPP_TAIL _(g) \
        )), \
        r \
    ) \
    /**/
#
# endif

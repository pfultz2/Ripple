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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_DROP_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_DROP_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_DROP */
#
# define RPP_DROP(n, g) RPP_DROP_BYPASS(RPP_LIMIT_EXPR, n, g)
# define RPP_DROP_ID() RPP_DROP
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_DROP_BYPASS */
#
# define RPP_DROP_BYPASS(s, n, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_DROP_I(RPP_OBSTRUCT(), RPP_PREV(s), n, g)) \
    /**/
# define RPP_DROP_BYPASS_ID() RPP_DROP_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_DROP_INDIRECT() DETAIL_RPP_DROP_I
# define DETAIL_RPP_DROP_I(_, s, n, g) \
    RPP_IF _(n)( \
        RPP_EXPR_S(s) _(DETAIL_RPP_DROP_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(n), RPP_TAIL _(g) \
        )), \
        g \
    ) \
    /**/
#
# endif

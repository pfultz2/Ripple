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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_SIZE_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_SIZE_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_SIZE */
#
# define RPP_SIZE(g) RPP_SIZE_BYPASS(RPP_LIMIT_EXPR, g)
# define RPP_SIZE_ID() RPP_SIZE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_SIZE_BYPASS */
#
# define RPP_SIZE_BYPASS(s, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_SIZE_I(RPP_OBSTRUCT(), RPP_PREV(s), g, 0)) \
    /**/
# define RPP_SIZE_BYPASS_ID() RPP_SIZE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_SIZE_INDIRECT() DETAIL_RPP_SIZE_I
# define DETAIL_RPP_SIZE_I(_, s, g, size) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_EXPR_S(s) _(DETAIL_RPP_SIZE_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL _(g), RPP_INC(size) \
        )), \
        size \
    ) \
    /**/
#
# endif

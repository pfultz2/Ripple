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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_POP_BACK_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_POP_BACK_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_POP_BACK */
#
# define RPP_POP_BACK(g) RPP_POP_BACK_BYPASS(RPP_LIMIT_EXPR, g)
# define RPP_POP_BACK_ID() RPP_POP_BACK
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_POP_BACK_BYPASS */
#
# define RPP_POP_BACK_BYPASS(s, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_POP_BACK_I(RPP_OBSTRUCT(), RPP_PREV(s), g)) \
    /**/
# define RPP_POP_BACK_BYPASS_ID() RPP_POP_BACK_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_POP_BACK_INDIRECT() DETAIL_RPP_POP_BACK_I
# define DETAIL_RPP_POP_BACK_I(_, s, g) \
    RPP_IIF _(RPP_IS_CONS(RPP_TAIL(g)))( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_POP_BACK_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL(g) \
            )), \
            RPP_HEAD(g) \
        ), \
        RPP_NIL(RPP_TYPEOF(g)) \
    ) \
    /**/
        
#
# endif

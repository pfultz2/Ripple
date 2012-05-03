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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_PUSH_BACK_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_PUSH_BACK_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_PUSH_BACK */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PUSH_BACK(g, ...) RPP_PUSH_BACK_BYPASS(RPP_LIMIT_EXPR, g, __VA_ARGS__)
# else
#    define RPP_PUSH_BACK(g, x) RPP_PUSH_BACK_BYPASS(RPP_LIMIT_EXPR, g, x)
# endif
#
# define RPP_PUSH_BACK_ID() RPP_PUSH_BACK
#
# /* RPP_PUSH_BACK_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PUSH_BACK_BYPASS(s, g, ...) DETAIL_RPP_PUSH_BACK_U(s, g, (__VA_ARGS__))
# else
#    define RPP_PUSH_BACK_BYPASS(s, g, x) DETAIL_RPP_PUSH_BACK_U(s, g, (x))
# endif
#
# define RPP_PUSH_BACK_BYPASS_ID() RPP_PUSH_BACK_BYPASS
#
# define DETAIL_RPP_PUSH_BACK_U(s, g, px) \
    RPP_EXPR_S(s)(DETAIL_RPP_PUSH_BACK_I(RPP_OBSTRUCT(), RPP_PREV(s), g, px)) \
    /**/
# define DETAIL_RPP_PUSH_BACK_INDIRECT() DETAIL_RPP_PUSH_BACK_I
# define DETAIL_RPP_PUSH_BACK_I(_, s, g, px) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_PUSH_BACK_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL _(g), px \
            )), \
            RPP_HEAD _(g) \
        ), \
        RPP_CONS _(g, RPP_REM px) \
    ) \
    /**/
#
# endif

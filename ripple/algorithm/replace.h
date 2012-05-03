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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_REMOVE_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_REMOVE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_REPLACE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPLACE(i, g, ...) RPP_REPLACE_BYPASS(RPP_LIMIT_EXPR, i, g, __VA_ARGS__)
# else
#    define RPP_REPLACE(i, g, x) RPP_REPLACE_BYPASS(RPP_LIMIT_EXPR, i, g, x)
# endif
#
# define RPP_REPLACE_ID() RPP_REPLACE
#
# /* RPP_REPLACE_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REPLACE_BYPASS(s, i, g, ...) DETAIL_RPP_REPLACE_BYPASS_U(s, i, g, (__VA_ARGS__))
# else
#    define RPP_REPLACE_BYPASS(s, i, g, x) DETAIL_RPP_REPLACE_BYPASS_U(s, i, g, (x))
# endif
#
# define RPP_REPLACE_BYPASS_ID() RPP_REPLACE_BYPASS
#
# define DETAIL_RPP_REPLACE_BYPASS_U(s, i, g, px) \
    RPP_EXPR_S(s)(DETAIL_RPP_REPLACE_I(RPP_OBSTRUCT(), RPP_PREV(s), i, g, px)) \
    /**/
# define DETAIL_RPP_REPLACE_INDIRECT() DETAIL_RPP_REPLACE_I
# define DETAIL_RPP_REPLACE_I(_, s, i, g, px) \
    RPP_IF _(i)( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_REPLACE_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(i), RPP_TAIL _(g), px \
            )), \
            RPP_HEAD _(g) \
        ), \
        RPP_CONS _(RPP_TAIL _(g), RPP_REM px) \
    ) \
    /**/
#
# endif

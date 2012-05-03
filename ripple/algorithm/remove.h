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
#
# /* RPP_REMOVE */
#
# define RPP_REMOVE(i, g) RPP_REMOVE_BYPASS(RPP_LIMIT_EXPR, i, g)
# define RPP_REMOVE_ID() RPP_REMOVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_REMOVE_BYPASS */
#
# define RPP_REMOVE_BYPASS(s, i, g) \
    RPP_EXPR_S(s)(DETAIL_RPP_REMOVE_I(RPP_OBSTRUCT(), RPP_PREV(s), i, g)) \
    /**/
# define RPP_REMOVE_BYPASS_ID() RPP_REMOVE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_REMOVE_INDIRECT() DETAIL_RPP_REMOVE_I
# define DETAIL_RPP_REMOVE_I(_, s, i, g) \
    RPP_IF _(i)( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_REMOVE_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(i), RPP_TAIL _(g) \
            )), \
            RPP_HEAD _(g) \
        ), \
        RPP_TAIL _(g) \
    ) \
    /**/
#
# endif

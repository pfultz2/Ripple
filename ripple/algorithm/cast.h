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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_CAST_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_CAST_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/generics/is_type.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_CAST */
#
# define RPP_CAST(type, g) RPP_CAST_BYPASS(RPP_LIMIT_EXPR, type, g)
# define RPP_CAST_ID() RPP_CAST
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_CAST_BYPASS */
#
# define RPP_CAST_BYPASS(s, type, g) \
    RPP_IIF(RPP_IS_TYPE(type, g))( \
        g, \
        RPP_EXPR_S(s)(DETAIL_RPP_CAST_I(RPP_OBSTRUCT(), RPP_PREV(s), type, g)) \
    ) \
    /**/
# define RPP_CAST_BYPASS_ID() RPP_CAST_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_CAST_INDIRECT() DETAIL_RPP_CAST_I
# define DETAIL_RPP_CAST_I(_, s, type, g) \
    RPP_IIF _(RPP_IS_CONS(g))( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_CAST_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), type, RPP_TAIL _(g) \
            )), \
            RPP_HEAD _(g) \
        ), \
        RPP_NIL(type) \
    ) \
    /**/
#
# endif

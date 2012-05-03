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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_CONCAT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_CONCAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_CONCAT */
#
# define RPP_CONCAT(g) RPP_CONCAT_BYPASS(RPP_LIMIT_EXPR, g)
# define RPP_CONCAT_ID() RPP_CONCAT
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_CONCAT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_CONCAT_BYPASS(s, g) \
        RPP_EXPR_S(s)(DETAIL_RPP_CONCAT_I(RPP_OBSTRUCT(), RPP_PREV(s), g,)) \
        /**/
# else
#    define RPP_CONCAT_BYPASS(s, g) \
        RPP_INLINE_WHEN(RPP_IS_CONS(g))( \
            RPP_EXPR_S(s)(DETAIL_RPP_CONCAT_I(RPP_OBSTRUCT(), RPP_PREV(s), RPP_TAIL(g), RPP_HEAD(g))) \
        ) \
        /**/
# endif
#
# define RPP_CONCAT_BYPASS_ID() RPP_CONCAT_BYPASS
#
# define DETAIL_RPP_CONCAT_INDIRECT() DETAIL_RPP_CONCAT_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_CONCAT_I(_, s, g, ...) \
        RPP_IIF _(RPP_IS_CONS(g))( \
            RPP_EXPR_S(s) _(DETAIL_RPP_CONCAT_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL _(g), RPP_VARIADIC_CAT _(__VA_ARGS__, RPP_HEAD _(g)) \
            )), \
            __VA_ARGS__ \
        ) \
        /**/
# else
#    define DETAIL_RPP_CONCAT_I(_, s, g, res) \
        RPP_IIF _(RPP_IS_CONS(g))( \
            RPP_EXPR_S(s) _(DETAIL_RPP_CONCAT_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL _(g), RPP_CAT _(res, RPP_HEAD _(g)) \
            )), \
            res \
        ) \
        /**/
# endif
#
# endif

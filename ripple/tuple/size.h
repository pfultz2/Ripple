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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_SIZE_H
# define RIPPLE_PREPROCESSOR_TUPLE_SIZE_H
#
# include <ripple/arithmetic/in_range.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_empty.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
#
# /* RPP_TUPLE_QUICK_SIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_QUICK_SIZE(tuple) \
        DETAIL_RPP_TUPLE_QUICK_SIZE_I(RPP_TUPLE_BATCH_FORK(RPP_LIMIT_TUPLE, tuple)) \
        /**/
#    define RPP_TUPLE_QUICK_SIZE_ID() RPP_TUPLE_QUICK_SIZE
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_QUICK_SIZE_I(fork) \
        RPP_IIF(RPP_IS_EMPTY_NON_FUNCTION(fork))( \
            RPP_LIMIT_TUPLE, fork \
        ) \
        /**/
# endif
#
# /* RPP_TUPLE_SIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_SIZE(tuple) RPP_TUPLE_SIZE_BYPASS(RPP_LIMIT_EXPR, tuple)
#    define RPP_TUPLE_SIZE_ID() RPP_TUPLE_SIZE
# endif
#
# /* RPP_TUPLE_SIZE_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_SIZE_BYPASS(s, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_SIZE_0(RPP_OBSTRUCT(), RPP_PREV(s), tuple, 0)) \
        /**/
#    define RPP_TUPLE_SIZE_BYPASS_ID() RPP_TUPLE_SIZE_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_SIZE_INDIRECT(n) DETAIL_RPP_TUPLE_SIZE_ ## n
#    define DETAIL_RPP_TUPLE_SIZE_0(_, s, tuple, x) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(10, tuple))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_SIZE_INDIRECT _(0)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_SANS_BATCH _(10, tuple), RPP_INC(x) \
            )), \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_SIZE_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), tuple, \
                RPP_IF _(x)( \
                    RPP_IIF _(RPP_IN_RANGE _(x ## 0))( \
                        x ## 0, \
                        RPP_LIMIT_MAG \
                    ), \
                    0 \
                ) \
            )) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_SIZE_1(_, s, tuple, x) \
        RPP_IIF _(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_SIZE_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_TAIL _(tuple), RPP_INC(x) \
            )), \
            x \
        ) \
        /**/
# endif
#
# /* RPP_VARIADIC_QUICK_SIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_QUICK_SIZE(...) RPP_TUPLE_QUICK_SIZE((__VA_ARGS__))
#    define RPP_VARIADIC_QUICK_SIZE_ID() RPP_VARIADIC_QUICK_SIZE
# endif
#
# /* RPP_VARIADIC_SIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SIZE(...) RPP_TUPLE_SIZE((__VA_ARGS__))
#    define RPP_VARIADIC_SIZE_ID() RPP_VARIADIC_SIZE
# endif
#
# /* RPP_VARIADIC_SIZE_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SIZE_BYPASS(s, ...) RPP_TUPLE_SIZE_BYPASS(s, (__VA_ARGS__))
#    define RPP_VARIADIC_SIZE_BYPASS_ID() RPP_VARIADIC_SIZE_BYPASS
# endif
#
# endif

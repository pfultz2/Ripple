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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_CONCAT_H
# define RIPPLE_PREPROCESSOR_TUPLE_CONCAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
#
# /* RPP_TUPLE_CONCAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_CONCAT(tuple) RPP_TUPLE_CONCAT_BYPASS(RPP_LIMIT_EXPR, tuple)
#    define RPP_TUPLE_CONCAT_ID() RPP_TUPLE_CONCAT
# endif
#
# /* RPP_TUPLE_CONCAT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_CONCAT_BYPASS(s, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_CONCAT_0( \
                RPP_OBSTRUCT(), RPP_PREV(s), tuple, \
            ) \
        ) \
        /**/
#    define RPP_TUPLE_CONCAT_BYPASS_ID() RPP_TUPLE_CONCAT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_CONCAT_INDIRECT(n) DETAIL_RPP_TUPLE_CONCAT_ ## n
#    define DETAIL_RPP_TUPLE_CONCAT_0(_, s, tuple, res) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(10, tuple))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_CONCAT_INDIRECT _(0)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_SANS_BATCH _(10, tuple), RPP_CAT _(res, RPP_EXPR_S _(s)(RPP_VARIADIC_CAT RPP_TUPLE_BATCH _(10, tuple))) \
            )), \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_CONCAT_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), tuple, res \
            )) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_CONCAT_1(_, s, tuple, res) \
        RPP_IIF _(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_CONCAT_INDIRECT _(1)( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_TAIL _(tuple), RPP_CAT _(res, RPP_TUPLE_HEAD _(tuple)) \
            )), \
            res \
        ) \
        /**/
# endif
#
# endif

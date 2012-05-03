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
# ifndef RIPPLE_PREPROCESSOR_STRING_COMPARE_H
# define RIPPLE_PREPROCESSOR_STRING_COMPARE_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/compare.h>
# include <ripple/limits.h>
# include <ripple/logical/compl.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/string/core.h>
#
# /* RPP_STRING_COMPARE */
#
# define RPP_STRING_COMPARE(a, b) RPP_STRING_COMPARE_BYPASS(RPP_LIMIT_EXPR, a, b)
# define RPP_STRING_COMPARE_ID() RPP_STRING_COMPARE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_COMPARE_BYPASS */
#
# define RPP_STRING_COMPARE_BYPASS(s, a, b) \
    RPP_EXPR_S(s)(DETAIL_RPP_STRING_COMPARE_I( \
        RPP_OBSTRUCT(), RPP_PREV(s), a, b \
    )) \
    /**/
# define RPP_STRING_COMPARE_BYPASS_ID() RPP_STRING_COMPARE_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_STRING_COMPARE_INDIRECT() DETAIL_RPP_STRING_COMPARE_I
# define DETAIL_RPP_STRING_COMPARE_I(_, s, a, b) \
    RPP_IIF _(RPP_STRING_IS_CONS(a))( \
        RPP_IIF _(RPP_STRING_IS_CONS _(b))( \
            RPP_IIF _(RPP_COMPARE _(RPP_STRING_HEAD _(a), RPP_STRING_HEAD _(b)))( \
                RPP_EXPR_S _(s)(DETAIL_RPP_STRING_COMPARE_INDIRECT _()( \
                    RPP_OBSTRUCT _(), RPP_PREV(s), RPP_STRING_TAIL _(a), RPP_STRING_TAIL _(b) \
                )), \
                0 \
            ), \
            0 \
        ), \
        RPP_COMPL _(RPP_STRING_IS_CONS _(b)) \
    ) \
    /**/
#
# endif

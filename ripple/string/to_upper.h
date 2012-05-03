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
# ifndef RIPPLE_PREPROCESSOR_STRING_TO_UPPER_H
# define RIPPLE_PREPROCESSOR_STRING_TO_UPPER_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/split.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/string/core.h>
# include <ripple/string/to_lower.h>
#
# /* RPP_TO_UPPER */
#
# define RPP_TO_UPPER(c) RPP_SPLIT(1, RPP_PRIMITIVE_CAT(DETAIL_RPP_TO_LOWER_, c))
# define RPP_TO_UPPER_ID() RPP_TO_UPPER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_TO_UPPER */
#
# define RPP_STRING_TO_UPPER(string) RPP_STRING_TO_UPPER_BYPASS(RPP_LIMIT_EXPR, string)
# define RPP_STRING_TO_UPPER_ID() RPP_STRING_TO_UPPER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_TO_UPPER_BYPASS */
#
# define RPP_STRING_TO_UPPER_BYPASS(s, string) \
    RPP_EXPR_S(s)(DETAIL_RPP_STRING_TO_UPPER_I( \
        RPP_OBSTRUCT(), RPP_PREV(s), string \
    )) \
    /**/
# define RPP_STRING_TO_UPPER_BYPASS_ID() RPP_STRING_TO_UPPER_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_STRING_TO_UPPER_INDIRECT() DETAIL_RPP_STRING_TO_UPPER_I
# define DETAIL_RPP_STRING_TO_UPPER_I(_, s, string) \
    RPP_INLINE_WHEN _(RPP_STRING_IS_CONS(string))( \
        RPP_TO_UPPER _(RPP_STRING_HEAD _(string)) \
        RPP_EXPR_S(s) _(DETAIL_RPP_STRING_TO_UPPER_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_STRING_TAIL _(string) \
        )) \
    ) \
    /**/
#
# endif

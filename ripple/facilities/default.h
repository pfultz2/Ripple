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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_DEFAULT_H
# define RIPPLE_PREPROCESSOR_FACILITIES_DEFAULT_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_DEFAULT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DEFAULT(def, ...) \
        RPP_IIF(RPP_IS_OPTIONAL(__VA_ARGS__))( \
            def, RPP_NON_OPTIONAL(RPP_OPTIONAL(__VA_ARGS__)) \
        ) \
        /**/
#    define RPP_DEFAULT_ID() RPP_DEFAULT
# endif
#
# /* RPP_DEFAULT_AT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DEFAULT_AT(i, def, ...) RPP_DEFAULT_AT_BYPASS(RPP_LIMIT_EXPR, i, def, __VA_ARGS__)
#    define RPP_DEFAULT_AT_ID() RPP_DEFAULT_AT
# endif
#
# /* RPP_DEFAULT_AT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DEFAULT_AT_BYPASS(s, i, def, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_DEFAULT_AT_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), i, def, __VA_ARGS__ \
        ))
        /**/
#    define RPP_DEFAULT_AT_BYPASS_ID() RPP_DEFAULT_AT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_DEFAULT_AT_INDIRECT() DETAIL_RPP_DEFAULT_AT_I
#    define DETAIL_RPP_DEFAULT_AT_I(_, s, i, def, ...) \
        RPP_IF _(i)( \
            RPP_EXPR_S(s) _(DETAIL_RPP_DEFAULT_AT_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(i), def, RPP_OPTIONAL _(__VA_ARGS__) \
            )), \
            RPP_DEFAULT _(def, __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif

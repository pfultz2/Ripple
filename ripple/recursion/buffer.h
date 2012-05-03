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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_BUFFER_H
# define RIPPLE_PREPROCESSOR_RECURSION_BUFFER_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_BUFFER */
#
# define RPP_BUFFER(size) RPP_BUFFER_S(RPP_STATE(), size)
# define RPP_BUFFER_ID() RPP_BUFFER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_BUFFER_S */
#
# define RPP_BUFFER_S(s, size) \
    RPP_EXPR_S(s)(DETAIL_RPP_BUFFER_I(RPP_OBSTRUCT(), RPP_NEXT(s), size)) \
    /**/
# define RPP_BUFFER_S_ID() RPP_BUFFER_S
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BUFFER_INDIRECT() DETAIL_RPP_BUFFER_I
# define DETAIL_RPP_BUFFER_I(_, s, size) \
    RPP_IF _(size)( \
        RPP_EXPR_S(s) _(DETAIL_RPP_BUFFER_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_DEC(size) \
        )), \
        RPP_PREV(s) \
    ) \
    /**/
#
# /* RPP_FIXED */
#
# define RPP_FIXED(size) RPP_FIXED_S(RPP_STATE(), size)
# define RPP_FIXED_ID() RPP_FIXED
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_FIXED_S */
#
# define RPP_FIXED_S(s, size) \
    RPP_EXPR_S(s)(DETAIL_RPP_FIXED_I(RPP_OBSTRUCT(), RPP_NEXT(s), size, RPP_LIMIT_EXPR)) \
    /**/
# define RPP_FIXED_S_ID() RPP_FIXED_S
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_FIXED_INDIRECT() DETAIL_RPP_FIXED_I
# define DETAIL_RPP_FIXED_I(_, s, size, res) \
    RPP_IF _(size)( \
        RPP_EXPR_S(s) _(DETAIL_RPP_FIXED_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_NEXT(s), RPP_DEC(size), RPP_PREV(res) \
        )), \
        res \
    ) \
    /**/
#
# endif

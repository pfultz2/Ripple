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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MOD_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MOD_H
#
# include <ripple/arithmetic/div.h>
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/debug/failure.h>
# include <ripple/limits.h>
# include <ripple/logical/not.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_MOD */
#
# define RPP_MOD(x, y) RPP_MOD_BYPASS(RPP_LIMIT_EXPR, x, y)
# define RPP_MOD_ID() RPP_MOD
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_MOD_BYPASS */
#
# define RPP_MOD_BYPASS(s, x, y) \
    RPP_INLINE_WHEN(RPP_NOT(y))(RPP_FAILURE()) \
    RPP_EXPR_S(s)(DETAIL_RPP_DIV_I(RPP_PREV(s), (RPP_PREV(s)), 0, 0, x, y, 0, 1)) \
    /**/
# define RPP_MOD_BYPASS_ID() RPP_MOD_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

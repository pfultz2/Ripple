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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_XNOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_XNOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
# include <ripple/logical/not.h>
#
# /* RPP_XNOR */
#
# define RPP_XNOR(p) RPP_CAT(DETAIL_RPP_XNOR_, RPP_BOOL(p))
# define RPP_XNOR_ID() RPP_XNOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_XNOR_0(q) RPP_NOT(q)
# define DETAIL_RPP_XNOR_1(q) RPP_BOOL(q)
#
# endif

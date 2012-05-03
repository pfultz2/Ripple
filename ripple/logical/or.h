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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_OR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_OR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
#
# /* RPP_OR */
#
# define RPP_OR(p) RPP_CAT(DETAIL_RPP_OR_, RPP_BOOL(p))
# define RPP_OR_ID() RPP_OR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_OR_0(q) RPP_BOOL(q)
# define DETAIL_RPP_OR_1(q) 1
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_AND_H
# define RIPPLE_PREPROCESSOR_LOGICAL_AND_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
#
# /* RPP_AND */
#
# define RPP_AND(p) RPP_CAT(DETAIL_RPP_AND_, RPP_BOOL(p))
# define RPP_AND_ID() RPP_AND
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_AND_0(q) 0
# define DETAIL_RPP_AND_1(q) RPP_BOOL(q)
#
# endif

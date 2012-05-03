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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_NOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_NOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
# include <ripple/logical/not.h>
#
# /* RPP_NOR */
#
# define RPP_NOR(p) RPP_CAT(DETAIL_RPP_NOR_, RPP_BOOL(p))
# define RPP_NOR_ID() RPP_NOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_NOR_0(q) RPP_NOT(q)
# define DETAIL_RPP_NOR_1(q) 0
#
# endif

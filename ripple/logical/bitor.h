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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BITOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BITOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_BITOR */
#
# define RPP_BITOR(x) RPP_PRIMITIVE_CAT(DETAIL_RPP_BITOR_, x)
# define RPP_BITOR_ID() RPP_BITOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BITOR_0(y) y
# define DETAIL_RPP_BITOR_1(y) 1
#
# endif

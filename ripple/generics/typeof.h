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
# ifndef RIPPLE_PREPROCESSOR_GENERICS_TYPEOF_H
# define RIPPLE_PREPROCESSOR_GENERICS_TYPEOF_H
#
# include <ripple/config.h>
# include <ripple/facilities/split.h>
#
# /* RPP_TYPEOF */
#
# define RPP_TYPEOF(g) RPP_SPLIT_SHADOW(0, DETAIL_RPP_TYPEOF_I g)
# define RPP_TYPEOF_ID() RPP_TYPEOF
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_TYPEOF_I(type) type, ~
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_NOT_H
# define RIPPLE_PREPROCESSOR_LOGICAL_NOT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
#
# /* RPP_NOT */
#
# define RPP_NOT(x) RPP_IS_NULLARY(RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_NOT_, x))
# define RPP_NOT_ID() RPP_NOT
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_NOT_0 ()
#
# endif

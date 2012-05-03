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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_MIN_H
# define RIPPLE_PREPROCESSOR_COMPARISON_MIN_H
#
# include <ripple/config.h>
# include <ripple/comparison/less.h>
# include <ripple/control/iif.h>
#
# /* RPP_MIN */
#
# define RPP_MIN(x, y) RPP_IIF(RPP_LESS(y, x))(y, x)
# define RPP_MIN_ID() RPP_MIN
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

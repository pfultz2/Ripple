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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_GREATER_H
# define RIPPLE_PREPROCESSOR_COMPARISON_GREATER_H
#
# include <ripple/comparison/less.h>
# include <ripple/config.h>
#
# /* RPP_GREATER */
#
# define RPP_GREATER(x, y) RPP_LESS(y, x)
# define RPP_GREATER_ID() RPP_GREATER
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

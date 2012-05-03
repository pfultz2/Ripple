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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_MAX_H
# define RIPPLE_PREPROCESSOR_COMPARISON_MAX_H
#
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
#
# /* RPP_MAX */
#
# define RPP_MAX(x, y) RPP_IIF(RPP_LESS(x, y))(y, x)
# define RPP_MAX_ID() RPP_MAX
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

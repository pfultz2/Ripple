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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_UNLESS_H
# define RIPPLE_PREPROCESSOR_CONTROL_UNLESS_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/logical/not.h>
#
# /* RPP_UNLESS */
#
# define RPP_UNLESS(cond) RPP_INLINE_WHEN(RPP_NOT(cond))
# define RPP_UNLESS_ID() RPP_UNLESS
#
# if CONFIG_RIPPLE_STD
#    define RPP_UNLESS_ CONFIG_RIPPLE_STD(RPP_UNLESS)
# endif
#
# endif

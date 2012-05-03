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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_WHEN_H
# define RIPPLE_PREPROCESSOR_CONTROL_WHEN_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/logical/bool.h>
#
# /* RPP_WHEN */
#
# define RPP_WHEN(cond) RPP_INLINE_WHEN(RPP_BOOL(cond))
# define RPP_WHEN_ID() RPP_WHEN
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

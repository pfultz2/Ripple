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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_IF_H
# define RIPPLE_PREPROCESSOR_CONTROL_IF_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/logical/bool.h>
#
# /* RPP_IF */
#
# define RPP_IF(cond) RPP_IIF(RPP_BOOL(cond))
# define RPP_IF_ID() RPP_IF
#
# if CONFIG_RIPPLE_STD
# endif
#
# define RPP_IF_SHADOW(cond) RPP_IIF_SHADOW(RPP_BOOL(cond))
#
# endif

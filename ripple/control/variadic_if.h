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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_VARIADIC_IF_H
# define RIPPLE_PREPROCESSOR_CONTROL_VARIADIC_IF_H
#
# include <ripple/config.h>
# include <ripple/control/variadic_iif.h>
# include <ripple/logical/bool.h>
#
# /* RPP_VARIADIC_IF */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_IF(cond) RPP_VARIADIC_IIF(RPP_BOOL(cond))
#    define RPP_VARIADIC_IF_ID() RPP_VARIADIC_IF
# endif
#
# endif

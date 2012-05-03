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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_INCLUDE_IF_H
# define RIPPLE_PREPROCESSOR_CONTROL_INCLUDE_IF_H
#
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/null.h>
#
# /* RPP_INCLUDE_IF */
#
# define RPP_INCLUDE_IF(cond, file) RPP_IF(cond)(file, RPP_NULL())
# define RPP_INCLUDE_IF_ID() RPP_INCLUDE_IF
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

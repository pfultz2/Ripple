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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BOOL_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BOOL_H
#
# include <ripple/config.h>
# include <ripple/logical/compl.h>
# include <ripple/logical/not.h>
#
# /* RPP_BOOL */
#
# define RPP_BOOL(x) RPP_COMPL(RPP_NOT(x))
# define RPP_BOOL_ID() RPP_BOOL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

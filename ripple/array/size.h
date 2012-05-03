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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_SIZE_H
# define RIPPLE_PREPROCESSOR_ARRAY_SIZE_H
#
# include <ripple/config.h>
# include <ripple/facilities/split.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARRAY_SIZE */
#
# define RPP_ARRAY_SIZE(array) RPP_SPLIT(0, RPP_TUPLE_REM(2) array)
# define RPP_ARRAY_SIZE_ID() RPP_ARRAY_SIZE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

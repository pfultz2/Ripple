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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_TO_TUPLE_H
# define RIPPLE_PREPROCESSOR_ARRAY_TO_TUPLE_H
#
# include <ripple/config.h>
# include <ripple/facilities/split.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARRAY_TO_TUPLE */
#
# define RPP_ARRAY_TO_TUPLE(array) RPP_SPLIT(1, RPP_TUPLE_REM(2) array)
# define RPP_ARRAY_TO_TUPLE_ID() RPP_ARRAY_TO_TUPLE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

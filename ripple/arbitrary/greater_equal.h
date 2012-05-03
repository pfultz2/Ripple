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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_GREATER_EQUAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_GREATER_EQUAL_H
#
# include <ripple/arbitrary/less_equal.h>
# include <ripple/config.h>
#
# /* RPP_ARBITRARY_GREATER_EQUAL */
#
# define RPP_ARBITRARY_GREATER_EQUAL(x, y) RPP_ARBITRARY_LESS_EQUAL(y, x)
# define RPP_ARBITRARY_GREATER_EQUAL_ID() RPP_ARBITRARY_GREATER_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARBITRARY_GREATER_EQUAL_INTERNAL */
#
# define RPP_ARBITRARY_GREATER_EQUAL_INTERNAL(x, y) RPP_ARBITRARY_LESS_EQUAL_INTERNAL(y, x)
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_GREATER_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_GREATER_H
#
# include <ripple/arbitrary/less_equal.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_ARBITRARY_GREATER */
#
# define RPP_ARBITRARY_GREATER(x, y) RPP_COMPL(RPP_ARBITRARY_LESS_EQUAL(x, y))
# define RPP_ARBITRARY_GREATER_ID() RPP_ARBITRARY_GREATER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARBITRARY_GREATER_INTERNAL */
#
# define RPP_ARBITRARY_GREATER_INTERNAL(x, y) RPP_COMPL(RPP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y))
#
# endif

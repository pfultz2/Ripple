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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_NOT_EQUAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_NOT_EQUAL_H
#
# include <ripple/arbitrary/equal.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_ARBITRARY_NOT_EQUAL */
#
# define RPP_ARBITRARY_NOT_EQUAL(x, y) RPP_COMPL(RPP_ARBITRARY_EQUAL(x, y))
# define RPP_ARBITRARY_NOT_EQUAL_ID() RPP_ARBITRARY_NOT_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARBITRARY_NOT_EQUAL_INTERNAL */
#
# define RPP_ARBITRARY_NOT_EQUAL_INTERNAL(x, y) RPP_COMPL(RPP_ARBITRARY_EQUAL_INTERNAL(x, y))
#
# endif

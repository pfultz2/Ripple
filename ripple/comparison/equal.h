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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_EQUAL_H
# define RIPPLE_PREPROCESSOR_COMPARISON_EQUAL_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_EQUAL */
#
# define RPP_EQUAL(x, y) RPP_COMPL(RPP_NOT_EQUAL(x, y))
# define RPP_EQUAL_ID() RPP_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

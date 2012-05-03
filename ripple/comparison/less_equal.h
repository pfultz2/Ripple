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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_LESS_EQUAL_H
# define RIPPLE_PREPROCESSOR_COMPARISON_LESS_EQUAL_H
#
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_LESS_EQUAL */
#
# define RPP_LESS_EQUAL(x, y) RPP_COMPL(RPP_LESS(y, x))
# define RPP_LESS_EQUAL_ID() RPP_LESS_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

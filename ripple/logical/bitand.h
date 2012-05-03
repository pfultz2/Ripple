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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BITAND_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BITAND_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_BITAND */
#
# define RPP_BITAND(x) RPP_PRIMITIVE_CAT(DETAIL_RPP_BITAND_, x)
# define RPP_BITAND_ID() RPP_BITAND
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BITAND_0(y) 0
# define DETAIL_RPP_BITAND_1(y) y
#
# endif

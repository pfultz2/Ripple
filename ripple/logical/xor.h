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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_XOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_XOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
# include <ripple/logical/not.h>
#
# /* RPP_XOR */
#
# define RPP_XOR(p) RPP_CAT(DETAIL_RPP_XOR_, RPP_BOOL(p))
# define RPP_XOR_ID() RPP_XOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_XOR_0(q) RPP_BOOL(q)
# define DETAIL_RPP_XOR_1(q) RPP_NOT(q)
#
# endif

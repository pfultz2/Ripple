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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_NAND_H
# define RIPPLE_PREPROCESSOR_LOGICAL_NAND_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
# include <ripple/logical/not.h>
#
# /* RPP_NAND */
#
# define RPP_NAND(p) RPP_CAT(DETAIL_RPP_NAND_, RPP_BOOL(p))
# define RPP_NAND_ID() RPP_NAND
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_NAND_0(q) 1
# define DETAIL_RPP_NAND_1(q) RPP_NOT(q)
#
# endif

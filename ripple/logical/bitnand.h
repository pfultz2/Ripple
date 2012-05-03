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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BITNAND_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BITNAND_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_BITNAND */
#
# define RPP_BITNAND(x) RPP_PRIMITIVE_CAT(DETAIL_RPP_BITNAND_, x)
# define RPP_BITNAND_ID() RPP_BITNAND
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BITNAND_0(y) 1
# define DETAIL_RPP_BITNAND_1(y) RPP_COMPL(y)
#
# endif

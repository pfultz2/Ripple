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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BITNOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BITNOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_BITNOR */
#
# define RPP_BITNOR(x) RPP_PRIMITIVE_CAT(DETAIL_RPP_BITNOR_, x)
# define RPP_BITNOR_ID() RPP_BITNOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BITNOR_0(y) RPP_COMPL(y)
# define DETAIL_RPP_BITNOR_1(y) 0
#
# endif

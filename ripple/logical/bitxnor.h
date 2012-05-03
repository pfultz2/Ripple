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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_BITXNOR_H
# define RIPPLE_PREPROCESSOR_LOGICAL_BITXNOR_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/compl.h>
#
# /* RPP_BITXNOR */
#
# define RPP_BITXNOR(x) RPP_PRIMITIVE_CAT(DETAIL_RPP_BITXNOR_, x)
# define RPP_BITXNOR_ID() RPP_BITXOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BITXNOR_0(y) RPP_COMPL(y)
# define DETAIL_RPP_BITXNOR_1(y) y
#
# endif

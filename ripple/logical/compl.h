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
# ifndef RIPPLE_PREPROCESSOR_LOGICAL_COMPL_H
# define RIPPLE_PREPROCESSOR_LOGICAL_COMPL_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_COMPL */
#
# define RPP_COMPL(bit) RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_COMPL_, bit)
# define RPP_COMPL_ID() RPP_COMPL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_COMPL_0 1
# define DETAIL_RPP_COMPL_1 0
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_VARIADIC_IIF_H
# define RIPPLE_PREPROCESSOR_CONTROL_VARIADIC_IIF_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_VARIADIC_IIF */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_IIF(bit) RPP_PRIMITIVE_CAT(DETAIL_RPP_VARIADIC_IIF_, bit)
#    define RPP_VARIADIC_IIF_ID() RPP_VARIADIC_IIF
#    define DETAIL_RPP_VARIADIC_IIF_0(...) RPP_REM
#    define DETAIL_RPP_VARIADIC_IIF_1(...) __VA_ARGS__ RPP_EAT
# endif
#
# endif

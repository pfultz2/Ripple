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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_IIF_H
# define RIPPLE_PREPROCESSOR_CONTROL_IIF_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_IIF */
#
# define RPP_IIF(bit) RPP_PRIMITIVE_CAT(DETAIL_RPP_IIF_, bit)
# define RPP_IIF_ID() RPP_IIF
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_IIF_0(t, ...) __VA_ARGS__
#    define DETAIL_RPP_IIF_1(t, ...) t
# else
#    define DETAIL_RPP_IIF_0(t, f) f
#    define DETAIL_RPP_IIF_1(t, f) t
# endif
#
# define RPP_IIF_SHADOW(bit) RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_IIF_SHADOW_, bit)
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_IIF_SHADOW_0(t, ...) __VA_ARGS__
#    define DETAIL_RPP_IIF_SHADOW_1(t, ...) t
# else
#    define DETAIL_RPP_IIF_SHADOW_0(t, f) f
#    define DETAIL_RPP_IIF_SHADOW_1(t, f) t
# endif
#
# endif

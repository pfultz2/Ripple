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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_SPLIT_H
# define RIPPLE_PREPROCESSOR_FACILITIES_SPLIT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_SPLIT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SPLIT(i, ...) RPP_PRIMITIVE_CAT(DETAIL_RPP_SPLIT_, i)(__VA_ARGS__)
# else
#    define RPP_SPLIT(i, im) RPP_PRIMITIVE_CAT(DETAIL_RPP_SPLIT_, i)(im)
# endif
#
# define RPP_SPLIT_ID() RPP_SPLIT
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SPLIT_0(a, ...) a
#    define DETAIL_RPP_SPLIT_1(a, ...) __VA_ARGS__
# else
#    define DETAIL_RPP_SPLIT_0(a, b) a
#    define DETAIL_RPP_SPLIT_1(a, b) b
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_SPLIT_SHADOW(i, ...) RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_SPLIT_SHADOW_, i)(__VA_ARGS__)
# else
#    define RPP_SPLIT_SHADOW(i, im) RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_SPLIT_SHADOW_, i)(im)
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SPLIT_SHADOW_0(a, ...) a
#    define DETAIL_RPP_SPLIT_SHADOW_1(a, ...) __VA_ARGS__
# else
#    define DETAIL_RPP_SPLIT_SHADOW_0(a, b) a
#    define DETAIL_RPP_SPLIT_SHADOW_1(a, b) b
# endif
#
# endif

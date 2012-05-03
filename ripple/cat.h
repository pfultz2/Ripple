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
# ifndef RIPPLE_PREPROCESSOR_CAT_H
# define RIPPLE_PREPROCESSOR_CAT_H
#
# include <ripple/config.h>
#
# /* RPP_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_CAT(a, ...) RPP_PRIMITIVE_CAT(a, __VA_ARGS__)
# else
#    define RPP_CAT(a, ...) RPP_PRIMITIVE_CAT((a, __VA_ARGS__))
#    define RPP_CAT_I(x) RPP_PRIMITIVE_CAT x
# endif
#
# define RPP_CAT_ID() RPP_CAT
#
# if CONFIG_RIPPLE_STD
#    define RPP_CAT_SHADOW(a, ...) RPP_PRIMITIVE_CAT_SHADOW(a, __VA_ARGS__)
# else
#    define RPP_CAT_SHADOW(a, ...) RPP_CAT_SHADOW_I((a, __VA_ARGS__))
#    define RPP_CAT_SHADOW_I(x) RPP_PRIMITIVE_CAT_SHADOW x
# endif
#
# /* RPP_PRIMITIVE_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
# else
#    define RPP_PRIMITIVE_CAT(a, ...) RPP_PRIMITIVE_CAT_RES(a ## __VA_ARGS__)
#    define RPP_PRIMITIVE_CAT_RES(...) RPP_PRIMITIVE_CAT_RES_I((__VA_ARGS__))
#    define RPP_PRIMITIVE_CAT_RES_I(x) RPP_PRIMITIVE_CAT_RES_II x
#    define RPP_PRIMITIVE_CAT_RES_II(...) __VA_ARGS__
# endif
#
# define RPP_PRIMITIVE_CAT_ID() RPP_PRIMITIVE_CAT
#
# if CONFIG_RIPPLE_STD
#    define RPP_PRIMITIVE_CAT_SHADOW(a, ...) a ## __VA_ARGS__
# else
#    define RPP_PRIMITIVE_CAT_SHADOW(a, ...)  RPP_PRIMITIVE_CAT_SHADOW_RES(a ## __VA_ARGS__)
#    define RPP_PRIMITIVE_CAT_SHADOW_RES(...) RPP_PRIMITIVE_CAT_SHADOW_RES_I((__VA_ARGS__))
#    define RPP_PRIMITIVE_CAT_SHADOW_RES_I(x) RPP_PRIMITIVE_CAT_SHADOW_RES_II x
#    define RPP_PRIMITIVE_CAT_SHADOW_RES_II(...) __VA_ARGS__
# endif
#
# endif

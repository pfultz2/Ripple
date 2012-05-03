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
# ifndef RIPPLE_PREPROCESSOR_USTRINGIZE_H
# define RIPPLE_PREPROCESSOR_USTRINGIZE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_USTRINGIZE */
#
# ifdef __cplusplus
#
#    define RPP_USTRINGIZE(n) RPP_PRIMITIVE_CAT(DETAIL_RPP_USTRINGIZE_, n)
#    define RPP_USTRINGIZE_ID() RPP_USTRINGIZE
#
#    if CONFIG_RIPPLE_STD
#        define DETAIL_RPP_USTRINGIZE_8(...) DETAIL_RPP_PRIMITIVE_USTRINGIZE_8(__VA_ARGS__)
#        define DETAIL_RPP_USTRINGIZE_16(...) DETAIL_RPP_PRIMITIVE_USTRINGIZE_16(__VA_ARGS__)
#        define DETAIL_RPP_USTRINGIZE_32(...) DETAIL_RPP_PRIMITIVE_USTRINGIZE_32(__VA_ARGS__)
#    else
#        define DETAIL_RPP_USTRINGIZE_8(x) DETAIL_RPP_PRIMITIVE_USTRINGIZE_8(x)
#        define DETAIL_RPP_USTRINGIZE_16(x) DETAIL_RPP_PRIMITIVE_USTRINGIZE_16(x)
#        define DETAIL_RPP_USTRINGIZE_32(x) DETAIL_RPP_PRIMITIVE_USTRINGIZE_32(x)
#    endif
#
# endif
#
# /* RPP_PRIMITIVE_USTRINGIZE */
#
# ifdef __cplusplus
#
#    define RPP_PRIMITIVE_USTRINGIZE(n) RPP_PRIMITIVE_CAT(DETAIL_RPP_PRIMITIVE_USTRINGIZE_, n)
#    define RPP_PRIMITIVE_USTRINGIZE_ID() RPP_PRIMITIVE_USTRINGIZE
#
#    if CONFIG_RIPPLE_STD
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_8(...) RPP_PRIMITIVE_CAT(u8, #__VA_ARGS__)
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_16(...) RPP_PRIMITIVE_CAT(u, #__VA_ARGS__)
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_32(...) RPP_PRIMITIVE_CAT(U, #__VA_ARGS__)
#    else
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_8(x) RPP_PRIMITIVE_CAT(u8, #x)
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_16(x) RPP_PRIMITIVE_CAT(u, #x)
#        define DETAIL_RPP_PRIMITIVE_USTRINGIZE_32(x) RPP_PRIMITIVE_CAT(U, #x)
#    endif
#
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_WSTRINGIZE_H
# define RIPPLE_PREPROCESSOR_WSTRINGIZE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_WSTRINGIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WSTRINGIZE(...) RPP_PRIMITIVE_WSTRINGIZE(__VA_ARGS__)
# else
#    define RPP_WSTRINGIZE(x) RPP_PRIMITIVE_WSTRINGIZE(x)
# endif
#
# define RPP_WSTRINGIZE_ID() RPP_WSTRINGIZE
#
# /* RPP_PRIMITIVE_WSTRINGIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PRIMITIVE_WSTRINGIZE(...) RPP_PRIMITIVE_CAT(L, #__VA_ARGS__)
# else
#    define RPP_PRIMITIVE_WSTRINGIZE(x) RPP_PRIMITIVE_CAT(L, #x)
# endif
#
# define RPP_PRIMITIVE_WSTRINGIZE_ID() RPP_PRIMITIVE_WSTRINGIZE
#
# endif

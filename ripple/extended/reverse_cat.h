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
# ifndef RIPPLE_PREPROCESSOR_EXTENDED_REVERSE_CAT_H
# define RIPPLE_PREPROCESSOR_EXTENDED_REVERSE_CAT_H
#
# include <ripple/config.h>
#
# /* RPP_REVERSE_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REVERSE_CAT(a, ...) RPP_PRIMITIVE_REVERSE_CAT(a, __VA_ARGS__)
# else
#    define RPP_REVERSE_CAT(a, b) RPP_PRIMITIVE_REVERSE_CAT(a, b)
# endif
#
# define RPP_REVERSE_CAT_ID() RPP_REVERSE_CAT
#
# /* RPP_PRIMITIVE_REVERSE_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PRIMITIVE_REVERSE_CAT(a, ...) __VA_ARGS__ ## a
# else
#    define RPP_PRIMITIVE_REVERSE_CAT(a, b) b ## a
# endif
#
# define RPP_PRIMITIVE_REVERSE_CAT_ID() RPP_PRIMITIVE_REVERSE_CAT
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_BINARY_H
# define RIPPLE_PREPROCESSOR_FACILITIES_BINARY_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_BINARY */
#
# define RPP_BINARY(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_BINARY_, i)
# define RPP_BINARY_ID() RPP_BINARY
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_BINARY_0(a, ...) a
#    define DETAIL_RPP_BINARY_1(a, ...) __VA_ARGS__
# else
#    define DETAIL_RPP_BINARY_0(a, b) a
#    define DETAIL_RPP_BINARY_1(a, b) b
# endif
#
# /* RPP_BINARY_CTOR */
#
# define RPP_BINARY_CTOR(i, bin) RPP_BINARY(i) bin
# define RPP_BINARY_CTOR_ID() RPP_BINARY_CTOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

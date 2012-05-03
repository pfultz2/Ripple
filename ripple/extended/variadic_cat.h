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
# ifndef RIPPLE_PREPROCESSOR_EXTENDED_VARIADIC_CAT_H
# define RIPPLE_PREPROCESSOR_EXTENDED_VARIADIC_CAT_H
#
# include <ripple/config.h>
#
# /* RPP_VARIADIC_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_CAT(...) DETAIL_RPP_VARIADIC_CAT_I(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,)
#    define RPP_VARIADIC_CAT_ID() RPP_VARIADIC_CAT
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_VARIADIC_CAT_I(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) \
        a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## n ## o ## p ## q ## r ## s ## t ## u ## v ## w ## x ## y \
        /**/
# endif
#
# endif

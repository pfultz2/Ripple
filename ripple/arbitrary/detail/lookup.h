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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_LOOKUP_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_LOOKUP_H
#
# include <ripple/cat.h>
#
# /* RPP_ARBITRARY_LOOKUP */
#
# define RPP_ARBITRARY_LOOKUP(n, tuple) RPP_PRIMITIVE_CAT(DETAIL_RPP_ARBITRARY_LOOKUP_, n) tuple
#
# define DETAIL_RPP_ARBITRARY_LOOKUP_0(a, b, c, d, e, f, g, h, i, j) a
# define DETAIL_RPP_ARBITRARY_LOOKUP_1(a, b, c, d, e, f, g, h, i, j) b
# define DETAIL_RPP_ARBITRARY_LOOKUP_2(a, b, c, d, e, f, g, h, i, j) c
# define DETAIL_RPP_ARBITRARY_LOOKUP_3(a, b, c, d, e, f, g, h, i, j) d
# define DETAIL_RPP_ARBITRARY_LOOKUP_4(a, b, c, d, e, f, g, h, i, j) e
# define DETAIL_RPP_ARBITRARY_LOOKUP_5(a, b, c, d, e, f, g, h, i, j) f
# define DETAIL_RPP_ARBITRARY_LOOKUP_6(a, b, c, d, e, f, g, h, i, j) g
# define DETAIL_RPP_ARBITRARY_LOOKUP_7(a, b, c, d, e, f, g, h, i, j) h
# define DETAIL_RPP_ARBITRARY_LOOKUP_8(a, b, c, d, e, f, g, h, i, j) i
# define DETAIL_RPP_ARBITRARY_LOOKUP_9(a, b, c, d, e, f, g, h, i, j) j
#
# endif

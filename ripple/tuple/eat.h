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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_EAT_H
# define RIPPLE_PREPROCESSOR_TUPLE_EAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_TUPLE_EAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_EAT(size) DETAIL_RPP_TUPLE_EAT_I
# else
#    define RPP_TUPLE_EAT(size) RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_EAT_, size)
# endif
#
# define RPP_TUPLE_EAT_ID() RPP_TUPLE_EAT
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_EAT_I(...)
# else
#    define DETAIL_RPP_TUPLE_EAT_0()
#    define DETAIL_RPP_TUPLE_EAT_1(a)
#    define DETAIL_RPP_TUPLE_EAT_2(a, b)
#    define DETAIL_RPP_TUPLE_EAT_3(a, b, c)
#    define DETAIL_RPP_TUPLE_EAT_4(a, b, c, d)
#    define DETAIL_RPP_TUPLE_EAT_5(a, b, c, d, e)
#    define DETAIL_RPP_TUPLE_EAT_6(a, b, c, d, e, f)
#    define DETAIL_RPP_TUPLE_EAT_7(a, b, c, d, e, f, g)
#    define DETAIL_RPP_TUPLE_EAT_8(a, b, c, d, e, f, g, h)
#    define DETAIL_RPP_TUPLE_EAT_9(a, b, c, d, e, f, g, h, i)
#    define DETAIL_RPP_TUPLE_EAT_10(a, b, c, d, e, f, g, h, i, j)
#    define DETAIL_RPP_TUPLE_EAT_11(a, b, c, d, e, f, g, h, i, j, k)
#    define DETAIL_RPP_TUPLE_EAT_12(a, b, c, d, e, f, g, h, i, j, k, l)
#    define DETAIL_RPP_TUPLE_EAT_13(a, b, c, d, e, f, g, h, i, j, k, l, m)
#    define DETAIL_RPP_TUPLE_EAT_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)
#    define DETAIL_RPP_TUPLE_EAT_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
#    define DETAIL_RPP_TUPLE_EAT_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
#    define DETAIL_RPP_TUPLE_EAT_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
#    define DETAIL_RPP_TUPLE_EAT_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
#    define DETAIL_RPP_TUPLE_EAT_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
#    define DETAIL_RPP_TUPLE_EAT_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
#    define DETAIL_RPP_TUPLE_EAT_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
#    define DETAIL_RPP_TUPLE_EAT_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
#    define DETAIL_RPP_TUPLE_EAT_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
#    define DETAIL_RPP_TUPLE_EAT_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
#    define DETAIL_RPP_TUPLE_EAT_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# /* RPP_EAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_EAT(...)
# else
#    define RPP_EAT(x)
# endif
#
# define RPP_EAT_ID() RPP_EAT
#
# endif

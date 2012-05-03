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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_REM_H
# define RIPPLE_PREPROCESSOR_TUPLE_REM_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_TUPLE_REM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_REM(size) DETAIL_RPP_TUPLE_REM_I
# else
#    define RPP_TUPLE_REM(size) RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_REM_, size)
# endif
#
# define RPP_TUPLE_REM_ID() RPP_TUPLE_REM
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_REM_I(...) __VA_ARGS__
# else
#    define DETAIL_RPP_TUPLE_REM_0()
#    define DETAIL_RPP_TUPLE_REM_1(a) a
#    define DETAIL_RPP_TUPLE_REM_2(a, b) a, b
#    define DETAIL_RPP_TUPLE_REM_3(a, b, c) a, b, c
#    define DETAIL_RPP_TUPLE_REM_4(a, b, c, d) a, b, c, d
#    define DETAIL_RPP_TUPLE_REM_5(a, b, c, d, e) a, b, c, d, e
#    define DETAIL_RPP_TUPLE_REM_6(a, b, c, d, e, f) a, b, c, d, e, f
#    define DETAIL_RPP_TUPLE_REM_7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#    define DETAIL_RPP_TUPLE_REM_8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#    define DETAIL_RPP_TUPLE_REM_9(a, b, c, d, e, f, g, h, i) a, b, c, d, e, f, g, h, i
#    define DETAIL_RPP_TUPLE_REM_10(a, b, c, d, e, f, g, h, i, j) a, b, c, d, e, f, g, h, i, j
#    define DETAIL_RPP_TUPLE_REM_11(a, b, c, d, e, f, g, h, i, j, k) a, b, c, d, e, f, g, h, i, j, k
#    define DETAIL_RPP_TUPLE_REM_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l
#    define DETAIL_RPP_TUPLE_REM_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a, b, c, d, e, f, g, h, i, j, k, l, m
#    define DETAIL_RPP_TUPLE_REM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a, b, c, d, e, f, g, h, i, j, k, l, m, n
#    define DETAIL_RPP_TUPLE_REM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#    define DETAIL_RPP_TUPLE_REM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#    define DETAIL_RPP_TUPLE_REM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
#    define DETAIL_RPP_TUPLE_REM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
#    define DETAIL_RPP_TUPLE_REM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
#    define DETAIL_RPP_TUPLE_REM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
#    define DETAIL_RPP_TUPLE_REM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
#    define DETAIL_RPP_TUPLE_REM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
#    define DETAIL_RPP_TUPLE_REM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
#    define DETAIL_RPP_TUPLE_REM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
#    define DETAIL_RPP_TUPLE_REM_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
# endif
#
# /* RPP_TUPLE_REM_CTOR */
#
# define RPP_TUPLE_REM_CTOR(size, tuple) RPP_TUPLE_REM(size) tuple
# define RPP_TUPLE_REM_CTOR_ID() RPP_TUPLE_REM_CTOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_REM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_REM(...) __VA_ARGS__
# else
#    define RPP_REM(x) x
# endif
#
# define RPP_REM_ID() RPP_REM
#
# /* RPP_REM_CTOR */
#
# define RPP_REM_CTOR(tuple) RPP_REM tuple
# define RPP_REM_CTOR_ID() RPP_REM_CTOR
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

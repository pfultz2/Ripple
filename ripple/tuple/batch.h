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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_BATCH_H
# define RIPPLE_PREPROCESSOR_TUPLE_BATCH_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_IS_BATCH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_IS_BATCH(n, tuple) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_SPLIT(0, RPP_SPLIT(1, \
                DETAIL_RPP_TUPLE_IS_BATCH_A(n, DETAIL_RPP_TUPLE_IS_BATCH_B, RPP_REM tuple), 1, 1 \
            )), \
            0 \
        ) \
        /**/
#    define RPP_TUPLE_IS_BATCH_ID() RPP_TUPLE_IS_BATCH
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_IS_BATCH_A(n, b, im) \
        DETAIL_RPP_TUPLE_IS_BATCH_ ## n( \
            im, \
            b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b(), b() \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_IS_BATCH_B() 0, 0
#    define DETAIL_RPP_TUPLE_IS_BATCH_1(...) 1, 1
#    define DETAIL_RPP_TUPLE_IS_BATCH_2(a, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_3(a, b, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_4(a, b, c, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_5(a, b, c, d, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_6(a, b, c, d, e, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_7(a, b, c, d, e, f, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_8(a, b, c, d, e, f, g, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_9(a, b, c, d, e, f, g, h, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_10(a, b, c, d, e, f, g, h, i, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_11(a, b, c, d, e, f, g, h, i, j, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, _, ...) _
#    define DETAIL_RPP_TUPLE_IS_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, _, ...) _
# endif
#
# /* RPP_TUPLE_BATCH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_BATCH(n, tuple) \
        RPP_EXPAND( \
            RPP_DEFER(RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_BATCH_, n))( \
                RPP_REM tuple, \
            ) \
        ) \
        /**/
#    define RPP_TUPLE_BATCH_ID() RPP_TUPLE_BATCH
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_BATCH_1(a, ...) (a)
#    define DETAIL_RPP_TUPLE_BATCH_2(a, b, ...) (a, b)
#    define DETAIL_RPP_TUPLE_BATCH_3(a, b, c, ...) (a, b, c)
#    define DETAIL_RPP_TUPLE_BATCH_4(a, b, c, d, ...) (a, b, c, d)
#    define DETAIL_RPP_TUPLE_BATCH_5(a, b, c, d, e, ...) (a, b, c, d, e)
#    define DETAIL_RPP_TUPLE_BATCH_6(a, b, c, d, e, f, ...) (a, b, c, d, e, f)
#    define DETAIL_RPP_TUPLE_BATCH_7(a, b, c, d, e, f, g, ...) (a, b, c, d, e, f, g)
#    define DETAIL_RPP_TUPLE_BATCH_8(a, b, c, d, e, f, g, h, ...) (a, b, c, d, e, f, g, h)
#    define DETAIL_RPP_TUPLE_BATCH_9(a, b, c, d, e, f, g, h, i, ...) (a, b, c, d, e, f, g, h, i)
#    define DETAIL_RPP_TUPLE_BATCH_10(a, b, c, d, e, f, g, h, i, j, ...) (a, b, c, d, e, f, g, h, i, j)
#    define DETAIL_RPP_TUPLE_BATCH_11(a, b, c, d, e, f, g, h, i, j, k, ...) (a, b, c, d, e, f, g, h, i, j, k)
#    define DETAIL_RPP_TUPLE_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, l, ...) (a, b, c, d, e, f, g, h, i, j, k, l)
#    define DETAIL_RPP_TUPLE_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m)
#    define DETAIL_RPP_TUPLE_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n)
#    define DETAIL_RPP_TUPLE_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)
#    define DETAIL_RPP_TUPLE_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)
#    define DETAIL_RPP_TUPLE_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q)
#    define DETAIL_RPP_TUPLE_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r)
#    define DETAIL_RPP_TUPLE_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s)
#    define DETAIL_RPP_TUPLE_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t)
#    define DETAIL_RPP_TUPLE_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u)
#    define DETAIL_RPP_TUPLE_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v)
#    define DETAIL_RPP_TUPLE_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w)
#    define DETAIL_RPP_TUPLE_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x)
#    define DETAIL_RPP_TUPLE_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# /* RPP_TUPLE_SANS_BATCH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_SANS_BATCH(n, tuple) \
        RPP_TUPLE_TAIL(RPP_EXPAND( \
            RPP_DEFER(RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_SANS_BATCH_, n))( \
                RPP_REM tuple \
            ) \
        )) \
        /**/
#    define RPP_TUPLE_SANS_BATCH_ID() RPP_TUPLE_SANS_BATCH
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_SANS_BATCH_1(...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_2(a, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_3(a, b, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_4(a, b, c, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_5(a, b, c, d, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_6(a, b, c, d, e, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_7(a, b, c, d, e, f, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_8(a, b, c, d, e, f, g, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_9(a, b, c, d, e, f, g, h, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_10(a, b, c, d, e, f, g, h, i, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_11(a, b, c, d, e, f, g, h, i, j, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_12(a, b, c, d, e, f, g, h, i, j, k, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_13(a, b, c, d, e, f, g, h, i, j, k, l, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_14(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, ...) (__VA_ARGS__)
#    define DETAIL_RPP_TUPLE_SANS_BATCH_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, ...) (__VA_ARGS__)
# endif
#
# /* RPP_TUPLE_BATCH_FORK */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_BATCH_FORK(n, tuple) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            RPP_SPLIT(0, RPP_SPLIT(1, \
                RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_BATCH_FORK_, n)( \
                    RPP_COMMA, RPP_REM tuple \
                ),, \
            )), \
            0 \
        ) \
        /**/
#    define RPP_TUPLE_BATCH_FORK_ID() RPP_TUPLE_BATCH_FORK
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_BATCH_FORK_1(_, im)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_2(_, im) DETAIL_RPP_TUPLE_IS_BATCH_2(im, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_3(_, im) DETAIL_RPP_TUPLE_IS_BATCH_3(im, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_4(_, im) DETAIL_RPP_TUPLE_IS_BATCH_4(im, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_5(_, im) DETAIL_RPP_TUPLE_IS_BATCH_5(im, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_6(_, im) DETAIL_RPP_TUPLE_IS_BATCH_6(im, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_7(_, im) DETAIL_RPP_TUPLE_IS_BATCH_7(im, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_8(_, im) DETAIL_RPP_TUPLE_IS_BATCH_8(im, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_9(_, im) DETAIL_RPP_TUPLE_IS_BATCH_9(im, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_10(_, im) DETAIL_RPP_TUPLE_IS_BATCH_10(im, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_11(_, im) DETAIL_RPP_TUPLE_IS_BATCH_11(im, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_12(_, im) DETAIL_RPP_TUPLE_IS_BATCH_12(im, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_13(_, im) DETAIL_RPP_TUPLE_IS_BATCH_13(im, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_14(_, im) DETAIL_RPP_TUPLE_IS_BATCH_14(im, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_15(_, im) DETAIL_RPP_TUPLE_IS_BATCH_15(im, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_16(_, im) DETAIL_RPP_TUPLE_IS_BATCH_16(im, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_17(_, im) DETAIL_RPP_TUPLE_IS_BATCH_17(im, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_18(_, im) DETAIL_RPP_TUPLE_IS_BATCH_18(im, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_19(_, im) DETAIL_RPP_TUPLE_IS_BATCH_19(im, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_20(_, im) DETAIL_RPP_TUPLE_IS_BATCH_20(im, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_21(_, im) DETAIL_RPP_TUPLE_IS_BATCH_21(im, _() 20, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_22(_, im) DETAIL_RPP_TUPLE_IS_BATCH_22(im, _() 21, _() 20, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_23(_, im) DETAIL_RPP_TUPLE_IS_BATCH_23(im, _() 22, _() 21, _() 20, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_24(_, im) DETAIL_RPP_TUPLE_IS_BATCH_24(im, _() 23, _() 22, _() 21, _() 20, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
#    define DETAIL_RPP_TUPLE_BATCH_FORK_25(_, im) DETAIL_RPP_TUPLE_IS_BATCH_25(im, _() 24, _() 23, _() 22, _() 21, _() 20, _() 19, _() 18, _() 17, _() 16, _() 15, _() 14, _() 13, _() 12, _() 11, _() 10, _() 9, _() 8, _() 7, _() 6, _() 5, _() 4, _() 3, _() 2, _() 1,)
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_ELEM_H
# define RIPPLE_PREPROCESSOR_TUPLE_ELEM_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/cat.h>
# include <ripple/comparison/greater.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/expand.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_VARIADIC_ELEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_ELEM(i, ...) RPP_TUPLE_ELEM(?, i, (__VA_ARGS__))
#    define RPP_VARIADIC_ELEM_ID() RPP_VARIADIC_ELEM
# endif
#
# /* RPP_TUPLE_ELEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_ELEM(size, i, tuple) DETAIL_RPP_TUPLE_ELEM_I(i, DETAIL_RPP_TUPLE_ELEM_A tuple)
# else
#    define RPP_TUPLE_ELEM(size, i, tuple) \
        DETAIL_RPP_TUPLE_ELEM_I( \
            i, \
            RPP_EXPAND( \
                RPP_DEFER(RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_ELEM_E_, size)) \
                    (RPP_OBSTRUCT RPP_COMMA_IF(size) RPP_TUPLE_REM(size) tuple) \
            ) \
        ) \
        /**/
# endif
#
# define RPP_TUPLE_ELEM_ID() RPP_TUPLE_ELEM
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_ELEM_A(...) DETAIL_RPP_TUPLE_ELEM_B(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,)
#    define DETAIL_RPP_TUPLE_ELEM_B(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, ...) \
        (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) \
        /**/
# else
#    define DETAIL_RPP_TUPLE_ELEM_E_0(_) (_(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_1(_, a) (a, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_2(_, a, b) (a, b, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_3(_, a, b, c) (a, b, c, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_4(_, a, b, c, d) (a, b, c, d, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_5(_, a, b, c, d, e) (a, b, c, d, e, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_6(_, a, b, c, d, e, f) (a, b, c, d, e, f, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_7(_, a, b, c, d, e, f, g) (a, b, c, d, e, f, g, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_8(_, a, b, c, d, e, f, g, h) (a, b, c, d, e, f, g, h, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_9(_, a, b, c, d, e, f, g, h, i) (a, b, c, d, e, f, g, h, i, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_10(_, a, b, c, d, e, f, g, h, i, j) (a, b, c, d, e, f, g, h, i, j, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_11(_, a, b, c, d, e, f, g, h, i, j, k) (a, b, c, d, e, f, g, h, i, j, k, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_12(_, a, b, c, d, e, f, g, h, i, j, k, l) (a, b, c, d, e, f, g, h, i, j, k, l, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_13(_, a, b, c, d, e, f, g, h, i, j, k, l, m) (a, b, c, d, e, f, g, h, i, j, k, l, m, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_14(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, _(), _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_15(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, _(), _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_16(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, _(), _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_17(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, _(), _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_18(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, _(), _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_19(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, _(), _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_20(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, _(), _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_21(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, _(), _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_22(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, _(), _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_23(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, _(), _())
#    define DETAIL_RPP_TUPLE_ELEM_E_24(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, _())
#    define DETAIL_RPP_TUPLE_ELEM_E_25(_, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y)
# endif
#
# define DETAIL_RPP_TUPLE_ELEM_I(i, tuple) DETAIL_RPP_TUPLE_ELEM_ ## i tuple
# define DETAIL_RPP_TUPLE_ELEM_0(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a
# define DETAIL_RPP_TUPLE_ELEM_1(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) b
# define DETAIL_RPP_TUPLE_ELEM_2(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) c
# define DETAIL_RPP_TUPLE_ELEM_3(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) d
# define DETAIL_RPP_TUPLE_ELEM_4(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) e
# define DETAIL_RPP_TUPLE_ELEM_5(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) f
# define DETAIL_RPP_TUPLE_ELEM_6(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) g
# define DETAIL_RPP_TUPLE_ELEM_7(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) h
# define DETAIL_RPP_TUPLE_ELEM_8(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) i
# define DETAIL_RPP_TUPLE_ELEM_9(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) j
# define DETAIL_RPP_TUPLE_ELEM_10(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) k
# define DETAIL_RPP_TUPLE_ELEM_11(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) l
# define DETAIL_RPP_TUPLE_ELEM_12(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) m
# define DETAIL_RPP_TUPLE_ELEM_13(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) n
# define DETAIL_RPP_TUPLE_ELEM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) o
# define DETAIL_RPP_TUPLE_ELEM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) p
# define DETAIL_RPP_TUPLE_ELEM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) q
# define DETAIL_RPP_TUPLE_ELEM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) r
# define DETAIL_RPP_TUPLE_ELEM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) s
# define DETAIL_RPP_TUPLE_ELEM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) t
# define DETAIL_RPP_TUPLE_ELEM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) u
# define DETAIL_RPP_TUPLE_ELEM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) v
# define DETAIL_RPP_TUPLE_ELEM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) w
# define DETAIL_RPP_TUPLE_ELEM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) x
# define DETAIL_RPP_TUPLE_ELEM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) y
#
# /* RPP_TUPLE_ELEM_ALT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_ELEM_ALT(i, tuple) RPP_TUPLE_ELEM_ALT_BYPASS(RPP_LIMIT_EXPR, i, tuple)
#    define RPP_TUPLE_ELEM_ALT_ID() RPP_TUPLE_ELEM_ALT
# endif
#
# /* RPP_TUPLE_ELEM_ALT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_ELEM_ALT_BYPASS(s, i, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_ELEM_ALT_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), RPP_DEC, i, tuple \
        )) \
        /**/
#    define RPP_TUPLE_ELEM_ALT_BYPASS_ID() RPP_TUPLE_ELEM_ALT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_ELEM_ALT_INDIRECT() DETAIL_RPP_TUPLE_ELEM_ALT_I
#    define DETAIL_RPP_TUPLE_ELEM_ALT_I(_, s, d, i, tuple) \
        RPP_IIF _(RPP_GREATER(i, 24))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_ELEM_ALT_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), d, \
                d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(i))))))))))))))))))))))))), \
                RPP_TUPLE_SANS_BATCH _(25, tuple) \
            )), \
            RPP_TUPLE_ELEM _(?, i, tuple) \
        ) \
        /**/
# endif
#
# endif

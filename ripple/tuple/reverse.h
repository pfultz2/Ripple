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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_REVERSE_H
# define RIPPLE_PREPROCESSOR_TUPLE_REVERSE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/empty.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_REVERSE */
#
# define RPP_TUPLE_REVERSE(size, tuple) RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_REVERSE_, size) tuple
# define RPP_TUPLE_REVERSE_ID() RPP_TUPLE_REVERSE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_TUPLE_REVERSE_0() ()
# define DETAIL_RPP_TUPLE_REVERSE_1(a) (a)
# define DETAIL_RPP_TUPLE_REVERSE_2(a, b) (b, a)
# define DETAIL_RPP_TUPLE_REVERSE_3(a, b, c) (c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_4(a, b, c, d) (d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_5(a, b, c, d, e) (e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_6(a, b, c, d, e, f) (f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_7(a, b, c, d, e, f, g) (g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_8(a, b, c, d, e, f, g, h) (h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_9(a, b, c, d, e, f, g, h, i) (i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_10(a, b, c, d, e, f, g, h, i, j) (j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_11(a, b, c, d, e, f, g, h, i, j, k) (k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_12(a, b, c, d, e, f, g, h, i, j, k, l) (l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
# define DETAIL_RPP_TUPLE_REVERSE_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a)
#
# /* RPP_TUPLE_REVERSE_ALT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_REVERSE_ALT(tuple) RPP_TUPLE_REVERSE_ALT_BYPASS(RPP_LIMIT_EXPR, tuple)
#    define RPP_TUPLE_REVERSE_ALT_ID() RPP_TUPLE_REVERSE_ALT
# endif
#
# /* RPP_TUPLE_REVERSE_ALT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_REVERSE_ALT_BYPASS(s, tuple) \
        RPP_INLINE_WHEN(RPP_TUPLE_IS_CONS(tuple))( \
            (RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_REVERSE_ALT_I( \
                RPP_OBSTRUCT(), RPP_PREV(s), tuple, RPP_EMPTY \
            ))) \
        ) \
        /**/
#    define RPP_TUPLE_REVERSE_ALT_BYPASS_ID() RPP_TUPLE_REVERSE_ALT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_REVERSE_ALT_INDIRECT(n) DETAIL_RPP_TUPLE_REVERSE_ALT_I
#    define DETAIL_RPP_TUPLE_REVERSE_ALT_I(_, s, tuple, sep) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(25, tuple))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_REVERSE_ALT_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_SANS_BATCH _(25, tuple), RPP_COMMA \
            )) \
            RPP_TUPLE_REM_CTOR _(?, RPP_TUPLE_REVERSE _(25, RPP_TUPLE_BATCH _(25, tuple))) sep _(), \
            RPP_INLINE_WHEN _(RPP_TUPLE_IS_CONS _(tuple))( \
                RPP_TUPLE_REM_CTOR _(?, RPP_TUPLE_REVERSE _(RPP_TUPLE_BATCH_FORK _(25, tuple), tuple)) sep() \
            ) \
        ) \
        /**/
# endif
#
# endif

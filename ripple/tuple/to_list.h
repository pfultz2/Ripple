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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_TO_LIST_H
# define RIPPLE_PREPROCESSOR_TUPLE_TO_LIST_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_TO_LIST */
#
# define RPP_TUPLE_TO_LIST(size, tuple) RPP_PRIMITIVE_CAT(DETAIL_RPP_TUPLE_TO_LIST_, size) tuple
# define RPP_TUPLE_TO_LIST_ID() RPP_TUPLE_TO_LIST
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_TUPLE_TO_LIST_0() ...
# define DETAIL_RPP_TUPLE_TO_LIST_1(a) (a, ...)
# define DETAIL_RPP_TUPLE_TO_LIST_2(a, b) (a, (b, ...))
# define DETAIL_RPP_TUPLE_TO_LIST_3(a, b, c) (a, (b, (c, ...)))
# define DETAIL_RPP_TUPLE_TO_LIST_4(a, b, c, d) (a, (b, (c, (d, ...))))
# define DETAIL_RPP_TUPLE_TO_LIST_5(a, b, c, d, e) (a, (b, (c, (d, (e, ...)))))
# define DETAIL_RPP_TUPLE_TO_LIST_6(a, b, c, d, e, f) (a, (b, (c, (d, (e, (f, ...))))))
# define DETAIL_RPP_TUPLE_TO_LIST_7(a, b, c, d, e, f, g) (a, (b, (c, (d, (e, (f, (g, ...)))))))
# define DETAIL_RPP_TUPLE_TO_LIST_8(a, b, c, d, e, f, g, h) (a, (b, (c, (d, (e, (f, (g, (h, ...))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_9(a, b, c, d, e, f, g, h, i) (a, (b, (c, (d, (e, (f, (g, (h, (i, ...)))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_10(a, b, c, d, e, f, g, h, i, j) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, ...))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_11(a, b, c, d, e, f, g, h, i, j, k) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, ...)))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_12(a, b, c, d, e, f, g, h, i, j, k, l) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, ...))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, ...)))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, ...))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, ...)))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, ...))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, ...)))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, ...))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, ...)))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, ...))))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, ...)))))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, ...))))))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, ...)))))))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, (x, ...))))))))))))))))))))))))
# define DETAIL_RPP_TUPLE_TO_LIST_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, (x, (y, ...)))))))))))))))))))))))))
#
# /* RPP_TUPLE_TO_LIST_ALT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TO_LIST_ALT(tuple) RPP_TUPLE_TO_LIST_ALT_BYPASS(RPP_LIMIT_EXPR, tuple)
#    define RPP_TUPLE_TO_LIST_ALT_ID() RPP_TUPLE_TO_LIST_ALT
# endif
#
# /* RPP_TUPLE_TO_LIST_ALT_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TO_LIST_ALT_BYPASS(s, tuple) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_TO_LIST_ALT_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), tuple \
        )) \
        /**/
#    define RPP_TUPLE_TO_LIST_ALT_BYPASS_ID() RPP_TUPLE_TO_LIST_ALT_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_TO_LIST_ALT_INDIRECT() DETAIL_RPP_TUPLE_TO_LIST_ALT_I
#    define DETAIL_RPP_TUPLE_TO_LIST_ALT_I(_, s, tuple) \
        RPP_IIF _(RPP_TUPLE_IS_BATCH(25, tuple))( \
            RPP_EXPR_S _(s)(RPP_OBSTRUCT(DETAIL_RPP_TUPLE_TO_LIST_ALT_II)( \
                RPP_TUPLE_REM_CTOR _(?, RPP_TUPLE_BATCH _(25, tuple)), \
                RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_TO_LIST_ALT_INDIRECT _()( \
                    RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TUPLE_SANS_BATCH _(25, tuple) \
                )) \
            )), \
            RPP_TUPLE_TO_LIST _(RPP_TUPLE_BATCH_FORK _(25, tuple), tuple) \
        ) \
        /**/
#    define DETAIL_RPP_TUPLE_TO_LIST_ALT_II(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z) \
        (a, (b, (c, (d, (e, (f, (g, (h, (i, (j, (k, (l, (m, (n, (o, (p, (q, (r, (s, (t, (u, (v, (w, (x, (y, z))))))))))))))))))))))))) \
        /**/
# endif
#
# endif

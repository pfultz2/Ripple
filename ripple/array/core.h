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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_CORE_H
# define RIPPLE_PREPROCESSOR_ARRAY_CORE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/array/elem.h>
# include <ripple/array/size.h>
# include <ripple/array/to_tuple.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/compl.h>
# include <ripple/logical/not.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/basic.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARRAY */
#
# define RPP_ARRAY RPP_ARRAY
# define RPP_ARRAY_ID() RPP_ARRAY
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARRAY_TAG */
#
# define RPP_ARRAY_TAG(tag) tag
# define RPP_ARRAY_TAG_ID() RPP_ARRAY_TAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARRAY_NIL */
#
# define RPP_ARRAY_NIL() (0, ())
# define RPP_ARRAY_NIL_ID() RPP_ARRAY_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARRAY_CONS */
#
# define RPP_ARRAY_CONS(array, x) \
    RPP_EXPAND(RPP_DEFER(DETAIL_RPP_ARRAY_CONS_I)( \
        RPP_TUPLE_REM(2) array, x \
    )) \
    /**/
# define RPP_ARRAY_CONS_ID() RPP_ARRAY_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARRAY_CONS_I(size, tuple, x) \
    (RPP_INC(size), (x RPP_COMMA_IF(size) RPP_TUPLE_REM(size) tuple)) \
    /**/
#
# /* RPP_ARRAY_ITEM */
#
# define RPP_ARRAY_ITEM(x) x
# define RPP_ARRAY_ITEM_ID() RPP_ARRAY_ITEM
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARRAY_HEAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARRAY_HEAD(array) RPP_TUPLE_HEAD(RPP_ARRAY_TO_TUPLE(array))
# else
#    define RPP_ARRAY_HEAD(array) RPP_ARRAY_ELEM(0, array)
# endif
#
# define RPP_ARRAY_HEAD_ID() RPP_ARRAY_HEAD
#
# /* RPP_ARRAY_TAIL */
#
# define RPP_ARRAY_TAIL(array) \
    RPP_IF(RPP_DEC(RPP_ARRAY_SIZE(array)))( \
        DETAIL_RPP_ARRAY_TAIL_I array, RPP_ARRAY_NIL() \
    ) \
    /**/
# define RPP_ARRAY_TAIL_ID() RPP_ARRAY_TAIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARRAY_TAIL_I(size, tuple) (RPP_DEC(size), (RPP_SPLIT(1, RPP_REM tuple)))
# else
#    define DETAIL_RPP_ARRAY_TAIL_II(size, tuple) DETAIL_RPP_ARRAY_TAIL_ ## size tuple
#    define DETAIL_RPP_ARRAY_TAIL_I(size, tuple) DETAIL_RPP_ARRAY_TAIL_ ## size tuple
#    define DETAIL_RPP_ARRAY_TAIL_2(a, b) (1, (b))
#    define DETAIL_RPP_ARRAY_TAIL_3(a, b, c) (2, (b, c))
#    define DETAIL_RPP_ARRAY_TAIL_4(a, b, c, d) (3, (b, c, d))
#    define DETAIL_RPP_ARRAY_TAIL_5(a, b, c, d, e) (4, (b, c, d, e))
#    define DETAIL_RPP_ARRAY_TAIL_6(a, b, c, d, e, f) (5, (b, c, d, e, f))
#    define DETAIL_RPP_ARRAY_TAIL_7(a, b, c, d, e, f, g) (6, (b, c, d, e, f, g))
#    define DETAIL_RPP_ARRAY_TAIL_8(a, b, c, d, e, f, g, h) (7, (b, c, d, e, f, g, h))
#    define DETAIL_RPP_ARRAY_TAIL_9(a, b, c, d, e, f, g, h, i) (8, (b, c, d, e, f, g, h, i))
#    define DETAIL_RPP_ARRAY_TAIL_10(a, b, c, d, e, f, g, h, i, j) (9, (b, c, d, e, f, g, h, i, j))
#    define DETAIL_RPP_ARRAY_TAIL_11(a, b, c, d, e, f, g, h, i, j, k) (10, (b, c, d, e, f, g, h, i, j, k))
#    define DETAIL_RPP_ARRAY_TAIL_12(a, b, c, d, e, f, g, h, i, j, k, l) (11, (b, c, d, e, f, g, h, i, j, k, l))
#    define DETAIL_RPP_ARRAY_TAIL_13(a, b, c, d, e, f, g, h, i, j, k, l, m) (12, (b, c, d, e, f, g, h, i, j, k, l, m))
#    define DETAIL_RPP_ARRAY_TAIL_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) (13, (b, c, d, e, f, g, h, i, j, k, l, m, n))
#    define DETAIL_RPP_ARRAY_TAIL_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (14, (b, c, d, e, f, g, h, i, j, k, l, m, n, o))
#    define DETAIL_RPP_ARRAY_TAIL_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (15, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p))
#    define DETAIL_RPP_ARRAY_TAIL_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) (16, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q))
#    define DETAIL_RPP_ARRAY_TAIL_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) (17, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r))
#    define DETAIL_RPP_ARRAY_TAIL_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) (18, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s))
#    define DETAIL_RPP_ARRAY_TAIL_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) (19, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t))
#    define DETAIL_RPP_ARRAY_TAIL_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) (20, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u))
#    define DETAIL_RPP_ARRAY_TAIL_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) (21, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v))
#    define DETAIL_RPP_ARRAY_TAIL_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) (22, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w))
#    define DETAIL_RPP_ARRAY_TAIL_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) (23, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x))
#    define DETAIL_RPP_ARRAY_TAIL_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) (24, (b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y))
# endif
#
# /* RPP_ARRAY_IS_CONS */
#
# define RPP_ARRAY_IS_CONS(array) RPP_COMPL(RPP_ARRAY_IS_NIL(array))
# define RPP_ARRAY_IS_CONS_ID() RPP_ARRAY_IS_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARRAY_IS_NIL */
#
# define RPP_ARRAY_IS_NIL(array) RPP_NOT(RPP_ARRAY_SIZE(array))
# define RPP_ARRAY_IS_NIL_ID() RPP_ARRAY_IS_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

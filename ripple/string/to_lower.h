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
# ifndef RIPPLE_PREPROCESSOR_STRING_TO_LOWER_H
# define RIPPLE_PREPROCESSOR_STRING_TO_LOWER_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/split.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/string/core.h>
#
# /* RPP_TO_LOWER */
#
# define RPP_TO_LOWER(c) RPP_SPLIT(0, RPP_PRIMITIVE_CAT(DETAIL_RPP_TO_LOWER_, c))
# define RPP_TO_LOWER_ID() RPP_TO_LOWER
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_TO_LOWER__ _, _
# define DETAIL_RPP_TO_LOWER_0 0, 0
# define DETAIL_RPP_TO_LOWER_1 1, 1
# define DETAIL_RPP_TO_LOWER_2 2, 2
# define DETAIL_RPP_TO_LOWER_3 3, 3
# define DETAIL_RPP_TO_LOWER_4 4, 4
# define DETAIL_RPP_TO_LOWER_5 5, 5
# define DETAIL_RPP_TO_LOWER_6 6, 6
# define DETAIL_RPP_TO_LOWER_7 7, 7
# define DETAIL_RPP_TO_LOWER_8 8, 8
# define DETAIL_RPP_TO_LOWER_9 9, 9
# define DETAIL_RPP_TO_LOWER_a a, A
# define DETAIL_RPP_TO_LOWER_b b, B
# define DETAIL_RPP_TO_LOWER_c c, C
# define DETAIL_RPP_TO_LOWER_d d, D
# define DETAIL_RPP_TO_LOWER_e e, E
# define DETAIL_RPP_TO_LOWER_f f, F
# define DETAIL_RPP_TO_LOWER_g g, G
# define DETAIL_RPP_TO_LOWER_h h, H
# define DETAIL_RPP_TO_LOWER_i i, I
# define DETAIL_RPP_TO_LOWER_j j, J
# define DETAIL_RPP_TO_LOWER_k k, K
# define DETAIL_RPP_TO_LOWER_l l, L
# define DETAIL_RPP_TO_LOWER_m m, M
# define DETAIL_RPP_TO_LOWER_n n, N
# define DETAIL_RPP_TO_LOWER_o o, O
# define DETAIL_RPP_TO_LOWER_p p, P
# define DETAIL_RPP_TO_LOWER_q q, Q
# define DETAIL_RPP_TO_LOWER_r r, R
# define DETAIL_RPP_TO_LOWER_s s, S
# define DETAIL_RPP_TO_LOWER_t t, T
# define DETAIL_RPP_TO_LOWER_u u, U
# define DETAIL_RPP_TO_LOWER_v v, V
# define DETAIL_RPP_TO_LOWER_w w, W
# define DETAIL_RPP_TO_LOWER_x x, X
# define DETAIL_RPP_TO_LOWER_y y, Y
# define DETAIL_RPP_TO_LOWER_z z, Z
# define DETAIL_RPP_TO_LOWER_A a, A
# define DETAIL_RPP_TO_LOWER_B b, B
# define DETAIL_RPP_TO_LOWER_C c, C
# define DETAIL_RPP_TO_LOWER_D d, D
# define DETAIL_RPP_TO_LOWER_E e, E
# define DETAIL_RPP_TO_LOWER_F f, F
# define DETAIL_RPP_TO_LOWER_G g, G
# define DETAIL_RPP_TO_LOWER_H h, H
# define DETAIL_RPP_TO_LOWER_I i, I
# define DETAIL_RPP_TO_LOWER_J j, J
# define DETAIL_RPP_TO_LOWER_K k, K
# define DETAIL_RPP_TO_LOWER_L l, L
# define DETAIL_RPP_TO_LOWER_M m, M
# define DETAIL_RPP_TO_LOWER_N n, N
# define DETAIL_RPP_TO_LOWER_O o, O
# define DETAIL_RPP_TO_LOWER_P p, P
# define DETAIL_RPP_TO_LOWER_Q q, Q
# define DETAIL_RPP_TO_LOWER_R r, R
# define DETAIL_RPP_TO_LOWER_S s, S
# define DETAIL_RPP_TO_LOWER_T t, T
# define DETAIL_RPP_TO_LOWER_U u, U
# define DETAIL_RPP_TO_LOWER_V v, V
# define DETAIL_RPP_TO_LOWER_W w, W
# define DETAIL_RPP_TO_LOWER_X x, X
# define DETAIL_RPP_TO_LOWER_Y y, Y
# define DETAIL_RPP_TO_LOWER_Z z, Z
#
# /* RPP_STRING_TO_LOWER */
#
# define RPP_STRING_TO_LOWER(string) RPP_STRING_TO_LOWER_BYPASS(RPP_LIMIT_EXPR, string)
# define RPP_STRING_TO_LOWER_ID() RPP_STRING_TO_LOWER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_TO_LOWER_BYPASS */
#
# define RPP_STRING_TO_LOWER_BYPASS(s, string) \
    RPP_EXPR_S(s)(DETAIL_RPP_STRING_TO_LOWER_I( \
        RPP_OBSTRUCT(), RPP_PREV(s), string \
    )) \
    /**/
# define RPP_STRING_TO_LOWER_BYPASS_ID() RPP_STRING_TO_LOWER_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_STRING_TO_LOWER_INDIRECT() DETAIL_RPP_STRING_TO_LOWER_I
# define DETAIL_RPP_STRING_TO_LOWER_I(_, s, string) \
    RPP_INLINE_WHEN _(RPP_STRING_IS_CONS(string))( \
        RPP_TO_LOWER _(RPP_STRING_HEAD _(string)) \
        RPP_EXPR_S(s) _(DETAIL_RPP_STRING_TO_LOWER_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), RPP_STRING_TAIL _(string) \
        )) \
    ) \
    /**/
#
# endif

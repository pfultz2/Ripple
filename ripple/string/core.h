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
# ifndef RIPPLE_PREPROCESSOR_STRING_CORE_H
# define RIPPLE_PREPROCESSOR_STRING_CORE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/inline_unless.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_empty.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/compl.h>
#
# /* RPP_STRING */
#
# define RPP_STRING RPP_STRING
# define RPP_STRING_ID() RPP_STRING
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_TAG */
#
# define RPP_STRING_TAG(tag) tag
# define RPP_STRING_TAG_ID() RPP_STRING_TAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_STRING_NIL()
# else
#    define RPP_STRING_NIL() ()
# endif
#
# define RPP_STRING_NIL_ID() RPP_STRING_NIL
#
# /* RPP_STRING_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_STRING_CONS(string, x) x string
# else
#    define RPP_STRING_CONS(string, x) x RPP_INLINE_WHEN(RPP_STRING_IS_NIL(string))(RPP_EMPTY) string
# endif
#
# define RPP_STRING_CONS_ID() RPP_STRING_CONS
#
# /* RPP_STRING_ITEM */
#
# define RPP_STRING_ITEM(x) x
# define RPP_STRING_ITEM_ID() RPP_STRING_ITEM
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_HEAD */
#
# define RPP_STRING_HEAD(string) \
    RPP_SPLIT( \
        0, RPP_EXPAND( \
            DETAIL_RPP_STRING_HEAD_I RPP_PRIMITIVE_CAT(DETAIL_RPP_STRING_, string) \
        ) \
    ) \
    /**/
# define RPP_STRING_HEAD_ID() RPP_STRING_HEAD
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_STRING_HEAD_I(x) x, ~
#
# /* RPP_STRING_TAIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_STRING_TAIL(string) \
        RPP_SPLIT( \
            1, RPP_EXPAND( \
                DETAIL_RPP_STRING_TAIL_I RPP_PRIMITIVE_CAT(DETAIL_RPP_STRING_, string) \
            ) \
        ) \
        /**/
# else
#    define RPP_STRING_TAIL(string) \
        DETAIL_RPP_STRING_TAIL_II(RPP_SPLIT( \
            1, RPP_EXPAND( \
                DETAIL_RPP_STRING_TAIL_I RPP_PRIMITIVE_CAT(DETAIL_RPP_STRING_, string) \
            ) \
        )) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_STRING_TAIL_I(x) x,
# else
#    define DETAIL_RPP_STRING_TAIL_I(x) x, ()
#    define DETAIL_RPP_STRING_TAIL_II(r) \
        RPP_INLINE_UNLESS(RPP_IS_EMPTY(RPP_EMPTY r))( \
            RPP_EMPTY \
        ) r \
        /**/
# endif
#
# /* RPP_STRING_IS_CONS */
#
# define RPP_STRING_IS_CONS(string) RPP_COMPL(RPP_STRING_IS_NIL(string))
# define RPP_STRING_IS_CONS_ID() RPP_STRING_IS_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_STRING_IS_NIL */
#
# define RPP_STRING_IS_NIL(string) RPP_IS_NULLARY(string())
# define RPP_STRING_IS_NIL_ID() RPP_STRING_IS_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_STRING__ (_)
# define DETAIL_RPP_STRING_0 (0)
# define DETAIL_RPP_STRING_1 (1)
# define DETAIL_RPP_STRING_2 (2)
# define DETAIL_RPP_STRING_3 (3)
# define DETAIL_RPP_STRING_4 (4)
# define DETAIL_RPP_STRING_5 (5)
# define DETAIL_RPP_STRING_6 (6)
# define DETAIL_RPP_STRING_7 (7)
# define DETAIL_RPP_STRING_8 (8)
# define DETAIL_RPP_STRING_9 (9)
# define DETAIL_RPP_STRING_a (a)
# define DETAIL_RPP_STRING_b (b)
# define DETAIL_RPP_STRING_c (c)
# define DETAIL_RPP_STRING_d (d)
# define DETAIL_RPP_STRING_e (e)
# define DETAIL_RPP_STRING_f (f)
# define DETAIL_RPP_STRING_g (g)
# define DETAIL_RPP_STRING_h (h)
# define DETAIL_RPP_STRING_i (i)
# define DETAIL_RPP_STRING_j (j)
# define DETAIL_RPP_STRING_k (k)
# define DETAIL_RPP_STRING_l (l)
# define DETAIL_RPP_STRING_m (m)
# define DETAIL_RPP_STRING_n (n)
# define DETAIL_RPP_STRING_o (o)
# define DETAIL_RPP_STRING_p (p)
# define DETAIL_RPP_STRING_q (q)
# define DETAIL_RPP_STRING_r (r)
# define DETAIL_RPP_STRING_s (s)
# define DETAIL_RPP_STRING_t (t)
# define DETAIL_RPP_STRING_u (u)
# define DETAIL_RPP_STRING_v (v)
# define DETAIL_RPP_STRING_w (w)
# define DETAIL_RPP_STRING_x (x)
# define DETAIL_RPP_STRING_y (y)
# define DETAIL_RPP_STRING_z (z)
# define DETAIL_RPP_STRING_A (A)
# define DETAIL_RPP_STRING_B (B)
# define DETAIL_RPP_STRING_C (C)
# define DETAIL_RPP_STRING_D (D)
# define DETAIL_RPP_STRING_E (E)
# define DETAIL_RPP_STRING_F (F)
# define DETAIL_RPP_STRING_G (G)
# define DETAIL_RPP_STRING_H (H)
# define DETAIL_RPP_STRING_I (I)
# define DETAIL_RPP_STRING_J (J)
# define DETAIL_RPP_STRING_K (K)
# define DETAIL_RPP_STRING_L (L)
# define DETAIL_RPP_STRING_M (M)
# define DETAIL_RPP_STRING_N (N)
# define DETAIL_RPP_STRING_O (O)
# define DETAIL_RPP_STRING_P (P)
# define DETAIL_RPP_STRING_Q (Q)
# define DETAIL_RPP_STRING_R (R)
# define DETAIL_RPP_STRING_S (S)
# define DETAIL_RPP_STRING_T (T)
# define DETAIL_RPP_STRING_U (U)
# define DETAIL_RPP_STRING_V (V)
# define DETAIL_RPP_STRING_W (W)
# define DETAIL_RPP_STRING_X (X)
# define DETAIL_RPP_STRING_Y (Y)
# define DETAIL_RPP_STRING_Z (Z)
#
# endif

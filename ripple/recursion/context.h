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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_CONTEXT_H
# define RIPPLE_PREPROCESSOR_RECURSION_CONTEXT_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/detection/is_unary.h>
# include <ripple/facilities/split.h>
# include <ripple/recursion/auto_rec.h>
#
# /* RPP_CONTEXT */
#
# define RPP_CONTEXT(bit) DETAIL_RPP_CONTEXT_I(DETAIL_RPP_CONTEXT_N(), bit)
# define RPP_CONTEXT_ID() RPP_CONTEXT
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_CONTEXT_N() RPP_AUTO_REC(DETAIL_RPP_CONTEXT_P, 16)
# define DETAIL_RPP_CONTEXT_P(n) \
    RPP_IS_NULLARY(DETAIL_RPP_CONTEXT_ ## n ## _0(DETAIL_RPP_CONTEXT_ ## n ## _1(()))) \
    /**/
#
# define DETAIL_RPP_CONTEXT_I(n, bit) DETAIL_RPP_CONTEXT_II(n, bit)
# define DETAIL_RPP_CONTEXT_II(n, bit) DETAIL_RPP_CONTEXT_ ## n ## _ ## bit
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_CONTEXT_1_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_1_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_2_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_2_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_3_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_3_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_4_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_4_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_5_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_5_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_6_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_6_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_7_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_7_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_8_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_8_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_9_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_9_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_10_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_10_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_11_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_11_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_12_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_12_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_13_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_13_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_14_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_14_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_15_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_15_1(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_16_0(...) __VA_ARGS__
#    define DETAIL_RPP_CONTEXT_16_1(...) __VA_ARGS__
# else
#    define DETAIL_RPP_CONTEXT_1_0(x) x
#    define DETAIL_RPP_CONTEXT_1_1(x) x
#    define DETAIL_RPP_CONTEXT_2_0(x) x
#    define DETAIL_RPP_CONTEXT_2_1(x) x
#    define DETAIL_RPP_CONTEXT_3_0(x) x
#    define DETAIL_RPP_CONTEXT_3_1(x) x
#    define DETAIL_RPP_CONTEXT_4_0(x) x
#    define DETAIL_RPP_CONTEXT_4_1(x) x
#    define DETAIL_RPP_CONTEXT_5_0(x) x
#    define DETAIL_RPP_CONTEXT_5_1(x) x
#    define DETAIL_RPP_CONTEXT_6_0(x) x
#    define DETAIL_RPP_CONTEXT_6_1(x) x
#    define DETAIL_RPP_CONTEXT_7_0(x) x
#    define DETAIL_RPP_CONTEXT_7_1(x) x
#    define DETAIL_RPP_CONTEXT_8_0(x) x
#    define DETAIL_RPP_CONTEXT_8_1(x) x
#    define DETAIL_RPP_CONTEXT_9_0(x) x
#    define DETAIL_RPP_CONTEXT_9_1(x) x
#    define DETAIL_RPP_CONTEXT_10_0(x) x
#    define DETAIL_RPP_CONTEXT_10_1(x) x
#    define DETAIL_RPP_CONTEXT_11_0(x) x
#    define DETAIL_RPP_CONTEXT_11_1(x) x
#    define DETAIL_RPP_CONTEXT_12_0(x) x
#    define DETAIL_RPP_CONTEXT_12_1(x) x
#    define DETAIL_RPP_CONTEXT_13_0(x) x
#    define DETAIL_RPP_CONTEXT_13_1(x) x
#    define DETAIL_RPP_CONTEXT_14_0(x) x
#    define DETAIL_RPP_CONTEXT_14_1(x) x
#    define DETAIL_RPP_CONTEXT_15_0(x) x
#    define DETAIL_RPP_CONTEXT_15_1(x) x
#    define DETAIL_RPP_CONTEXT_16_0(x) x
#    define DETAIL_RPP_CONTEXT_16_1(x) x
# endif
#
# /* RPP_ABSOLUTE */
#
# define RPP_ABSOLUTE(n) \
    DETAIL_RPP_ABSOLUTE_I(DETAIL_RPP_ABSOLUTE_A(n, 0)(n, 1)) \
    /**/
# define RPP_ABSOLUTE_ID() RPP_ABSOLUTE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ABSOLUTE_I(res) \
    RPP_INLINE_WHEN(RPP_IS_UNARY(res))(RPP_SPLIT(0, DETAIL_RPP_ABSOLUTE_II res)) \
    /**/
# define DETAIL_RPP_ABSOLUTE_II(x) x, ...
#
# define DETAIL_RPP_ABSOLUTE_A(n, bit) RPP_IIF(RPP_IS_NULLARY(DETAIL_RPP_CONTEXT_I(n, bit)(())))(DETAIL_RPP_ABSOLUTE_B, (bit))
# define DETAIL_RPP_ABSOLUTE_B(n, bit) RPP_IIF(RPP_IS_NULLARY(DETAIL_RPP_CONTEXT_I(n, bit)(())))(DETAIL_RPP_ABSOLUTE_A, (bit))
#
# /* RPP_RELATIVE */
#
# define RPP_RELATIVE(n) RPP_PRIMITIVE_CAT(DETAIL_RPP_RELATIVE_, n)(DETAIL_RPP_CONTEXT_N())
# define RPP_RELATIVE_ID() RPP_RELATIVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_RELATIVE_0(n) RPP_ABSOLUTE(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_1(n) DETAIL_RPP_RELATIVE_0(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_2(n) DETAIL_RPP_RELATIVE_1(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_3(n) DETAIL_RPP_RELATIVE_2(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_4(n) DETAIL_RPP_RELATIVE_3(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_5(n) DETAIL_RPP_RELATIVE_4(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_6(n) DETAIL_RPP_RELATIVE_5(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_7(n) DETAIL_RPP_RELATIVE_6(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_8(n) DETAIL_RPP_RELATIVE_7(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_9(n) DETAIL_RPP_RELATIVE_8(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_10(n) DETAIL_RPP_RELATIVE_9(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_11(n) DETAIL_RPP_RELATIVE_10(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_12(n) DETAIL_RPP_RELATIVE_11(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_13(n) DETAIL_RPP_RELATIVE_12(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_14(n) DETAIL_RPP_RELATIVE_13(RPP_DEC(n))
# define DETAIL_RPP_RELATIVE_15(n) DETAIL_RPP_RELATIVE_14(RPP_DEC(n))
#
# /* RPP_RETRIEVE */
#
# define RPP_RETRIEVE() RPP_RELATIVE(0)
# define RPP_RETRIEVE_ID() RPP_RETRIEVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

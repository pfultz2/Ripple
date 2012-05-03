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
# ifndef RIPPLE_PREPROCESSOR_EXTENDED_AUTO_CAT_H
# define RIPPLE_PREPROCESSOR_EXTENDED_AUTO_CAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/facilities/intercept.h>
# include <ripple/recursion/auto_rec.h>
#
# /* RPP_AUTO_CAT */
#
# define RPP_AUTO_CAT RPP_CAT(DETAIL_RPP_AUTO_CAT_, RPP_AUTO_REC(DETAIL_RPP_AUTO_CAT_P, 16))
# define RPP_AUTO_CAT_ID() RPP_AUTO_CAT
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_AUTO_CAT_P(n) RPP_IS_NULLARY(DETAIL_RPP_AUTO_CAT_ ## n(RPP_INTERCEPT, 0)())
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_AUTO_CAT_1(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_1(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_2(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_2(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_3(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_3(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_4(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_4(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_5(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_5(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_6(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_6(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_7(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_7(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_8(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_8(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_9(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_9(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_10(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_10(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_11(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_11(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_12(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_12(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_13(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_13(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_14(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_14(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_15(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_15(a, __VA_ARGS__)
#    define DETAIL_RPP_AUTO_CAT_16(a, ...) DETAIL_RPP_PRIMITIVE_AUTO_CAT_16(a, __VA_ARGS__)
# else
#    define DETAIL_RPP_AUTO_CAT_1(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_1(a, b)
#    define DETAIL_RPP_AUTO_CAT_2(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_2(a, b)
#    define DETAIL_RPP_AUTO_CAT_3(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_3(a, b)
#    define DETAIL_RPP_AUTO_CAT_4(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_4(a, b)
#    define DETAIL_RPP_AUTO_CAT_5(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_5(a, b)
#    define DETAIL_RPP_AUTO_CAT_6(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_6(a, b)
#    define DETAIL_RPP_AUTO_CAT_7(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_7(a, b)
#    define DETAIL_RPP_AUTO_CAT_8(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_8(a, b)
#    define DETAIL_RPP_AUTO_CAT_9(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_9(a, b)
#    define DETAIL_RPP_AUTO_CAT_10(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_10(a, b)
#    define DETAIL_RPP_AUTO_CAT_11(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_11(a, b)
#    define DETAIL_RPP_AUTO_CAT_12(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_12(a, b)
#    define DETAIL_RPP_AUTO_CAT_13(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_13(a, b)
#    define DETAIL_RPP_AUTO_CAT_14(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_14(a, b)
#    define DETAIL_RPP_AUTO_CAT_15(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_15(a, b)
#    define DETAIL_RPP_AUTO_CAT_16(a, b) DETAIL_RPP_PRIMITIVE_AUTO_CAT_16(a, b)
# endif
#
# /* RPP_PRIMITIVE_AUTO_CAT */
#
# define RPP_PRIMITIVE_AUTO_CAT RPP_CAT(DETAIL_RPP_PRIMITIVE_AUTO_CAT_, RPP_AUTO_REC(DETAIL_RPP_AUTO_CAT_P, 16))
# define RPP_PRIMITIVE_AUTO_CAT_ID() RPP_PRIMITIVE_AUTO_CAT
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_1(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_2(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_3(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_4(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_5(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_6(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_7(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_8(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_9(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_10(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_11(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_12(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_13(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_14(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_15(a, ...) a ## __VA_ARGS__
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_16(a, ...) a ## __VA_ARGS__
# else
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_1(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_2(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_3(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_4(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_5(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_6(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_7(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_8(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_9(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_10(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_11(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_12(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_13(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_14(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_15(a, b) a ## b
#    define DETAIL_RPP_PRIMITIVE_AUTO_CAT_16(a, b) a ## b
# endif
#
# endif

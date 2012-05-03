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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_EQUALIZE_H
# define RIPPLE_PREPROCESSOR_RECURSION_EQUALIZE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_EQUALIZE */
#
# define RPP_EQUALIZE(n) RPP_PRIMITIVE_CAT_SHADOW(DETAIL_RPP_EQUALIZE_, n)
# define RPP_EQUALIZE_ID() RPP_EQUALIZE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_EQUALIZE_1(x) x
# define DETAIL_RPP_EQUALIZE_2(x) DETAIL_RPP_EQUALIZE_1(x)
# define DETAIL_RPP_EQUALIZE_3(x) DETAIL_RPP_EQUALIZE_2(x)
# define DETAIL_RPP_EQUALIZE_4(x) DETAIL_RPP_EQUALIZE_3(x)
# define DETAIL_RPP_EQUALIZE_5(x) DETAIL_RPP_EQUALIZE_4(x)
# define DETAIL_RPP_EQUALIZE_6(x) DETAIL_RPP_EQUALIZE_5(x)
# define DETAIL_RPP_EQUALIZE_7(x) DETAIL_RPP_EQUALIZE_6(x)
# define DETAIL_RPP_EQUALIZE_8(x) DETAIL_RPP_EQUALIZE_7(x)
# define DETAIL_RPP_EQUALIZE_9(x) DETAIL_RPP_EQUALIZE_8(x)
# define DETAIL_RPP_EQUALIZE_10(x) DETAIL_RPP_EQUALIZE_9(x)
# define DETAIL_RPP_EQUALIZE_11(x) DETAIL_RPP_EQUALIZE_10(x)
# define DETAIL_RPP_EQUALIZE_12(x) DETAIL_RPP_EQUALIZE_11(x)
# define DETAIL_RPP_EQUALIZE_13(x) DETAIL_RPP_EQUALIZE_12(x)
# define DETAIL_RPP_EQUALIZE_14(x) DETAIL_RPP_EQUALIZE_13(x)
# define DETAIL_RPP_EQUALIZE_15(x) DETAIL_RPP_EQUALIZE_14(x)
# define DETAIL_RPP_EQUALIZE_16(x) DETAIL_RPP_EQUALIZE_15(x)
# define DETAIL_RPP_EQUALIZE_17(x) DETAIL_RPP_EQUALIZE_16(x)
# define DETAIL_RPP_EQUALIZE_18(x) DETAIL_RPP_EQUALIZE_17(x)
# define DETAIL_RPP_EQUALIZE_19(x) DETAIL_RPP_EQUALIZE_18(x)
# define DETAIL_RPP_EQUALIZE_20(x) DETAIL_RPP_EQUALIZE_19(x)
# define DETAIL_RPP_EQUALIZE_21(x) DETAIL_RPP_EQUALIZE_20(x)
# define DETAIL_RPP_EQUALIZE_22(x) DETAIL_RPP_EQUALIZE_21(x)
# define DETAIL_RPP_EQUALIZE_23(x) DETAIL_RPP_EQUALIZE_22(x)
# define DETAIL_RPP_EQUALIZE_24(x) DETAIL_RPP_EQUALIZE_23(x)
# define DETAIL_RPP_EQUALIZE_25(x) DETAIL_RPP_EQUALIZE_24(x)
#
# endif

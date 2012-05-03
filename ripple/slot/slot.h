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
# ifndef RIPPLE_PREPROCESSOR_SLOT_SLOT_H
# define RIPPLE_PREPROCESSOR_SLOT_SLOT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/expand.h>
# include <ripple/recursion/basic.h>
# include <ripple/stringize.h>
#
# /* RPP_ASSIGN_SLOT */
#
# define RPP_ASSIGN_SLOT(i) DETAIL_RPP_ASSIGN_SLOT_I(i)
# define RPP_ASSIGN_SLOT_ID() RPP_ASSIGN_SLOT
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ASSIGN_SLOT_I(i) RPP_PRIMITIVE_STRINGIZE(ripple/slot/detail/s ## i.h)
#
# /* RPP_SLOT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SLOT(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_SLOT_, i)()
# else
#    define RPP_SLOT(i) RPP_EXPAND(RPP_PRIMITIVE_CAT(DETAIL_RPP_SLOT_, i)())
# endif
#
# define RPP_SLOT_ID() RPP_SLOT
#
# define DETAIL_RPP_SLOT_1 0 RPP_EMPTY
# define DETAIL_RPP_SLOT_2 0 RPP_EMPTY
# define DETAIL_RPP_SLOT_3 0 RPP_EMPTY
# define DETAIL_RPP_SLOT_4 0 RPP_EMPTY
# define DETAIL_RPP_SLOT_5 0 RPP_EMPTY
#
# define DETAIL_RPP_SLOT_MOD_0 DETAIL_RPP_SLOT_MOD_1 % 10UL
# define DETAIL_RPP_SLOT_MOD_1 DETAIL_RPP_SLOT_MOD_2 % 100UL
# define DETAIL_RPP_SLOT_MOD_2 DETAIL_RPP_SLOT_MOD_3 % 1000UL
# define DETAIL_RPP_SLOT_MOD_3 DETAIL_RPP_SLOT_MOD_4 % 10000UL
# define DETAIL_RPP_SLOT_MOD_4 DETAIL_RPP_SLOT_MOD_5 % 100000UL
# define DETAIL_RPP_SLOT_MOD_5 DETAIL_RPP_SLOT_MOD_6 % 1000000UL
# define DETAIL_RPP_SLOT_MOD_6 DETAIL_RPP_SLOT_MOD_7 % 10000000UL
# define DETAIL_RPP_SLOT_MOD_7 DETAIL_RPP_SLOT_MOD_8 % 100000000UL
# define DETAIL_RPP_SLOT_MOD_8 DETAIL_RPP_SLOT_MOD_9 % 1000000000UL
# define DETAIL_RPP_SLOT_MOD_9 % 1000000000UL
#
# define DETAIL_RPP_SLOT_DIV_0 1UL
# define DETAIL_RPP_SLOT_DIV_1 10UL
# define DETAIL_RPP_SLOT_DIV_2 100UL
# define DETAIL_RPP_SLOT_DIV_3 1000UL
# define DETAIL_RPP_SLOT_DIV_4 10000UL
# define DETAIL_RPP_SLOT_DIV_5 100000UL
# define DETAIL_RPP_SLOT_DIV_6 1000000UL
# define DETAIL_RPP_SLOT_DIV_7 10000000UL
# define DETAIL_RPP_SLOT_DIV_8 100000000UL
# define DETAIL_RPP_SLOT_DIV_9 1000000000UL
#
# define DETAIL_RPP_SLOT_DIGIT(n) DETAIL_RPP_SLOT_MOD_ ## n / DETAIL_RPP_SLOT_DIV_ ## n
#
# define RPP_SLOT_SHARED() "ripple/slot/detail/shared.h"
#
# if !CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SLOT_CC(n) RPP_DEFER(DETAIL_RPP_SLOT_CC_ ## n)
#    define DETAIL_RPP_SLOT_CC_2(a, b) a ## b
#    define DETAIL_RPP_SLOT_CC_3(a, b, c) a ## b ## c
#    define DETAIL_RPP_SLOT_CC_4(a, b, c, d) a ## b ## c ## d
#    define DETAIL_RPP_SLOT_CC_5(a, b, c, d, e) a ## b ## c ## d ## e
#    define DETAIL_RPP_SLOT_CC_6(a, b, c, d, e, f) a ## b ## c ## d ## e ## f
#    define DETAIL_RPP_SLOT_CC_7(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
#    define DETAIL_RPP_SLOT_CC_8(a, b, c, d, e, f, g, h) a ## b ## c ## d ## e ## f ## g ## h
#    define DETAIL_RPP_SLOT_CC_9(a, b, c, d, e, f, g, h, i) a ## b ## c ## d ## e ## f ## g ## h ## i
#    define DETAIL_RPP_SLOT_CC_10(a, b, c, d, e, f, g, h, i, j) a ## b ## c ## d ## e ## f ## g ## h ## i ## j
# endif
#
# endif

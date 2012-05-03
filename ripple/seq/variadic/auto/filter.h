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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_AUTO_FILTER_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_AUTO_FILTER_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/higher_order.h>
# include <ripple/seq/variadic/filter.h>
#
# /* RPP_VARIADIC_SEQ_AUTO_FILTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_AUTO_FILTER RPP_CAT(DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_, RPP_HIGHER_ORDER())
#    define RPP_VARIADIC_SEQ_AUTO_FILTER_ID() RPP_VARIADIC_SEQ_AUTO_FILTER
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_1(...) RPP_HIGHER_ORDER(1)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_2(...) RPP_HIGHER_ORDER(2)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_3(...) RPP_HIGHER_ORDER(3)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_4(...) RPP_HIGHER_ORDER(4)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_5(...) RPP_HIGHER_ORDER(5)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_6(...) RPP_HIGHER_ORDER(6)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_7(...) RPP_HIGHER_ORDER(7)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
#    define DETAIL_RPP_VARIADIC_SEQ_AUTO_FILTER_8(...) RPP_HIGHER_ORDER(8)(, RPP_EXPR(RPP_VARIADIC_SEQ_FILTER(__VA_ARGS__)))
# endif
#
# endif

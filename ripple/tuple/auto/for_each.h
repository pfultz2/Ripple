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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_AUTO_FOR_EACH_H
# define RIPPLE_PREPROCESSOR_TUPLE_AUTO_FOR_EACH_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/higher_order.h>
# include <ripple/tuple/for_each.h>
#
# /* RPP_TUPLE_AUTO_FOR_EACH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_AUTO_FOR_EACH RPP_CAT(DETAIL_RPP_TUPLE_AUTO_FOR_EACH_, RPP_HIGHER_ORDER())
#    define RPP_TUPLE_AUTO_FOR_EACH_ID() RPP_TUPLE_AUTO_FOR_EACH
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_1(...) RPP_HIGHER_ORDER(1)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_2(...) RPP_HIGHER_ORDER(2)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_3(...) RPP_HIGHER_ORDER(3)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_4(...) RPP_HIGHER_ORDER(4)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_5(...) RPP_HIGHER_ORDER(5)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_6(...) RPP_HIGHER_ORDER(6)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_7(...) RPP_HIGHER_ORDER(7)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
#    define DETAIL_RPP_TUPLE_AUTO_FOR_EACH_8(...) RPP_HIGHER_ORDER(8)(, RPP_EXPR(RPP_TUPLE_FOR_EACH(__VA_ARGS__)))
# endif
#
# endif

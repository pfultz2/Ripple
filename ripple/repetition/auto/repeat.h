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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_AUTO_REPEAT_H
# define RIPPLE_PREPROCESSOR_REPETITION_AUTO_REPEAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/higher_order.h>
# include <ripple/repetition/repeat.h>
#
# /* RPP_AUTO_REPEAT */
#
# define RPP_AUTO_REPEAT RPP_CAT(DETAIL_RPP_AUTO_REPEAT_, RPP_HIGHER_ORDER())
# define RPP_AUTO_REPEAT_ID() RPP_AUTO_REPEAT
#
# define DETAIL_RPP_AUTO_REPEAT_1(...) RPP_HIGHER_ORDER(1)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_2(...) RPP_HIGHER_ORDER(2)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_3(...) RPP_HIGHER_ORDER(3)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_4(...) RPP_HIGHER_ORDER(4)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_5(...) RPP_HIGHER_ORDER(5)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_6(...) RPP_HIGHER_ORDER(6)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_7(...) RPP_HIGHER_ORDER(7)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
# define DETAIL_RPP_AUTO_REPEAT_8(...) RPP_HIGHER_ORDER(8)(, RPP_EXPR(RPP_REPEAT(__VA_ARGS__)))
#
# endif

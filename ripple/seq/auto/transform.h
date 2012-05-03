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
# ifndef RIPPLE_PREPROCESSOR_SEQ_AUTO_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_SEQ_AUTO_TRANSFORM_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/higher_order.h>
# include <ripple/seq/transform.h>
#
# /* RPP_SEQ_AUTO_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_AUTO_TRANSFORM RPP_CAT(DETAIL_RPP_SEQ_AUTO_TRANSFORM_, RPP_HIGHER_ORDER())
#    define RPP_SEQ_AUTO_TRANSFORM_ID() RPP_SEQ_AUTO_TRANSFORM
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_1(...) RPP_HIGHER_ORDER(1)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_2(...) RPP_HIGHER_ORDER(2)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_3(...) RPP_HIGHER_ORDER(3)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_4(...) RPP_HIGHER_ORDER(4)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_5(...) RPP_HIGHER_ORDER(5)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_6(...) RPP_HIGHER_ORDER(6)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_7(...) RPP_HIGHER_ORDER(7)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
#    define DETAIL_RPP_SEQ_AUTO_TRANSFORM_8(...) RPP_HIGHER_ORDER(8)(, RPP_EXPR(RPP_SEQ_TRANSFORM(__VA_ARGS__)))
# endif
#
# endif

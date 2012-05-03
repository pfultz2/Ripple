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
# ifndef RIPPLE_PREPROCESSOR_LIMITS_H
# define RIPPLE_PREPROCESSOR_LIMITS_H
#
# include <ripple/config.h>
#
# /* RPP_LIMIT_AS_ARGS */
#
# define RPP_LIMIT_AS_ARGS 5
# define RPP_LIMIT_AS_ARGS_ID() RPP_LIMIT_AS_ARGS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_AUTO_CAT */
#
# define RPP_LIMIT_AUTO_CAT 16
# define RPP_LIMIT_AUTO_CAT_ID() RPP_LIMIT_AUTO_CAT
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_BIND */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIMIT_BIND 16
#    define RPP_LIMIT_BIND_ID() RPP_LIMIT_BIND
# endif
#
# /* RPP_LIMIT_BLOCK */
#
# define RPP_LIMIT_BLOCK 5
# define RPP_LIMIT_BLOCK_ID() RPP_LIMIT_BLOCK
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_CLOSURE */
#
# define RPP_LIMIT_CLOSURE 25
# define RPP_LIMIT_CLOSURE_ID() RPP_LIMIT_CLOSURE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_CONTEXT */
#
# define RPP_LIMIT_CONTEXT 16
# define RPP_LIMIT_CONTEXT_ID() RPP_LIMIT_CONTEXT
#
# /* RPP_LIMIT_EQUALIZE */
#
# define RPP_LIMIT_EQUALIZE 25
# define RPP_LIMIT_EQUALIZE_ID() RPP_LIMIT_EQUALIZE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_EXPANDER */
#
# define RPP_LIMIT_EXPANDER 5
# define RPP_LIMIT_EXPANDER_ID() RPP_LIMIT_EXPANDER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_EXPR */
#
# define RPP_LIMIT_EXPR 512
# define RPP_LIMIT_EXPR_ID() RPP_LIMIT_EXPR
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_HIGHER_ORDER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIMIT_HIGHER_ORDER 8
#    define RPP_LIMIT_HIGHER_ORDER_ID() RPP_LIMIT_HIGHER_ORDER
# endif
#
# /* RPP_LIMIT_ITERATION */
#
# define RPP_LIMIT_ITERATION 512
# define RPP_LIMIT_ITERATION_ID() RPP_LIMIT_ITERATION
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_ITERATION_DEPTH */
#
# define RPP_LIMIT_ITERATION_DEPTH 5
# define RPP_LIMIT_ITERATION_DEPTH_ID() RPP_LIMIT_ITERATION_DEPTH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_LAMBDA */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIMIT_LAMBDA 50
#    define RPP_LIMIT_LAMBDA_ID() RPP_LIMIT_LAMBDA
# endif
#
# /* RPP_LIMIT_MAG */
#
# define RPP_LIMIT_MAG 512
# define RPP_LIMIT_MAG_ID() RPP_LIMIT_MAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_PHASE */
#
# define RPP_LIMIT_PHASE 5
# define RPP_LIMIT_PHASE_ID() RPP_LIMIT_PHASE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_PLACEHOLDERS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIMIT_PLACEHOLDERS 25
#    define RPP_LIMIT_PLACEHOLDERS_ID() RPP_LIMIT_PLACEHOLDERS
# endif
#
# /* RPP_LIMIT_SLOT */
#
# define RPP_LIMIT_SLOT 5
# define RPP_LIMIT_SLOT_ID() RPP_LIMIT_SLOT
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_SLOT_VALUE */
#
# define RPP_LIMIT_SLOT_VALUE 10
# define RPP_LIMIT_SLOT_VALUE_ID() RPP_LIMIT_SLOT_VALUE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_TUPLE */
#
# define RPP_LIMIT_TUPLE 25
# define RPP_LIMIT_TUPLE_ID() RPP_LIMIT_TUPLE
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIMIT_VARIADIC_CAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIMIT_VARIADIC_CAT 25
#    define RPP_LIMIT_VARIADIC_CAT_ID() RPP_LIMIT_VARIADIC_CAT
# endif
#
# endif

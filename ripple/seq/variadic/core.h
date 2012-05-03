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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_CORE_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_CORE_H
#
# include <ripple/config.h>
# include <ripple/seq/core.h>
#
# /* RPP_VARIADIC_SEQ */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ RPP_VARIADIC_SEQ
#    define RPP_VARIADIC_SEQ_ID() RPP_VARIADIC_SEQ
# endif
#
# /* RPP_VARIADIC_SEQ_TAG */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_TAG(tag) RPP_SEQ_TAG(tag)
#    define RPP_VARIADIC_SEQ_TAG_ID() RPP_VARIADIC_SEQ_TAG
# endif
#
# /* RPP_VARIADIC_SEQ_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_NIL() RPP_SEQ_NIL()
#    define RPP_VARIADIC_SEQ_NIL_ID() RPP_VARIADIC_SEQ_NIL
# endif
#
# /* RPP_VARIADIC_SEQ_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_CONS(seq, ...) RPP_SEQ_CONS(seq, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_CONS_ID() RPP_VARIADIC_SEQ_CONS
# endif
#
# /* RPP_VARIADIC_SEQ_ITEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_ITEM(...) (__VA_ARGS__)
#    define RPP_VARIADIC_SEQ_ITEM_ID() RPP_VARIADIC_SEQ_ITEM
# endif
#
# /* RPP_VARIADIC_SEQ_HEAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_HEAD(seq) RPP_SEQ_HEAD(seq)
#    define RPP_VARIADIC_SEQ_HEAD_ID() RPP_VARIADIC_SEQ_HEAD
# endif
#
# /* RPP_VARIADIC_SEQ_TAIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_TAIL(seq) RPP_SEQ_TAIL(seq)
#    define RPP_VARIADIC_SEQ_TAIL_ID() RPP_VARIADIC_SEQ_TAIL
# endif
#
# /* RPP_VARIADIC_SEQ_IS_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_IS_CONS(seq) RPP_SEQ_IS_CONS(seq)
#    define RPP_VARIADIC_SEQ_IS_CONS_ID() RPP_VARIADIC_SEQ_IS_CONS
# endif
#
# /* RPP_VARIADIC_SEQ_IS_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_IS_NIL(seq) RPP_SEQ_IS_NIL(seq)
#    define RPP_VARIADIC_SEQ_IS_NIL_ID() RPP_VARIADIC_SEQ_IS_NIL
# endif
#
# endif

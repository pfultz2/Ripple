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
# ifndef RIPPLE_PREPROCESSOR_SEQ_CORE_H
# define RIPPLE_PREPROCESSOR_SEQ_CORE_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/compl.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ */
#
# define RPP_SEQ RPP_SEQ
# define RPP_SEQ_ID() RPP_SEQ
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_SEQ_TAG */
#
# define RPP_SEQ_TAG(tag) tag
# define RPP_SEQ_TAG_ID() RPP_SEQ_TAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_SEQ_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_NIL()
# else
#    define RPP_SEQ_NIL() ~
# endif
#
# define RPP_SEQ_NIL_ID() RPP_SEQ_NIL
#
# /* RPP_SEQ_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_CONS(seq, ...) (__VA_ARGS__) seq
# else
#    define RPP_SEQ_CONS(seq, x) (x) RPP_INLINE_WHEN(RPP_IS_UNARY(seq))(seq)
# endif
#
# define RPP_SEQ_CONS_ID() RPP_SEQ_CONS
#
# /* RPP_SEQ_ITEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_ITEM(...) __VA_ARGS__
# else
#    define RPP_SEQ_ITEM(x) x
# endif
#
# define RPP_SEQ_ITEM_ID() RPP_SEQ_ITEM
#
# /* RPP_SEQ_HEAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_HEAD(seq) RPP_TUPLE_REM_CTOR(?, RPP_SPLIT(0, DETAIL_RPP_SEQ_HEAD_I seq))
# else
#    define RPP_SEQ_HEAD(seq) RPP_SPLIT(0, DETAIL_RPP_SEQ_HEAD_I seq)
# endif
#
# define RPP_SEQ_HEAD_ID() RPP_SEQ_HEAD
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_HEAD_I(...) (__VA_ARGS__),
# else
#    define DETAIL_RPP_SEQ_HEAD_I(x) x, ~
# endif
#
# /* RPP_SEQ_TAIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_TAIL(seq) RPP_EAT seq
# else
#    define RPP_SEQ_TAIL(seq) \
        RPP_IIF(RPP_IS_UNARY(RPP_EAT seq ~))( \
            RPP_EAT seq, RPP_SEQ_NIL() \
        ) \
        /**/
# endif
#
# define RPP_SEQ_TAIL_ID() RPP_SEQ_TAIL
#
# /* RPP_SEQ_IS_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_IS_CONS(seq) RPP_IS_VARIADIC(seq)
# else
#    define RPP_SEQ_IS_CONS(seq) RPP_IS_UNARY(seq)
# endif
#
# define RPP_SEQ_IS_CONS_ID() RPP_SEQ_IS_CONS
#
# /* RPP_SEQ_IS_NIL */
#
# define RPP_SEQ_IS_NIL(seq) RPP_COMPL(RPP_SEQ_IS_CONS(seq))
# define RPP_SEQ_IS_NIL_ID() RPP_SEQ_IS_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

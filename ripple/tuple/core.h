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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_CORE_H
# define RIPPLE_PREPROCESSOR_TUPLE_CORE_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_empty.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/compl.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE RPP_TUPLE
#    define RPP_TUPLE_ID() RPP_TUPLE
# endif
#
# /* RPP_TUPLE_TAG */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TAG(tag) tag
#    define RPP_TUPLE_TAG_ID() RPP_TUPLE_TAG
# endif
#
# /* RPP_TUPLE_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_NIL()
#    define RPP_TUPLE_NIL_ID() RPP_TUPLE_NIL
# endif
#
# /* RPP_TUPLE_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_CONS(tuple, x) \
        (x RPP_INLINE_WHEN(RPP_TUPLE_IS_CONS(tuple))(, RPP_REM tuple)) \
        /**/
#    define RPP_TUPLE_CONS_ID() RPP_TUPLE_CONS
# endif
#
# /* RPP_TUPLE_ITEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_ITEM(x) x
#    define RPP_TUPLE_ITEM_ID() RPP_TUPLE_ITEM
# endif
#
# /* RPP_TUPLE_HEAD */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_HEAD(tuple) RPP_SPLIT(0, RPP_REM tuple,)
#    define RPP_TUPLE_HEAD_ID() RPP_TUPLE_HEAD
# endif
#
# /* RPP_TUPLE_TAIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_TAIL(tuple) \
        RPP_INLINE_WHEN( \
            RPP_COMPL(RPP_IS_EMPTY_NON_FUNCTION(RPP_SPLIT(1, RPP_REM tuple,))) \
        )((RPP_SPLIT(1, RPP_REM tuple))) \
        /**/
#    define RPP_TUPLE_TAIL_ID() RPP_TUPLE_TAIL
# endif
#
# /* RPP_TUPLE_IS_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_IS_CONS(tuple) RPP_IS_VARIADIC(tuple)
#    define RPP_TUPLE_IS_CONS_ID() RPP_TUPLE_IS_CONS
# endif
#
# /* RPP_TUPLE_IS_NIL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_IS_NIL(tuple) RPP_COMPL(RPP_TUPLE_IS_CONS(tuple))
#    define RPP_TUPLE_IS_NIL_ID() RPP_TUPLE_IS_NIL
# endif
#
# endif

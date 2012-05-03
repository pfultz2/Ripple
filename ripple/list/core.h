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
# ifndef RIPPLE_PREPROCESSOR_LIST_CORE_H
# define RIPPLE_PREPROCESSOR_LIST_CORE_H
#
# include <ripple/config.h>
# include <ripple/detection/is_binary.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/compl.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_LIST */
#
# define RPP_LIST RPP_LIST
# define RPP_LIST_ID() RPP_LIST
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_TAG */
#
# define RPP_LIST_TAG(tag) tag
# define RPP_LIST_TAG_ID() RPP_LIST_TAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_NIL */
#
# define RPP_LIST_NIL() ...
# define RPP_LIST_NIL_ID() RPP_LIST_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_CONS */
#
# define RPP_LIST_CONS(list, x) (x, list)
# define RPP_LIST_CONS_ID() RPP_LIST_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_ITEM */
#
# define RPP_LIST_ITEM(x) x
# define RPP_LIST_ITEM_ID() RPP_LIST_ITEM
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_HEAD */
#
# define RPP_LIST_HEAD(list) RPP_SPLIT(0, RPP_TUPLE_REM(2) list)
# define RPP_LIST_HEAD_ID() RPP_LIST_HEAD
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_TAIL */
#
# define RPP_LIST_TAIL(list) RPP_SPLIT(1, RPP_TUPLE_REM(2) list)
# define RPP_LIST_TAIL_ID() RPP_LIST_TAIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_IS_CONS */
#
# define RPP_LIST_IS_CONS(list) RPP_IS_BINARY(list)
# define RPP_LIST_IS_CONS_ID() RPP_LIST_IS_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_LIST_IS_NIL */
#
# define RPP_LIST_IS_NIL(list) RPP_COMPL(RPP_LIST_IS_CONS(list))
# define RPP_LIST_IS_NIL_ID() RPP_LIST_IS_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_GENERICS_CORE_H
# define RIPPLE_PREPROCESSOR_GENERICS_CORE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/generics/strip.h>
# include <ripple/generics/typeof.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TAG */
#
# define RPP_TAG(type) RPP_PRIMITIVE_CAT(type, _TAG)
# define RPP_TAG_ID() RPP_TAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_NIL */
#
# define RPP_NIL(type) (type) RPP_PRIMITIVE_CAT(type, _NIL)()
# define RPP_NIL_ID() RPP_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_CONS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_CONS(g, ...) DETAIL_RPP_CONS_I(RPP_TYPEOF(g), RPP_STRIP(g), (__VA_ARGS__))
# else
#    define RPP_CONS(g, x) DETAIL_RPP_CONS_I(RPP_TYPEOF(g), RPP_STRIP(g), (x))
# endif
#
# define RPP_CONS_ID() RPP_CONS
#
# define DETAIL_RPP_CONS_I(type, data, px) (type) RPP_PRIMITIVE_CAT(type, _CONS)(data, RPP_REM px)
#
# /* RPP_ITEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ITEM(type, ...) RPP_PRIMITIVE_CAT(type, _ITEM)(__VA_ARGS__)
# else
#    define RPP_ITEM(type, x) RPP_PRIMITIVE_CAT(type, _ITEM)(x)
# endif
#
# define RPP_ITEM_ID() RPP_ITEM
#
# /* RPP_HEAD */
#
# define RPP_HEAD(g) DETAIL_RPP_HEAD_I(RPP_TYPEOF(g), RPP_STRIP(g))
# define RPP_HEAD_ID() RPP_HEAD
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_HEAD_I(type, data) RPP_PRIMITIVE_CAT(type, _HEAD)(data)
#
# /* RPP_TAIL */
#
# define RPP_TAIL(g) DETAIL_RPP_TAIL_I(RPP_TYPEOF(g), RPP_STRIP(g))
# define RPP_TAIL_ID() RPP_TAIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_TAIL_I(type, data) (type) RPP_PRIMITIVE_CAT(type, _TAIL)(data)
#
# /* RPP_IS_CONS */
#
# define RPP_IS_CONS(g) DETAIL_RPP_IS_CONS_I(RPP_TYPEOF(g), RPP_STRIP(g))
# define RPP_IS_CONS_ID() RPP_IS_CONS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_IS_CONS_I(type, data) RPP_PRIMITIVE_CAT(type, _IS_CONS)(data)
#
# /* RPP_IS_NIL */
#
# define RPP_IS_NIL(g) DETAIL_RPP_IS_NIL_I(RPP_TYPEOF(g), RPP_STRIP(g))
# define RPP_IS_NIL_ID() RPP_IS_NIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_IS_NIL_I(type, data) RPP_PRIMITIVE_CAT(type, _IS_NIL)(data)
#
# endif

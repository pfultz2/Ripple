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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_INLINE_WHEN_H
# define RIPPLE_PREPROCESSOR_CONTROL_INLINE_WHEN_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_INLINE_WHEN */
#
# define RPP_INLINE_WHEN(bit) RPP_PRIMITIVE_CAT(DETAIL_RPP_INLINE_WHEN_, bit)
# define RPP_INLINE_WHEN_ID() RPP_INLINE_WHEN
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_INLINE_WHEN_0(...)
#    define DETAIL_RPP_INLINE_WHEN_1(...) __VA_ARGS__
# else
#    define DETAIL_RPP_INLINE_WHEN_0(x)
#    define DETAIL_RPP_INLINE_WHEN_1(x) x
# endif
#
# endif

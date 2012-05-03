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
# ifndef RIPPLE_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
# define RIPPLE_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/extended/variadic_cat.h>
#
# /* RPP_PARTIAL_CAT */
#
# define RPP_PARTIAL_CAT(i, j) RPP_CAT(DETAIL_RPP_PARTIAL_CAT_, RPP_PRIMITIVE_CAT(i, j))
# define RPP_PARTIAL_CAT_ID() RPP_PARTIAL_CAT
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_PARTIAL_CAT_00(a, ...) RPP_PRIMITIVE_CAT(RPP_PARTIAL ## a, __VA_ARGS__ ## RPP_PARTIAL)
#    define DETAIL_RPP_PARTIAL_CAT_01(a, ...) RPP_PRIMITIVE_CAT(RPP_PARTIAL ## a, __VA_ARGS__)
#    define DETAIL_RPP_PARTIAL_CAT_10(a, ...) RPP_PRIMITIVE_CAT(a, __VA_ARGS__ ## RPP_PARTIAL)
#    define DETAIL_RPP_PARTIAL_CAT_11(a, ...) RPP_PRIMITIVE_CAT(a, __VA_ARGS__)
# else
#    define DETAIL_RPP_PARTIAL_CAT_00(a, b) RPP_PRIMITIVE_CAT(RPP_PARTIAL ## a, b ## RPP_PARTIAL)
#    define DETAIL_RPP_PARTIAL_CAT_01(a, b) RPP_PRIMITIVE_CAT(RPP_PARTIAL ## a, b)
#    define DETAIL_RPP_PARTIAL_CAT_10(a, b) RPP_PRIMITIVE_CAT(a, b ## RPP_PARTIAL)
#    define DETAIL_RPP_PARTIAL_CAT_11(a, b) RPP_PRIMITIVE_CAT(a, b)
# endif
#
# define RPP_PARTIALRPP_PARTIAL
#
# /* RPP_PARTIAL */
#
# define RPP_PARTIAL
#
# /* RPP_PARTIAL_CAT_II */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PARTIAL_CAT_II(i, j) RPP_VARIADIC_CAT(DETAIL_RPP_PARTIAL_CAT_II_, i, j)
#    define RPP_PARTIAL_CAT_II_ID() RPP_PARTIAL_CAT_II
#    define DETAIL_RPP_PARTIAL_CAT_II_00(p, ...) RPP_PRIMITIVE_CAT(p ## __VA_ARGS__)
#    define DETAIL_RPP_PARTIAL_CAT_II_01(p, a, ...) RPP_PRIMITIVE_CAT(p ## a, __VA_ARGS__)
#    define DETAIL_RPP_PARTIAL_CAT_II_10(p, a, ...) RPP_PRIMITIVE_CAT(a, p ## __VA_ARGS__)
#    define DETAIL_RPP_PARTIAL_CAT_II_11(p, ...) RPP_PRIMITIVE_CAT(__VA_ARGS__)
# endif
#
# endif

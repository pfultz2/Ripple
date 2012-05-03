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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SCAN_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SCAN_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_SCAN */
#
# define RPP_SCAN(level) RPP_PRIMITIVE_CAT(DETAIL_RPP_SCAN_, level)
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SCAN_1(...) __VA_ARGS__
#    define DETAIL_RPP_SCAN_2(...) __VA_ARGS__
#    define DETAIL_RPP_SCAN_3(...) __VA_ARGS__
#    define DETAIL_RPP_SCAN_4(...) __VA_ARGS__
# else
#    define DETAIL_RPP_SCAN_1(x) x
#    define DETAIL_RPP_SCAN_2(x) x
#    define DETAIL_RPP_SCAN_3(x) x
#    define DETAIL_RPP_SCAN_4(x) x
# endif
#
# endif

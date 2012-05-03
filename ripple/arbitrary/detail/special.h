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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SPECIAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SPECIAL_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/punctuation/paren.h>
#
# /* RPP_SPECIAL */
#
# define RPP_SPECIAL(digit) RPP_PRIMITIVE_CAT(DETAIL_RPP_SPECIAL_, digit)
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SPECIAL_00(...)
#    define DETAIL_RPP_SPECIAL_0(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_1(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_2(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_3(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_4(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_5(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_6(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_7(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_8(...) __VA_ARGS__
#    define DETAIL_RPP_SPECIAL_9(...) __VA_ARGS__
# else
#    define DETAIL_RPP_SPECIAL_00(x)
#    define DETAIL_RPP_SPECIAL_0(x) x
#    define DETAIL_RPP_SPECIAL_1(x) x
#    define DETAIL_RPP_SPECIAL_2(x) x
#    define DETAIL_RPP_SPECIAL_3(x) x
#    define DETAIL_RPP_SPECIAL_4(x) x
#    define DETAIL_RPP_SPECIAL_5(x) x
#    define DETAIL_RPP_SPECIAL_6(x) x
#    define DETAIL_RPP_SPECIAL_7(x) x
#    define DETAIL_RPP_SPECIAL_8(x) x
#    define DETAIL_RPP_SPECIAL_9(x) x
# endif
#
# /* RPP_SPECIAL_CLOSE */
#
# define RPP_SPECIAL_CLOSE(x) DETAIL_RPP_SPECIAL_CLOSE_A x(00)
#
# define DETAIL_RPP_SPECIAL_CLOSE_A(digit) RPP_SPECIAL(digit)(RPP_RPAREN() DETAIL_RPP_SPECIAL_CLOSE_B)
# define DETAIL_RPP_SPECIAL_CLOSE_B(digit) RPP_SPECIAL(digit)(RPP_RPAREN() DETAIL_RPP_SPECIAL_CLOSE_A)
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_BINARY_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_SEQ_BINARY_TRANSFORM_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_BINARY_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_BINARY_TRANSFORM(seq, ...) RPP_CAT(DETAIL_RPP_SEQ_BINARY_TRANSFORM_A seq, 0)(RPP_TUPLE_EAT, __VA_ARGS__)
# else
#    define RPP_SEQ_BINARY_TRANSFORM(seq, def) RPP_CAT(DETAIL_RPP_SEQ_BINARY_TRANSFORM_A seq, 0)(RPP_TUPLE_EAT, def)
# endif
#
# define RPP_SEQ_BINARY_TRANSFORM_ID() RPP_SEQ_BINARY_TRANSFORM
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_A(...) (RPP_TUPLE_REM, __VA_ARGS__)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_B
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_B(...) (RPP_TUPLE_REM, __VA_ARGS__)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_A
# else
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_A(x) (RPP_TUPLE_REM, x)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_B
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_B(x) (RPP_TUPLE_REM, x)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_A
# endif
#
# define DETAIL_RPP_SEQ_BINARY_TRANSFORM_A0
# define DETAIL_RPP_SEQ_BINARY_TRANSFORM_B0
#
# /* RPP_SEQ_BINARY_TRANSFORM_2ND */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_BINARY_TRANSFORM_2ND(seq, ...) RPP_CAT(DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A seq, 0)(0, __VA_ARGS__)
# else
#    define RPP_SEQ_BINARY_TRANSFORM_2ND(seq, def) RPP_CAT(DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A seq, 0)(0, def)
# endif
#
# define RPP_SEQ_BINARY_TRANSFORM_2ND_ID() RPP_SEQ_BINARY_TRANSFORM_2ND
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A(...) (1, __VA_ARGS__)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_B
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_B(...) (1, __VA_ARGS__)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A
# else
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A(x) (1, x)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_B
#    define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_B(x) (1, x)() DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A
# endif
#
# define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_A0
# define DETAIL_RPP_SEQ_BINARY_TRANSFORM_2ND_B0
#
# endif

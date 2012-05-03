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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_PLUS_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_PLUS_H
#
# include <ripple/arbitrary/detail/lookup.h>
# include <ripple/cat.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/indirect.h>
#
# /* RPP_PLUS */
#
# define RPP_PLUS(a, b) \
    RPP_ARBITRARY_LOOKUP(b, RPP_ARBITRARY_LOOKUP(a, ( \
        ((0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9)), \
        ((0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0)), \
        ((0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1)), \
        ((0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2)), \
        ((0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3)), \
        ((0, 5), (0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4)), \
        ((0, 6), (0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5)), \
        ((0, 7), (0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6)), \
        ((0, 8), (0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7)), \
        ((0, 9), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8)) \
    ))) \
    /**/
#
# /* RPP_PLUS_3RD */
#
# define RPP_PLUS_3RD(mode) RPP_PRIMITIVE_CAT(DETAIL_RPP_PLUS_3RD_, mode)
#
# define DETAIL_RPP_PLUS_3RD_0(bin) (RPP_BINARY(1) bin) RPP_INDIRECT(RPP_BINARY(0) bin)
# define DETAIL_RPP_PLUS_3RD_1(bin, n) DETAIL_RPP_PLUS_3RD_2(RPP_BINARY(0) bin, RPP_PLUS(RPP_BINARY(1) bin, n))
# define DETAIL_RPP_PLUS_3RD_2(a, bin) (RPP_BINARY(1) bin) RPP_INDIRECT(RPP_BINARY_CTOR(1, RPP_PLUS(a, RPP_BINARY(0) bin)))
#
# endif

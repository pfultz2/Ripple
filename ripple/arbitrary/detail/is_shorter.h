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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
#
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/detection/is_unary.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_ARBITRARY_IS_SHORTER */
#
# define RPP_ARBITRARY_IS_SHORTER(x, y) \
    RPP_IS_UNARY(RPP_SCAN(1)( \
        DETAIL_RPP_ARBITRARY_IS_SHORTER_A x(00) y ~ RPP_SPECIAL_CLOSE(x) \
    )) \
    /**/
#
# define DETAIL_RPP_ARBITRARY_IS_SHORTER_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_IS_SHORTER_I RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_IS_SHORTER_B)
# define DETAIL_RPP_ARBITRARY_IS_SHORTER_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_IS_SHORTER_I RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_IS_SHORTER_A)
# define DETAIL_RPP_ARBITRARY_IS_SHORTER_I(y) RPP_EAT y
#
# endif

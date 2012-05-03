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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_MUL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_MUL_H
#
# include <ripple/arbitrary/add.h>
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/merge.h>
# include <ripple/arbitrary/detail/plus.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/detail/times.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/control/inline_unless.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/logical/bitxor.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/reverse.h>
# include <ripple/tuple/elem.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_MUL */
#
# define RPP_ARBITRARY_MUL(x, y) DETAIL_RPP_ARBITRARY_MUL_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_MUL_ID() RPP_ARBITRARY_MUL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_MUL_I(x, y) \
    RPP_INLINE_UNLESS(RPP_BITXOR(RPP_ARBITRARY_SIGN(x))(RPP_ARBITRARY_SIGN(y)))( \
        RPP_REM \
    )(RPP_ARBITRARY_MUL_INTERNAL( \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))(RPP_REM) x, \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(y))(RPP_REM) y \
    )) \
    /**/
#
# /* RPP_ARBITRARY_MUL_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_MUL_INTERNAL(x, y) \
        RPP_SPLIT( \
            0, \
            RPP_SCAN(2)(DETAIL_RPP_ARBITRARY_MUL_A x(00), y,, RPP_BINARY(1) RPP_SPECIAL_CLOSE(x)) \
        ) \
        /**/
# else
#    define RPP_ARBITRARY_MUL_INTERNAL(x, y) \
        RPP_TUPLE_ELEM( \
            4, 0, \
            (RPP_SCAN(2)( \
                DETAIL_RPP_ARBITRARY_MUL_A x(00) RPP_DEFER(RPP_TUPLE_REM)(4)(~, y, (), RPP_BINARY(1)) RPP_SPECIAL_CLOSE(x) \
            )) \
        ) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_MUL_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_MUL_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_MUL_B)
#    define DETAIL_RPP_ARBITRARY_MUL_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_MUL_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_MUL_A)
#    define DETAIL_RPP_ARBITRARY_MUL_II(...) DETAIL_RPP_ARBITRARY_MUL_III(__VA_ARGS__)
#    define DETAIL_RPP_ARBITRARY_MUL_III(digit, res, y, shift, add) \
        add( \
            res, \
            RPP_ARBITRARY_FIX_INTERNAL( \
                RPP_SEQ_REVERSE(RPP_SCAN(1)( \
                    DETAIL_RPP_ARBITRARY_MUL_M(0) RPP_ARBITRARY_RMERGE(y, (digit), DETAIL_RPP_ARBITRARY_MUL_M, digit)() \
                )) \
                shift \
            ) \
        ), \
        y, shift(0), RPP_ARBITRARY_ADD_INTERNAL \
        /**/
# else
#    define DETAIL_RPP_ARBITRARY_MUL_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_MUL_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_MUL_B)
#    define DETAIL_RPP_ARBITRARY_MUL_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_MUL_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_MUL_A)
#    define DETAIL_RPP_ARBITRARY_MUL_II(digit, im) DETAIL_RPP_ARBITRARY_MUL_III(digit, im)
#    define DETAIL_RPP_ARBITRARY_MUL_III(digit, res, y, shift, add) \
        add( \
            res, \
            RPP_ARBITRARY_FIX_INTERNAL( \
                RPP_SEQ_REVERSE(RPP_SCAN(1)( \
                    DETAIL_RPP_ARBITRARY_MUL_M(0) RPP_ARBITRARY_RMERGE(y, (digit), DETAIL_RPP_ARBITRARY_MUL_M, digit)(RPP_DEFER(RPP_EMPTY)()) \
                )) \
                RPP_EMPTY shift \
            ) \
        ), \
        y, shift(0), RPP_ARBITRARY_ADD_INTERNAL \
        /**/
# endif
#
# define DETAIL_RPP_ARBITRARY_MUL_M(carry) DETAIL_RPP_ARBITRARY_MUL_ ## carry
# define DETAIL_RPP_ARBITRARY_MUL_0(x, y) RPP_PLUS_3RD(0)(RPP_TIMES(x, y))
# define DETAIL_RPP_ARBITRARY_MUL_1(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 1)
# define DETAIL_RPP_ARBITRARY_MUL_2(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 2)
# define DETAIL_RPP_ARBITRARY_MUL_3(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 3)
# define DETAIL_RPP_ARBITRARY_MUL_4(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 4)
# define DETAIL_RPP_ARBITRARY_MUL_5(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 5)
# define DETAIL_RPP_ARBITRARY_MUL_6(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 6)
# define DETAIL_RPP_ARBITRARY_MUL_7(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 7)
# define DETAIL_RPP_ARBITRARY_MUL_8(x, y) RPP_PLUS_3RD(1)(RPP_TIMES(x, y), 8)
#
# endif

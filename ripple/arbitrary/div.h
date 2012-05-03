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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DIV_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DIV_H
#
# include <ripple/arbitrary/bool.h>
# include <ripple/arbitrary/detail/divide.h>
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/merge.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/equal.h>
# include <ripple/arbitrary/less.h>
# include <ripple/arbitrary/less_equal.h>
# include <ripple/arbitrary/mul.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/arbitrary/sub.h>
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_unless.h>
# include <ripple/control/inline_when.h>
# include <ripple/debug/failure.h>
# include <ripple/detection/is_unary.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/empty.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/core.h>
# include <ripple/seq/reverse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_DIV */
#
# define RPP_ARBITRARY_DIV(x, y) DETAIL_RPP_ARBITRARY_DIV_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_DIV_ID() RPP_ARBITRARY_DIV
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_DIV_I(x, y) \
    RPP_INLINE_UNLESS(RPP_BITXOR(RPP_ARBITRARY_SIGN(x))(RPP_ARBITRARY_SIGN(y)))( \
        RPP_REM \
    )(RPP_ARBITRARY_DIV_INTERNAL( \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))(RPP_REM) x, \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(y))(RPP_REM) y \
    )) \
    /**/
#
# /* RPP_ARBITRARY_DIV_INTERNAL */
#
# define RPP_ARBITRARY_DIV_INTERNAL(x, y) \
    RPP_ARBITRARY_FIX(RPP_BINARY_CTOR(0, DETAIL_RPP_ARBITRARY_DIV_1(x, y))) \
    /**/
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_DIV_1(x, y) \
        RPP_IIF(RPP_ARBITRARY_BOOL_INTERNAL(y))( \
            RPP_IIF(RPP_ARBITRARY_LESS_INTERNAL(x, y))( \
                ((0), x), \
                RPP_IIF(RPP_ARBITRARY_EQUAL_INTERNAL(x, y))( \
                    ((1), (0)), \
                    RPP_SCAN(2)(RPP_DEFER(DETAIL_RPP_ARBITRARY_DIV_3)( \
                        y, RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_DIV_A y(00) DETAIL_RPP_ARBITRARY_DIV_2(RPP_DEFER(RPP_OBSTRUCT)(), x, y,) RPP_SPECIAL_CLOSE(y)) \
                    )) \
                ) \
            ), \
            RPP_FAILURE() \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_2(_, x, y, rem) \
        RPP_IIF(RPP_IS_UNARY(y))( \
            DETAIL_RPP_ARBITRARY_DIV_INDIRECT _(2)( \
                RPP_DEFER _(RPP_OBSTRUCT)(), RPP_EAT x, RPP_EAT y, rem _(RPP_SEQ_HEAD _(x)) \
            ), \
            RPP_INLINE_UNLESS _(RPP_IS_UNARY _(RPP_EAT _ rem))((0)) rem, x \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_3(y, rem, pool) \
        RPP_SCAN(3)(DETAIL_RPP_ARBITRARY_DIV_X (0)pool(00)(DETAIL_RPP_ARBITRARY_DIV_4(y, RPP_SEQ_HEAD(y), rem, pool)) RPP_SPECIAL_CLOSE((0)pool)) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_5(y, digit, est, rem, pool) \
        DETAIL_RPP_ARBITRARY_DIV_6( \
            y, digit, est, \
            RPP_ARBITRARY_FIX_INTERNAL(RPP_SEQ_REVERSE(RPP_SCAN(1)( \
                DETAIL_RPP_ARBITRARY_MUL_M(0) RPP_ARBITRARY_RMERGE(y, (est), DETAIL_RPP_ARBITRARY_MUL_M, est)() \
            ))), \
            rem, pool \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_7(y, digit, diff, pool) \
        RPP_IIF(RPP_IS_UNARY(pool))( \
            DETAIL_RPP_ARBITRARY_DIV_INDIRECT RPP_OBSTRUCT()(4)( \
                y, digit, diff(RPP_SEQ_HEAD(pool)), RPP_EAT pool \
            ), \
            , diff \
        ) \
        /**/
# else
#    define DETAIL_RPP_ARBITRARY_DIV_ID(x) (x)
#    define DETAIL_RPP_ARBITRARY_DIV_1(x, y) \
        RPP_IIF(RPP_ARBITRARY_BOOL_INTERNAL(y))( \
            RPP_IIF(RPP_ARBITRARY_LESS_INTERNAL(x, y))( \
                ((0), x), \
                RPP_IIF(RPP_ARBITRARY_EQUAL_INTERNAL(x, y))( \
                    ((1), (0)), \
                    RPP_SCAN(2)(RPP_DEFER(DETAIL_RPP_ARBITRARY_DIV_3)( \
                        y, RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_DIV_A y(00) DETAIL_RPP_ARBITRARY_DIV_2(RPP_DEFER(RPP_OBSTRUCT)(), x RPP_EMPTY, y ~, DETAIL_RPP_ARBITRARY_DIV_ID) RPP_SPECIAL_CLOSE(y)) \
                    )) \
                ) \
            ), \
            RPP_FAILURE() \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_2(_, x, y, rem) \
        RPP_IIF(RPP_IS_UNARY(y))( \
            DETAIL_RPP_ARBITRARY_DIV_INDIRECT _(2)( \
                RPP_DEFER _(RPP_OBSTRUCT)(), RPP_EAT x, RPP_EAT y, rem _(RPP_SEQ_HEAD _(x)) \
            ), \
            RPP_INLINE_UNLESS _(RPP_IS_UNARY _(RPP_EAT _ rem ~))((0)) rem RPP_COMMA _() x \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_3(y, rem, pool) \
        RPP_SCAN(3)(DETAIL_RPP_ARBITRARY_DIV_X (0)pool()(00) (DETAIL_RPP_ARBITRARY_DIV_4(y, RPP_SEQ_HEAD(y), rem, pool() ~)) RPP_SPECIAL_CLOSE((0)pool())) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_5(y, digit, est, rem, pool) \
        DETAIL_RPP_ARBITRARY_DIV_6( \
            y, digit, est, \
            RPP_ARBITRARY_FIX_INTERNAL(RPP_SEQ_REVERSE(RPP_SCAN(1)( \
                DETAIL_RPP_ARBITRARY_MUL_M(0) RPP_ARBITRARY_RMERGE(y, (est), DETAIL_RPP_ARBITRARY_MUL_M, est)(RPP_DEFER(RPP_EMPTY)()) \
            ))), \
            rem, pool \
        ) \
        /**/
#    define DETAIL_RPP_ARBITRARY_DIV_7(y, digit, diff, pool) \
        RPP_IIF(RPP_IS_UNARY(pool))( \
            DETAIL_RPP_ARBITRARY_DIV_INDIRECT RPP_OBSTRUCT()(4)( \
                y, digit, diff(RPP_SEQ_HEAD(pool)), RPP_EAT pool \
            ), \
            RPP_COMMA() diff \
        ) \
        /**/
# endif
#
# define DETAIL_RPP_DIV_MULTISCAN(x) \
    RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)( \
        RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)(RPP_SCAN(4)(x))))) \
    ))))) \
    /**/
#
# define DETAIL_RPP_ARBITRARY_DIV_A(digit) RPP_SPECIAL(digit)(RPP_SCAN(2) RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DIV_B)
# define DETAIL_RPP_ARBITRARY_DIV_B(digit) RPP_SPECIAL(digit)(RPP_SCAN(2) RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DIV_A)
# define DETAIL_RPP_ARBITRARY_DIV_X(digit) RPP_SPECIAL(digit)(DETAIL_RPP_DIV_MULTISCAN RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DIV_Y)
# define DETAIL_RPP_ARBITRARY_DIV_Y(digit) RPP_SPECIAL(digit)(DETAIL_RPP_DIV_MULTISCAN RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DIV_X)
#
# define DETAIL_RPP_ARBITRARY_DIV_INDIRECT(n) DETAIL_RPP_ARBITRARY_DIV_ ## n
#
# define DETAIL_RPP_ARBITRARY_DIV_4(y, digit, rem, pool) \
    DETAIL_RPP_ARBITRARY_DIV_5(y, digit, RPP_DIVIDE(RPP_SEQ_HEAD(rem), RPP_SEQ_HEAD(RPP_EAT rem), digit), rem, pool) \
    /**/
# define DETAIL_RPP_ARBITRARY_DIV_6(y, digit, est, trial, rem, pool) \
    RPP_IIF(RPP_ARBITRARY_LESS_EQUAL_INTERNAL(trial, rem))( \
        (est) DETAIL_RPP_ARBITRARY_DIV_7, \
        DETAIL_RPP_ARBITRARY_DIV_INDIRECT RPP_OBSTRUCT()(5)( \
            y, digit, RPP_DEC(est), rem, pool \
        ) RPP_TUPLE_EAT(4) \
    )(y, digit, RPP_ARBITRARY_SUB_INTERNAL(rem, trial), pool) \
    /**/
#
# endif

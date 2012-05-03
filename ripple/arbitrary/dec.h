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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DEC_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DEC_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/inc.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_DEC */
#
# define RPP_ARBITRARY_DEC(x) DETAIL_RPP_ARBITRARY_DEC_I(RPP_ARBITRARY_FIX(x))
# define RPP_ARBITRARY_DEC_ID() RPP_ARBITRARY_DEC
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_DEC_I(x) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        (RPP_ARBITRARY_INC_INTERNAL(RPP_REM x)), \
        RPP_IIF(RPP_ARBITRARY_BOOL_INTERNAL(x))( \
            RPP_ARBITRARY_DEC_INTERNAL(x), ((1)) \
        ) \
    ) \
    /**/
#
# /* RPP_ARBITRARY_DEC_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_DEC_INTERNAL(x) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SPLIT( \
            0, \
            RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_DEC_A x(00), DETAIL_RPP_ARBITRARY_DEC_IV RPP_SPECIAL_CLOSE(x)) \
        )) \
        /**/
# else
#    define RPP_ARBITRARY_DEC_INTERNAL(x) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SPLIT( \
            0, \
            RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_DEC_A x(00) RPP_EMPTY RPP_DEFER(RPP_COMMA)() DETAIL_RPP_ARBITRARY_DEC_IV RPP_SPECIAL_CLOSE(x)) \
        )()) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_DEC_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_DEC_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_DEC_B)
#    define DETAIL_RPP_ARBITRARY_DEC_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_DEC_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_DEC_A)
#    define DETAIL_RPP_ARBITRARY_DEC_II(...) DETAIL_RPP_ARBITRARY_DEC_III(__VA_ARGS__)
# else
#    define DETAIL_RPP_ARBITRARY_DEC_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_DEC_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_DEC_B)
#    define DETAIL_RPP_ARBITRARY_DEC_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_DEC_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_DEC_A)
#    define DETAIL_RPP_ARBITRARY_DEC_II(digit, im) DETAIL_RPP_ARBITRARY_DEC_III(digit, im)
# endif
#
# define DETAIL_RPP_ARBITRARY_DEC_III(digit, res, op) op(digit)(res)
# define DETAIL_RPP_ARBITRARY_DEC_IV(digit) DETAIL_RPP_ARBITRARY_DEC_ ## digit
# define DETAIL_RPP_ARBITRARY_DEC_V(digit) (digit) DETAIL_RPP_ARBITRARY_DEC_VI
# define DETAIL_RPP_ARBITRARY_DEC_VI(res) res, DETAIL_RPP_ARBITRARY_DEC_V
#
# define DETAIL_RPP_ARBITRARY_DEC_0(res) (9) res, DETAIL_RPP_ARBITRARY_DEC_IV
# define DETAIL_RPP_ARBITRARY_DEC_1(res) (0) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_2(res) (1) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_3(res) (2) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_4(res) (3) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_5(res) (4) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_6(res) (5) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_7(res) (6) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_8(res) (7) res, DETAIL_RPP_ARBITRARY_DEC_V
# define DETAIL_RPP_ARBITRARY_DEC_9(res) (8) res, DETAIL_RPP_ARBITRARY_DEC_V
#
# endif

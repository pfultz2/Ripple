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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_INC_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_INC_H
#
# include <ripple/arbitrary/dec.h>
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_INC */
#
# define RPP_ARBITRARY_INC(x) DETAIL_RPP_ARBITRARY_INC_I(RPP_ARBITRARY_FIX(x))
# define RPP_ARBITRARY_INC_ID() RPP_ARBITRARY_INC
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_INC_I(x) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        RPP_ARBITRARY_FIX((RPP_ARBITRARY_DEC_INTERNAL(RPP_REM x))), \
        RPP_ARBITRARY_INC_INTERNAL(x) \
    ) \
    /**/
#
# /* RPP_ARBITRARY_INC_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_INC_INTERNAL(x) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SPLIT( \
            0, \
            RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_INC_A (0)x(00), DETAIL_RPP_ARBITRARY_INC_IV RPP_SPECIAL_CLOSE((0)x)) \
        )) \
        /**/
# else
#    define RPP_ARBITRARY_INC_INTERNAL(x) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SPLIT( \
            0, \
            RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_INC_A (0)x(00) RPP_EMPTY RPP_DEFER(RPP_COMMA)() DETAIL_RPP_ARBITRARY_INC_IV RPP_SPECIAL_CLOSE((0)x)) \
        )()) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_INC_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_INC_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_INC_B)
#    define DETAIL_RPP_ARBITRARY_INC_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_INC_II RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_INC_A)
#    define DETAIL_RPP_ARBITRARY_INC_II(...) DETAIL_RPP_ARBITRARY_INC_III(__VA_ARGS__)
# else
#    define DETAIL_RPP_ARBITRARY_INC_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_INC_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_INC_B)
#    define DETAIL_RPP_ARBITRARY_INC_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_INC_II RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_INC_A)
#    define DETAIL_RPP_ARBITRARY_INC_II(digit, im) DETAIL_RPP_ARBITRARY_INC_III(digit, im)
# endif
#
# define DETAIL_RPP_ARBITRARY_INC_III(digit, res, op) op(digit)(res)
# define DETAIL_RPP_ARBITRARY_INC_IV(digit) DETAIL_RPP_ARBITRARY_INC_ ## digit
# define DETAIL_RPP_ARBITRARY_INC_V(digit) (digit) DETAIL_RPP_ARBITRARY_INC_VI
# define DETAIL_RPP_ARBITRARY_INC_VI(res) res, DETAIL_RPP_ARBITRARY_INC_V
#
# define DETAIL_RPP_ARBITRARY_INC_0(res) (1) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_1(res) (2) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_2(res) (3) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_3(res) (4) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_4(res) (5) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_5(res) (6) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_6(res) (7) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_7(res) (8) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_8(res) (9) res, DETAIL_RPP_ARBITRARY_INC_V
# define DETAIL_RPP_ARBITRARY_INC_9(res) (0) res, DETAIL_RPP_ARBITRARY_INC_IV
#
# endif

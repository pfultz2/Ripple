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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DEMOTE_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DEMOTE_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_DEMOTE */
#
# define RPP_ARBITRARY_DEMOTE(x) DETAIL_RPP_ARBITRARY_DEMOTE_I(RPP_ARBITRARY_FIX(x))
# define RPP_ARBITRARY_DEMOTE_ID() RPP_ARBITRARY_DEMOTE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_DEMOTE_I(x) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        -RPP_ARBITRARY_DEMOTE_INTERNAL(RPP_REM x), \
        RPP_ARBITRARY_DEMOTE_INTERNAL(x) \
    ) \
    /**/
#
# /* RPP_ARBITRARY_DEMOTE_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_DEMOTE_INTERNAL(x) \
        RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_DEMOTE_A x(00) DETAIL_RPP_ARBITRARY_DEMOTE_X x(00)) \
        /**/
# else
#    define RPP_ARBITRARY_DEMOTE_INTERNAL(x) \
        RPP_SCAN(1)(RPP_SCAN(1)( \
            DETAIL_RPP_ARBITRARY_DEMOTE_A RPP_EAT x(00) RPP_SEQ_HEAD(x) DETAIL_RPP_ARBITRARY_DEMOTE_X RPP_EAT x(00) \
        )) \
        /**/
# endif
#
# define DETAIL_RPP_ARBITRARY_DEMOTE_A(digit) RPP_SPECIAL(digit)(RPP_CAT RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DEMOTE_B)
# define DETAIL_RPP_ARBITRARY_DEMOTE_B(digit) RPP_SPECIAL(digit)(RPP_CAT RPP_DEFER(RPP_LPAREN)() DETAIL_RPP_ARBITRARY_DEMOTE_A)
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_DEMOTE_X(digit) RPP_SPECIAL(digit)(, digit RPP_RPAREN() DETAIL_RPP_ARBITRARY_DEMOTE_Y)
#    define DETAIL_RPP_ARBITRARY_DEMOTE_Y(digit) RPP_SPECIAL(digit)(, digit RPP_RPAREN() DETAIL_RPP_ARBITRARY_DEMOTE_X)
# else
#    define DETAIL_RPP_ARBITRARY_DEMOTE_X(digit) RPP_SPECIAL(digit)(RPP_COMMA() digit RPP_RPAREN() DETAIL_RPP_ARBITRARY_DEMOTE_Y)
#    define DETAIL_RPP_ARBITRARY_DEMOTE_Y(digit) RPP_SPECIAL(digit)(RPP_COMMA() digit RPP_RPAREN() DETAIL_RPP_ARBITRARY_DEMOTE_X)
# endif
#
# endif

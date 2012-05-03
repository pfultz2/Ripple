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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_MERGE_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_MERGE_H
#
# include <ripple/arbitrary/detail/is_shorter.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/detail/special.h>
# include <ripple/arbitrary/detail/swap.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/core.h>
# include <ripple/seq/reverse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/elem.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_FMERGE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_FMERGE(x, y, op, def) \
        RPP_SCAN(1)(RPP_EAT RPP_SPLIT( \
            0, \
            RPP_IIF(RPP_ARBITRARY_IS_SHORTER(x, y))( \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_FMERGE_A y(00), RPP_SEQ_REVERSE(x), op, def, RPP_SWAP RPP_SPECIAL_CLOSE(y)), \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_FMERGE_A x(00), RPP_SEQ_REVERSE(y), op, def, RPP_SPECIAL_CLOSE(x)) \
            ) \
        )) \
        /**/
# else
#    define RPP_ARBITRARY_FMERGE(x, y, op, def) \
        RPP_SCAN(1)(RPP_EAT RPP_TUPLE_ELEM( \
            5, 0, \
            (RPP_IIF(RPP_ARBITRARY_IS_SHORTER(x, y))( \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_FMERGE_A y(00) RPP_DEFER(RPP_TUPLE_REM)(5)(RPP_EMPTY, RPP_SEQ_REVERSE(x), op, def, RPP_SWAP) RPP_SPECIAL_CLOSE(y)), \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_FMERGE_A x(00) RPP_DEFER(RPP_TUPLE_REM)(5)(RPP_EMPTY, RPP_SEQ_REVERSE(y), op, def, RPP_NO_SWAP) RPP_SPECIAL_CLOSE(x)) \
            )) \
        )()) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_FMERGE_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_FMERGE_I RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_FMERGE_B)
#    define DETAIL_RPP_ARBITRARY_FMERGE_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_FMERGE_I RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_FMERGE_A)
#    define DETAIL_RPP_ARBITRARY_FMERGE_I(...) DETAIL_RPP_ARBITRARY_FMERGE_II(__VA_ARGS__)
#    define DETAIL_RPP_ARBITRARY_FMERGE_II(digit, res, y, op, def, swap) \
        (op) swap(digit, RPP_SEQ_HEAD(y)) res, RPP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# else
#    define DETAIL_RPP_ARBITRARY_FMERGE_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_FMERGE_I RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_FMERGE_B)
#    define DETAIL_RPP_ARBITRARY_FMERGE_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_FMERGE_I RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_FMERGE_A)
#    define DETAIL_RPP_ARBITRARY_FMERGE_I(digit, im) DETAIL_RPP_ARBITRARY_FMERGE_II(digit, im)
#    define DETAIL_RPP_ARBITRARY_FMERGE_II(digit, res, y, op, def, swap) \
        (op) swap(digit, RPP_SEQ_HEAD(y)) res, RPP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# endif
#
# /* RPP_ARBITRARY_RMERGE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_RMERGE(x, y, op, def) \
        RPP_SPLIT( \
            0, \
            RPP_IIF(RPP_ARBITRARY_IS_SHORTER(x, y))( \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_RMERGE_A y(00) RPP_EAT, RPP_SEQ_REVERSE(x), op, def, RPP_SWAP RPP_SPECIAL_CLOSE(y)), \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_RMERGE_A x(00) RPP_EAT, RPP_SEQ_REVERSE(y), op, def, RPP_SPECIAL_CLOSE(x)) \
            ) \
        ) \
        /**/
# else
#    define RPP_ARBITRARY_RMERGE(x, y, op, def) \
        RPP_TUPLE_ELEM( \
            5, 0, \
            (RPP_IIF(RPP_ARBITRARY_IS_SHORTER(x, y))( \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_RMERGE_A y(00) RPP_DEFER(RPP_TUPLE_REM)(5)(RPP_EAT, RPP_SEQ_REVERSE(x), op, def, RPP_SWAP) RPP_SPECIAL_CLOSE(y)), \
                RPP_SCAN(1)(DETAIL_RPP_ARBITRARY_RMERGE_A x(00) RPP_DEFER(RPP_TUPLE_REM)(5)(RPP_EAT, RPP_SEQ_REVERSE(y), op, def, RPP_NO_SWAP) RPP_SPECIAL_CLOSE(x)) \
            )) \
        ) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_RMERGE_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_RMERGE_I RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_RMERGE_B)
#    define DETAIL_RPP_ARBITRARY_RMERGE_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_RMERGE_I RPP_DEFER(RPP_LPAREN)() digit, DETAIL_RPP_ARBITRARY_RMERGE_A)
#    define DETAIL_RPP_ARBITRARY_RMERGE_I(...) DETAIL_RPP_ARBITRARY_RMERGE_II(__VA_ARGS__)
#    define DETAIL_RPP_ARBITRARY_RMERGE_II(digit, res, y, op, def, swap) \
        res(op) swap(digit, RPP_SEQ_HEAD(y)), RPP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# else
#    define DETAIL_RPP_ARBITRARY_RMERGE_A(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_RMERGE_I RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_RMERGE_B)
#    define DETAIL_RPP_ARBITRARY_RMERGE_B(digit) RPP_SPECIAL(digit)(DETAIL_RPP_ARBITRARY_RMERGE_I RPP_DEFER(RPP_LPAREN)() digit RPP_COMMA() DETAIL_RPP_ARBITRARY_RMERGE_A)
#    define DETAIL_RPP_ARBITRARY_RMERGE_I(digit, im) DETAIL_RPP_ARBITRARY_RMERGE_II(digit, im)
#    define DETAIL_RPP_ARBITRARY_RMERGE_II(digit, res, y, op, def, swap) \
        res(op) swap(digit, RPP_SEQ_HEAD(y)), RPP_SEQ_TAIL(y(def)), op, def, swap \
        /**/
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_DUPLEX_H
# define RIPPLE_PREPROCESSOR_SEQ_DUPLEX_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/extended/reverse_cat.h>
# include <ripple/limits.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_SEQ_DUPLEX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_DUPLEX(seq) RPP_SEQ_DUPLEX_BYPASS(RPP_LIMIT_EXPR, seq)
#    define RPP_SEQ_DUPLEX_ID() RPP_SEQ_DUPLEX
# endif
#
# /* RPP_SEQ_DUPLEX_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_DUPLEX_BYPASS(s, seq) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_DUPLEX_I( \
            RPP_OBSTRUCT(), RPP_PREV(s), 1, RPP_REVERSE_CAT(0, DETAIL_RPP_SEQ_DUPLEX_A seq) \
        )) \
        /**/
#    define RPP_SEQ_DUPLEX_BYPASS_ID() RPP_SEQ_DUPLEX_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_DUPLEX_INDIRECT() DETAIL_RPP_SEQ_DUPLEX_I
#    define DETAIL_RPP_SEQ_DUPLEX_I(_, s, n, seq) \
        RPP_IIF _(RPP_IS_VARIADIC(RPP_EAT seq))( \
            RPP_EXPR_S _(s)(DETAIL_RPP_SEQ_DUPLEX_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_INC(n), RPP_REVERSE_CAT(0, DETAIL_RPP_SEQ_DUPLEX_A seq) \
            )), \
            (n, seq) \
        ) \
        /**/
#    define DETAIL_RPP_SEQ_DUPLEX_A(...) RPP_DEFER(RPP_LPAREN)(), (__VA_ARGS__) DETAIL_RPP_SEQ_DUPLEX_B
#    define DETAIL_RPP_SEQ_DUPLEX_B(...) , (__VA_ARGS__) RPP_DEFER(RPP_RPAREN)() DETAIL_RPP_SEQ_DUPLEX_A
#    define DETAIL_RPP_SEQ_DUPLEX_A0
#    define DETAIL_RPP_SEQ_DUPLEX_B0 ,)
# endif
#
# endif

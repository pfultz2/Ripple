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
# ifndef RIPPLE_PREPROCESSOR_SEQ_REVERSE_H
# define RIPPLE_PREPROCESSOR_SEQ_REVERSE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/placemarker_if.h>
# include <ripple/facilities/expand.h>
# include <ripple/limits.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/detail/close.h>
# include <ripple/seq/duplex.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_REVERSE */
#
# define RPP_SEQ_REVERSE(seq) RPP_EXPAND(DETAIL_RPP_SEQ_REVERSE_I(RPP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define RPP_SEQ_REVERSE_ID() RPP_SEQ_REVERSE
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_REVERSE_I(bin) DETAIL_RPP_SEQ_REVERSE_II bin RPP_SEQ_CLOSE(bin)
#    define DETAIL_RPP_SEQ_REVERSE_II(m, ...) m(?)(DETAIL_RPP_SEQ_REVERSE_III RPP_DEFER(RPP_LPAREN)()(__VA_ARGS__), DETAIL_RPP_SEQ_REVERSE_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_REVERSE_I(bin) DETAIL_RPP_SEQ_REVERSE_II bin DETAIL_RPP_SEQ_REVERSE_ID RPP_SEQ_CLOSE(bin)
#    define DETAIL_RPP_SEQ_REVERSE_II(m, x) m(2)(DETAIL_RPP_SEQ_REVERSE_III RPP_DEFER(RPP_LPAREN)()(x), DETAIL_RPP_SEQ_REVERSE_INDIRECT)
#    define DETAIL_RPP_SEQ_REVERSE_ID(x) (x)
# endif
#
# define DETAIL_RPP_SEQ_REVERSE_INDIRECT() DETAIL_RPP_SEQ_REVERSE_II
# define DETAIL_RPP_SEQ_REVERSE_III(x, res) res x
#
# /* RPP_SEQ_REVERSE_DUPLEX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_REVERSE_DUPLEX(seq) RPP_SEQ_REVERSE_DUPLEX_BYPASS(RPP_LIMIT_EXPR, seq)
#    define RPP_SEQ_REVERSE_DUPLEX_ID() RPP_SEQ_REVERSE_DUPLEX
# endif
#
# /* RPP_SEQ_REVERSE_DUPLEX_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_REVERSE_DUPLEX_BYPASS(s, seq) \
        RPP_EXPR_S(s)(RPP_EXPR_S(s)(RPP_DEFER(DETAIL_RPP_SEQ_REVERSE_DUPLEX_I)( \
            RPP_DEFER(RPP_OBSTRUCT)(), RPP_PREV(RPP_PREV(s)), RPP_TUPLE_REM_CTOR(?, RPP_SEQ_DUPLEX_BYPASS(s, seq)) \
        ))) \
        /**/
#    define RPP_SEQ_REVERSE_DUPLEX_BYPASS_ID() RPP_SEQ_REVERSE_DUPLEX_BYPASS
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_REVERSE_DUPLEX_INDIRECT() DETAIL_RPP_SEQ_REVERSE_DUPLEX_I
#    define DETAIL_RPP_SEQ_REVERSE_DUPLEX_I(_, s, n, seq) \
        RPP_IF _(n)( \
            RPP_EXPR_S _(s)(DETAIL_RPP_SEQ_REVERSE_DUPLEX_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_DEC(n), DETAIL_RPP_SEQ_REVERSE_DUPLEX_A _ seq(0,,) \
            )), \
            seq \
        ) \
        /**/
#    define DETAIL_RPP_SEQ_REVERSE_DUPLEX_A(p, a, b) RPP_PLACEMARKER_IF(p)(b a DETAIL_RPP_SEQ_REVERSE_DUPLEX_B)
#    define DETAIL_RPP_SEQ_REVERSE_DUPLEX_B(p, a, b) RPP_PLACEMARKER_IF(p)(b a DETAIL_RPP_SEQ_REVERSE_DUPLEX_A)
# endif
#
# endif

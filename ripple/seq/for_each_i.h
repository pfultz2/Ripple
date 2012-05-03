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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FOR_EACH_I_H
# define RIPPLE_PREPROCESSOR_SEQ_FOR_EACH_I_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/optional.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/detail/close.h>
# include <ripple/seq/reverse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/elem.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_FOR_EACH_I */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOR_EACH_I(macro, ...) RPP_SEQ_FOR_EACH_I_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_SEQ_FOR_EACH_I(macro, seq, data) RPP_SEQ_FOR_EACH_I_S(RPP_STATE(), macro, seq, data)
# endif
#
# define RPP_SEQ_FOR_EACH_I_ID() RPP_SEQ_FOR_EACH_I
#
# /* RPP_SEQ_FOR_EACH_I_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOR_EACH_I_S(s, macro, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FOR_EACH_I_B_I \
            DETAIL_RPP_SEQ_FOR_EACH_I_A_I( \
                s, macro, RPP_SEQ_BINARY_TRANSFORM(RPP_SEQ_REVERSE(RPP_NON_OPTIONAL(__VA_ARGS__)),), RPP_EXPOSE(RPP_PACK_OPTIONAL(__VA_ARGS__)) \
            )(0,) \
        ) \
        /**/
# else
#    define RPP_SEQ_FOR_EACH_I_S(s, macro, seq, data) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FOR_EACH_I_B_I \
            DETAIL_RPP_SEQ_FOR_EACH_I_A_I( \
                s, macro, RPP_SEQ_BINARY_TRANSFORM(RPP_SEQ_REVERSE(seq), ~), data \
            )(0, ~, ~, ~, ~, ~, ~) \
        ) \
        /**/
# endif
#
# define RPP_SEQ_FOR_EACH_I_S_ID() RPP_SEQ_FOR_EACH_I_S
#
# define DETAIL_RPP_SEQ_FOR_EACH_I_A_INDIRECT() DETAIL_RPP_SEQ_FOR_EACH_I_A_II
# define DETAIL_RPP_SEQ_FOR_EACH_I_B_INDIRECT() DETAIL_RPP_SEQ_FOR_EACH_I_B_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_I(s, macro, bin, ...) \
        RPP_SPLIT(0, RPP_EXPR_S(s)( \
            DETAIL_RPP_SEQ_FOR_EACH_I_A_II bin, 0, RPP_NEXT(s), macro, RPP_CALL(macro), __VA_ARGS__ RPP_SEQ_CLOSE(bin) \
        )) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_II(id, ...) \
        id(?)(DETAIL_RPP_SEQ_FOR_EACH_I_A_III RPP_OBSTRUCT() RPP_LPAREN()(__VA_ARGS__) RPP_COMMA() DETAIL_RPP_SEQ_FOR_EACH_I_A_INDIRECT) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_III(...) DETAIL_RPP_SEQ_FOR_EACH_I_A_IV(__VA_ARGS__)
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_IV(px, r, n, s, macro, _m, ...) \
        r(1, px, n, s, macro, _m, __VA_ARGS__)(), RPP_INC(n), s, macro, _m, __VA_ARGS__ \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_B_I(i, ...) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FOR_EACH_I_B_II, RPP_EAT)(__VA_ARGS__) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_B_II(px, n, s, macro, _m, ...) \
        _m()(s, macro, n, RPP_REM px __VA_ARGS__) DETAIL_RPP_SEQ_FOR_EACH_I_B_INDIRECT \
        /**/
# else
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_I(s, macro, bin, data) \
        RPP_TUPLE_ELEM(6, 0, RPP_EXPR_S(s)( \
            DETAIL_RPP_SEQ_FOR_EACH_I_A_II bin (DETAIL_RPP_SEQ_FOR_EACH_I_A_V, 0, RPP_NEXT(s), macro, RPP_CALL(macro), data) RPP_SEQ_CLOSE(bin) \
        )) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_II(id, x) \
        id(1)(DETAIL_RPP_SEQ_FOR_EACH_I_A_III RPP_OBSTRUCT() RPP_LPAREN() x RPP_COMMA() DETAIL_RPP_SEQ_FOR_EACH_I_A_INDIRECT) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_III(x, aux) RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_FOR_EACH_I_A_IV)(x, RPP_TUPLE_REM(6) aux))
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_IV(x, r, n, s, macro, _m, data) \
        (r(1, x, n, s, macro, _m, data)(), RPP_INC(n), s, macro, _m, data) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_A_V(i, x, n, s, macro, _m, data) (i, x, n, s, macro, _m, data)
#    define DETAIL_RPP_SEQ_FOR_EACH_I_B_I(i, x, n, s, macro, _m, data) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FOR_EACH_I_B_II, RPP_TUPLE_EAT(6))(x, n, s, macro, _m, data) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_I_B_II(x, n, s, macro, _m, data) \
        _m()(s, macro, n RPP_COMMA() x RPP_COMMA() data) DETAIL_RPP_SEQ_FOR_EACH_I_B_INDIRECT \
        /**/
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_SEQ_TRANSFORM_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/infuse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_TRANSFORM(op, ...) RPP_SEQ_TRANSFORM_S(RPP_STATE(), op, __VA_ARGS__)
# else
#    define RPP_SEQ_TRANSFORM(op, seq, data) RPP_SEQ_TRANSFORM_S(RPP_STATE(), op, seq, data)
# endif
#
# define RPP_SEQ_TRANSFORM_ID() RPP_SEQ_TRANSFORM
#
# /* RPP_SEQ_TRANSFORM_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_TRANSFORM_S(s, op, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_TRANSFORM_I \
            RPP_SEQ_INFUSE(RPP_NON_OPTIONAL(__VA_ARGS__), 1, RPP_NEXT(s), op, RPP_CALL(op), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
# else
#    define RPP_SEQ_TRANSFORM_S(s, op, seq, data) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_TRANSFORM_I \
            RPP_SEQ_INFUSE(seq, (1, RPP_NEXT(s), op, RPP_CALL(op), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
# endif
#
# define RPP_SEQ_TRANSFORM_S_ID() RPP_SEQ_TRANSFORM
#
# define DETAIL_RPP_SEQ_TRANSFORM_INDIRECT() DETAIL_RPP_SEQ_TRANSFORM_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_TRANSFORM_I(i, ...) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_TRANSFORM_II, RPP_EAT)(__VA_ARGS__) \
        /**/
#    define DETAIL_RPP_SEQ_TRANSFORM_II(s, op, _o, pd, ...) (_o()(s, op, __VA_ARGS__ RPP_EXPOSE(pd))) DETAIL_RPP_SEQ_TRANSFORM_INDIRECT
# else
#    define DETAIL_RPP_SEQ_TRANSFORM_I(aux, x) \
        RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_TRANSFORM_II)(RPP_TUPLE_REM(5) aux, x)) \
        /**/
#    define DETAIL_RPP_SEQ_TRANSFORM_II(i, s, op, _o, data, x) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_TRANSFORM_III, RPP_TUPLE_EAT(5))(s, op, _o, data, x) \
        /**/
#    define DETAIL_RPP_SEQ_TRANSFORM_III(s, op, _o, data, x) (_o()(s, op, x RPP_COMMA() data)) DETAIL_RPP_SEQ_TRANSFORM_INDIRECT
# endif
#
# endif

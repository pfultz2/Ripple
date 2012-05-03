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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FILTER_H
# define RIPPLE_PREPROCESSOR_SEQ_FILTER_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/optional.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/infuse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_FILTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FILTER(pred, ...) RPP_SEQ_FILTER_S(RPP_STATE(), pred, __VA_ARGS__)
# else
#    define RPP_SEQ_FILTER(pred, seq, data) RPP_SEQ_FILTER_S(RPP_STATE(), pred, seq, data)
# endif
#
# define RPP_SEQ_FILTER_ID() RPP_SEQ_FILTER
#
# /* RPP_SEQ_FILTER_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FILTER_S(s, pred, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FILTER_I \
            RPP_SEQ_INFUSE(RPP_NON_OPTIONAL(__VA_ARGS__), 1, RPP_NEXT(s), pred, RPP_CALL(pred), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
# else
#    define RPP_SEQ_FILTER_S(s, pred, seq, data) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FILTER_I \
            RPP_SEQ_INFUSE(seq, (1, RPP_NEXT(s), pred, RPP_CALL(pred), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
# endif
#
# define RPP_SEQ_FILTER_S_ID() RPP_SEQ_FILTER_S
#
# define DETAIL_RPP_SEQ_FILTER_INDIRECT() DETAIL_RPP_SEQ_FILTER_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_FILTER_I(i, ...) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FILTER_II, RPP_EAT)(RPP_OBSTRUCT(), __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_SEQ_FILTER_II(_, s, pred, _p, pd, ...) \
        RPP_INLINE_WHEN _(_p()(s, pred, __VA_ARGS__ RPP_EXPOSE(pd)))( \
            (__VA_ARGS__) \
        ) DETAIL_RPP_SEQ_FILTER_INDIRECT \
        /**/
# else
#    define DETAIL_RPP_SEQ_FILTER_I(aux, x) \
        RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_FILTER_II)(RPP_TUPLE_REM(5) aux, x)) \
        /**/
#    define DETAIL_RPP_SEQ_FILTER_II(i, s, pred, _p, data, x) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FILTER_III, RPP_TUPLE_EAT(6))(RPP_OBSTRUCT(), s, pred, _p, data, x) \
        /**/
#    define DETAIL_RPP_SEQ_FILTER_III(_, s, pred, _p, data, x) \
        RPP_INLINE_WHEN _(_p()(s, pred, x RPP_COMMA() data))( \
            (x) \
        ) DETAIL_RPP_SEQ_FILTER_INDIRECT \
        /**/
# endif
#
# endif

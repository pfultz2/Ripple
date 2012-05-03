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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FOR_EACH_H
# define RIPPLE_PREPROCESSOR_SEQ_FOR_EACH_H
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
# /* RPP_SEQ_FOR_EACH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOR_EACH(macro, ...) RPP_SEQ_FOR_EACH_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_SEQ_FOR_EACH(macro, seq, data) RPP_SEQ_FOR_EACH_S(RPP_STATE(), macro, seq, data)
# endif
#
# define RPP_SEQ_FOR_EACH_ID() RPP_SEQ_FOR_EACH
#
# /* RPP_SEQ_FOR_EACH_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOR_EACH_S(s, macro, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FOR_EACH_I \
            RPP_SEQ_INFUSE(RPP_NON_OPTIONAL(__VA_ARGS__), 1, RPP_NEXT(s), macro, RPP_CALL(macro), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
# else
#    define RPP_SEQ_FOR_EACH_S(s, macro, seq, data) \
        RPP_EXPR_S(s)(DETAIL_RPP_SEQ_FOR_EACH_I \
            RPP_SEQ_INFUSE(seq, (1, RPP_NEXT(s), macro, RPP_CALL(macro), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
# endif
#
# define RPP_SEQ_FOR_EACH_S_ID() RPP_SEQ_FOR_EACH_S
#
# define DETAIL_RPP_SEQ_FOR_EACH_INDIRECT() DETAIL_RPP_SEQ_FOR_EACH_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_FOR_EACH_I(i, ...) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FOR_EACH_II, RPP_EAT)(__VA_ARGS__) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_II(s, macro, _m, pd, ...) _m()(s, macro, __VA_ARGS__ RPP_EXPOSE(pd)) DETAIL_RPP_SEQ_FOR_EACH_INDIRECT
# else
#    define DETAIL_RPP_SEQ_FOR_EACH_I(aux, x) \
        RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_FOR_EACH_II)(RPP_TUPLE_REM(5) aux, x)) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_II(i, s, macro, _m, data, x) \
        RPP_IIF(i)(DETAIL_RPP_SEQ_FOR_EACH_III, RPP_TUPLE_EAT(5))(s, macro, _m, data, x) \
        /**/
#    define DETAIL_RPP_SEQ_FOR_EACH_III(s, macro, _m, data, x) _m()(s, macro, x RPP_COMMA() data) DETAIL_RPP_SEQ_FOR_EACH_INDIRECT
# endif
#
# endif

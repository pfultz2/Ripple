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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FOLD_RIGHT_AUX_H
# define RIPPLE_PREPROCESSOR_SEQ_FOLD_RIGHT_AUX_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/expand.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/infuse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/elem.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_FOLD_RIGHT_AUX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_RIGHT_AUX(op, seq, data, ...) RPP_SEQ_FOLD_RIGHT_AUX_S(RPP_STATE(), op, seq, data, __VA_ARGS__)
# else
#    define RPP_SEQ_FOLD_RIGHT_AUX(op, seq, data, state) RPP_SEQ_FOLD_RIGHT_AUX_S(RPP_STATE(), op, seq, data, state)
# endif
#
# define RPP_SEQ_FOLD_RIGHT_AUX_ID() RPP_SEQ_FOLD_RIGHT_AUX
#
# /* RPP_SEQ_FOLD_RIGHT_AUX_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, ...) \
        RPP_EXPAND(DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_I( \
            RPP_SEQ_INFUSE(seq, 1, RPP_NEXT(s), op, RPP_PLANAR(op), RPP_INLINE_WHEN(RPP_IS_VARIADIC(data))(RPP_REM)(data))(0,), \
            (__VA_ARGS__) \
        )) \
        /**/
# else
#    define RPP_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, state) \
        RPP_EXPAND(DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_I( \
            RPP_SEQ_INFUSE(seq, (1, RPP_NEXT(s), op, RPP_PLANAR(op), RPP_INLINE_WHEN(RPP_IS_UNARY(data))(RPP_REM)(data)))((0, ~, ~, ~, ~), ~), \
            (state) \
        )) \
        /**/
# endif
#
# define RPP_SEQ_FOLD_RIGHT_AUX_S_ID() RPP_SEQ_FOLD_RIGHT_AUX_S
#
# define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_I(seq, ps) DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A seq RPP_REM ps DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B seq
# define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT() DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A
# define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT() DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A(i, ...) RPP_IIF(i)(DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_I, RPP_EAT)(__VA_ARGS__)
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_I(s, op, _o, data, ...) _o()(s, op) RPP_REM data, __VA_ARGS__, DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B(i, ...) RPP_INLINE_WHEN(i)(RPP_PLANAR_CLOSE() DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A(aux, x) RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_I)(RPP_TUPLE_REM(5) aux, x))
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_I(i, s, op, _o, data, x) RPP_IIF(i)(DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_II, RPP_TUPLE_EAT(5))(s, op, _o, data, x)
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_II(s, op, _o, data, x) _o()(s, op) x, RPP_REM data, DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B(aux, x) RPP_INLINE_WHEN(RPP_TUPLE_ELEM(5, 0, aux))(RPP_PLANAR_CLOSE() DETAIL_RPP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT)
# endif
#
# endif

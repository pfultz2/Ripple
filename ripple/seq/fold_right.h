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
# ifndef RIPPLE_PREPROCESSOR_SEQ_FOLD_RIGHT_H
# define RIPPLE_PREPROCESSOR_SEQ_FOLD_RIGHT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/expand.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/infuse.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/elem.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_FOLD_RIGHT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_RIGHT(op, seq, ...) RPP_SEQ_FOLD_RIGHT_S(RPP_STATE(), op, seq, __VA_ARGS__)
# else
#    define RPP_SEQ_FOLD_RIGHT(op, seq, state) RPP_SEQ_FOLD_RIGHT_S(RPP_STATE(), op, seq, state)
# endif
#
# define RPP_SEQ_FOLD_RIGHT_ID() RPP_SEQ_FOLD_RIGHT
#
# /* RPP_SEQ_FOLD_RIGHT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_FOLD_RIGHT_S(s, op, seq, ...) \
        RPP_EXPAND(DETAIL_RPP_SEQ_FOLD_RIGHT_I( \
            RPP_SEQ_INFUSE(seq, 1, RPP_NEXT(s), op, RPP_PLANAR(op))(0,), \
            (__VA_ARGS__) \
        )) \
        /**/
# else
#    define RPP_SEQ_FOLD_RIGHT_S(s, op, seq, state) \
        RPP_EXPAND(DETAIL_RPP_SEQ_FOLD_RIGHT_I( \
            RPP_SEQ_INFUSE(seq, (1, RPP_NEXT(s), op, RPP_PLANAR(op)))((0, ~, ~, ~), ~), \
            (state) \
        )) \
        /**/
# endif
#
# define RPP_SEQ_FOLD_RIGHT_S_ID() RPP_SEQ_FOLD_RIGHT_S
#
# define DETAIL_RPP_SEQ_FOLD_RIGHT_I(seq, ps) DETAIL_RPP_SEQ_FOLD_RIGHT_A seq RPP_REM ps DETAIL_RPP_SEQ_FOLD_RIGHT_B seq
# define DETAIL_RPP_SEQ_FOLD_RIGHT_A_INDIRECT() DETAIL_RPP_SEQ_FOLD_RIGHT_A
# define DETAIL_RPP_SEQ_FOLD_RIGHT_B_INDIRECT() DETAIL_RPP_SEQ_FOLD_RIGHT_B
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_A(i, ...) RPP_IIF(i)(DETAIL_RPP_SEQ_FOLD_RIGHT_A_I, RPP_EAT)(__VA_ARGS__)
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_A_I(s, op, _o, ...) _o()(s, op) __VA_ARGS__, DETAIL_RPP_SEQ_FOLD_RIGHT_A_INDIRECT
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_B(i, ...) RPP_INLINE_WHEN(i)(RPP_PLANAR_CLOSE() DETAIL_RPP_SEQ_FOLD_RIGHT_B_INDIRECT)
# else
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_A(aux, x) RPP_EXPAND(RPP_DEFER(DETAIL_RPP_SEQ_FOLD_RIGHT_A_I)(RPP_TUPLE_REM(4) aux, x))
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_A_I(i, s, op, _o, x) RPP_IIF(i)(DETAIL_RPP_SEQ_FOLD_RIGHT_A_II, RPP_TUPLE_EAT(4))(s, op, _o, x)
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_A_II(s, op, _o, x) _o()(s, op) x, DETAIL_RPP_SEQ_FOLD_RIGHT_A_INDIRECT
#    define DETAIL_RPP_SEQ_FOLD_RIGHT_B(aux, x) RPP_INLINE_WHEN(RPP_TUPLE_ELEM(4, 0, aux))(RPP_PLANAR_CLOSE() DETAIL_RPP_SEQ_FOLD_RIGHT_B_INDIRECT)
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_SHIFTED */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED(count, sep, ...) RPP_DELINEATE_SHIFTED_S(RPP_STATE(), count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_SHIFTED(count, sep, macro, data) RPP_DELINEATE_SHIFTED_S(RPP_STATE(), count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_SHIFTED_ID() RPP_DELINEATE_SHIFTED
#
# /* RPP_DELINEATE_SHIFTED_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED_S(s, count, sep, ...) \
        DETAIL_RPP_DELINEATE_SHIFTED_U(s, count, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_SHIFTED_S(s, count, sep, macro, data) DETAIL_RPP_DELINEATE_SHIFTED_U(s, count, sep, macro, (data))
# endif
#
# define RPP_DELINEATE_SHIFTED_S_ID() RPP_DELINEATE_SHIFTED_S
#
# define DETAIL_RPP_DELINEATE_SHIFTED_U(s, count, sep, macro, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_SHIFTED_I( \
        s, RPP_NEXT(s), RPP_DEC(count), RPP_EMPTY, sep, macro, RPP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_SHIFTED_INDIRECT() DETAIL_RPP_DELINEATE_SHIFTED_I
# define DETAIL_RPP_DELINEATE_SHIFTED_I(s, o, count, sep, ss, macro, _m, pd) \
    RPP_IF(count)( \
        DETAIL_RPP_DELINEATE_SHIFTED_II, RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), RPP_NEXT(s), o, count, sep, ss, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_SHIFTED_II(_, s, o, count, sep, ss, macro, _m, pd) \
    RPP_EXPR_S(s) _(DETAIL_RPP_DELINEATE_SHIFTED_INDIRECT _()( \
        s, o, RPP_DEC(count), ss, ss, macro, _m, pd \
    )) \
    _m()(o, macro, count RPP_EXPOSE(pd)) sep() \
    /**/
#
# endif

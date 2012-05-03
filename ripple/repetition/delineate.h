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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE(count, sep, ...) RPP_DELINEATE_S(RPP_STATE(), count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE(count, sep, macro, data) RPP_DELINEATE_S(RPP_STATE(), count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_ID() RPP_DELINEATE
#
# /* RPP_DELINEATE_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_S(s, count, sep, ...) \
        DETAIL_RPP_DELINEATE_U(s, count, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_S(s, count, sep, macro, data) DETAIL_RPP_DELINEATE_U(s, count, sep, macro, (data))
# endif
#
# define RPP_DELINEATE_S_ID() RPP_DELINEATE_S
#
# define DETAIL_RPP_DELINEATE_U(s, count, sep, macro, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_I( \
        s, RPP_NEXT(s), count, RPP_EMPTY, sep, macro, RPP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_INDIRECT() DETAIL_RPP_DELINEATE_I
# define DETAIL_RPP_DELINEATE_I(s, o, count, sep, ss, macro, _m, pd) \
    RPP_IF(count)( \
        DETAIL_RPP_DELINEATE_II, RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), RPP_NEXT(s), o, RPP_DEC(count), sep, ss, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_II(_, s, o, count, sep, ss, macro, _m, pd) \
    RPP_EXPR_S(s) _(DETAIL_RPP_DELINEATE_INDIRECT _()( \
        s, o, count, ss, ss, macro, _m, pd \
    )) \
    _m()(o, macro, count RPP_EXPOSE(pd)) sep() \
    /**/
#
# endif

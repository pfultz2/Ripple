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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_FROM_TO */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_FROM_TO(from, to, sep, ...) RPP_DELINEATE_FROM_TO_S(RPP_STATE(), from, to, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_FROM_TO(from, to, sep, macro, data) RPP_DELINEATE_FROM_TO_S(RPP_STATE(), from, to, sep, macro, data)
# endif
#
# define RPP_DELINEATE_FROM_TO_ID() RPP_DELINEATE_FROM_TO
#
# /* RPP_DELINEATE_FROM_TO_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_FROM_TO_S(s, from, to, sep, ...) \
        DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_FROM_TO_S(s, from, to, sep, macro, data) DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, macro, (data))
# endif
#
# define RPP_DELINEATE_FROM_TO_S_ID() RPP_DELINEATE_FROM_TO_S
#
# define DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, macro, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_FROM_TO_I(RPP_NEXT(s), RPP_NEXT(s), from, to, RPP_EMPTY, sep, macro, RPP_TRAMPOLINE(macro), pd)) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT() DETAIL_RPP_DELINEATE_FROM_TO_I
# define DETAIL_RPP_DELINEATE_FROM_TO_I(s, o, from, to, s1, s2, macro, _m, pd) \
    RPP_IIF(RPP_NOT_EQUAL(from, to))( \
        DETAIL_RPP_DELINEATE_FROM_TO_II, RPP_TUPLE_EAT(9) \
    )(s, o, from, RPP_DEC(to), s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_II(s, o, from, to, s1, s2, macro, _m, pd) \
    RPP_DEFER(RPP_EXPR_S(s))(RPP_DEFER(DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT)()( \
        RPP_NEXT(s), o, from, to, s2, s2, macro, _m, pd \
    )) \
    _m()(o, macro, to RPP_EXPOSE(pd)) s1()
    /**/
#
# endif

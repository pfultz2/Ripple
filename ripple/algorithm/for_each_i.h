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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_I_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_I_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH_I */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I(macro, ...) RPP_FOR_EACH_I_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_I(macro, g, data) RPP_FOR_EACH_I_S(RPP_STATE(), macro, g, data)
# endif
#
# define RPP_FOR_EACH_I_ID() RPP_FOR_EACH_I
#
# /* RPP_FOR_EACH_I_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I_S(s, macro, ...) DETAIL_RPP_FOR_EACH_I_U(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
# else
#    define RPP_FOR_EACH_I_S(s, macro, g, data) DETAIL_RPP_FOR_EACH_I_U(s, macro, g, (data))
# endif
#
# define RPP_FOR_EACH_I_S_ID() RPP_FOR_EACH_I_S
#
# define DETAIL_RPP_FOR_EACH_I_U(s, macro, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOR_EACH_I_I( \
        RPP_NEXT(s), RPP_NEXT(s), 0, macro, RPP_TRAMPOLINE(macro), RPP_TYPEOF(g), g, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_INDIRECT() DETAIL_RPP_FOR_EACH_I_I
# define DETAIL_RPP_FOR_EACH_I_I(s, o, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_I_II, RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), s, o, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_II(_, s, o, n, macro, _m, type, g, pd) \
    _m()(o, macro, n RPP_COMMA() RPP_ITEM(type, RPP_HEAD(g)) RPP_EXPOSE(pd)) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOR_EACH_I_INDIRECT _()( \
        RPP_NEXT(s), o, RPP_INC(n), macro, _m, type, RPP_TAIL(g), pd \
    )) \
    /**/
#
# endif

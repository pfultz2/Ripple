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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH(macro, ...) RPP_FOR_EACH_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH(macro, g, data) RPP_FOR_EACH_S(RPP_STATE(), macro, g, data)
# endif
#
# define RPP_FOR_EACH_ID() RPP_FOR_EACH
#
# /* RPP_FOR_EACH_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_S(s, macro, ...) DETAIL_RPP_FOR_EACH_U(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
# else
#    define RPP_FOR_EACH_S(s, macro, g, data) DETAIL_RPP_FOR_EACH_U(s, macro, g, (data))
# endif
#
# define RPP_FOR_EACH_S_ID() RPP_FOR_EACH_S
#
# define DETAIL_RPP_FOR_EACH_U(s, macro, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOR_EACH_I( \
        RPP_NEXT(s), RPP_NEXT(s), macro, RPP_TRAMPOLINE(macro), RPP_TYPEOF(g), g, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_INDIRECT() DETAIL_RPP_FOR_EACH_I
# define DETAIL_RPP_FOR_EACH_I(s, o, macro, _m, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_II, RPP_TUPLE_EAT(8) \
    )(RPP_OBSTRUCT(), s, o, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_II(_, s, o, macro, _m, type, g, pd) \
    _m()(o, macro, RPP_ITEM(type, RPP_HEAD(g)) RPP_EXPOSE(pd)) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOR_EACH_INDIRECT _()( \
        RPP_NEXT(s), o, macro, _m, type, RPP_TAIL(g), pd \
    )) \
    /**/
#
# endif

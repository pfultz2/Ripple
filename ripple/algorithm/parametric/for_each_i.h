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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_I_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_I_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
#
# /* RPP_FOR_EACH_I_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I_PARAMETRIC(macro, ...) RPP_FOR_EACH_I_PARAMETRIC_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_I_PARAMETRIC(macro, g, data) RPP_FOR_EACH_I_PARAMETRIC_S(RPP_STATE(), macro, g, data)
# endif
#
# define RPP_FOR_EACH_I_PARAMETRIC_ID() RPP_FOR_EACH_I_PARAMETRIC
#
# /* RPP_FOR_EACH_I_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I_PARAMETRIC_S(s, macro, ...) \
        DETAIL_RPP_FOR_EACH_I_PARAMETRIC_U(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_EACH_I_PARAMETRIC_S(s, macro, g, data) DETAIL_RPP_FOR_EACH_I_PARAMETRIC_U(s, macro, g, (data))
# endif
#
# define RPP_FOR_EACH_I_PARAMETRIC_S_ID() RPP_FOR_EACH_I_PARAMETRIC_S
#
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_U(s, macro, g, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOR_EACH_I_PARAMETRIC_I( \
        RPP_NEXT(s), RPP_NEXT(s), 0, macro, RPP_TRAMPOLINE(macro), RPP_TYPEOF(g), g, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_INDIRECT() DETAIL_RPP_FOR_EACH_I_PARAMETRIC_I
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_I(s, o, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_LIMIT_EXPR))( \
        DETAIL_RPP_FOR_EACH_I_PARAMETRIC_II, DETAIL_RPP_FOR_EACH_I_PARAMETRIC_IV \
    )(RPP_PHASE(0), s, o, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_II(_, s, o, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_I_PARAMETRIC_III, RPP_TUPLE_EAT(9) \
    )(_, s, o, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_III(_, s, o, n, macro, _m, type, g, pd) \
    _(0, _m)()(o, macro, n _(0, RPP_COMMA)() RPP_ITEM(type, RPP_HEAD(g)) _(0, RPP_EXPOSE)(pd)) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_I_PARAMETRIC_INDIRECT)()( \
        RPP_NEXT(s), o, RPP_INC(n), macro, _m, type, RPP_TAIL(g), pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_PARAMETRIC_IV(_, s, o, n, macro, _m, type, g, pd) \
    DETAIL_RPP_FOR_EACH_I_PARAMETRIC_II(RPP_PHASE(1), o, o, n, macro, _m, type, g, pd) \
    /**/
#
# endif

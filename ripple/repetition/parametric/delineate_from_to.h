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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_FROM_TO_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_FROM_TO_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/limits.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_FROM_TO_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_FROM_TO_PARAMETRIC(from, to, sep, ...) RPP_DELINEATE_FROM_TO_PARAMETRIC_S(RPP_STATE(), from, to, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_FROM_TO_PARAMETRIC(from, to, sep, macro, data) RPP_DELINEATE_FROM_TO_PARAMETRIC_S(RPP_STATE(), from, to, sep, macro, data)
# endif
#
# define RPP_DELINEATE_FROM_TO_PARAMETRIC_ID() RPP_DELINEATE_FROM_TO_PARAMETRIC
#
# /* RPP_DELINEATE_FROM_TO_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_FROM_TO_PARAMETRIC_S(s, from, to, sep, ...) \
        DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_FROM_TO_PARAMETRIC_S(s, from, to, sep, macro, data) DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, macro, (data))
# endif
#
# define RPP_DELINEATE_FROM_TO_PARAMETRIC_S_ID() RPP_DELINEATE_FROM_TO_PARAMETRIC_S
#
# define DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_U(s, from, to, sep, macro, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_I( \
        RPP_NEXT(s), RPP_NEXT(s), from, to, RPP_EMPTY, sep, macro, RPP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_INDIRECT() DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_I
# define DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_I(s, o, from, to, s1, s2, macro, _m, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_LIMIT_EXPR))( \
        DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_II, DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_III \
    )(RPP_PHASE(0), s, o, from, to, s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_II(_, s, o, from, to, s1, s2, macro, _m, pd) \
    _(1, RPP_IIF)(RPP_NOT_EQUAL(from, to))( \
        _(1, RPP_EXPR_S)(s), RPP_EAT \
    )( \
        _(1, s1)() _(1, _m)()(o, macro, from _(1, RPP_EXPOSE)(pd)) \
        _(1, DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_INDIRECT)()( \
            RPP_NEXT(s), o, RPP_INC(from), to, s2, s2, macro, _m, pd \
        ) \
    ) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_III(_, s, o, from, to, s1, s2, macro, _m, pd) \
    DETAIL_RPP_DELINEATE_FROM_TO_PARAMETRIC_II(RPP_PHASE(1), o, o, from, to, s1, s2, macro, _m, pd) \
    /**/
#
# endif

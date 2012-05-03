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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_DELINEATE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/limits.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_PARAMETRIC(count, sep, ...) RPP_DELINEATE_PARAMETRIC_S(RPP_STATE(), count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_PARAMETRIC(count, sep, macro, data) RPP_DELINEATE_PARAMETRIC_S(RPP_STATE(), count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_PARAMETRIC_ID() RPP_DELINEATE_PARAMETRIC
#
# /* RPP_DELINEATE_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_PARAMETRIC_S(s, count, sep, ...) \
        DETAIL_RPP_DELINEATE_PARAMETRIC_U(s, count, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_PARAMETRIC_S(s, count, sep, macro, data) \
        DETAIL_RPP_DELINEATE_PARAMETRIC_U(s, count, sep, macro, (data)) \
        /**/
# endif
#
# define RPP_DELINEATE_PARAMETRIC_S_ID() RPP_DELINEATE_PARAMETRIC_S
#
# define DETAIL_RPP_DELINEATE_PARAMETRIC_U(s, count, sep, macro, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_PARAMETRIC_I( \
        RPP_NEXT(s), RPP_NEXT(s), count, RPP_EMPTY, sep, \
        macro, RPP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_PARAMETRIC_INDIRECT() DETAIL_RPP_DELINEATE_PARAMETRIC_I
# define DETAIL_RPP_DELINEATE_PARAMETRIC_I(s, o, count, s1, s2, macro, _m, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_LIMIT_EXPR))( \
        DETAIL_RPP_DELINEATE_PARAMETRIC_II, DETAIL_RPP_DELINEATE_PARAMETRIC_III \
    )(RPP_PHASE(0), s, o, count, s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_PARAMETRIC_II(_, s, o, count, s1, s2, macro, _m, pd) \
    _(1, RPP_IF)(count)( \
        _(1, RPP_EXPR_S)(s), RPP_EAT \
    )( \
        _(1, DETAIL_RPP_DELINEATE_PARAMETRIC_INDIRECT)()( \
            RPP_NEXT(s), o, RPP_DEC(count), s2, s2, macro, _m, pd \
        ) \
        _(1, _m)()(o, macro, RPP_DEC(count) _(1, RPP_EXPOSE)(pd)) \
        _(1, s1)() \
    ) \
    /**/
# define DETAIL_RPP_DELINEATE_PARAMETRIC_III(_, s, o, count, s1, s2, macro, _m, pd) \
    DETAIL_RPP_DELINEATE_PARAMETRIC_II(RPP_PHASE(1), o, o, count, s1, s2, macro, _m, pd) \
    /**/
#
# endif

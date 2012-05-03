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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_DELINEATE_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_DELINEATE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_X(size, count, sep, ...) RPP_DELINEATE_X_S(RPP_STATE(), size, count, sep, __VA_ARGS__)
# else
#    define RPP_DELINEATE_X(size, count, sep, macro, data) RPP_DELINEATE_X_S(RPP_STATE(), size, count, sep, macro, data)
# endif
#
# define RPP_DELINEATE_X_ID() RPP_DELINEATE_X
#
# /* RPP_DELINEATE_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_X_S(s, size, count, sep, ...) \
        DETAIL_RPP_DELINEATE_X_U(s, size, count, sep, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_DELINEATE_X_S(s, size, count, sep, macro, data) DETAIL_RPP_DELINEATE_X_U(s, size, count, sep, macro, (data))
# endif
#
# define RPP_DELINEATE_X_S_ID() RPP_DELINEATE_X_S
#
# define DETAIL_RPP_DELINEATE_X_U(s, size, count, sep, macro, pd) \
    DETAIL_RPP_DELINEATE_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), \
        count, RPP_EMPTY, sep, macro, RPP_CALL(macro), pd \
    ) \
    /**/
# define DETAIL_RPP_DELINEATE_X_INDIRECT() DETAIL_RPP_DELINEATE_X_I
# define DETAIL_RPP_DELINEATE_X_I(s, jump, fix, count, s1, s2, macro, _m, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_DELINEATE_X_II, DETAIL_RPP_DELINEATE_X_III \
        ), \
        DETAIL_RPP_DELINEATE_X_V \
    )(RPP_PHASE(0), s, jump, fix, count, s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_X_II(_, s, jump, fix, count, s1, s2, macro, _m, pd) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_DELINEATE_X_III(_, s, (RPP_NEXT(s)) jump, fix, count, s1, s2, macro, _m, pd) \
    ) \
    /**/
# define DETAIL_RPP_DELINEATE_X_III(_, s, jump, fix, count, s1, s2, macro, _m, pd) \
    RPP_IF(count)( \
        DETAIL_RPP_DELINEATE_X_IV, RPP_TUPLE_EAT(10) RPP_OBSTRUCT() \
    )(_, s, jump, fix, RPP_DEC(count), s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_X_IV(_, s, jump, fix, count, s1, s2, macro, _m, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_DELINEATE_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, count, s2, s2, macro, _m, pd \
    )) \
    _(0, _m)()(s, macro, count _(0, RPP_EXPOSE)(pd)) _(1, s1)() \
    /**/
# define DETAIL_RPP_DELINEATE_X_V(_, s, jump, fix, count, s1, s2, macro, _m, pd) \
    DETAIL_RPP_DELINEATE_X_VI(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, count, s1, s2, macro, _m, pd) \
    /**/
# define DETAIL_RPP_DELINEATE_X_VI(s, jump, fix, count, s1, s2, macro, _m, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_DELINEATE_X_II, DETAIL_RPP_DELINEATE_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, count, s1, s2, macro, _m, pd) \
    /**/
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_X_FOR_EACH_I_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_X_FOR_EACH_I_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH_I_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I_X(size, macro, ...) RPP_FOR_EACH_I_X_S(RPP_STATE(), size, macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_I_X(size, macro, g, data) RPP_FOR_EACH_I_X_S(RPP_STATE(), size, macro, g, data)
# endif
#
# define RPP_FOR_EACH_I_X_ID() RPP_FOR_EACH_I_X
#
# /* RPP_FOR_EACH_I_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_I_X_S(s, size, macro, ...) \
        DETAIL_RPP_FOR_EACH_I_X_U(s, size, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_EACH_I_X_S(s, size, macro, g, data) DETAIL_RPP_FOR_EACH_I_X_U(s, size, macro, g, (data))
# endif
#
# define RPP_FOR_EACH_I_X_S_ID() RPP_FOR_EACH_I_X_S
#
# define DETAIL_RPP_FOR_EACH_I_X_U(s, size, macro, g, pd) \
    DETAIL_RPP_FOR_EACH_I_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), \
        0, macro, RPP_CALL(macro), RPP_TYPEOF(g), g, pd \
    ) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_INDIRECT() DETAIL_RPP_FOR_EACH_I_X_I
# define DETAIL_RPP_FOR_EACH_I_X_I(s, jump, fix, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_FOR_EACH_I_X_II, DETAIL_RPP_FOR_EACH_I_X_III \
        ), \
        DETAIL_RPP_FOR_EACH_I_X_V \
    )(RPP_PHASE(0), s, jump, fix, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_II(_, s, jump, fix, n, macro, _m, type, g, pd) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_FOR_EACH_I_X_III(_, s, (RPP_NEXT(s)) jump, fix, n, macro, _m, type, g, pd) \
    ) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_III(_, s, jump, fix, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_I_X_IV, RPP_TUPLE_EAT RPP_OBSTRUCT()(10) \
    )(_, s, jump, fix, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_IV(_, s, jump, fix, n, macro, _m, type, g, pd) \
    _(0, _m)()(s, macro, n _(0, RPP_COMMA)() RPP_ITEM(type, RPP_HEAD(g)) _(0, RPP_EXPOSE)(pd)) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_I_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, RPP_INC(n), macro, _m, type, RPP_TAIL(g), pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_V(_, s, jump, fix, n, macro, _m, type, g, pd) \
    DETAIL_RPP_FOR_EACH_I_X_VI(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, n, macro, _m, type, g, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_I_X_VI(s, jump, fix, n, macro, _m, type, g, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_FOR_EACH_I_X_II, DETAIL_RPP_FOR_EACH_I_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, n, macro, _m, type, g, pd) \
    /**/
#
# endif

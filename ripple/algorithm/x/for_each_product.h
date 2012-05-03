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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_X_FOR_EACH_PRODUCT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_X_FOR_EACH_PRODUCT_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH_PRODUCT_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT_X(size, macro, ...) RPP_FOR_EACH_PRODUCT_X_S(RPP_STATE(), size, macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_PRODUCT_X(size, macro, seq, data) RPP_FOR_EACH_PRODUCT_X_S(RPP_STATE(), size, macro, seq, data)
# endif
#
# define RPP_FOR_EACH_PRODUCT_X_ID() RPP_FOR_EACH_PRODUCT_X
#
# /* RPP_FOR_EACH_PRODUCT_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT_X_S(s, size, macro, ...) \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_U(s, size, macro, RPP_NON_OPTIONAL(__VA_ARGS__),, RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_EACH_PRODUCT_X_S(s, size, macro, seq, data) DETAIL_RPP_FOR_EACH_PRODUCT_X_U(s, size, macro, seq, DETAIL_RPP_FOR_EACH_PRODUCT_X_N, (data))
# endif
#
# define RPP_FOR_EACH_PRODUCT_X_S_ID() RPP_FOR_EACH_PRODUCT_X_S
#
# if !CONFIG_RIPPLE_STD
#    define DETAIL_RPP_FOR_EACH_PRODUCT_X_N(x) (x)
# endif
#
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_U(s, size, macro, seq, bind, pd) \
    RPP_IIF(RPP_SEQ_IS_CONS(seq))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_I, RPP_TUPLE_EAT(8) \
    )(RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), macro, RPP_CALL(macro), RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_INDIRECT() DETAIL_RPP_FOR_EACH_PRODUCT_X_I
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_I(s, jump, fix, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_FOR_EACH_PRODUCT_X_II, DETAIL_RPP_FOR_EACH_PRODUCT_X_III \
        ), \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_VII \
    )(RPP_PHASE(0), s, jump, fix, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_II(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_III(_, s, (RPP_NEXT(s)) jump, fix, macro, _m, g, seq, bind, pd) \
    ) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_III(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_IV, RPP_TUPLE_EAT RPP_OBSTRUCT()(10) \
    )(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_IV(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_SEQ_IS_CONS(seq))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_V, DETAIL_RPP_FOR_EACH_PRODUCT_X_VI \
    )(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_PRODUCT_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, macro, _m, RPP_TAIL(g), seq, bind, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_V(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_PRODUCT_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, macro, _m, RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind (RPP_HEAD(g)), pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_VI(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    _(0, _m)()(s, macro, bind (RPP_HEAD(g)) _(0, RPP_EXPOSE)(pd)) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_VII(_, s, jump, fix, macro, _m, g, seq, bind, pd) \
    DETAIL_RPP_FOR_EACH_PRODUCT_X_VIII(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_X_VIII(s, jump, fix, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_X_II, DETAIL_RPP_FOR_EACH_PRODUCT_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, macro, _m, g, seq, bind, pd) \
    /**/
#
# endif

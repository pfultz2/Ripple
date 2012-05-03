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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH_PRODUCT_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT_PARAMETRIC(macro, ...) RPP_FOR_EACH_PRODUCT_PARAMETRIC_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_PRODUCT_PARAMETRIC(macro, seq, data) RPP_FOR_EACH_PRODUCT_PARAMETRIC_S(RPP_STATE(), macro, seq, data)
# endif
#
# define RPP_FOR_EACH_PRODUCT_PARAMETRIC_ID() RPP_FOR_EACH_PRODUCT_PARAMETRIC
#
# /* RPP_FOR_EACH_PRODUCT_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT_PARAMETRIC_S(s, macro, ...) \
        DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__),, RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_FOR_EACH_PRODUCT_PARAMETRIC_S(s, macro, seq, data) DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, seq, DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_N, (data))
# endif
#
# define RPP_FOR_EACH_PRODUCT_PARAMETRIC_S_ID() RPP_FOR_EACH_PRODUCT_PARAMETRIC_S
#
# if !CONFIG_RIPPLE_STD
#    define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_N(x) (x)
# endif
#
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, seq, bind, pd) \
    RPP_EXPR_S(s)(DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_I( \
        RPP_NEXT(s), RPP_NEXT(s), macro, RPP_TRAMPOLINE(macro), RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT() DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_I
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_I(s, o, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_LIMIT_EXPR))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_II, DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_VI \
    )(RPP_PHASE(0), s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_II(_, s, o, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_III, RPP_TUPLE_EAT(9) \
    )(_, s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_III(_, s, o, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_SEQ_IS_CONS(seq))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_IV, DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_V \
    )(_, s, o, macro, _m, g, seq, bind, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT)()( \
        RPP_NEXT(s), o, macro, _m, RPP_TAIL(g), seq, bind, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_IV(_, s, o, macro, _m, g, seq, bind, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT)()( \
        RPP_NEXT(s), o, macro, _m, RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind (RPP_HEAD(g)), pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_V(_, s, o, macro, _m, g, seq, bind, pd) \
    _(0, _m)()(o, macro, bind (RPP_HEAD(g)) _(0, RPP_EXPOSE)(pd)) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_VI(_, s, o, macro, _m, g, seq, bind, pd) \
    DETAIL_RPP_FOR_EACH_PRODUCT_PARAMETRIC_II(RPP_PHASE(1), o, o, macro, _m, g, seq, bind, pd) \
    /**/
#
# endif

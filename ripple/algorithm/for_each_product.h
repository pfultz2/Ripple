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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_PRODUCT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_FOR_EACH_PRODUCT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FOR_EACH_PRODUCT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT(macro, ...) RPP_FOR_EACH_PRODUCT_S(RPP_STATE(), macro, __VA_ARGS__)
# else
#    define RPP_FOR_EACH_PRODUCT(macro, seq, data) RPP_FOR_EACH_PRODUCT_S(RPP_STATE(), macro, seq, data)
# endif
#
# define RPP_FOR_EACH_PRODUCT_ID() RPP_FOR_EACH_PRODUCT
#
# /* RPP_FOR_EACH_PRODUCT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FOR_EACH_PRODUCT_S(s, macro, ...) DETAIL_RPP_FOR_EACH_PRODUCT_U(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__),, RPP_PACK_OPTIONAL(__VA_ARGS__))
# else
#    define RPP_FOR_EACH_PRODUCT_S(s, macro, seq, data) DETAIL_RPP_FOR_EACH_PRODUCT_U(s, macro, seq, DETAIL_RPP_FOR_EACH_PRODUCT_N, (data))
# endif
#
# define RPP_FOR_EACH_PRODUCT_S_ID() RPP_FOR_EACH_PRODUCT_S
#
# if !CONFIG_RIPPLE_STD
#    define DETAIL_RPP_FOR_EACH_PRODUCT_N(x) (x)
# endif
#
# define DETAIL_RPP_FOR_EACH_PRODUCT_U(s, macro, seq, bind, pd) \
    RPP_EXPR_S(s)(RPP_IIF(RPP_SEQ_IS_CONS(seq))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_I, RPP_TUPLE_EAT(8) \
    )(RPP_NEXT(s), RPP_NEXT(s), macro, RPP_TRAMPOLINE(macro), RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind, pd)) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_INDIRECT() DETAIL_RPP_FOR_EACH_PRODUCT_I
# define DETAIL_RPP_FOR_EACH_PRODUCT_I(s, o, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_II, RPP_TUPLE_EAT(9) \
    )(RPP_OBSTRUCT(), s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_II(_, s, o, macro, _m, g, seq, bind, pd) \
    RPP_IIF(RPP_SEQ_IS_CONS(seq))( \
        DETAIL_RPP_FOR_EACH_PRODUCT_III, DETAIL_RPP_FOR_EACH_PRODUCT_IV \
    )(RPP_OBSTRUCT(), s, o, macro, _m, g, seq, bind, pd) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOR_EACH_PRODUCT_INDIRECT _()( \
        RPP_NEXT(s), o, macro, _m, RPP_TAIL(g), seq, bind, pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_III(_, s, o, macro, _m, g, seq, bind, pd) \
    RPP_EXPR_S(s) _(DETAIL_RPP_FOR_EACH_PRODUCT_INDIRECT _()( \
        RPP_NEXT(s), o, macro, _m, RPP_SEQ_HEAD(seq), RPP_SEQ_TAIL(seq), bind(RPP_HEAD(g)), pd \
    )) \
    /**/
# define DETAIL_RPP_FOR_EACH_PRODUCT_IV(_, s, o, macro, _m, g, seq, bind, pd) \
    _m()(o, macro, bind(RPP_HEAD(g)) RPP_EXPOSE(pd)) \
    /**/
#
# endif

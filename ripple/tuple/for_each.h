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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FOR_EACH_H
# define RIPPLE_PREPROCESSOR_TUPLE_FOR_EACH_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_FOR_EACH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOR_EACH(macro, ...) RPP_TUPLE_FOR_EACH_S(RPP_STATE(), macro, __VA_ARGS__)
#    define RPP_TUPLE_FOR_EACH_ID() RPP_TUPLE_FOR_EACH
# endif
#
# /* RPP_TUPLE_FOR_EACH_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOR_EACH_S(s, macro, ...) DETAIL_RPP_TUPLE_FOR_EACH_I(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
#    define RPP_TUPLE_FOR_EACH_S_ID() RPP_TUPLE_FOR_EACH_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FOR_EACH_I(s, macro, tuple, pd) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FOR_EACH_1( \
            RPP_NEXT(s), RPP_NEXT(s), macro, RPP_TRAMPOLINE(macro), tuple, pd \
        )) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_INDIRECT(n) DETAIL_RPP_TUPLE_FOR_EACH_ ## n
#    define DETAIL_RPP_TUPLE_FOR_EACH_1(s, o, macro, _m, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FOR_EACH_1_I, DETAIL_RPP_TUPLE_FOR_EACH_2 \
        )(s, o, macro, _m, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_1_I(s, o, macro, _m, tuple, pd) \
        DETAIL_RPP_TUPLE_FOR_EACH_1_II(s, o, macro, _m, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_1_II(...) DETAIL_RPP_TUPLE_FOR_EACH_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FOR_EACH_1_III(_, s, o, macro, _m, a, b, c, d, e, f, g, h, i, j, tuple, pd) \
        _m()(o, macro, a RPP_EXPOSE(pd)) _m()(o, macro, b RPP_EXPOSE(pd)) _m()(o, macro, c RPP_EXPOSE(pd)) _m()(o, macro, d RPP_EXPOSE(pd)) _m()(o, macro, e RPP_EXPOSE(pd)) \
        _m()(o, macro, f RPP_EXPOSE(pd)) _m()(o, macro, g RPP_EXPOSE(pd)) _m()(o, macro, h RPP_EXPOSE(pd)) _m()(o, macro, i RPP_EXPOSE(pd)) _m()(o, macro, j RPP_EXPOSE(pd)) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOR_EACH_INDIRECT _(1)( \
            RPP_NEXT(s), o, macro, _m, tuple, pd \
        )) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_2(s, o, macro, _m, tuple, pd) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FOR_EACH_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, macro, _m, tuple, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_2_I(_, s, o, macro, _m, tuple, pd) \
        _m()(o, macro, RPP_TUPLE_HEAD(tuple) RPP_EXPOSE(pd)) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOR_EACH_INDIRECT _(2)( \
            RPP_NEXT(s), o, macro, _m, RPP_TUPLE_TAIL(tuple), pd \
        )) \
        /**/
# endif
#
# endif

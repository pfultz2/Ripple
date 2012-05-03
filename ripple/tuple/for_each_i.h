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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_FOR_EACH_I_H
# define RIPPLE_PREPROCESSOR_TUPLE_FOR_EACH_I_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/batch.h>
# include <ripple/tuple/eat.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TUPLE_FOR_EACH_I */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOR_EACH_I(macro, ...) RPP_TUPLE_FOR_EACH_I_S(RPP_STATE(), macro, __VA_ARGS__)
#    define RPP_TUPLE_FOR_EACH_I_ID() RPP_TUPLE_FOR_EACH_I
# endif
#
# /* RPP_TUPLE_FOR_EACH_I_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_FOR_EACH_I_S(s, macro, ...) DETAIL_RPP_TUPLE_FOR_EACH_I_I(s, macro, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__))
#    define RPP_TUPLE_FOR_EACH_I_S_ID() RPP_TUPLE_FOR_EACH_I_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_I(s, macro, tuple, pd) \
        RPP_EXPR_S(s)(DETAIL_RPP_TUPLE_FOR_EACH_I_1( \
            RPP_NEXT(s), RPP_NEXT(s), macro, RPP_TRAMPOLINE(macro), tuple, 0, pd \
        )) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_INDIRECT(n) DETAIL_RPP_TUPLE_FOR_EACH_I_ ## n
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_1(s, o, macro, _m, tuple, n, pd) \
        RPP_IIF(RPP_TUPLE_IS_BATCH(10, tuple))( \
            DETAIL_RPP_TUPLE_FOR_EACH_I_1_I, DETAIL_RPP_TUPLE_FOR_EACH_I_2 \
        )(s, o, macro, _m, tuple, n, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_1_I(s, o, macro, _m, tuple, n, pd) \
        DETAIL_RPP_TUPLE_FOR_EACH_I_1_II(s, o, macro, _m, RPP_TUPLE_REM_CTOR(?, RPP_TUPLE_BATCH(10, tuple)), RPP_TUPLE_SANS_BATCH(10, tuple), n, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_1_II(...) DETAIL_RPP_TUPLE_FOR_EACH_I_1_III(RPP_OBSTRUCT(), __VA_ARGS__)
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_1_III(_, s, o, macro, _m, a, b, c, d, e, f, g, h, i, j, tuple, n, pd) \
        _m()(o, macro, n, a RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(n), b RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(n)), c RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(n))), d RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(n)))), e RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n))))), f RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n)))))), g RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n))))))), h RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n)))))))), i RPP_EXPOSE(pd)) \
        _m()(o, macro, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n))))))))), j RPP_EXPOSE(pd)) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOR_EACH_I_INDIRECT _(1)( \
            RPP_NEXT(s), o, macro, _m, tuple, RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(RPP_INC(n)))))))))), pd \
        )) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_2(s, o, macro, _m, tuple, n, pd) \
        RPP_IIF(RPP_TUPLE_IS_CONS(tuple))( \
            DETAIL_RPP_TUPLE_FOR_EACH_I_2_I, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, macro, _m, tuple, n, pd) \
        /**/
#    define DETAIL_RPP_TUPLE_FOR_EACH_I_2_I(_, s, o, macro, _m, tuple, n, pd) \
        _m()(o, macro, n, RPP_TUPLE_HEAD(tuple) RPP_EXPOSE(pd)) \
        RPP_EXPR_S _(s)(DETAIL_RPP_TUPLE_FOR_EACH_I_INDIRECT _(2)( \
            RPP_NEXT(s), o, macro, _m, RPP_TUPLE_TAIL(tuple), RPP_INC(n), pd \
        )) \
        /**/
# endif
#
# endif

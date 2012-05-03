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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_COMBINATORIAL_REPEAT_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_COMBINATORIAL_REPEAT_H
#
# include <ripple/algorithm/for_each_product.h>
# include <ripple/arithmetic/dec.h>
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_COMBINATORIAL_REPEAT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_COMBINATORIAL_REPEAT(count, macro, ...) RPP_COMBINATORIAL_REPEAT_S(RPP_STATE(), count, macro, __VA_ARGS__)
#    define RPP_COMBINATORIAL_REPEAT_ID() RPP_COMBINATORIAL_REPEAT
# endif
#
# /* RPP_COMBINATORIAL_REPEAT_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_COMBINATORIAL_REPEAT_S(s, count, macro, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_COMBINATORIAL_REPEAT_I( \
            RPP_NEXT(s), RPP_NEXT(s), count, 1, RPP_CALL(macro), macro, RPP_NON_OPTIONAL(__VA_ARGS__), (RPP_NON_OPTIONAL(__VA_ARGS__)), RPP_PACK_OPTIONAL(__VA_ARGS__) \
        )) \
        /**/
#    define RPP_COMBINATORIAL_REPEAT_S_ID() RPP_COMBINATORIAL_REPEAT_S
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_COMBINATORIAL_REPEAT_INDIRECT() DETAIL_RPP_COMBINATORIAL_REPEAT_I
#    define DETAIL_RPP_COMBINATORIAL_REPEAT_I(s, o, count, ...) \
        RPP_IF(count)( \
            DETAIL_RPP_COMBINATORIAL_REPEAT_II, RPP_EAT \
        )(RPP_OBSTRUCT(), s, o, count, __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_COMBINATORIAL_REPEAT_II(_, s, o, count, size, _m, macro, g, acc, pd) \
        RPP_EXPR_S _(s)( \
            RPP_FOR_EACH_PRODUCT_S _( \
                RPP_NEXT(s), DETAIL_RPP_COMBINATORIAL_REPEAT_III, acc, o, size, _m, macro, pd \
            ) \
            DETAIL_RPP_COMBINATORIAL_REPEAT_INDIRECT _()( \
                RPP_NEXT(s), o, RPP_DEC(count), RPP_INC(size), _m, macro, g, acc(g), pd \
            ) \
        ) \
        /**/
#    define DETAIL_RPP_COMBINATORIAL_REPEAT_III(s, product, o, size, _m, macro, pd) \
        RPP_OBSTRUCT(_m)()(o, macro, size, product RPP_EXPOSE(pd)) \
        /**/
# endif
#
# endif

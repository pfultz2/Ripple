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
# ifndef RIPPLE_PREPROCESSOR_DELINEATE_SHIFTED_PARAMS_H
# define RIPPLE_PREPROCESSOR_DELINEATE_SHIFTED_PARAMS_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/detection/is_binary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_DELINEATE_SHIFTED_PARAMS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED_PARAMS(count, sep, ...) RPP_DELINEATE_SHIFTED_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, sep, __VA_ARGS__)
# else /* TODO */
#    define RPP_DELINEATE_SHIFTED_PARAMS(count, sep, param) RPP_DELINEATE_SHIFTED_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, sep, param)
# endif
#
# define RPP_DELINEATE_SHIFTED_PARAMS_ID() RPP_DELINEATE_SHIFTED_PARAMS
#
# /* RPP_DELINEATE_SHIFTED_PARAMS_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_SHIFTED_PARAMS_BYPASS(s, count, sep, ...) DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_U(s, RPP_IS_VARIADIC(__VA_ARGS__), count, sep, (__VA_ARGS__))
# else /* TODO */
#    define RPP_DELINEATE_SHIFTED_PARAMS_BYPASS(s, count, sep, param) DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_U(s, RPP_IS_BINARY(param), count, sep, (param))
# endif
#
# define RPP_DELINEATE_SHIFTED_PARAMS_BYPASS_ID() RPP_DELINEATE_SHIFTED_PARAMS_BYPASS
#
# define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_U(s, id, count, sep, pp) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_I( \
        RPP_OBSTRUCT(), RPP_PREV(s), id, RPP_DEC(count), RPP_EMPTY, sep, pp \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_INDIRECT() DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_I
# define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_I(_, s, id, count, sep, ss, pp) \
    RPP_WHEN _(count)( \
        RPP_EXPR_S(s) _(DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_INDIRECT _()( \
            RPP_OBSTRUCT _(), RPP_PREV(s), id, RPP_DEC(count), ss, ss, pp \
        )) \
        RPP_PRIMITIVE_CAT(DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_, id) _(count, RPP_REM pp) sep _() \
    ) \
    /**/
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_0(c, ...) __VA_ARGS__ ## c
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_1(c, ...) RPP_DEFER(DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_2)(c, RPP_REM __VA_ARGS__)
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_2(c, a, ...) a ## c __VA_ARGS__ ## c
# else /* TODO */
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_0(c, param) param ## c
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_1(c, param) RPP_DEFER(DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_2)(c, RPP_TUPLE_REM(2) param)
#    define DETAIL_RPP_DELINEATE_SHIFTED_PARAMS_2(c, a, b) a ## c b ## c
# endif
#
# endif

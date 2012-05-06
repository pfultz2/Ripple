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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE */
#
# define RPP_DELINEATE(count, sep, macro) RPP_DELINEATE_S(RPP_STATE(), count, sep, macro)
#
# define RPP_DELINEATE_ID() RPP_DELINEATE
#
# /* RPP_DELINEATE_S */
#
# define RPP_DELINEATE_S(s, count, sep, macro) \
        DETAIL_RPP_DELINEATE_U(s, count, sep, macro) \
        /**/
#
# define RPP_DELINEATE_S_ID() RPP_DELINEATE_S
#
# define DETAIL_RPP_DELINEATE_U(s, count, sep, macro) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_I( \
        s, count, RPP_EMPTY, sep, macro, RPP_INVOKER(macro) \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_INDIRECT() DETAIL_RPP_DELINEATE_I
# define DETAIL_RPP_DELINEATE_I(s, count, sep, ss, macro, _m) \
    RPP_IF(count)( \
        DETAIL_RPP_DELINEATE_II, RPP_EAT \
    )(RPP_OBSTRUCT(), RPP_NEXT(s), RPP_DEC(count), sep, ss, macro, _m) \
    /**/
# define DETAIL_RPP_DELINEATE_II(_, s, count, sep, ss, macro, _m) \
    RPP_EXPR_S(s) _(DETAIL_RPP_DELINEATE_INDIRECT _()( \
        s, count, ss, ss, macro, _m \
    )) \
    _m _()(s, macro, s, count) sep() \
    /**/
# endif

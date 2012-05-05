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
        s, RPP_NEXT(s), count, RPP_EMPTY, sep, macro, RPP_INVOKER(macro) \
    )) \
    /**/
# define DETAIL_RPP_DELINEATE_INDIRECT() DETAIL_RPP_DELINEATE_I
# define DETAIL_RPP_DELINEATE_I(s, ns, count, sep, ss, macro, _m) \
    RPP_IF(count)( \
        DETAIL_RPP_DELINEATE_II, RPP_EAT \
    )(RPP_OBSTRUCT(), RPP_NEXT(s), ns, RPP_DEC(count), sep, ss, macro, _m) \
    /**/
# define DETAIL_RPP_DELINEATE_II(_, s, ns, count, sep, ss, macro, _m) \
    RPP_EXPR_S(s) _(DETAIL_RPP_DELINEATE_INDIRECT _()( \
        s, ns, count, ss, ss, macro, _m \
    )) \
    _m _(macro, ns, count) sep() \
    /**/
#
# endif

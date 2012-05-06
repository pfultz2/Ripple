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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DELINEATE_FROM_TO */
#
# define RPP_DELINEATE_FROM_TO(from, to, sep, macro) RPP_DELINEATE_FROM_TO_S(RPP_STATE(), from, to, sep, macro)
#
# define RPP_DELINEATE_FROM_TO_ID() RPP_DELINEATE_FROM_TO
#
# /* RPP_DELINEATE_FROM_TO_S */
#
# define RPP_DELINEATE_FROM_TO_S(s, from, to, sep, macro) \
        DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, macro) \
        /**/
#
# define RPP_DELINEATE_FROM_TO_S_ID() RPP_DELINEATE_FROM_TO_S
#
# define DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, macro) \
    RPP_EXPR_S(s)(DETAIL_RPP_DELINEATE_FROM_TO_I(RPP_NEXT(s), from, to, RPP_EMPTY, sep, macro, RPP_INVOKER(macro))) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT() DETAIL_RPP_DELINEATE_FROM_TO_I
# define DETAIL_RPP_DELINEATE_FROM_TO_I(s, from, to, s1, s2, macro, _m) \
    RPP_IIF(RPP_NOT_EQUAL(from, to))( \
        DETAIL_RPP_DELINEATE_FROM_TO_II, RPP_EAT \
    )(s, from, RPP_DEC(to), s1, s2, macro, _m) \
    /**/
# define DETAIL_RPP_DELINEATE_FROM_TO_II(s, from, to, s1, s2, macro, _m) \
    RPP_DEFER(RPP_EXPR_S(s))(RPP_DEFER(DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT)()( \
        RPP_NEXT(s), from, to, s2, s2, macro, _m \
    )) \
    RPP_DEFER(_m)()(s, macro, s, to) s1()
    /**/
#
# endif

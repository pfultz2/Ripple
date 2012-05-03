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
# ifndef RIPPLE_PREPROCESSOR_COMPARISON_NOT_EQUAL_H
# define RIPPLE_PREPROCESSOR_COMPARISON_NOT_EQUAL_H
#
# include <ripple/cat.h>
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/facilities/expand.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_NOT_EQUAL */
#
# define RPP_NOT_EQUAL(x, y) \
    RPP_IS_NULLARY( \
        RPP_EXPAND(RPP_PRIMITIVE_CAT(DETAIL_RPP_LESS_, x)( \
            RPP_EAT, \
            RPP_PRIMITIVE_CAT(DETAIL_RPP_LESS_, y) RPP_TUPLE_EAT(2) \
        ))(RPP_EAT, ()) \
    ) \
    /**/
# define RPP_NOT_EQUAL_ID() RPP_NOT_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

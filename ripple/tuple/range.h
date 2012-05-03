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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_RANGE_H
# define RIPPLE_PREPROCESSOR_TUPLE_RANGE_H
#
# include <ripple/config.h>
# include <ripple/limits.h>
# include <ripple/tuple/drop.h>
# include <ripple/tuple/take.h>
#
# /* RPP_TUPLE_RANGE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_RANGE(i, len, tuple) RPP_TUPLE_RANGE_BYPASS(RPP_LIMIT_EXPR, i, len, tuple)
#    define RPP_TUPLE_RANGE_ID() RPP_TUPLE_RANGE
# endif
#
# /* RPP_TUPLE_RANGE_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_RANGE_BYPASS(s, i, len, tuple) \
        RPP_TUPLE_TAKE_BYPASS(s, len, RPP_TUPLE_DROP_BYPASS(s, i, tuple)) \
        /**/
#    define RPP_TUPLE_RANGE_BYPASS_ID() RPP_TUPLE_RANGE_BYPASS
# endif
#
# endif

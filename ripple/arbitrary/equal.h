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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_EQUAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_EQUAL_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/merge.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/detection/is_unary.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/indirect.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_ARBITRARY_EQUAL */
#
# define RPP_ARBITRARY_EQUAL(x, y) DETAIL_RPP_ARBITRARY_EQUAL_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_EQUAL_ID() RPP_ARBITRARY_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_EQUAL_I(x, y) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        RPP_IIF(RPP_ARBITRARY_SIGN(y))( \
            RPP_ARBITRARY_EQUAL_INTERNAL(RPP_REM x, RPP_REM y), \
            0 \
        ), \
        RPP_IIF(RPP_ARBITRARY_SIGN(y))( \
            0, \
            RPP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* RPP_ARBITRARY_EQUAL_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        RPP_IS_UNARY(RPP_SCAN(1)( \
            DETAIL_RPP_ARBITRARY_EQUAL_M(0) RPP_ARBITRARY_FMERGE(x, y, DETAIL_RPP_ARBITRARY_EQUAL_M, 0)() \
        )) \
        /**/
# else
#    define RPP_ARBITRARY_EQUAL_INTERNAL(x, y) \
        RPP_IS_UNARY(RPP_SCAN(1)( \
            DETAIL_RPP_ARBITRARY_EQUAL_M(0) RPP_ARBITRARY_FMERGE(x, y, DETAIL_RPP_ARBITRARY_EQUAL_M, 0)(RPP_DEFER(RPP_EMPTY)()) \
        )) \
        /**/
# endif
#
# define DETAIL_RPP_ARBITRARY_EQUAL_M(x) DETAIL_RPP_ARBITRARY_EQUAL_II
# define DETAIL_RPP_ARBITRARY_EQUAL_II(x, y) DETAIL_RPP_ARBITRARY_EQUAL_ ## x ## y RPP_INDIRECT(0)
# define DETAIL_RPP_ARBITRARY_EQUAL_00
# define DETAIL_RPP_ARBITRARY_EQUAL_11
# define DETAIL_RPP_ARBITRARY_EQUAL_22
# define DETAIL_RPP_ARBITRARY_EQUAL_33
# define DETAIL_RPP_ARBITRARY_EQUAL_44
# define DETAIL_RPP_ARBITRARY_EQUAL_55
# define DETAIL_RPP_ARBITRARY_EQUAL_66
# define DETAIL_RPP_ARBITRARY_EQUAL_77
# define DETAIL_RPP_ARBITRARY_EQUAL_88
# define DETAIL_RPP_ARBITRARY_EQUAL_99
#
# endif

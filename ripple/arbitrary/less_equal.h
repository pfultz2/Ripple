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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_LESS_EQUAL_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/merge.h>
# include <ripple/arbitrary/detail/rel.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/indirect.h>
# include <ripple/logical/compl.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_LESS_EQUAL */
#
# define RPP_ARBITRARY_LESS_EQUAL(x, y) DETAIL_RPP_ARBITRARY_LESS_EQUAL_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_LESS_EQUAL_ID() RPP_ARBITRARY_LESS_EQUAL
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_LESS_EQUAL_I(x, y) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        RPP_IIF(RPP_ARBITRARY_SIGN(y))( \
            RPP_ARBITRARY_LESS_EQUAL_INTERNAL(RPP_REM y, RPP_REM x), \
            1 \
        ), \
        RPP_IIF(RPP_ARBITRARY_SIGN(y))( \
            0, \
            RPP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y) \
        ) \
    ) \
    /**/
#
# /* RPP_ARBITRARY_LESS_EQUAL_INTERNAL */
#
# define RPP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y) \
    RPP_COMPL(RPP_SCAN(1)( \
        DETAIL_RPP_ARBITRARY_LESS_EQUAL_M(1) RPP_ARBITRARY_FMERGE(x, y, DETAIL_RPP_ARBITRARY_LESS_EQUAL_M, 0)(RPP_DEC) \
    )) \
    /**/
#
# define DETAIL_RPP_ARBITRARY_LESS_EQUAL_M(x) DETAIL_RPP_ARBITRARY_LESS_EQUAL_ ## x
# define DETAIL_RPP_ARBITRARY_LESS_EQUAL_0(a, b) RPP_INDIRECT(0)
# define DETAIL_RPP_ARBITRARY_LESS_EQUAL_1(a, b) RPP_INDIRECT(RPP_ARBITRARY_REL(a, b))
# define DETAIL_RPP_ARBITRARY_LESS_EQUAL_2(a, b) RPP_INDIRECT(2)
#
# endif

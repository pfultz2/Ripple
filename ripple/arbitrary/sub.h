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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_SUB_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_SUB_H
#
# include <ripple/arbitrary/add.h>
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/detail/merge.h>
# include <ripple/arbitrary/detail/minus.h>
# include <ripple/arbitrary/detail/scan.h>
# include <ripple/arbitrary/less_equal.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/facilities/binary.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/indirect.h>
# include <ripple/logical/bitor.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/reverse.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_SUB */
#
# define RPP_ARBITRARY_SUB(x, y) DETAIL_RPP_ARBITRARY_SUB_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_SUB_ID() RPP_ARBITRARY_SUB
#
# if CONFIG_RIPPLE_STD
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_ARBITRARY_SUB_I(x, y) \
        RPP_VARIADIC_CAT(DETAIL_RPP_ARBITRARY_SUB_S_, RPP_ARBITRARY_SIGN(x), RPP_ARBITRARY_SIGN(y))( \
            RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))(RPP_REM) x, \
            RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(y))(RPP_REM) y \
        ) \
        /**/
# else
#    define DETAIL_RPP_ARBITRARY_SUB_I(x, y) \
        RPP_CAT(DETAIL_RPP_ARBITRARY_SUB_S_, RPP_CAT(RPP_ARBITRARY_SIGN(x), RPP_ARBITRARY_SIGN(y)))( \
            RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))(RPP_REM) x, \
            RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(y))(RPP_REM) y \
        ) \
        /**/
# endif
#
# define DETAIL_RPP_ARBITRARY_SUB_S_00(x, y) DETAIL_RPP_ARBITRARY_SUB_S_11(y, x)
# define DETAIL_RPP_ARBITRARY_SUB_S_01(x, y) RPP_ARBITRARY_ADD_INTERNAL(x, y)
# define DETAIL_RPP_ARBITRARY_SUB_S_10(x, y) (RPP_ARBITRARY_ADD_INTERNAL(x, y))
# define DETAIL_RPP_ARBITRARY_SUB_S_11(x, y) \
    RPP_ARBITRARY_FIX(RPP_IIF(RPP_ARBITRARY_LESS_EQUAL_INTERNAL(x, y))( \
        RPP_ARBITRARY_SUB_INTERNAL(y, x), (RPP_ARBITRARY_SUB_INTERNAL(x, y)) \
    )) \
    /**/
#
# /* RPP_ARBITRARY_SUB_INTERNAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARBITRARY_SUB_INTERNAL(x, y) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SEQ_REVERSE(RPP_SCAN(1)( \
            DETAIL_RPP_ARBITRARY_SUB_M(0) RPP_ARBITRARY_RMERGE(x, y, DETAIL_RPP_ARBITRARY_SUB_M, 0)() \
        ))) \
        /**/
# else
#    define RPP_ARBITRARY_SUB_INTERNAL(x, y) \
        RPP_ARBITRARY_FIX_INTERNAL(RPP_SEQ_REVERSE(RPP_SCAN(1)( \
            DETAIL_RPP_ARBITRARY_SUB_M(0) RPP_ARBITRARY_RMERGE(x, y, DETAIL_RPP_ARBITRARY_SUB_M, 0)(RPP_DEFER(RPP_EMPTY)()) \
        ))) \
        /**/
# endif
#
# define DETAIL_RPP_ARBITRARY_SUB_M(borrow) DETAIL_RPP_ARBITRARY_SUB_ ## borrow
# define DETAIL_RPP_ARBITRARY_SUB_0(x, y) DETAIL_RPP_ARBITRARY_SUB_II(RPP_MINUS(x, y), 0)
# define DETAIL_RPP_ARBITRARY_SUB_1(x, y) DETAIL_RPP_ARBITRARY_SUB_II(RPP_MINUS(x, y), 1)
# define DETAIL_RPP_ARBITRARY_SUB_II(bin, c) DETAIL_RPP_ARBITRARY_SUB_III(RPP_BINARY(0) bin, RPP_MINUS(RPP_BINARY(1) bin, c))
# define DETAIL_RPP_ARBITRARY_SUB_III(b, bin) (RPP_BINARY(1) bin) RPP_INDIRECT(RPP_BITOR(b)(RPP_BINARY(0) bin))
#
# endif

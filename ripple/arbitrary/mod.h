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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_MOD_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_MOD_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/div.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/control/inline_unless.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/binary.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_MOD */
#
# define RPP_ARBITRARY_MOD(x, y) DETAIL_RPP_ARBITRARY_MOD_I(RPP_ARBITRARY_FIX(x), RPP_ARBITRARY_FIX(y))
# define RPP_ARBITRARY_MOD_ID() RPP_ARBITRARY_MOD
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_MOD_I(x, y) \
    RPP_INLINE_UNLESS(RPP_ARBITRARY_SIGN(x))( \
        RPP_REM \
    )(RPP_ARBITRARY_MOD_INTERNAL( \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))(RPP_REM) x, \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(y))(RPP_REM) y \
    )) \
    /**/
#
# /* RPP_ARBITRARY_MOD_INTERNAL */
#
# define RPP_ARBITRARY_MOD_INTERNAL(x, y) RPP_BINARY_CTOR(1, DETAIL_RPP_ARBITRARY_DIV_1(x, y))
#
# endif

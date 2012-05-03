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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
#
# include <ripple/arbitrary/bool.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/control/if.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_unless.h>
# include <ripple/detection/is_unary.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_FIX */
#
# define RPP_ARBITRARY_FIX(x) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        DETAIL_RPP_ARBITRARY_FIX_I(RPP_ARBITRARY_FIX_INTERNAL(RPP_REM x)), \
        RPP_ARBITRARY_FIX_INTERNAL(x) \
    ) \
    /**/
#
# define DETAIL_RPP_ARBITRARY_FIX_I(x) \
    RPP_INLINE_UNLESS(RPP_ARBITRARY_BOOL_INTERNAL(x))( \
        RPP_REM \
    )(x) \
    /**/
#
# /* RPP_ARBITRARY_FIX_INTERNAL */
#
# define RPP_ARBITRARY_FIX_INTERNAL(x) DETAIL_RPP_ARBITRARY_FIX_II(DETAIL_RPP_ARBITRARY_FIX_A x)
#
# define DETAIL_RPP_ARBITRARY_FIX_II(c) RPP_IIF(RPP_IS_UNARY(c))(c, (0))
# define DETAIL_RPP_ARBITRARY_FIX_A(digit) RPP_IF(digit)((digit), DETAIL_RPP_ARBITRARY_FIX_B)
# define DETAIL_RPP_ARBITRARY_FIX_B(digit) RPP_IF(digit)((digit), DETAIL_RPP_ARBITRARY_FIX_A)
#
# endif

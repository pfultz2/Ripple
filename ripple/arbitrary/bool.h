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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_BOOL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_BOOL_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/logical/compl.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_BOOL */
#
# define RPP_ARBITRARY_BOOL(x) \
    RPP_ARBITRARY_BOOL_INTERNAL(RPP_ARBITRARY_FIX_INTERNAL( \
        RPP_INLINE_WHEN(RPP_ARBITRARY_SIGN(x))( \
            RPP_REM \
        ) x \
    )) \
    /**/
# define RPP_ARBITRARY_BOOL_ID() RPP_ARBITRARY_BOOL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ARBITRARY_BOOL_INTERNAL */
#
# define RPP_ARBITRARY_BOOL_INTERNAL(x) \
    RPP_COMPL(RPP_IS_NULLARY(DETAIL_RPP_ARBITRARY_BOOL_I x)) \
    /**/
#
# define DETAIL_RPP_ARBITRARY_BOOL_I(digit) DETAIL_RPP_ARBITRARY_BOOL_ ## digit
# define DETAIL_RPP_ARBITRARY_BOOL_0 ()
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_NEG_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_NEG_H
#
# include <ripple/arbitrary/detail/fix.h>
# include <ripple/arbitrary/sign.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/tuple/rem.h>
#
# define RPP_ARBITRARY_NEG(x) DETAIL_RPP_ARBITRARY_NEG_I(RPP_ARBITRARY_FIX(x))
# define RPP_ARBITRARY_NEG_ID() RPP_ARBITRARY_NEG
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ARBITRARY_NEG_I(x) \
    RPP_IIF(RPP_ARBITRARY_SIGN(x))( \
        RPP_REM x, RPP_ARBITRARY_FIX((x)) \
    ) \
    /**/
#
# endif

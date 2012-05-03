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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_DELVE_H
# define RIPPLE_PREPROCESSOR_RECURSION_DELVE_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_DELVE */
#
# define RPP_DELVE() DETAIL_RPP_DELVE_I(0)
# define RPP_DELVE_ID() RPP_DELVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_DELVE_INDIRECT() DETAIL_RPP_DELVE_I
# define DETAIL_RPP_DELVE_I(n) \
    RPP_IIF_SHADOW(RPP_IS_NULLARY(RPP_HALT(())))( \
        DETAIL_RPP_DELVE_INDIRECT RPP_OBSTRUCT()()(RPP_INC(n)), \
        n \
    ) \
    /**/
#
# /* RPP_HALT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_HALT(...) __VA_ARGS__
# else
#    define RPP_HALT(x) x
# endif
#
# define RPP_HALT_ID() RPP_HALT
#
# endif

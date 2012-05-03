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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_DELAY_H
# define RIPPLE_PREPROCESSOR_RECURSION_DELAY_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/control/if.h>
# include <ripple/config.h>
#
# /* RPP_DELAY */
#
# define RPP_DELAY(count, macro) \
    RPP_IF_SHADOW(count)( \
        RPP_DELAY_ID RPP_OBSTRUCT()()(RPP_DEC(count), macro), \
        macro \
    ) \
    /**/
# define RPP_DELAY_ID() RPP_DELAY
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

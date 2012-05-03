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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_DETAIN_H
# define RIPPLE_PREPROCESSOR_SANDBOX_DETAIN_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_DETAIN */
#
# define RPP_DETAIN(pred, macro) \
    RPP_IIF_SHADOW(pred())( \
        RPP_DETAIN_ID RPP_OBSTRUCT()()(pred, macro), \
        macro \
    ) \
    /**/
# define RPP_DETAIN_ID() RPP_DETAIN
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

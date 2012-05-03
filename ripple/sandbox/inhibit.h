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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_INHIBIT_H
# define RIPPLE_PREPROCESSOR_SANDBOX_INHIBIT_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_INHIBIT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_INHIBIT(pred, op, macro, ...) \
        RPP_IIF_SHADOW(pred(__VA_ARGS__))( \
            RPP_OBSTRUCT(RPP_INHIBIT_ID)()(pred, op, macro, op(__VA_ARGS__)), \
            macro \
        ) \
        /**/
# else
#    define RPP_INHIBIT(pred, op, macro, state) \
        RPP_IIF_SHADOW(pred(state))( \
            RPP_INHIBIT_ID RPP_OBSTRUCT()()(pred, op, macro, op(state)), \
            macro \
        ) \
        /**/
# endif
#
# define RPP_INHIBIT_ID() RPP_INHIBIT
#
# endif

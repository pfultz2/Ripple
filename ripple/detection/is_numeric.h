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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_NUMERIC_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_NUMERIC_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_empty.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/facilities/intercept.h>
#
# /* RPP_IS_NUMERIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_NUMERIC(x) \
        RPP_IIF(RPP_IS_VARIADIC(x))( \
            0, \
            RPP_IS_EMPTY(RPP_CAT(RPP_INTERCEPT, x)) \
        ) \
        /**/
# else
#    define RPP_IS_NUMERIC(x) RPP_IS_EMPTY(RPP_CAT(RPP_INTERCEPT, x))
# endif
#
# define RPP_IS_NUMERIC_ID() RPP_IS_NUMERIC
#
# endif

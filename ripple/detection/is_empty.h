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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_EMPTY_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_EMPTY_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/detection/is_variadic.h>
#
# /* RPP_IS_EMPTY */
#
# define RPP_IS_EMPTY(id) \
    RPP_IS_NULLARY(RPP_PRIMITIVE_CAT(DETAIL_RPP_IS_EMPTY_, id DETAIL_RPP_IS_EMPTY_I)) \
    /**/
# define RPP_IS_EMPTY_ID() RPP_IS_EMPTY
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_IS_EMPTY_DETAIL_RPP_IS_EMPTY_I ()
#
# /* RPP_IS_EMPTY_NON_FUNCTION */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_EMPTY_NON_FUNCTION(...) \
        RPP_IIF(RPP_IS_VARIADIC(__VA_ARGS__))( \
            0, \
            RPP_IS_NULLARY(DETAIL_RPP_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ ()) \
        ) \
        /**/
#    define RPP_IS_EMPTY_NON_FUNCTION_ID() RPP_IS_EMPTY_NON_FUNCTION
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_IS_EMPTY_NON_FUNCTION_C() ()
# endif
#
# endif

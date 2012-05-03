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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_UNBOX_H
# define RIPPLE_PREPROCESSOR_FACILITIES_UNBOX_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_unary.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_UNBOX */
#
# if CONFIG_RIPPLE_STD
#    define RPP_UNBOX(...) \
        RPP_INLINE_WHEN(RPP_IS_VARIADIC(__VA_ARGS__))( \
            RPP_REM __VA_ARGS__ \
        ) \
        /**/
# else
#    define RPP_UNBOX(x) \
        RPP_INLINE_WHEN(RPP_IS_UNARY(x))( \
            RPP_REM x \
        ) \
        /**/
# endif
#
# define RPP_UNBOX_ID() RPP_UNBOX
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_ENCODE_H
# define RIPPLE_PREPROCESSOR_FACILITIES_ENCODE_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ENCODE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENCODE(...) (__VA_ARGS__)
#    define RPP_ENCODE_ID() RPP_ENCODE
# endif
#
# /* RPP_DECODE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DECODE(...) \
        RPP_INLINE_WHEN(RPP_IS_VARIADIC(__VA_ARGS__))( \
            RPP_REM \
        ) __VA_ARGS__ \
        /**/
#    define RPP_DECODE_ID() RPP_DECODE
# endif
#
# endif

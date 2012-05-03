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
# ifndef RIPPLE_PREPROCESSOR_STRINGIZE_H
# define RIPPLE_PREPROCESSOR_STRINGIZE_H
#
# include <ripple/config.h>
#
# /* RPP_STRINGIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_STRINGIZE(...) RPP_PRIMITIVE_STRINGIZE(__VA_ARGS__)
# else
#    define RPP_STRINGIZE(...) RPP_PRIMITIVE_STRINGIZE((__VA_ARGS__))
#    define RPP_STRINGIZE_I(x) RPP_PRIMITIVE_STRINGIZE x
# endif
#
# define RPP_STRINGIZE_ID() RPP_STRINGIZE
#
# /* RPP_PRIMITIVE_STRINGIZE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PRIMITIVE_STRINGIZE(...) #__VA_ARGS__
# else
#    define RPP_PRIMITIVE_STRINGIZE(...) #__VA_ARGS__
# endif
#
# define RPP_PRIMITIVE_STRINGIZE_ID() RPP_PRIMITIVE_STRINGIZE
#
# endif

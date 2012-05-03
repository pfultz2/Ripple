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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_WHITESPACE_H
# define RIPPLE_PREPROCESSOR_FACILITIES_WHITESPACE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/extended/reverse_cat.h>
#
# /* RPP_NO_LEADING */
#
# if CONFIG_RIPPLE_STD
#    define RPP_NO_LEADING(...) RPP_PRIMITIVE_CAT(, __VA_ARGS__)
#    define RPP_NO_LEADING_ID() RPP_NO_LEADING
# endif
#
# /* RPP_NO_TRAILING */
#
# if CONFIG_RIPPLE_STD
#    define RPP_NO_TRAILING(...) RPP_PRIMITIVE_REVERSE_CAT(, __VA_ARGS__)
#    define RPP_NO_TRAILING_ID() RPP_NO_TRAILING
# endif
#
# /* RPP_CLEAN */
#
# if CONFIG_RIPPLE_STD
#    define RPP_CLEAN(...) RPP_NO_LEADING(RPP_NO_TRAILING(__VA_ARGS__))
#    define RPP_CLEAN_ID() RPP_CLEAN
# endif
#
# endif

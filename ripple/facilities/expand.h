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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_EXPAND_H
# define RIPPLE_PREPROCESSOR_FACILITIES_EXPAND_H
#
# include <ripple/config.h>
#
# /* RPP_EXPAND */
#
# if CONFIG_RIPPLE_STD
#    define RPP_EXPAND(...) __VA_ARGS__
# else
#    define RPP_EXPAND(x) x
# endif
#
# define RPP_EXPAND_ID() RPP_EXPAND
#
# endif

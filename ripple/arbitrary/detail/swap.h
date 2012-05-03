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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SWAP_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_SWAP_H
#
# include <ripple/config.h>
#
# /* RPP_SWAP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SWAP(a, ...) (__VA_ARGS__, a)
# else
#    define RPP_SWAP(a, b) (b, a)
# endif
#
# /* RPP_NO_SWAP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_NO_SWAP(a, ...) (a, __VA_ARGS__)
# else
#    define RPP_NO_SWAP(a, b) (a, b)
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_EQUALIZATION_ASSERT_H
# define RIPPLE_PREPROCESSOR_SANDBOX_EQUALIZATION_ASSERT_H
#
# include <ripple/config.h>
# include <ripple/debug/failure.h>
# include <ripple/recursion/equalize.h>
# include <ripple/recursion/delay.h>
# include <ripple/recursion/delve.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_IS_EQUALIZED */
#
# define RPP_IS_EQUALIZED(n) RPP_DELAY(n, RPP_FAILURE)()
# define RPP_IS_EQUALIZED_ID() RPP_IS_EQUALIZED
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_EQUALIZATION_ASSERT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_EQUALIZATION_ASSERT(...) RPP_EAT(__VA_ARGS__)
# else
#    define RPP_EQUALIZATION_ASSERT(x) RPP_EAT(x)
# endif
#
# define RPP_EQUALIZATION_ASSERT_ID() RPP_EQUALIZATION_ASSERT
#
# endif

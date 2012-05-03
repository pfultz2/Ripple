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
# ifndef RIPPLE_PREPROCESSOR_DEBUG_ASSERT_H
# define RIPPLE_PREPROCESSOR_DEBUG_ASSERT_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/debug/failure.h>
# include <ripple/facilities/empty.h>
# include <ripple/logical/not.h>
#
# /* RPP_ASSERT */
#
# define RPP_ASSERT(cond) RPP_INLINE_WHEN(RPP_NOT(cond))(RPP_FAILURE())
# define RPP_ASSERT_ID() RPP_ASSERT
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ASSERT_MSG */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ASSERT_MSG(cond, ...) RPP_INLINE_WHEN(RPP_NOT(cond))(__VA_ARGS__)
# else
#    define RPP_ASSERT_MSG(cond, msg) RPP_INLINE_WHEN(RPP_NOT(cond))(msg)
# endif
#
# define RPP_ASSERT_MSG_ID() RPP_ASSERT_MSG
#
# endif

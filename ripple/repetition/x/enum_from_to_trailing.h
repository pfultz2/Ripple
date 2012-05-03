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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_ENUM_FROM_TO_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_ENUM_FROM_TO_TRAILING_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/x/enum_from_to.h>
#
# /* RPP_ENUM_FROM_TO_TRAILING_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO_TRAILING_X(size, from, to, ...) RPP_ENUM_FROM_TO_TRAILING_X_S(RPP_STATE(), size, from, to, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO_TRAILING_X(size, from, to, macro, data) RPP_ENUM_FROM_TO_TRAILING_X_S(RPP_STATE(), size, from, to, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_TRAILING_X_ID() RPP_ENUM_FROM_TO_TRAILING_X
#
# /* RPP_ENUM_FROM_TO_TRAILING_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO_TRAILING_X_S(s, size, from, to, ...) RPP_COMMA_IF(RPP_NOT_EQUAL(from, to)) RPP_ENUM_FROM_TO_X_S(s, size, from, to, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO_TRAILING_X_S(s, size, from, to, macro, data) RPP_COMMA_IF(RPP_NOT_EQUAL(from, to)) RPP_ENUM_FROM_TO_X_S(s, size, from, to, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_TRAILING_X_S_ID() RPP_ENUM_FROM_TO_TRAILING_X_S
#
# endif

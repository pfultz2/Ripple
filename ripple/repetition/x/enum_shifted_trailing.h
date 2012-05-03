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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_X_ENUM_SHIFTED_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_X_ENUM_SHIFTED_TRAILING_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/x/enum_shifted.h>
#
# /* RPP_ENUM_SHIFTED_TRAILING_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_X(size, count, ...) RPP_ENUM_SHIFTED_TRAILING_X_S(RPP_STATE(), size, count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_X(size, count, macro, data) RPP_ENUM_SHIFTED_TRAILING_X_S(RPP_STATE(), size, count, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_X_ID() RPP_ENUM_SHIFTED_TRAILING_X
#
# /* RPP_ENUM_SHIFTED_TRAILING_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_X_S(s, size, count, ...) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_X_S(s, size, count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_X_S(s, size, count, macro, data) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_X_S(s, size, count, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_X_S_ID() RPP_ENUM_SHIFTED_TRAILING_X_S
#
# endif

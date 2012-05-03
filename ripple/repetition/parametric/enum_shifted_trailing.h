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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_SHIFTED_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_SHIFTED_TRAILING_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/parametric/enum_shifted.h>
#
# /* RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC(count, ...) RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S(RPP_STATE(), count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC(count, macro, data) RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S(RPP_STATE(), count, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_ID() RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC
#
# /* RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S(s, count, ...) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_PARAMETRIC_S(s, count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S(s, count, macro, data) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_PARAMETRIC_S(s, count, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S_ID() RPP_ENUM_SHIFTED_TRAILING_PARAMETRIC_S
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_FROM_TO_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_PARAMETRIC_ENUM_FROM_TO_TRAILING_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/parametric/enum_from_to.h>
#
# /* RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC(from, to, ...) RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(RPP_STATE(), from, to, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC(from, to, macro, data) RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(RPP_STATE(), from, to, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_ID() RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC
#
# /* RPP_ENUM_FROM_TO_TRAILING_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(s, from, to, ...) RPP_COMMA_IF(RPP_NOT_EQUAL(from, to)) RPP_ENUM_FROM_TO_PARAMETRIC_S(s, from, to, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S(s, from, to, macro, data) RPP_COMMA_IF(RPP_NOT_EQUAL(from, to)) RPP_ENUM_FROM_TO_PARAMETRIC_S(s, from, to, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S_ID() RPP_ENUM_FROM_TO_TRAILING_PARAMETRIC_S
#
# endif

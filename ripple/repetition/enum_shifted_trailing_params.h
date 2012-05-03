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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_PARAMS_H
# define RIPPLE_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_PARAMS_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/repetition/enum_shifted_params.h>
#
# /* RPP_ENUM_SHIFTED_TRAILING_PARAMS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMS(count, ...) RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMS(count, param) RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, param)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_PARAMS_ID() RPP_ENUM_SHIFTED_TRAILING_PARAMS
#
# /* RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(s, count, ...) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_PARAMS_BYPASS(s, count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS(s, count, param) RPP_COMMA_IF(RPP_DEC(count)) RPP_ENUM_SHIFTED_PARAMS_BYPASS(s, count, param)
# endif
#
# define RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS_ID() RPP_ENUM_SHIFTED_TRAILING_PARAMS_BYPASS
#
# endif

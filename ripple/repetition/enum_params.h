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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_ENUM_PARAMS_H
# define RIPPLE_PREPROCESSOR_REPETITION_ENUM_PARAMS_H
#
# include <ripple/config.h>
# include <ripple/limits.h>
# include <ripple/punctuation/comma.h>
# include <ripple/repetition/delineate_params.h>
#
# /* RPP_ENUM_PARAMS */
#
# define RPP_ENUM_PARAMS(count, ...) RPP_ENUM_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, __VA_ARGS__)
#
# define RPP_ENUM_PARAMS_ID() RPP_ENUM_PARAMS
#
# /* RPP_ENUM_PARAMS_BYPASS */
#
# define RPP_ENUM_PARAMS_BYPASS(s, count, ...) RPP_DELINEATE_PARAMS_BYPASS(s, count, RPP_COMMA, __VA_ARGS__)
#
# define RPP_ENUM_PARAMS_BYPASS_ID() RPP_ENUM_PARAMS_BYPASS
#
# endif

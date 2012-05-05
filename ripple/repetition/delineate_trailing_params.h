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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_PARAMS_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_TRAILING_PARAMS_H
#
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/limits.h>
# include <ripple/repetition/delineate_params.h>
#
# /* RPP_DELINEATE_TRAILING_PARAMS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING_PARAMS(count, sep, ...) RPP_DELINEATE_TRAILING_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, sep, __VA_ARGS__)
# else /* TODO */
#    define RPP_DELINEATE_TRAILING_PARAMS(count, sep, param) RPP_DELINEATE_TRAILING_PARAMS_BYPASS(RPP_LIMIT_EXPR, count, sep, param)
# endif
#
# define RPP_DELINEATE_TRAILING_PARAMS_ID() RPP_DELINEATE_TRAILING_PARAMS
#
# /* RPP_DELINEATE_TRAILING_PARAMS_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DELINEATE_TRAILING_PARAMS_BYPASS(s, count, sep, ...) RPP_WHEN(count)(sep()) RPP_DELINEATE_PARAMS_BYPASS(s, count, sep, __VA_ARGS__)
# else /* TODO */
#    define RPP_DELINEATE_TRAILING_PARAMS_BYPASS(s, count, sep, param) RPP_WHEN(count)(sep()) RPP_DELINEATE_PARAMS_BYPASS(s, count, sep, param)
# endif
#
# define RPP_DELINEATE_TRAILING_PARAMS_BYPASS_ID() RPP_DELINEATE_TRAILING_PARAMS_BYPASS
#
# endif

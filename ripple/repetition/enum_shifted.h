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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_ENUM_SHIFTED_H
# define RIPPLE_PREPROCESSOR_REPETITION_ENUM_SHIFTED_H
#
# include <ripple/config.h>
# include <ripple/punctuation/comma.h>
# include <ripple/repetition/delineate_shifted.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_ENUM_SHIFTED */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED(count, ...) RPP_ENUM_SHIFTED_S(RPP_STATE(), count, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED(count, macro, data) RPP_ENUM_SHIFTED_S(RPP_STATE(), count, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_ID() RPP_ENUM_SHIFTED
#
# /* RPP_ENUM_SHIFTED_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_SHIFTED_S(s, count, ...) RPP_DELINEATE_SHIFTED_S(s, count, RPP_COMMA, __VA_ARGS__)
# else
#    define RPP_ENUM_SHIFTED_S(s, count, macro, data) RPP_DELINEATE_SHIFTED_S(s, count, RPP_COMMA, macro, data)
# endif
#
# define RPP_ENUM_SHIFTED_S_ID() RPP_ENUM_SHIFTED_S
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_ENUM_FROM_TO_H
# define RIPPLE_PREPROCESSOR_REPETITION_ENUM_FROM_TO_H
#
# include <ripple/config.h>
# include <ripple/punctuation/comma.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/delineate_from_to.h>
#
# /* RPP_ENUM_FROM_TO */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO(from, to, ...) RPP_ENUM_FROM_TO_S(RPP_STATE(), from, to, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO(from, to, macro, data) RPP_ENUM_FROM_TO_S(RPP_STATE(), from, to, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_ID() RPP_ENUM_FROM_TO
#
# /* RPP_ENUM_FROM_TO_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ENUM_FROM_TO_S(s, from, to, ...) RPP_DELINEATE_FROM_TO_S(s, from, to, RPP_COMMA, __VA_ARGS__)
# else
#    define RPP_ENUM_FROM_TO_S(s, from, to, macro, data) RPP_DELINEATE_FROM_TO_S(s, from, to, RPP_COMMA, macro, data)
# endif
#
# define RPP_ENUM_FROM_TO_S_ID() RPP_ENUM_FROM_TO_S
#
# endif

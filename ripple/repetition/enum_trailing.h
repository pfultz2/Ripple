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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_ENUM_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_ENUM_TRAILING_H
#
# include <ripple/config.h>
# include <ripple/punctuation/comma_if.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/enum.h>
#
# /* RPP_ENUM_TRAILING */
#
# define RPP_ENUM_TRAILING(count, macro) RPP_ENUM_TRAILING_S(RPP_STATE(), count, macro)
#
# define RPP_ENUM_TRAILING_ID() RPP_ENUM_TRAILING
#
# /* RPP_ENUM_TRAILING_S */
#
# define RPP_ENUM_TRAILING_S(s, count, macro) RPP_COMMA_IF(count) RPP_ENUM_S(s, count, macro)
#
# define RPP_ENUM_TRAILING_S_ID() RPP_ENUM_TRAILING_S
#
# endif

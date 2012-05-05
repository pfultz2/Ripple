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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_TRAILING_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/delineate_shifted.h>
#
# /* RPP_DELINEATE_SHIFTED_TRAILING */
#
# define RPP_DELINEATE_SHIFTED_TRAILING(count, sep, macro) RPP_DELINEATE_SHIFTED_TRAILING_S(RPP_STATE(), count, sep, macro)
#
# define RPP_DELINEATE_SHIFTED_TRAILING_ID() RPP_DELINEATE_SHIFTED_TRAILING
#
# /* RPP_DELINEATE_SHIFTED_TRAILING_S */
#
# define RPP_DELINEATE_SHIFTED_TRAILING_S(s, count, sep, macro) RPP_WHEN(RPP_DEC(count))(sep()) RPP_DELINEATE_SHIFTED_S(s, count, sep, macro)
#
# define RPP_DELINEATE_SHIFTED_TRAILING_S_ID() RPP_DELINEATE_SHIFTED_TRAILING_S
#
# endif

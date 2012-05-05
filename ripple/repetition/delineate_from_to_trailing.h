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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_TRAILING_H
# define RIPPLE_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_TRAILING_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/recursion/expr.h>
# include <ripple/repetition/delineate_from_to.h>
#
# /* RPP_DELINEATE_FROM_TO_TRAILING */
#
# define RPP_DELINEATE_FROM_TO_TRAILING(from, to, sep, macro) RPP_DELINEATE_FROM_TO_TRAILING_S(RPP_STATE(), from, to, sep, macro)
#
# define RPP_DELINEATE_FROM_TO_TRAILING_ID() RPP_DELINEATE_FROM_TO_TRAILING
#
# /* RPP_DELINEATE_FROM_TO_TRAILING_S */
#
# define RPP_DELINEATE_FROM_TO_TRAILING_S(s, from, to, sep, macro) RPP_INLINE_WHEN(RPP_NOT_EQUAL(from, to))(sep()) RPP_DELINEATE_FROM_TO_S(s, from, to, sep, macro)
#
# define RPP_DELINEATE_FROM_TO_TRAILING_S_ID() RPP_DELINEATE_FROM_TO_TRAILING_S
#
# endif

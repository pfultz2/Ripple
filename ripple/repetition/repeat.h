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
# ifndef RIPPLE_PREPROCESSOR_REPETITION_REPEAT_H
# define RIPPLE_PREPROCESSOR_REPETITION_REPEAT_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/repetition/delineate.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_REPEAT */
#
# define RPP_REPEAT(count, macro) RPP_REPEAT_S(RPP_STATE(), count, macro)
#
# define RPP_REPEAT_ID() RPP_REPEAT
#
# /* RPP_REPEAT_S */
#
# define RPP_REPEAT_S(s, count, macro) RPP_DELINEATE_S(s, count, RPP_EMPTY, macro)
#
# define RPP_REPEAT_S_ID() RPP_REPEAT_S
#
# endif

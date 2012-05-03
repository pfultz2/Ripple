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
# ifndef RIPPLE_PREPROCESSOR_PUNCTUATION_COMMA_IF_H
# define RIPPLE_PREPROCESSOR_PUNCTUATION_COMMA_IF_H
#
# include <ripple/config.h>
# include <ripple/control/when.h>
# include <ripple/punctuation/comma.h>
#
# /* RPP_COMMA_IF */
#
# define RPP_COMMA_IF(cond) RPP_WHEN(cond)(RPP_COMMA())
# define RPP_COMMA_IF_ID() RPP_COMMA_IF
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

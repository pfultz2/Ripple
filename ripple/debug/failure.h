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
# ifndef RIPPLE_PREPROCESSOR_DEBUG_FAILURE_H
# define RIPPLE_PREPROCESSOR_DEBUG_FAILURE_H
#
# include <ripple/config.h>
#
# /* RPP_FAILURE */
#
# define RPP_FAILURE() DETAIL_RPP_FAILURE_I(!)
# define RPP_FAILURE_ID() RPP_FAILURE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_FAILURE_I() DETAIL_RPP_FAILURE_I
#
# endif

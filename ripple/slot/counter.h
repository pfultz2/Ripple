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
# ifndef RIPPLE_PREPROCESSOR_SLOT_COUNTER_H
# define RIPPLE_PREPROCESSOR_SLOT_COUNTER_H
#
# include <ripple/config.h>
# include <ripple/extended/variadic_cat.h>
# include <ripple/facilities/expand.h>
# include <ripple/slot/slot.h>
#
# /* RPP_COUNTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_COUNTER DETAIL_RPP_COUNTER_I()
# else
#    define RPP_COUNTER RPP_EXPAND(DETAIL_RPP_COUNTER_I())
# endif
#
# define RPP_COUNTER_ID() RPP_COUNTER
#
# ifndef RPP_SEED
#    define RPP_SEED 0
# endif
#
# define DETAIL_RPP_COUNTER_I() RPP_SEED
#
# /* RPP_UPDATE_COUNTER */
#
# define RPP_UPDATE_COUNTER() "ripple/slot/detail/counter.h"
# define RPP_UPDATE_COUNTER_ID() RPP_UPDATE_COUNTER
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

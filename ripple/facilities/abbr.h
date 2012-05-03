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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_ABBR_H
# define RIPPLE_PREPROCESSOR_FACILITIES_ABBR_H
#
# include <ripple/config.h>
#
# /* RPP_ABBR */
#
# define RPP_ABBR(id) RPP_ ## id
# define RPP_ABBR_ID() RPP_ABBR
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

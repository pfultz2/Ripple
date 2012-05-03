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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_IDENTITY_H
# define RIPPLE_PREPROCESSOR_FACILITIES_IDENTITY_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
#
# /* RPP_IDENTITY */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IDENTITY(...) __VA_ARGS__ RPP_EMPTY
# else
#    define RPP_IDENTITY(x) x RPP_EMPTY
# endif
#
# define RPP_IDENTITY_ID() RPP_IDENTITY
#
# endif

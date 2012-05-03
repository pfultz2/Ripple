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
# ifndef RIPPLE_PREPROCESSOR_GENERICS_STRIP_H
# define RIPPLE_PREPROCESSOR_GENERICS_STRIP_H
#
# include <ripple/config.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_STRIP */
#
# define RPP_STRIP(g) RPP_EAT g
# define RPP_STRIP_ID() RPP_STRIP
#
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_REVIVE_H
# define RIPPLE_PREPROCESSOR_RECURSION_REVIVE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_REVIVE */
#
# define RPP_REVIVE(macro) RPP_PRIMITIVE_CAT(macro, _ID)()
# define RPP_REVIVE_ID() RPP_REVIVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

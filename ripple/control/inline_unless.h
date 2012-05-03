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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_INLINE_UNLESS_H
# define RIPPLE_PREPROCESSOR_CONTROL_INLINE_UNLESS_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/logical/compl.h>
#
# /* RPP_INLINE_UNLESS */
#
# define RPP_INLINE_UNLESS(bit) RPP_INLINE_WHEN(RPP_COMPL(bit))
# define RPP_INLINE_UNLESS_ID() RPP_INLINE_UNLESS
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

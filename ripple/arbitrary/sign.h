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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_SIGN_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_SIGN_H
#
# include <ripple/config.h>
# include <ripple/detection/is_unary.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_ARBITRARY_SIGN */
#
# define RPP_ARBITRARY_SIGN(x) RPP_IS_UNARY(RPP_REM x)
# define RPP_ARBITRARY_SIGN_ID() RPP_ARBITRARY_SIGN
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_REVERSE_H
# define RIPPLE_PREPROCESSOR_ARRAY_REVERSE_H
#
# include <ripple/array/size.h>
# include <ripple/config.h>
# include <ripple/tuple/reverse.h>
#
# /* RPP_ARRAY_REVERSE */
#
# define RPP_ARRAY_REVERSE(array) (RPP_ARRAY_SIZE(array), RPP_TUPLE_REVERSE array)
# define RPP_ARRAY_REVERSE_ID() RPP_ARRAY_REVERSE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

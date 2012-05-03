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
# ifndef RIPPLE_PREPROCESSOR_ITERATION_LOCAL_H
# define RIPPLE_PREPROCESSOR_ITERATION_LOCAL_H
#
# include <ripple/config.h>
# include <ripple/facilities/binary.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_LOCAL_ITERATE */
#
# define RPP_LOCAL_ITERATE() "ripple/iteration/detail/local.h"
# define RPP_LOCAL_ITERATE_ID() RPP_LOCAL_ITERATE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_LOCAL_ITERATE_F(x, y) \
    (RPP_BINARY_CTOR(0, RPP_LOCAL_LIMITS)) <= x && x <= (RPP_BINARY_CTOR(1, RPP_LOCAL_LIMITS)) \
    /**/
# define DETAIL_RPP_LOCAL_ITERATE_R(x, y) \
    (RPP_BINARY_CTOR(0, RPP_LOCAL_LIMITS)) >= y && y >= (RPP_BINARY_CTOR(1, RPP_LOCAL_LIMITS)) \
    /**/
#
# endif

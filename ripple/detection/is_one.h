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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_ONE_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_ONE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/facilities/empty.h>
#
# /* RPP_IS_ONE */
#
# define RPP_IS_ONE(id) \
    RPP_IS_NULLARY(RPP_PRIMITIVE_CAT(DETAIL_RPP_IS_ONE_, id RPP_EMPTY())) \
    /**/
# define RPP_IS_ONE_ID() RPP_IS_ONE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_IS_ONE_1 ()
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_DETECTION_IS_FLAG_H
# define RIPPLE_PREPROCESSOR_DETECTION_IS_FLAG_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_empty.h>
# include <ripple/detection/is_one.h>
# include <ripple/facilities/empty.h>
#
# /* RPP_IS_FLAG */
#
# define RPP_IS_FLAG(id) \
    RPP_IIF(RPP_IS_EMPTY(id RPP_EMPTY()))( \
        1, RPP_IS_ONE(id) \
    ) \
    /**/
# define RPP_IS_FLAG_ID() RPP_IS_FLAG
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

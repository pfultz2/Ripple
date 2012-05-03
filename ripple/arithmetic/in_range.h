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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_IN_RANGE_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_IN_RANGE_H
#
# include <ripple/cat.h>
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
#
# /* RPP_IN_RANGE */
#
# define RPP_IN_RANGE(x) \
    RPP_IS_NULLARY( \
        RPP_PRIMITIVE_CAT(DETAIL_RPP_LESS_, x)((), ()) \
    ) \
    /**/
# define RPP_IN_RANGE_ID() RPP_IN_RANGE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

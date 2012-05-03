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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_AS_ARGS_H
# define RIPPLE_PREPROCESSOR_FACILITIES_AS_ARGS_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_AS_ARGS */
#
# define RPP_AS_ARGS(n) RPP_PRIMITIVE_CAT(DETAIL_RPP_AS_ARGS_, n)
# define RPP_AS_ARGS_ID() RPP_AS_ARGS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_AS_ARGS_2(s, array) (RPP_NEXT(s), RPP_TUPLE_REM_CTOR array)
# define DETAIL_RPP_AS_ARGS_3(s, a, array) (RPP_NEXT(s), a, RPP_TUPLE_REM_CTOR array)
# define DETAIL_RPP_AS_ARGS_4(s, a, b, array) (RPP_NEXT(s), a, b, RPP_TUPLE_REM_CTOR array)
# define DETAIL_RPP_AS_ARGS_5(s, a, b, c, array) (RPP_NEXT(s), a, b, c, RPP_TUPLE_REM_CTOR array)
#
# endif

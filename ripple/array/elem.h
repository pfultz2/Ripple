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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_ELEM_H
# define RIPPLE_PREPROCESSOR_ARRAY_ELEM_H
#
# include <ripple/array/size.h>
# include <ripple/array/to_tuple.h>
# include <ripple/config.h>
# include <ripple/tuple/elem.h>
#
# /* RPP_ARRAY_ELEM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_ARRAY_ELEM(i, array) RPP_TUPLE_ELEM(?, i, RPP_ARRAY_TO_TUPLE(array))
# else
#    define RPP_ARRAY_ELEM(i, array) RPP_TUPLE_ELEM(RPP_ARRAY_SIZE(array), i, RPP_ARRAY_TO_TUPLE(array))
# endif
#
# define RPP_ARRAY_ELEM_ID() RPP_ARRAY_ELEM
#
# endif

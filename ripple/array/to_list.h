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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_TO_LIST_H
# define RIPPLE_PREPROCESSOR_ARRAY_TO_LIST_H
#
# include <ripple/config.h>
# include <ripple/tuple/to_list.h>
#
# /* RPP_ARRAY_TO_LIST */
#
# define RPP_ARRAY_TO_LIST(array) RPP_TUPLE_TO_LIST array
# define RPP_ARRAY_TO_LIST_ID() RPP_ARRAY_TO_LIST
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_TUPLE_AS_ARGS_H
# define RIPPLE_PREPROCESSOR_TUPLE_AS_ARGS_H
#
# include <ripple/config.h>
# include <ripple/control/inline_when.h>
# include <ripple/tuple/core.h>
#
# /* RPP_TUPLE_AS_ARGS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TUPLE_AS_ARGS(tuple) \
        RPP_INLINE_WHEN(RPP_TUPLE_IS_NIL(tuple))(()) tuple \
        /**/
#    define RPP_TUPLE_AS_ARGS_ID() RPP_TUPLE_AS_ARGS
# endif
#
# endif

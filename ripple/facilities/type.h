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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_TYPE_H
# define RIPPLE_PREPROCESSOR_FACILITIES_TYPE_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/rail.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_TYPE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_TYPE(...) RPP_UNSAFE_RAIL(RPP_TUPLE_REM)(?)(__VA_ARGS__)
#    define RPP_TYPE_ID() RPP_TYPE
# endif
#
# /* RPP_TYPE_II */
#
# define RPP_TYPE_II RPP_UNSAFE_RAIL(RPP_EMPTY RPP_EMPTY)()
# define RPP_TYPE_II_ID() RPP_TYPE_II
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_BEGIN */
#
# define RPP_BEGIN RPP_UNSAFE_RAIL(RPP_RPAREN)()
# define RPP_BEGIN_ID() RPP_BEGIN
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_END */
#
# define RPP_END RPP_UNSAFE_RAIL(RPP_EMPTY RPP_LPAREN)()
# define RPP_END_ID() RPP_END
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

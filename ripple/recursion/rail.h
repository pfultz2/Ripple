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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_RAIL_H
# define RIPPLE_PREPROCESSOR_RECURSION_RAIL_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_RAIL */
#
# define RPP_RAIL(macro) \
    RPP_IIF_SHADOW(RPP_IS_NULLARY(RPP_WALL(())))( \
        RPP_RAIL_ID RPP_OBSTRUCT()()(macro), \
        macro RPP_OBSTRUCT() \
    ) \
    /**/
# define RPP_RAIL_ID() RPP_RAIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_UNSAFE_RAIL */
#
# define RPP_UNSAFE_RAIL(macro) \
    RPP_IIF_SHADOW(RPP_IS_NULLARY(RPP_WALL(())))( \
        RPP_UNSAFE_RAIL_ID RPP_OBSTRUCT()()(macro), \
        macro \
    ) \
    /**/
# define RPP_UNSAFE_RAIL_ID() RPP_UNSAFE_RAIL
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_WALL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_WALL(...) __VA_ARGS__
# else
#    define RPP_WALL(x) x
# endif
#
# define RPP_WALL_ID() RPP_WALL
#
# endif

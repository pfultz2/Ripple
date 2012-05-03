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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_DIV_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_DIV_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/arithmetic/machine/sub.h>
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/unless.h>
# include <ripple/debug/failure.h>
# include <ripple/recursion/machine.h>
#
# /* RPP_DIV_MACHINE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DIV_MACHINE(x, y) \
        RPP_UNLESS(y)(RPP_FAILURE()) \
        RPP_MACHINE((, x, (0xripple)(0xdiv), y, (0xripple)(0xstop),)) \
        /**/
#    define RPP_DIV_MACHINE_ID() RPP_DIV_MACHINE
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xdiv(p, x, y, ...) \
        RPP_INSTRUCTION(0xripple)(0xdetail)(0xdiv)(, x, y, 0, p ## __VA_ARGS__) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xdetail_0xdiv(p, x, y, r, ...) \
        RPP_IIF(RPP_LESS(x, y))( \
            (, r, p ## __VA_ARGS__), \
            (, x, (0xripple)(0xsub), y, (0xripple)(0xdetail)(0xdiv), y, RPP_INC(r), p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif

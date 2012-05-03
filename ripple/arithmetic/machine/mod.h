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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
#
# include <ripple/arithmetic/machine/sub.h>
# include <ripple/comparison/less.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/unless.h>
# include <ripple/debug/failure.h>
# include <ripple/recursion/machine.h>
#
# /* RPP_MOD_MACHINE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_MOD_MACHINE(x, y) \
        RPP_UNLESS(y)(RPP_FAILURE()) \
        RPP_MACHINE((, x, (0xripple)(0xmod), y, (0xripple)(0xstop),)) \
        /**/
#    define RPP_MOD_MACHINE_ID() RPP_MOD_MACHINE
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xmod(p, x, y, ...) \
        RPP_IIF(RPP_LESS(x, y))( \
            (, x, p ## __VA_ARGS__), \
            (, x, (0xripple)(0xsub), y, (0xripple)(0xmod), y, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif

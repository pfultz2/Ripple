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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/recursion/machine.h>
#
# /* RPP_SUB_MACHINE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SUB_MACHINE(x, y) \
        RPP_MACHINE((, x, (0xripple)(0xsub), y, (0xripple)(0xstop),)) \
        /**/
#    define RPP_SUB_MACHINE_ID() RPP_SUB_MACHINE
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xsub(p, x, y, ...) \
        RPP_IF(y)( \
            (, RPP_DEC(x), (0xripple)(0xsub), RPP_DEC(y), p ## __VA_ARGS__), \
            (, x, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif

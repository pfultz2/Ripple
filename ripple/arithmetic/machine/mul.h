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
# ifndef RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
# define RIPPLE_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/arithmetic/machine/add.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/recursion/machine.h>
#
# /* RPP_MUL_MACHINE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_MUL_MACHINE(x, y) \
        RPP_MACHINE((, x, (0xripple)(0xmul), y, (0xripple)(0xstop),)) \
        /**/
#    define RPP_MUL_MACHINE_ID() RPP_MUL_MACHINE
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xmul(p, x, y, ...) \
        RPP_INSTRUCTION(0xripple)(0xdetail)(0xmul)(, 0, x, y, p ## __VA_ARGS__) \
        /**/
# endif
#
# if CONFIG_RIPPLE_STD
#    define RPP_INSTRUCTION_0xripple_0xdetail_0xmul(p, r, x, y, ...) \
        RPP_IF(y)( \
            (, r, (0xripple)(0xadd), x, (0xripple)(0xdetail)(0xmul), x, RPP_DEC(y), p ## __VA_ARGS__), \
            (, r, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif

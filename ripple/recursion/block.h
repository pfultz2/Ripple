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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_BLOCK_H
# define RIPPLE_PREPROCESSOR_RECURSION_BLOCK_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
#
# /* RPP_BLOCK */
#
# define RPP_BLOCK(n, macro) RPP_PRIMITIVE_CAT(DETAIL_RPP_BLOCK_, n)(macro, RPP_EMPTY)
# define RPP_BLOCK_ID() RPP_BLOCK
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BLOCK_0(macro, _) macro
# define DETAIL_RPP_BLOCK_1(macro, _) macro _()
# define DETAIL_RPP_BLOCK_2(macro, _) macro _ _()()
# define DETAIL_RPP_BLOCK_3(macro, _) macro _ _ _()()()
# define DETAIL_RPP_BLOCK_4(macro, _) macro _ _ _ _()()()()
# define DETAIL_RPP_BLOCK_5(macro, _) macro _ _ _ _ _()()()()()
#
# endif

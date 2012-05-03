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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_PHASE_H
# define RIPPLE_PREPROCESSOR_RECURSION_PHASE_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/basic.h>
#
# /* RPP_PHASE */
#
# define RPP_PHASE(offset) RPP_PRIMITIVE_CAT(DETAIL_RPP_PHASE_, offset)
# define RPP_PHASE_ID() RPP_PHASE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_PHASE_0(n, macro) RPP_PRIMITIVE_CAT(DETAIL_RPP_PHASE_I_, n)(macro)
# define DETAIL_RPP_PHASE_1(n, macro) DETAIL_RPP_PHASE_0(RPP_INC(n), macro)
# define DETAIL_RPP_PHASE_2(n, macro) DETAIL_RPP_PHASE_1(RPP_INC(n), macro)
# define DETAIL_RPP_PHASE_3(n, macro) DETAIL_RPP_PHASE_2(RPP_INC(n), macro)
# define DETAIL_RPP_PHASE_4(n, macro) DETAIL_RPP_PHASE_3(RPP_INC(n), macro)
# define DETAIL_RPP_PHASE_5(n, macro) DETAIL_RPP_PHASE_4(RPP_INC(n), macro)
#
# define DETAIL_RPP_PHASE_I_0(macro) macro
# define DETAIL_RPP_PHASE_I_1(macro) RPP_DEFER(macro)
# define DETAIL_RPP_PHASE_I_2(macro) macro RPP_OBSTRUCT()
# define DETAIL_RPP_PHASE_I_3(macro) RPP_DEFER(DETAIL_RPP_PHASE_I_2)(macro)
# define DETAIL_RPP_PHASE_I_4(macro) RPP_DEFER(DETAIL_RPP_PHASE_I_3)(macro)
# define DETAIL_RPP_PHASE_I_5(macro) RPP_DEFER(DETAIL_RPP_PHASE_I_4)(macro)
#
# endif

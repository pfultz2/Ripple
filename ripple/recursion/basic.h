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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_BASIC_H
# define RIPPLE_PREPROCESSOR_RECURSION_BASIC_H
#
# include <ripple/config.h>
# include <ripple/facilities/empty.h>
#
# /* RPP_DEFER */
#
# define RPP_DEFER(macro) macro RPP_EMPTY()
# define RPP_DEFER_ID() RPP_DEFER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_REFER */
#
# define RPP_REFER(macro) macro
# define RPP_REFER_ID() RPP_REFER
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_OBSTRUCT */
#
# if CONFIG_RIPPLE_STD
#    define RPP_OBSTRUCT(macro) macro RPP_EMPTY RPP_EMPTY()()
# else
#    define RPP_OBSTRUCT() RPP_EMPTY RPP_EMPTY()()
# endif
#
# define RPP_OBSTRUCT_ID() RPP_OBSTRUCT
#
# endif

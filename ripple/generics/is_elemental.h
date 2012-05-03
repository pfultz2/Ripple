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
# ifndef RIPPLE_PREPROCESSOR_GENERICS_IS_ELEMENTAL_H
# define RIPPLE_PREPROCESSOR_GENERICS_IS_ELEMENTAL_H
#
# include <ripple/config.h>
# include <ripple/detection/is_variadic.h>
# include <ripple/generics/core.h>
# include <ripple/logical/compl.h>
#
# /* RPP_IS_ELEMENTAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_ELEMENTAL(type) \
        RPP_COMPL(RPP_IS_VARIADIC(RPP_ITEM(type,))) \
        /**/
# else
#    define RPP_IS_ELEMENTAL(type) 1
# endif
#
# define RPP_IS_ELEMENTAL_ID() RPP_IS_ELEMENTAL
#
# endif

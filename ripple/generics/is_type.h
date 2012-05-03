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
# ifndef RIPPLE_PREPROCESSOR_GENERICS_IS_TYPE_H
# define RIPPLE_PREPROCESSOR_GENERICS_IS_TYPE_H
#
# include <ripple/config.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/logical/compl.h>
#
# /* RPP_IS_TYPE */
#
# define RPP_IS_TYPE(type, g) \
    RPP_COMPL(RPP_IS_NULLARY( \
        RPP_TAG(type)(RPP_TAG(RPP_TYPEOF(g)))(()) \
    )) \
    /**/
# define RPP_IS_TYPE_ID() RPP_IS_TYPE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

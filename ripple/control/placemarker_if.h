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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_PLACEMARKER_IF_H
# define RIPPLE_PREPROCESSOR_CONTROL_PLACEMARKER_IF_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_PLACEMARKER_IF */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PLACEMARKER_IF(p) RPP_PRIMITIVE_CAT(DETAIL_RPP_PLACEMARKER_IF_, p)
#    define RPP_PLACEMARKER_IF_ID() RPP_PLACEMARKER_IF
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_PLACEMARKER_IF_(...) __VA_ARGS__
#    define DETAIL_RPP_PLACEMARKER_IF_0(...)
# endif
#
# endif

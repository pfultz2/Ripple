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
# ifndef RIPPLE_PREPROCESSOR_CONFIG_H
# define RIPPLE_PREPROCESSOR_CONFIG_H
#
# /* CONFIG_RIPPLE_STD */
#
# if !defined CONFIG_RIPPLE_STD
#    if defined (_MSVC_)
#        define CONFIG_RIPPLE_STD 0
#    else
#        define CONFIG_RIPPLE_STD 1
#    endif
# endif
#
#
# define CONFIG_RIPPLE_STD_ID() CONFIG_RIPPLE_STD
#
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_PUNCTUATION_PAREN_H
# define RIPPLE_PREPROCESSOR_PUNCTUATION_PAREN_H
#
# include <ripple/config.h>
#
# /* RPP_LPAREN */
#
# define RPP_LPAREN() (
# define RPP_LPAREN_ID() RPP_LPAREN
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RPAREN */
#
# define RPP_RPAREN() )
# define RPP_RPAREN_ID() RPP_RPAREN
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

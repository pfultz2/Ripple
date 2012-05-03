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
# ifndef RIPPLE_PREPROCESSOR_ARRAY_TO_SEQ_H
# define RIPPLE_PREPROCESSOR_ARRAY_TO_SEQ_H
#
# include <ripple/config.h>
# include <ripple/tuple/to_seq.h>
#
# /* RPP_ARRAY_TO_SEQ */
#
# define RPP_ARRAY_TO_SEQ(array) RPP_TUPLE_TO_SEQ array
# define RPP_ARRAY_TO_SEQ_ID() RPP_ARRAY_TO_SEQ
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

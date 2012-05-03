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
# ifndef RIPPLE_PREPROCESSOR_PUNCTUATION_HASH_H
# define RIPPLE_PREPROCESSOR_PUNCTUATION_HASH_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
#
# /* RPP_HASH */
#
# define RPP_HASH() DETAIL_RPP_HASH_I
# define RPP_HASH_ID() RPP_HASH
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_HASH_I #
#
# /* RPP_HASH_HASH */
#
# define RPP_HASH_HASH() RPP_CAT(RPP_HASH(), RPP_HASH())
# define RPP_HASH_HASH_ID() RPP_HASH_HASH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_DIGRAPH_HASH */
#
# define RPP_DIGRAPH_HASH() % ## :
# define RPP_DIGRAPH_HASH_ID() RPP_DIGRAPH_HASH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_DIGRAPH_HASH_HASH */
#
# define RPP_DIGRAPH_HASH_HASH() RPP_PRIMITIVE_CAT(% ## :, % ## :)
# define RPP_DIGRAPH_HASH_HASH_ID() RPP_DIGRAPH_HASH_HASH
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_REL_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_REL_H
#
# include <ripple/arbitrary/detail/lookup.h>
#
# /* RPP_ARBITRARY_REL */
#
# define RPP_ARBITRARY_REL(a, b) \
    RPP_ARBITRARY_LOOKUP(a, RPP_ARBITRARY_LOOKUP(b, ( \
        (1, 2, 2, 2, 2, 2, 2, 2, 2, 2), \
        (0, 1, 2, 2, 2, 2, 2, 2, 2, 2), \
        (0, 0, 1, 2, 2, 2, 2, 2, 2, 2), \
        (0, 0, 0, 1, 2, 2, 2, 2, 2, 2), \
        (0, 0, 0, 0, 1, 2, 2, 2, 2, 2), \
        (0, 0, 0, 0, 0, 1, 2, 2, 2, 2), \
        (0, 0, 0, 0, 0, 0, 1, 2, 2, 2), \
        (0, 0, 0, 0, 0, 0, 0, 1, 2, 2), \
        (0, 0, 0, 0, 0, 0, 0, 0, 1, 2), \
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 1) \
    ))) \
    /**/
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_EXPANDER_H
# define RIPPLE_PREPROCESSOR_FACILITIES_EXPANDER_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/enumerate.h>
#
# /* RPP_EXPANDER */
#
# define RPP_EXPANDER(arity) RPP_PRIMITIVE_CAT(DETAIL_RPP_EXPANDER_, arity)
# define RPP_EXPANDER_ID() RPP_EXPANDER
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_EXPANDER_2(s, seq) (RPP_NEXT(s), RPP_SEQ_ENUMERATE(seq))
# define DETAIL_RPP_EXPANDER_3(s, p1, seq) (RPP_NEXT(s), p1, RPP_SEQ_ENUMERATE(seq))
# define DETAIL_RPP_EXPANDER_4(s, p1, p2, seq) (RPP_NEXT(s), p1, p2, RPP_SEQ_ENUMERATE(seq))
# define DETAIL_RPP_EXPANDER_5(s, p1, p2, p3, seq) (RPP_NEXT(s), p1, p2, p3, RPP_SEQ_ENUMERATE(seq))
#
# endif

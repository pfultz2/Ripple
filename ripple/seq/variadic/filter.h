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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FILTER_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FILTER_H
#
# include <ripple/config.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/filter.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_FILTER */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FILTER(pred, ...) RPP_VARIADIC_SEQ_FILTER_S(RPP_STATE(), pred, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FILTER_ID() RPP_VARIADIC_SEQ_FILTER
# endif
#
# /* RPP_VARIADIC_SEQ_FILTER_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FILTER_S(s, pred, ...) RPP_DEFER(RPP_SEQ_UNZIP)(RPP_SEQ_FILTER_S(s, pred, RPP_SEQ_ZIP(RPP_NON_OPTIONAL(__VA_ARGS__)) RPP_EXPOSE(RPP_PACK_OPTIONAL(__VA_ARGS__))))
#    define RPP_VARIADIC_SEQ_FILTER_S_ID() RPP_VARIADIC_SEQ_FILTER_S
# endif
#
# endif

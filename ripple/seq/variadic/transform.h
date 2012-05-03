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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_TRANSFORM_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_TRANSFORM_H
#
# include <ripple/config.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/transform.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_TRANSFORM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_TRANSFORM(op, ...) RPP_VARIADIC_SEQ_TRANSFORM_S(RPP_STATE(), op, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_TRANSFORM_ID() RPP_VARIADIC_SEQ_TRANSFORM
# endif
#
# /* RPP_VARIADIC_SEQ_TRANSFORM_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_TRANSFORM_S(s, op, ...) RPP_SEQ_TRANSFORM_S(s, op, RPP_SEQ_ZIP(RPP_NON_OPTIONAL(__VA_ARGS__)) RPP_EXPOSE(RPP_PACK_OPTIONAL(__VA_ARGS__)))
#    define RPP_VARIADIC_SEQ_TRANSFORM_S_ID() RPP_VARIADIC_SEQ_TRANSFORM_S
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOR_EACH_H
# define RIPPLE_PREPROCESSOR_SEQ_VARIADIC_FOR_EACH_H
#
# include <ripple/config.h>
# include <ripple/facilities/optional.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/for_each.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_FOR_EACH */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOR_EACH(macro, ...) RPP_VARIADIC_SEQ_FOR_EACH_S(RPP_STATE(), macro, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOR_EACH_ID() RPP_VARIADIC_SEQ_FOR_EACH
# endif
#
# /* RPP_VARIADIC_SEQ_FOR_EACH_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOR_EACH_S(s, macro, ...) RPP_SEQ_FOR_EACH_S(s, macro, RPP_SEQ_ZIP(RPP_NON_OPTIONAL(__VA_ARGS__)) RPP_EXPOSE(RPP_PACK_OPTIONAL(__VA_ARGS__)))
#    define RPP_VARIADIC_SEQ_FOR_EACH_S_ID() RPP_VARIADIC_SEQ_FOR_EACH_S
# endif
#
# endif

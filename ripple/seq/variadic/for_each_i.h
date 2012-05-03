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
# include <ripple/seq/for_each_i.h>
# include <ripple/seq/zip.h>
#
# /* RPP_VARIADIC_SEQ_FOR_EACH_I */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOR_EACH_I(macro, ...) RPP_VARIADIC_SEQ_FOR_EACH_I_S(RPP_STATE(), macro, __VA_ARGS__)
#    define RPP_VARIADIC_SEQ_FOR_EACH_I_ID() RPP_VARIADIC_SEQ_FOR_EACH_I
# endif
#
# /* RPP_VARIADIC_SEQ_FOR_EACH_I_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_VARIADIC_SEQ_FOR_EACH_I_S(s, macro, ...) RPP_SEQ_FOR_EACH_I_S(s, macro, RPP_SEQ_ZIP(RPP_NON_OPTIONAL(__VA_ARGS__)) RPP_EXPOSE(RPP_PACK_OPTIONAL(__VA_ARGS__)))
#    define RPP_VARIADIC_SEQ_FOR_EACH_I_S_ID() RPP_VARIADIC_SEQ_FOR_EACH_I_S
# endif
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_RECURSION_DYNAMIC_H
# define RIPPLE_PREPROCESSOR_RECURSION_DYNAMIC_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/facilities/binary.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/detail/close.h>
# include <ripple/seq/infuse.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_DYNAMIC */
#
# define RPP_DYNAMIC(seq, macro, args) RPP_DYNAMIC_S(RPP_STATE(), seq, macro, args)
# define RPP_DYNAMIC_ID() RPP_DYNAMIC
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_DYNAMIC_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DYNAMIC_S(s, seq, macro, args) \
        RPP_EXPR_S(s)(DETAIL_RPP_DYNAMIC_I RPP_SEQ_INFUSE(seq, DETAIL_RPP_DYNAMIC_II, RPP_NEXT(s))(RPP_EAT, ~, ~)) \
        RPP_DEFER(macro) args \
        RPP_SEQ_CLOSE(RPP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
# else
#    define RPP_DYNAMIC_S(s, seq, macro, args) \
        RPP_EXPR_S(s)(DETAIL_RPP_DYNAMIC_I RPP_SEQ_INFUSE(seq, (DETAIL_RPP_DYNAMIC_II, RPP_NEXT(s)))((RPP_EAT, ~), ~)) \
        RPP_DEFER(macro) args \
        RPP_SEQ_CLOSE(RPP_SEQ_BINARY_TRANSFORM(seq, ~)) \
        /**/
# endif
#
# define DETAIL_RPP_DYNAMIC_INDIRECT() DETAIL_RPP_DYNAMIC_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_DYNAMIC_I(m, s, ...) m(s)
# else
#    define DETAIL_RPP_DYNAMIC_I(pair, _) RPP_BINARY(0) pair(RPP_BINARY(1) pair)
# endif
#
# define DETAIL_RPP_DYNAMIC_II(s) RPP_DEFER(RPP_EXPR_S)(s)(DETAIL_RPP_DYNAMIC_INDIRECT
#
# endif

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
# ifndef RIPPLE_PREPROCESSOR_SEQ_INFUSE_H
# define RIPPLE_PREPROCESSOR_SEQ_INFUSE_H
#
# include <ripple/config.h>
# include <ripple/facilities/expand.h>
# include <ripple/facilities/split.h>
# include <ripple/punctuation/comma.h>
# include <ripple/punctuation/paren.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/binary_transform.h>
# include <ripple/seq/detail/close.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_SEQ_INFUSE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_INFUSE(seq, ...) \
        RPP_SPLIT(0, RPP_EXPAND( \
            DETAIL_RPP_SEQ_INFUSE_I(RPP_SEQ_BINARY_TRANSFORM(seq,), __VA_ARGS__) \
        )) \
        /**/
# else
#    define RPP_SEQ_INFUSE(seq, data) \
        RPP_SPLIT(0, RPP_EXPAND( \
            DETAIL_RPP_SEQ_INFUSE_I(RPP_SEQ_BINARY_TRANSFORM(seq, ~), data) \
        ))() \
        /**/
# endif
#
# define RPP_SEQ_INFUSE_ID() RPP_SEQ_INFUSE
#
# define DETAIL_RPP_SEQ_INFUSE_A_ID() DETAIL_RPP_SEQ_INFUSE_A
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_INFUSE_I(bin, ...) DETAIL_RPP_SEQ_INFUSE_A bin, __VA_ARGS__ RPP_SEQ_CLOSE(bin)
#    define DETAIL_RPP_SEQ_INFUSE_A(m, ...) m(?)(DETAIL_RPP_SEQ_INFUSE_B RPP_DEFER(RPP_LPAREN)()(__VA_ARGS__), DETAIL_RPP_SEQ_INFUSE_A_ID)
#    define DETAIL_RPP_SEQ_INFUSE_B(...) DETAIL_RPP_SEQ_INFUSE_C(__VA_ARGS__)
#    define DETAIL_RPP_SEQ_INFUSE_C(x, res, ...) (__VA_ARGS__, RPP_REM x)() res, __VA_ARGS__
# else
#    define DETAIL_RPP_SEQ_INFUSE_I(bin, data) DETAIL_RPP_SEQ_INFUSE_A bin RPP_EMPTY RPP_DEFER(RPP_COMMA)() data RPP_SEQ_CLOSE(bin)
#    define DETAIL_RPP_SEQ_INFUSE_A(m, x) m(2)(DETAIL_RPP_SEQ_INFUSE_B RPP_DEFER(RPP_LPAREN)() x, DETAIL_RPP_SEQ_INFUSE_A_ID)
#    define DETAIL_RPP_SEQ_INFUSE_B(x, im) DETAIL_RPP_SEQ_INFUSE_C(x, im)
#    define DETAIL_RPP_SEQ_INFUSE_C(x, res, data) (data, x)() res, data
# endif
#
# endif

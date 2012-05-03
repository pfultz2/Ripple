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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_STREAM_H
# define RIPPLE_PREPROCESSOR_SANDBOX_STREAM_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/detection/is_nullary.h>
# include <ripple/list/core.h>
# include <ripple/logical/compl.h>
# include <ripple/recursion/basic.h>
#
# if !!!!!0 // WARNING: REDEFINITION!
#    undef RPP_LIST_TAIL
#    define RPP_LIST_TAIL(list) DETAIL_RPP_LIST_TAIL_SID(RPP_SPLIT(1, RPP_TUPLE_REM(2) list))
#    define DETAIL_RPP_LIST_TAIL_SID(x) x
# endif
#
# /* RPP_LIST_STREAM */
#
# if CONFIG_RIPPLE_STD
#    define RPP_LIST_STREAM(macro, ...) (macro(0, __VA_ARGS__), DETAIL_RPP_LIST_STREAM_I(1, macro, __VA_ARGS__))
#    define DETAIL_RPP_LIST_STREAM_I(n, macro, ...) \
        RPP_IIF_SHADOW(RPP_COMPL(RPP_IS_NULLARY(DETAIL_RPP_LIST_TAIL_SID(()))))( \
            (macro(n, __VA_ARGS__), DETAIL_RPP_LIST_STREAM_INDIRECT RPP_OBSTRUCT()()(RPP_INC(n), macro, __VA_ARGS__)), \
            DETAIL_RPP_LIST_STREAM_INDIRECT RPP_OBSTRUCT()()(n, macro, __VA_ARGS__) \
        ) \
        /**/
# else
#    define RPP_LIST_STREAM(macro, data) (macro(0, data), DETAIL_RPP_LIST_STREAM_I(1, macro, data))
#    define DETAIL_RPP_LIST_STREAM_I(n, macro, data) \
        RPP_IIF_SHADOW(RPP_COMPL(RPP_IS_NULLARY(DETAIL_RPP_LIST_TAIL_SID(()))))( \
            (macro(n, data), DETAIL_RPP_LIST_STREAM_INDIRECT RPP_OBSTRUCT()()(RPP_INC(n), macro, data)), \
            DETAIL_RPP_LIST_STREAM_INDIRECT RPP_OBSTRUCT()()(n, macro, data) \
        ) \
        /**/
# endif
#
# define RPP_LIST_STREAM_ID() RPP_LIST_STREAM
#
# define DETAIL_RPP_LIST_STREAM_INDIRECT() DETAIL_RPP_LIST_STREAM_I
#
# endif

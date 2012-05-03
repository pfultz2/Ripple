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
# ifndef RIPPLE_PREPROCESSOR_SANDBOX_APPLY_SCAN_H
# define RIPPLE_PREPROCESSOR_SANDBOX_APPLY_SCAN_H
#
# include <ripple/arithmetic/dec.h>
# include <ripple/config.h>
# include <ripple/control/if.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_APPLY_SCAN */
#
# if CONFIG_RIPPLE_STD
#    define RPP_APPLY_SCAN(p, n, ...) RPP_APPLY_SCAN_BYPASS(RPP_LIMIT_EXPR,, n, p ## __VA_ARGS__)
#    define RPP_APPLY_SCAN_ID() RPP_APPLY_SCAN
# endif
#
# /* RPP_APPLY_SCAN_BYPASS */
#
# if CONFIG_RIPPLE_STD
#    define RPP_APPLY_SCAN_BYPASS(s, p, n, ...) DETAIL_RPP_APPLY_SCAN_I(s,, RPP_DEC(n), p ## __VA_ARGS__)
#    define RPP_APPLY_SCAN_BYPASS_ID() RPP_APPLY_SCAN_BYPASS
#    define DETAIL_RPP_APPLY_SCAN_I(s, p, n, ...) \
        RPP_IF(n)( \
            DETAIL_RPP_APPLY_SCAN_II, DETAIL_RPP_APPLY_SCAN_V \
        )(s,, RPP_DEC(n), p ## __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_APPLY_SCAN_II(s, p, n, ...) \
        RPP_EXPR_S(s)(DETAIL_RPP_APPLY_SCAN_III( \
            RPP_PREV(s),, n, p ## __VA_ARGS__ \
        )) \
        /**/
#    define DETAIL_RPP_APPLY_SCAN_INDIRECT() DETAIL_RPP_APPLY_SCAN_III
#    define DETAIL_RPP_APPLY_SCAN_III(s, p, n, ...) \
        RPP_IF(n)( \
            DETAIL_RPP_APPLY_SCAN_IV, DETAIL_RPP_APPLY_SCAN_V \
        )(s,, n, p ## __VA_ARGS__) \
        /**/
#    define DETAIL_RPP_APPLY_SCAN_IV(s, p, n, ...) \
        RPP_DEFER(RPP_EXPR_S(s))(RPP_DEFER(DETAIL_RPP_APPLY_SCAN_INDIRECT)()( \
            RPP_PREV(s),, RPP_DEC(n), p ## __VA_ARGS__ \
        )) \
        /**/
#    define DETAIL_RPP_APPLY_SCAN_V(s, p, n, ...) p ## __VA_ARGS__
# endif
#
# endif

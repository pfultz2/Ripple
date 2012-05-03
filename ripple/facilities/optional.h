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
# ifndef RIPPLE_PREPROCESSOR_FACILITIES_OPTIONAL_H
# define RIPPLE_PREPROCESSOR_FACILITIES_OPTIONAL_H
#
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/control/inline_when.h>
# include <ripple/facilities/empty.h>
# include <ripple/facilities/split.h>
# include <ripple/tuple/core.h>
# include <ripple/tuple/rem.h>
#
# /* RPP_IS_OPTIONAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_IS_OPTIONAL(...) RPP_TUPLE_IS_NIL(RPP_TUPLE_TAIL((__VA_ARGS__)))
#    define RPP_IS_OPTIONAL_ID() RPP_IS_OPTIONAL
# endif
#
# /* RPP_OPTIONAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_OPTIONAL(...) \
        RPP_SPLIT(1, __VA_ARGS__ RPP_INLINE_WHEN(RPP_IS_OPTIONAL(__VA_ARGS__))(,)) \
        /**/
#    define RPP_OPTIONAL_ID() RPP_OPTIONAL
# endif
#
# /* RPP_NON_OPTIONAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_NON_OPTIONAL(...) RPP_SPLIT(0, __VA_ARGS__,)
#    define RPP_NON_OPTIONAL_ID() RPP_NON_OPTIONAL
# endif
#
# /* RPP_PACK_OPTIONAL */
#
# if CONFIG_RIPPLE_STD
#    define RPP_PACK_OPTIONAL(...) DETAIL_RPP_PACK_OPTIONAL_I(RPP_IS_OPTIONAL(__VA_ARGS__), __VA_ARGS__)
#    define RPP_PACK_OPTIONAL_ID() RPP_PACK_OPTIONAL
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_PACK_OPTIONAL_I(opt, ...) \
        (RPP_IIF(opt)(,,) RPP_SPLIT(1, __VA_ARGS__ RPP_INLINE_WHEN(opt)(,))) \
        /**/
# endif
#
# /* RPP_EXPOSE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_EXPOSE(pack) RPP_REM pack
# else
#    define RPP_EXPOSE(pack) , RPP_REM pack
# endif
#
# define RPP_EXPOSE_ID() RPP_EXPOSE
#
# endif

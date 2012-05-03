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
# ifndef RIPPLE_PREPROCESSOR_ITERATION_FILE_H
# define RIPPLE_PREPROCESSOR_ITERATION_FILE_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/control/null.h>
# include <ripple/facilities/expand.h>
# include <ripple/recursion/basic.h>
# include <ripple/seq/elem.h>
# include <ripple/slot/slot.h>
# include <ripple/stringize.h>
#
# /* RPP_ITERATE */
#
# define RPP_ITERATE() RPP_EXPAND(RPP_DEFER(DETAIL_RPP_ITERATE_I)(RPP_INC(RPP_ITERATION_DEPTH)))
# define RPP_ITERATE_ID() RPP_ITERATE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ITERATE_I(n) RPP_PRIMITIVE_STRINGIZE(ripple/iteration/detail/i ## n.h)
#
# /* RPP_ITERATION_DEPTH */
#
# define RPP_ITERATION_DEPTH 0
# define RPP_ITERATION_DEPTH_ID() RPP_ITERATION_DEPTH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_FRAME_ITERATION */
#
# define RPP_FRAME_ITERATION(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_ITERATION_, i)()
# define RPP_FRAME_ITERATION_ID() RPP_FRAME_ITERATION
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_FRAME_START */
#
# define RPP_FRAME_START(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_ITERATION_START_, i)()
# define RPP_FRAME_START_ID() RPP_FRAME_START
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_FRAME_FINISH */
#
# define RPP_FRAME_FINISH(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_ITERATION_FINISH_, i)()
# define RPP_FRAME_FINISH_ID() RPP_FRAME_FINISH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_FRAME_FLAGS */
#
# define RPP_FRAME_FLAGS(i) RPP_PRIMITIVE_CAT(DETAIL_RPP_ITERATION_FLAGS_, i)()
# define RPP_FRAME_FLAGS_ID() RPP_FRAME_FLAGS
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RELATIVE_ITERATION */
#
# define RPP_RELATIVE_ITERATION(i) RPP_FRAME_ITERATION(RPP_PRIMITIVE_CAT(DETAIL_RPP_RELATIVE_ITERATION_, i)())
# define RPP_RELATIVE_ITERATION_ID() RPP_RELATIVE_ITERATION
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RELATIVE_START */
#
# define RPP_RELATIVE_START(i) RPP_FRAME_START(RPP_PRIMITIVE_CAT(DETAIL_RPP_RELATIVE_ITERATION_, i)())
# define RPP_RELATIVE_START_ID() RPP_RELATIVE_START
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RELATIVE_FINISH */
#
# define RPP_RELATIVE_FINISH(i) RPP_FRAME_FINISH(RPP_PRIMITIVE_CAT(DETAIL_RPP_RELATIVE_ITERATION_, i)())
# define RPP_RELATIVE_FINISH_ID() RPP_RELATIVE_FINISH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_RELATIVE_FLAGS */
#
# define RPP_RELATIVE_FLAGS(i) RPP_FRAME_FLAGS(RPP_PRIMITIVE_CAT(DETAIL_RPP_RELATIVE_ITERATION_, i)())
# define RPP_RELATIVE_FLAGS_ID() RPP_RELATIVE_FLAGS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_RELATIVE_ITERATION_0() RPP_ITERATION_DEPTH
# define DETAIL_RPP_RELATIVE_ITERATION_1() RPP_DEC(RPP_ITERATION_DEPTH)
# define DETAIL_RPP_RELATIVE_ITERATION_2() RPP_DEC(DETAIL_RPP_RELATIVE_ITERATION_1())
# define DETAIL_RPP_RELATIVE_ITERATION_3() RPP_DEC(DETAIL_RPP_RELATIVE_ITERATION_2())
# define DETAIL_RPP_RELATIVE_ITERATION_4() RPP_DEC(DETAIL_RPP_RELATIVE_ITERATION_3())
#
# /* RPP_ITERATION */
#
# define RPP_ITERATION() RPP_RELATIVE_ITERATION(0)
# define RPP_ITERATION_ID() RPP_ITERATION
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ITERATION_START */
#
# define RPP_ITERATION_START() RPP_RELATIVE_START(0)
# define RPP_ITERATION_START_ID() RPP_ITERATION_START
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ITERATION_FINISH */
#
# define RPP_ITERATION_FINISH() RPP_RELATIVE_FINISH(0)
# define RPP_ITERATION_FINISH_ID() RPP_ITERATION_FINISH
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_ITERATION_FLAGS */
#
# define RPP_ITERATION_FLAGS() RPP_RELATIVE_FLAGS(0)
# define RPP_ITERATION_FLAGS_ID() RPP_ITERATION_FLAGS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_ITERATE_F(d, x) DETAIL_RPP_ITERATION_START_ ## d() <= x && x <= DETAIL_RPP_ITERATION_FINISH_ ## d()
# define DETAIL_RPP_ITERATE_R(d, x) DETAIL_RPP_ITERATION_START_ ## d() >= x && x >= DETAIL_RPP_ITERATION_FINISH_ ## d()
#
# endif

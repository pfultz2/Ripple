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
# ifndef RIPPLE_PREPROCESSOR_DEBUG_LINE_H
# define RIPPLE_PREPROCESSOR_DEBUG_LINE_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/iteration/file.h>
# include <ripple/stringize.h>
#
# /* RPP_LINE */
#
# define RPP_LINE(line, file) \
    line RPP_CAT(DETAIL_RPP_LINE_, RPP_ITERATION_DEPTH)(file, RPP_FRAME_ITERATION) \
    /**/
# define RPP_LINE_ID() RPP_LINE
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_LINE_0(file, i) RPP_PRIMITIVE_STRINGIZE(file)
# define DETAIL_RPP_LINE_1(file, i) RPP_STRINGIZE(file[i(1)])
# define DETAIL_RPP_LINE_2(file, i) RPP_STRINGIZE(file[i(1)][i(2)])
# define DETAIL_RPP_LINE_3(file, i) RPP_STRINGIZE(file[i(1)][i(2)][i(3)])
# define DETAIL_RPP_LINE_4(file, i) RPP_STRINGIZE(file[i(1)][i(2)][i(3)][i(4)])
# define DETAIL_RPP_LINE_5(file, i) RPP_STRINGIZE(file[i(1)][i(2)][i(3)][i(4)][i(5)])
#
# endif

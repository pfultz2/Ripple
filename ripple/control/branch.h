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
# ifndef RIPPLE_PREPROCESSOR_CONTROL_BRANCH_H
# define RIPPLE_PREPROCESSOR_CONTROL_BRANCH_H
#
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/logical/bool.h>
#
# /* RPP_BRANCH */
#
# define RPP_BRANCH(id) RPP_PRIMITIVE_CAT(DETAIL_RPP_BRANCH_A_, id)
# define RPP_BRANCH_ID() RPP_BRANCH
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_BRANCH_A_0xIF(cond) DETAIL_RPP_BRANCH_A_0xIIF(RPP_BOOL(cond))
# define DETAIL_RPP_BRANCH_A_0xIIF(bit) RPP_PRIMITIVE_CAT(DETAIL_RPP_BRANCH_A_0xIIF_, bit)
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_BRANCH_A_0xIIF_0(...) DETAIL_RPP_BRANCH_B
#    define DETAIL_RPP_BRANCH_A_0xIIF_1(...) __VA_ARGS__ DETAIL_RPP_BRANCH_C
# else
#    define DETAIL_RPP_BRANCH_A_0xIIF_0(x) DETAIL_RPP_BRANCH_B
#    define DETAIL_RPP_BRANCH_A_0xIIF_1(x) x DETAIL_RPP_BRANCH_C
# endif
#
# define DETAIL_RPP_BRANCH_B(id) RPP_PRIMITIVE_CAT(DETAIL_RPP_BRANCH_B_, id)
# define DETAIL_RPP_BRANCH_B_0xELIF DETAIL_RPP_BRANCH_A_0xIF
# define DETAIL_RPP_BRANCH_B_0xELIIF DETAIL_RPP_BRANCH_A_0xIIF
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_BRANCH_B_0xELSE(...) __VA_ARGS__ DETAIL_RPP_BRANCH_D
# else
#    define DETAIL_RPP_BRANCH_B_0xELSE(x) x DETAIL_RPP_BRANCH_D
# endif
#
# define DETAIL_RPP_BRANCH_B_0xENDIF
#
# define DETAIL_RPP_BRANCH_C(n) RPP_PRIMITIVE_CAT(DETAIL_RPP_BRANCH_C_, n)
# define DETAIL_RPP_BRANCH_C_0xELIF DETAIL_RPP_BRANCH_C_0xELIIF
# define DETAIL_RPP_BRANCH_C_0xELIIF(bit) DETAIL_RPP_BRANCH_C_0xELIIF_I
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_BRANCH_C_0xELIIF_I(...) DETAIL_RPP_BRANCH_C
#    define DETAIL_RPP_BRANCH_C_0xELSE(...) DETAIL_RPP_BRANCH_D
# else
#    define DETAIL_RPP_BRANCH_C_0xELIIF_I(x) DETAIL_RPP_BRANCH_C
#    define DETAIL_RPP_BRANCH_C_0xELSE(x) DETAIL_RPP_BRANCH_D
# endif
#
# define DETAIL_RPP_BRANCH_C_0xENDIF
#
# define DETAIL_RPP_BRANCH_D(id) RPP_PRIMITIVE_CAT(DETAIL_RPP_BRANCH_D_, id)
# define DETAIL_RPP_BRANCH_D_0xENDIF
#
# endif

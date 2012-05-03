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
# ifndef RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_DIVIDE_H
# define RIPPLE_PREPROCESSOR_ARBITRARY_DETAIL_DIVIDE_H
#
# include <ripple/arbitrary/detail/lookup.h>
# include <ripple/cat.h>
# include <ripple/config.h>
# include <ripple/extended/variadic_cat.h>
#
# /* RPP_DIVIDE */
#
# if CONFIG_RIPPLE_STD
#    define RPP_DIVIDE(a1, a2, b) \
        RPP_ARBITRARY_LOOKUP(b, RPP_VARIADIC_CAT(DETAIL_RPP_DIVIDE_, a1, a2)) \
        /**/
# else
#    define RPP_DIVIDE(a1, a2, b) \
        RPP_ARBITRARY_LOOKUP(b, RPP_CAT(DETAIL_RPP_DIVIDE_, RPP_PRIMITIVE_CAT(a1, a2))) \
        /**/
# endif
#
# define DETAIL_RPP_DIVIDE_00 (~, 0, 0, 0, 0, 0, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_01 (~, 1, 0, 0, 0, 0, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_02 (~, 2, 1, 0, 0, 0, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_03 (~, 3, 1, 1, 0, 0, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_04 (~, 4, 2, 1, 1, 0, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_05 (~, 5, 2, 1, 1, 1, 0, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_06 (~, 6, 3, 2, 1, 1, 1, 0, 0, 0)
# define DETAIL_RPP_DIVIDE_07 (~, 7, 3, 2, 1, 1, 1, 1, 0, 0)
# define DETAIL_RPP_DIVIDE_08 (~, 8, 4, 2, 2, 1, 1, 1, 1, 0)
# define DETAIL_RPP_DIVIDE_09 (~, 9, 4, 3, 2, 1, 1, 1, 1, 1)
# define DETAIL_RPP_DIVIDE_10 (~, 9, 5, 3, 2, 2, 1, 1, 1, 1)
# define DETAIL_RPP_DIVIDE_11 (~, 9, 5, 3, 2, 2, 1, 1, 1, 1)
# define DETAIL_RPP_DIVIDE_12 (~, 9, 6, 4, 3, 2, 2, 1, 1, 1)
# define DETAIL_RPP_DIVIDE_13 (~, 9, 6, 4, 3, 2, 2, 1, 1, 1)
# define DETAIL_RPP_DIVIDE_14 (~, 9, 7, 4, 3, 2, 2, 2, 1, 1)
# define DETAIL_RPP_DIVIDE_15 (~, 9, 7, 5, 3, 3, 2, 2, 1, 1)
# define DETAIL_RPP_DIVIDE_16 (~, 9, 8, 5, 4, 3, 2, 2, 2, 1)
# define DETAIL_RPP_DIVIDE_17 (~, 9, 8, 5, 4, 3, 2, 2, 2, 1)
# define DETAIL_RPP_DIVIDE_18 (~, 9, 9, 6, 4, 3, 3, 2, 2, 2)
# define DETAIL_RPP_DIVIDE_19 (~, 9, 9, 6, 4, 3, 3, 2, 2, 2)
# define DETAIL_RPP_DIVIDE_20 (~, 9, 9, 6, 5, 4, 3, 2, 2, 2)
# define DETAIL_RPP_DIVIDE_21 (~, 9, 9, 7, 5, 4, 3, 3, 2, 2)
# define DETAIL_RPP_DIVIDE_22 (~, 9, 9, 7, 5, 4, 3, 3, 2, 2)
# define DETAIL_RPP_DIVIDE_23 (~, 9, 9, 7, 5, 4, 3, 3, 2, 2)
# define DETAIL_RPP_DIVIDE_24 (~, 9, 9, 8, 6, 4, 4, 3, 3, 2)
# define DETAIL_RPP_DIVIDE_25 (~, 9, 9, 8, 6, 5, 4, 3, 3, 2)
# define DETAIL_RPP_DIVIDE_26 (~, 9, 9, 8, 6, 5, 4, 3, 3, 2)
# define DETAIL_RPP_DIVIDE_27 (~, 9, 9, 9, 6, 5, 4, 3, 3, 3)
# define DETAIL_RPP_DIVIDE_28 (~, 9, 9, 9, 7, 5, 4, 4, 3, 3)
# define DETAIL_RPP_DIVIDE_29 (~, 9, 9, 9, 7, 5, 4, 4, 3, 3)
# define DETAIL_RPP_DIVIDE_30 (~, 9, 9, 9, 7, 6, 5, 4, 3, 3)
# define DETAIL_RPP_DIVIDE_31 (~, 9, 9, 9, 7, 6, 5, 4, 3, 3)
# define DETAIL_RPP_DIVIDE_32 (~, 9, 9, 9, 8, 6, 5, 4, 4, 3)
# define DETAIL_RPP_DIVIDE_33 (~, 9, 9, 9, 8, 6, 5, 4, 4, 3)
# define DETAIL_RPP_DIVIDE_34 (~, 9, 9, 9, 8, 6, 5, 4, 4, 3)
# define DETAIL_RPP_DIVIDE_35 (~, 9, 9, 9, 8, 7, 5, 5, 4, 3)
# define DETAIL_RPP_DIVIDE_36 (~, 9, 9, 9, 9, 7, 6, 5, 4, 4)
# define DETAIL_RPP_DIVIDE_37 (~, 9, 9, 9, 9, 7, 6, 5, 4, 4)
# define DETAIL_RPP_DIVIDE_38 (~, 9, 9, 9, 9, 7, 6, 5, 4, 4)
# define DETAIL_RPP_DIVIDE_39 (~, 9, 9, 9, 9, 7, 6, 5, 4, 4)
# define DETAIL_RPP_DIVIDE_40 (~, 9, 9, 9, 9, 8, 6, 5, 5, 4)
# define DETAIL_RPP_DIVIDE_41 (~, 9, 9, 9, 9, 8, 6, 5, 5, 4)
# define DETAIL_RPP_DIVIDE_42 (~, 9, 9, 9, 9, 8, 7, 6, 5, 4)
# define DETAIL_RPP_DIVIDE_43 (~, 9, 9, 9, 9, 8, 7, 6, 5, 4)
# define DETAIL_RPP_DIVIDE_44 (~, 9, 9, 9, 9, 8, 7, 6, 5, 4)
# define DETAIL_RPP_DIVIDE_45 (~, 9, 9, 9, 9, 9, 7, 6, 5, 5)
# define DETAIL_RPP_DIVIDE_46 (~, 9, 9, 9, 9, 9, 7, 6, 5, 5)
# define DETAIL_RPP_DIVIDE_47 (~, 9, 9, 9, 9, 9, 7, 6, 5, 5)
# define DETAIL_RPP_DIVIDE_48 (~, 9, 9, 9, 9, 9, 8, 6, 6, 5)
# define DETAIL_RPP_DIVIDE_49 (~, 9, 9, 9, 9, 9, 8, 7, 6, 5)
# define DETAIL_RPP_DIVIDE_50 (~, 9, 9, 9, 9, 9, 8, 7, 6, 5)
# define DETAIL_RPP_DIVIDE_51 (~, 9, 9, 9, 9, 9, 8, 7, 6, 5)
# define DETAIL_RPP_DIVIDE_52 (~, 9, 9, 9, 9, 9, 8, 7, 6, 5)
# define DETAIL_RPP_DIVIDE_53 (~, 9, 9, 9, 9, 9, 8, 7, 6, 5)
# define DETAIL_RPP_DIVIDE_54 (~, 9, 9, 9, 9, 9, 9, 7, 6, 6)
# define DETAIL_RPP_DIVIDE_55 (~, 9, 9, 9, 9, 9, 9, 7, 6, 6)
# define DETAIL_RPP_DIVIDE_56 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_57 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_58 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_59 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_60 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_61 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_62 (~, 9, 9, 9, 9, 9, 9, 8, 7, 6)
# define DETAIL_RPP_DIVIDE_63 (~, 9, 9, 9, 9, 9, 9, 9, 7, 7)
# define DETAIL_RPP_DIVIDE_64 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_65 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_66 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_67 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_68 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_69 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_70 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_71 (~, 9, 9, 9, 9, 9, 9, 9, 8, 7)
# define DETAIL_RPP_DIVIDE_72 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_73 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_74 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_75 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_76 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_77 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_78 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_79 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_80 (~, 9, 9, 9, 9, 9, 9, 9, 9, 8)
# define DETAIL_RPP_DIVIDE_81 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_82 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_83 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_84 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_85 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_86 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_87 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_88 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_89 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_90 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_91 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_92 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_93 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_94 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_95 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_96 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_97 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_98 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
# define DETAIL_RPP_DIVIDE_99 (~, 9, 9, 9, 9, 9, 9, 9, 9, 9)
#
# endif

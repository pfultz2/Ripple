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
# ifndef RIPPLE_PREPROCESSOR_SEQ_ZIP_H
# define RIPPLE_PREPROCESSOR_SEQ_ZIP_H
#
# include <ripple/config.h>
# include <ripple/facilities/expand.h>
# include <ripple/seq/binary_transform.h>
#
# /* RPP_SEQ_ZIP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_ZIP(seq) \
        RPP_EXPAND(DETAIL_RPP_SEQ_ZIP_I RPP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
#    define RPP_SEQ_ZIP_ID() RPP_SEQ_ZIP
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_ZIP_INDIRECT() DETAIL_RPP_SEQ_ZIP_I
#    define DETAIL_RPP_SEQ_ZIP_I(id, ...) id(?)(((__VA_ARGS__)) DETAIL_RPP_SEQ_ZIP_INDIRECT)
# endif
#
# /* RPP_SEQ_UNZIP */
#
# if CONFIG_RIPPLE_STD
#    define RPP_SEQ_UNZIP(seq) \
        RPP_EXPAND(DETAIL_RPP_SEQ_UNZIP_I RPP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
#    define RPP_SEQ_UNZIP_ID() RPP_SEQ_UNZIP
# endif
#
# if CONFIG_RIPPLE_STD
#    define DETAIL_RPP_SEQ_UNZIP_INDIRECT() DETAIL_RPP_SEQ_UNZIP_I
#    define DETAIL_RPP_SEQ_UNZIP_I(id, zip) id(?)((RPP_REM zip) DETAIL_RPP_SEQ_UNZIP_INDIRECT)
# endif
#
# endif

/* ********************************************************************
 *                                                                    *
 *    (C) Copyright Paul Fultz II 2012.                               *
 *                                                                    *
 *    Distributed under the Boost Software License, Version 1.0.      *
 *    (See accompanying file LICENSE).                                *
 *                                                                    *
 *    See http://github.com/pfultz2/Ripple for most recent version.   *
 *                                                                    *
 ******************************************************************** */

#ifndef RIPPLE_PREPROCESSOR_OPS_H
#define RIPPLE_PREPROCESSOR_OPS_H
#include <ripple/config.h>

#define DETAIL_RPP_OPS_RES(x) x

#define RPP_INC(x) DETAIL_RPP_OPS_RES(DETAIL_RPP_INC_I RPP_PRIMITIVE_CAT(DETAIL_RPP_OPS_, x))
#define DETAIL_RPP_INC_I(x, y) y

#define RPP_DEC(x) DETAIL_RPP_OPS_RES(DETAIL_RPP_DEC_I RPP_PRIMITIVE_CAT(DETAIL_RPP_OPS_, x))
#define DETAIL_RPP_DEC_I(x, y) x

$for i in range(65537)
{
$if i == 0
{
#define DETAIL_RPP_OPS_$(i) ($(0), $(i+1))
}
$if i != 0
{
#define DETAIL_RPP_OPS_$(i) ($(i-1), $(i+1))
}
}

#endif
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

#ifndef RIPPLE_PREPROCESSOR_SEARCH_H
#define RIPPLE_PREPROCESSOR_SEARCH_H
#include <ripple/config.h>
#include <ripple/logic.h>

#define RPP_SEARCH(pred, n) DETAIL_RPP_BS_NODE_CHECK(pred, RPP_CAT(DETAIL_RPP_BS_NODE_E_, n)(pred))

#define DETAIL_RPP_BS_NODE_CHECK(p, x) RPP_IIF(p(x))(x, 0)

$for nmax in [15]
{
$for (n, m, i) in [(2**(i+1), 2**i, i) for i in range(nmax)]
{
#define DETAIL_RPP_BS_NODE_E_$(n)(p) DETAIL_RPP_BS_NODE_$(m) $for x in range(i+1) {(p)}
}
/**/
$for (n, m) in [((2**nmax)/2**(i+1), 2**i) for i in range(1, nmax)]
{
$for (x, y, j) in [( (j)*n, (j+2)*n, j ) for j in range(1,m*4, 4)]
{
#define DETAIL_RPP_BS_NODE_$((x+y)/2)(p) RPP_IIF(p($((x+y)/2)))(DETAIL_RPP_BS_NODE_$(x), DETAIL_RPP_BS_NODE_$(y))
$if n is 1
{
#define DETAIL_RPP_BS_NODE_$(x)(p) RPP_IIF(p($(x))) ($(x), $(x+1))
#define DETAIL_RPP_BS_NODE_$(y)(p) RPP_IIF(p($(y))) ($(y), $(y+1))
}
}
}
}

#endif
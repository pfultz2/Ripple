/* 
 * File:   binary_search.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 3:24 PM
 */

#ifndef BINARY_SEARCH_H
#define	BINARY_SEARCH_H


#define PX_BINARY_SEARCH(pred, n) DETAIL_PX_BS_NODE_CHECK(pred, PX_CAT(DETAIL_PX_BS_NODE_E_, n)(pred))

#define DETAIL_PX_BS_NODE_CHECK(p, x) PX_IIF(p(x))(x, 0)

$for nmax in [10]
{
$for (n, m, i) in [(2**(i+1), 2**i, i) for i in range(nmax)]
{
#define DETAIL_PX_BS_NODE_E_$(n)(p) DETAIL_PX_BS_NODE_$(m) $for x in range(i+1) {(p)}
}
//
$for (n, m) in [((2**nmax)/2**(i+1), 2**i) for i in range(1, nmax)]
{
$for (x, y, j) in [( (j)*n, (j+2)*n, j ) for j in range(1,m*4, 4)]
{
#define DETAIL_PX_BS_NODE_$((x+y)/2)(p) PX_IIF(p($((x+y)/2)))(DETAIL_PX_BS_NODE_$(x), DETAIL_PX_BS_NODE_$(y))
$if n is 1
{
#define DETAIL_PX_BS_NODE_$(x)(p) PX_IIF(p($(x))) ($(x), $(x+1))
#define DETAIL_PX_BS_NODE_$(y)(p) PX_IIF(p($(y))) ($(y), $(y+1))
}
}
}
}

#endif	/* BINARY_SEARCH_H */


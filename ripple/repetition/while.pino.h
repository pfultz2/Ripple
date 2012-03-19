/* 
 * File:   while.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 5:07 PM
 */

#ifndef WHILE_H
#define	WHILE_H

#if 0
#define PX_WHILE(state, pred, op)
#endif

#define PX_WHILE PX_CAT(DETAIL_PX_WHILE_F_, PX_REC_STATE())

#define DETAIL_PX_WHILE_NOP(...)

$for recursion_max in [1024]
{
$for x in range(1, recursion_max+1)
{
//$(x)
#define DETAIL_PX_WHILE_F_$(x)(state, pred, op) PX_IF(PX_INVOKE(pred, state)) \
( \
PX_REC_INVOKE_S($(x)), \
DETAIL_PX_WHILE_NOP \
) (DETAIL_PX_WHILE_, state, pred, op)
//
#define DETAIL_PX_WHILE_$(x)(state, pred, op) DETAIL_PX_WHILE_F_$(x+1)(PX_INVOKE(op, state), pred, op)
}
}


#endif	/* WHILE_H */


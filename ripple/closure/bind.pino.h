/* 
 * File:   bind.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 12:36 PM
 */

#ifndef BIND_H
#define	BIND_H

#define PX_BIND(m, ...) PX_BIND_NIL (m, __VA_ARGS__)

//Register BIND_INVOKE with INVOKE
#define PX_INVOKER_PX_BIND_NIL PX_INVOKER(PX_BIND_INVOKE_)

#define DETAIL_PX_BIND_INVOKE_M(b) PX_FIRST b
#define DETAIL_PX_BIND_INVOKE_ARGS(b) PX_TAIL b
//
$for recursion_max in [8]
{
$for x in range(1, recursion_max+1)
{
#define PX_BIND_INVOKE_$(x)(b, args) DETAIL_PX_INVOKE_MACRO_$(x)(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
}
}

#endif	/* BIND_H */


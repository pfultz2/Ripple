/* 
 * File:   invoke.h
 * Author: pfultz
 *
 * Created on January 19, 2012, 2:24 PM
 */

#ifndef INVOKE_H
#define	INVOKE_H

#include <ripple/control/iif.h>
#include <ripple/core/check.h>
#include <ripple/recursion/binary_search.h>
#include <ripple/recursion/invoke.h>

#define DETAIL_PX_INVOKE(m, n) PX_CAT(PX_IIF(DETAIL_PX_IS_INVOKER(m))(DETAIL_PX_INVOKE_EXP_, DETAIL_PX_INVOKE_MACRO_), n)

#define PX_INVOKER(x) x, 1,

#define DETAIL_PX_INVOKER(x) PX_JOIN(PX_INVOKER_, x)
#define DETAIL_PX_IS_INVOKER(x) PX_CHECK(DETAIL_PX_INVOKER(x))
#define DETAIL_PX_INVOKER_REMOVE_TAG(x) PX_CHECK_TAIL(DETAIL_PX_INVOKER(x))

#define DETAIL_PX_INVOKE_X(x) x, 1,
#define DETAIL_PX_INVOKE_P(n) PX_CHECK(PX_INVOKE_ ## n(DETAIL_PX_INVOKE_X, PX_NIL))

//#define PX_REC_INVOKE_INDIRECT_PX_INVOKE_(...) PX_REC_INVOKE(PX_INVOKE_, (__VA_ARGS__))
//
$for recursion_max in [8]
{
#define PX_INVOKE PX_CAT(PX_INVOKE_, PX_BINARY_SEARCH(DETAIL_PX_INVOKE_P, $(recursion_max)))
//
$for x in range(1, recursion_max+1)
{
//recursion level: $(x)
#define PX_INVOKE_$(x)(m, ...) DETAIL_PX_INVOKE(m, $(x))(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_$(x)(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_$(x)(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), $(x)) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
}
}


#endif	/* INVOKE_H */


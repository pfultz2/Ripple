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

#define DETAIL_PX_INVOKE(m, n) PX_CAT(PX_IIF(DETAIL_PX_IS_INVOKER(m))(DETAIL_PX_INVOKE_EXP_, DETAIL_PX_INVOKE_MACRO_), n)

#define PX_INVOKER(x) x, 1,

#define DETAIL_PX_INVOKER(x) PX_JOIN(PX_INVOKER_, x)
#define DETAIL_PX_IS_INVOKER(x) PX_CHECK(DETAIL_PX_INVOKER(x))
#define DETAIL_PX_INVOKER_REMOVE_TAG(x) PX_CHECK_TAIL(DETAIL_PX_INVOKER(x))

#define DETAIL_PX_INVOKE_X(x) x, 1,
#define DETAIL_PX_INVOKE_P(n) PX_CHECK(PX_INVOKE_ ## n(DETAIL_PX_INVOKE_X, PX_NIL))
//

#define PX_INVOKE PX_CAT(PX_INVOKE_, PX_BINARY_SEARCH(DETAIL_PX_INVOKE_P, 8))
//
//recursion level: 1
#define PX_INVOKE_1(m, ...) DETAIL_PX_INVOKE(m, 1)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_1(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_1(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 1) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 2
#define PX_INVOKE_2(m, ...) DETAIL_PX_INVOKE(m, 2)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_2(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_2(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 2) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 3
#define PX_INVOKE_3(m, ...) DETAIL_PX_INVOKE(m, 3)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_3(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_3(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 3) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 4
#define PX_INVOKE_4(m, ...) DETAIL_PX_INVOKE(m, 4)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_4(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_4(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 4) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 5
#define PX_INVOKE_5(m, ...) DETAIL_PX_INVOKE(m, 5)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_5(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_5(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 5) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 6
#define PX_INVOKE_6(m, ...) DETAIL_PX_INVOKE(m, 6)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_6(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_6(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 6) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 7
#define PX_INVOKE_7(m, ...) DETAIL_PX_INVOKE(m, 7)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_7(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_7(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 7) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)
//recursion level: 8
#define PX_INVOKE_8(m, ...) DETAIL_PX_INVOKE(m, 8)(m, (__VA_ARGS__))
#define DETAIL_PX_INVOKE_MACRO_8(m, args) m args 
#define DETAIL_PX_INVOKE_EXP_8(b, args) PX_CAT(PX_FIRST(DETAIL_PX_INVOKER(b)), 8) (DETAIL_PX_INVOKER_REMOVE_TAG(b), args)


#endif	/* INVOKE_H */


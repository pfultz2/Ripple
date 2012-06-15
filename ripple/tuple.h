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

#ifndef RIPPLE_PREPROCESSOR_TUPLE_H
#define RIPPLE_PREPROCESSOR_TUPLE_H
#include <ripple/config.h>


#define RPP_TUPLE_NIL()

#define RPP_TUPLE_IS_NIL(tuple) RPP_COMPL(RPP_TUPLE_IS_CONS(tuple))

#define RPP_TUPLE_IS_CONS(tuple) RPP_IS_PAREN(tuple)

#define RPP_TUPLE_CONS(tuple, x) ( x RPP_INLINE_WHEN(RPP_TUPLE_IS_CONS(tuple))(, RPP_REM tuple) )

#define RPP_TUPLE_HEAD(tuple) RPP_DETAIL_TUPLE_HEAD tuple
#define RPP_DETAIL_TUPLE_HEAD(...) RPP_DETAIL_TUPLE_HEAD_I(__VA_ARGS__,)
#define RPP_DETAIL_TUPLE_HEAD_I(x, ...) x


#define RPP_TUPLE_TAIL(tuple) RPP_IIF(RPP_TUPLE_IS_CONS(tuple))(RPP_DETAIL_TUPLE_TAIL, RPP_EAT)(tuple)
#define RPP_DETAIL_TUPLE_TAIL(tuple) RPP_CAT(RPP_DETAIL_TUPLE_TAIL_, RPP_IS_1(RPP_NARGS tuple)) tuple
#define RPP_DETAIL_TUPLE_TAIL_0(x, ...) (__VA_ARGS__)
#define RPP_DETAIL_TUPLE_TAIL_1(x)

#define RPP_TUPLE_SIZE(tuple) RPP_IIF(RPP_TUPLE_IS_CONS(tuple))(RPP_NARGS tuple, 0)

#define RPP_TUPLE_IS_SINGLE(tuple) RPP_IS_1(RPP_TUPLE_SIZE(tuple))


#endif
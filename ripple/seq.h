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

#ifndef RIPPLE_PREPROCESSOR_SEQ_H
#define RIPPLE_PREPROCESSOR_SEQ_H
#include <ripple/config.h>


#define RPP_SEQ_NIL()

#define RPP_SEQ_IS_NIL(seq) RPP_COMPL(RPP_SEQ_IS_CONS(seq))

#define RPP_SEQ_IS_CONS(seq) RPP_IS_PAREN(seq)

#define RPP_SEQ_CONS(seq, ...) (__VA_ARGS__) seq

#define RPP_SEQ_HEAD(seq) RPP_IIF(RPP_SEQ_IS_CONS(seq))(RPP_DETAIL_SEQ_HEAD, RPP_EAT)(RPP_DETAIL_SEQ_HEAD_MARK seq)
#define RPP_DETAIL_SEQ_HEAD_MARK(...) (__VA_ARGS__),
#define RPP_DETAIL_SEQ_HEAD(...) RPP_DETAIL_SEQ_HEAD_I(__VA_ARGS__,)
#define RPP_DETAIL_SEQ_HEAD_I(x, ...) RPP_REM x


#define RPP_SEQ_TAIL(seq) RPP_EAT seq

#endif
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

#ifndef RIPPLE_PREPROCESSOR_PUNCTUATION_H
#define RIPPLE_PREPROCESSOR_PUNCTUATION_H
#include <ripple/config.h>

#define RPP_COMMA() ,

#define RPP_COMMA_IF(n) RPP_IF(n)(RPP_COMMA, RPP_EMPTY)()

#endif
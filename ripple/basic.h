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

#ifndef RIPPLE_PREPROCESSOR_BASIC_H
#define RIPPLE_PREPROCESSOR_BASIC_H
#include <ripple/config.h>

#define RPP_EMPTY()

#define RPP_EAT(...)

#define RPP_REM(...) __VA_ARGS__

#define RPP_EXPAND(...) __VA_ARGS__

#define RPP_IDENTITY(...) __VA_ARGS__ RPP_EMPTY

#define RPP_DEFER(...) __VA_ARGS__ RPP_EMPTY()

#define RPP_OBSTRUCT(...) __VA_ARGS__ RPP_EMPTY() RPP_EMPTY()

#endif
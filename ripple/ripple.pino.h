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

#ifndef RIPPLE_PREPROCESSOR_RIPPLE_H
#define RIPPLE_PREPROCESSOR_RIPPLE_H

$for f in os.listdir(os.getcwd())
{
$if f.endswith(".h") and "pino" not in f and "test" not in f and "ripple" not in f
{
#include <ripple/$(f)>
}
}

#endif
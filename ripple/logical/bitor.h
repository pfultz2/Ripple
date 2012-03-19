/* 
 * File:   bitor.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 1:49 PM
 */

#ifndef BITOR_H
#define	BITOR_H

#include "config.h"

#define DETAIL_PX_BITOR_00 0
#define DETAIL_PX_BITOR_01 1
#define DETAIL_PX_BITOR_10 1
#define DETAIL_PX_BITOR_11 1

#ifdef PX_CONFIG_STD
#define DETAIL_PX_BITOR_I(x, y) DETAIL_PX_BITOR_ ## x ## y
#define PX_BITOR(x, y) DETAIL_PX_BITOR_I(x, y)
#else
#define DETAIL_PX_BITOR_RES(res) res
#define DETAIL_PX_BITOR_III(x, y) DETAIL_PX_BITOR_RES(DETAIL_PX_BITOR_ ## x ## y)
#define DETAIL_PX_BITOR_II(x, y) DETAIL_PX_BITOR_III(x, y)
#define DETAIL_PX_BITOR_I(args) DETAIL_PX_BITOR_II args
#define PX_BITOR(x, y) DETAIL_PX_BITOR_I((x, y))
#endif

#endif	/* BITOR_H */


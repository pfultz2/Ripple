/* 
 * File:   bitand.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 1:42 PM
 */

#ifndef BITAND_H
#define	BITAND_H

#include "config.h"

#define DETAIL_PX_BITAND_00 0
#define DETAIL_PX_BITAND_01 0
#define DETAIL_PX_BITAND_10 0
#define DETAIL_PX_BITAND_11 1

#ifdef PX_CONFIG_STD
#define DETAIL_PX_BITAND_I(x, y) DETAIL_PX_BITAND_ ## x ## y
#define PX_BITAND(x, y) DETAIL_PX_BITAND_I(x, y)
#else
#define DETAIL_PX_BITAND_RES(res) res
#define DETAIL_PX_BITAND_III(x, y) DETAIL_PX_BITAND_RES(DETAIL_PX_BITAND_ ## x ## y)
#define DETAIL_PX_BITAND_II(x, y) DETAIL_PX_BITAND_III(x, y)
#define DETAIL_PX_BITAND_I(args) DETAIL_PX_BITAND_II args
#define PX_BITAND(x, y) DETAIL_PX_BITAND_I((x, y))
#endif

#endif	/* BITAND_H */


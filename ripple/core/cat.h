/* 
 * File:   cat.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 1:08 PM
 */

#include "config.h"

#ifndef CAT_H
#define	CAT_H

#ifdef PX_CONFIG_STD

#define DETAIL_PX_CAT_I(x, y) x ## y
#define PX_CAT(x, y) DETAIL_PX_CAT_I(x, y)

#else

#define DETAIL_PX_CAT_RES(res) res
#define DETAIL_PX_CAT_III(x, y) DETAIL_PX_CAT_RES(x ## y)
#define DETAIL_PX_CAT_II(x, y) DETAIL_PX_CAT_III(x, y)
#define DETAIL_PX_CAT_I(args) DETAIL_PX_CAT_II args
#define PX_CAT(x, y) DETAIL_PX_CAT_I((x, y))

#endif

#endif	/* CAT_H */


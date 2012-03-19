/* 
 * File:   iif.h
 * Author: pfultz
 *
 * Created on January 17, 2012, 1:23 PM
 */

#ifndef IIF_H
#define	IIF_H

#include <ripple/config.h>

#define DETAIL_PX_IIF_0(t, f) f
#define DETAIL_PX_IIF_1(t, f) t

#ifdef PX_CONFIG_STD
#define DETAIL_PX_IIF_I(bit) DETAIL_PX_IIF_ ## bit
#define PX_IIF(bit) DETAIL_PX_IIF_I(bit)
#else
#define DETAIL_PX_IIF_RES(res) res
#define DETAIL_PX_IIF_III(bit) DETAIL_PX_IIF_RES(DETAIL_PX_IIF_ ## bit)
#define DETAIL_PX_IIF_II(bit) DETAIL_PX_IIF_III(bit)
#define DETAIL_PX_IIF_I(args) DETAIL_PX_IIF_II args
#define PX_IIF(bit) DETAIL_PX_IIF_I((bit))
#endif


#endif	/* IIF_H */


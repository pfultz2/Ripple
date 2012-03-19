/* 
 * File:   compl.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 4:48 PM
 */

#ifndef COMPL_H
#define	COMPL_H

#define DETAIL_PX_COMPL_0 1
#define DETAIL_PX_COMPL_1 0


#ifdef PX_CONFIG_STD
#define DETAIL_PX_COMPL_I(x) DETAIL_PX_COMPL_ ## x
#define PX_COMPL(x) DETAIL_PX_COMPL_I(x)
#else
#define DETAIL_PX_COMPL_RES(res) res
#define DETAIL_PX_COMPL_III(x) DETAIL_PX_COMPL_RES(DETAIL_PX_COMPL_ ## x)
#define DETAIL_PX_COMPL_II(x) DETAIL_PX_COMPL_III(x)
#define DETAIL_PX_COMPL_I(args) DETAIL_PX_COMPL_II args
#define PX_COMPL(x) DETAIL_PX_COMPL_I((x))
#endif

#endif	/* COMPL_H */


/* 
 * File:   bool.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 4:47 PM
 */

#ifndef BOOL_H
#define	BOOL_H

#define DETAIL_PX_BOOL_PROBE_0 ~, 1,

#define PX_BOOL(x) PX_CHECK(PX_JOIN(DETAIL_PX_BOOL_PROBE_, x))

#endif	/* BOOL_H */


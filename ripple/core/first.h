/* 
 * File:   first.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 2:37 PM
 */

#ifndef FIRST_H
#define	FIRST_H


#ifdef PX_CONFIG_STD
#define DETAIL_PX_FIRST_I(x, ...) x
#define PX_FIRST(...) DETAIL_PX_FIRST_I(__VA_ARGS__,)

#else
#define DETAIL_PX_FIRST_RES(x) x
#define DETAIL_PX_FIRST_II(x, ...) x
#define DETAIL_PX_FIRST_I(x) DETAIL_PX_FIRST_RES(DETAIL_PX_FIRST_II x)
#define PX_FIRST(...) DETAIL_PX_FIRST_I((__VA_ARGS__,~))

#endif

#endif	/* FIRST_H */


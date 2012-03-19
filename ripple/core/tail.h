/* 
 * File:   tail.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 2:37 PM
 */

#ifndef TAIL_H
#define	TAIL_H

//TODO: Check if there is a tail and return none
#ifdef PX_CONFIG_STD
#define DETAIL_PX_TAIL_I(x, ...) __VA_ARGS__
#define PX_TAIL(...) DETAIL_PX_TAIL_I(__VA_ARGS__,)

#else
#define DETAIL_PX_TAIL_RES(x) x
#define DETAIL_PX_TAIL_II(x, ...) __VA_ARGS__
#define DETAIL_PX_TAIL_I(x) DETAIL_PX_TAIL_RES(DETAIL_PX_TAIL_II x)
#define PX_TAIL(...) DETAIL_PX_TAIL_I((__VA_ARGS__,~))

#endif

#endif	/* TAIL_H */


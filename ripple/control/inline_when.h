/* 
 * File:   inline_when.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 4:58 PM
 */

#ifndef INLINE_WHEN_H
#define	INLINE_WHEN_H

#define DETAIL_PX_INLINE_WHEN_0(...) 
#define DETAIL_PX_INLINE_WHEN_1(...) __VA_ARGS__

#ifdef PX_CONFIG_STD
#define DETAIL_PX_INLINE_WHEN_I(bit) DETAIL_PX_INLINE_WHEN_ ## bit
#define PX_INLINE_WHEN(bit) DETAIL_PX_INLINE_WHEN_I(bit)
#else
#define DETAIL_PX_INLINE_WHEN_RES(res) res
#define DETAIL_PX_INLINE_WHEN_III(bit) DETAIL_PX_INLINE_WHEN_RES(DETAIL_PX_INLINE_WHEN_ ## bit)
#define DETAIL_PX_INLINE_WHEN_II(bit) DETAIL_PX_INLINE_WHEN_III(bit)
#define DETAIL_PX_INLINE_WHEN_I(args) DETAIL_PX_INLINE_WHEN_II args
#define PX_INLINE_WHEN(bit) DETAIL_PX_INLINE_WHEN_I((bit))
#endif

#endif	/* INLINE_WHEN_H */


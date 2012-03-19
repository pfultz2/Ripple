/* 
 * File:   expand.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 12:32 PM
 */

#ifndef EXPAND_H
#define	EXPAND_H

#ifdef PX_CONFIG_STD
#define DETAIL_PX_EXPAND(...) __VA_ARGS__
#define PX_EXPAND(...) DETAIL_PX_EXPAND(__VA_ARGS__)
#else

#define DETAIL_PX_EXPAND(...) __VA_ARGS__
#define DETAIL_PX_EXPAND_I(args) DETAIL_PX_EXPAND(DETAIL_PX_EXPAND args)
#define PX_EXPAND(...) DETAIL_PX_EXPAND_I((__VA_ARGS__))

#endif

#endif	/* EXPAND_H */


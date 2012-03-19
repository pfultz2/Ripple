/* 
 * File:   check.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 2:37 PM
 */

#ifndef CHECK_H
#define	CHECK_H

#define DETAIL_PX_CHECK_TAIL(x, n, ...) __VA_ARGS__
#define DETAIL_PX_CHECK_N(x, n, ...) n

#ifdef PX_CONFIG_STD
#define PX_CHECK(...) DETAIL_PX_CHECK_N(__VA_ARGS__, 0,)
#define PX_CHECK_TAIL(...) DETAIL_PX_CHECK_TAIL(__VA_ARGS__)

#else

#define DETAIL_PX_CHECK_RES(x) x
#define DETAIL_PX_CHECK_II(x) DETAIL_PX_CHECK_RES(DETAIL_PX_CHECK_N x)
#define DETAIL_PX_CHECK_I(x) DETAIL_PX_CHECK_II(x)
#define PX_CHECK(...) DETAIL_PX_CHECK_I((__VA_ARGS__, 0,~))

#define DETAIL_PX_CHECK_TAIL_RES(...) __VA_ARGS__
#define DETAIL_PX_CHECK_TAIL_I(args) DETAIL_PX_CHECK_TAIL_RES(DETAIL_PX_CHECK_TAIL args)
#define PX_CHECK_TAIL(...) DETAIL_PX_CHECK_TAIL_I((__VA_ARGS__))

#endif

#endif	/* CHECK_H */


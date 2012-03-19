/* 
 * File:   empty.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 12:31 PM
 */

#ifndef EMPTY_H
#define	EMPTY_H

#define PX_EMPTY(...)

#define DETAIL_PX_IS_EMPTY_PROBE(...) ~, 1,
#define DETAIL_PX_IS_EMPTY_EAT(...) 

//TODO: Add support for variadic args for EMPTY
#define DETAIL_PX_IS_EMPTY_P(x) PX_EXPAND(DETAIL_PX_IS_EMPTY_PROBE DETAIL_PX_IS_EMPTY_EAT x (~)(~))
#define DETAIL_PX_IS_EMPTY(x) PX_CHECK(DETAIL_PX_IS_EMPTY_P(x))

#ifdef PX_CONFIG_STD

#define PX_IS_EMPTY(x) DETAIL_PX_IS_EMPTY(x)

#else

#define DETAIL_PX_IS_EMPTY_I(x) DETAIL_PX_IS_EMPTY x
#define PX_IS_EMPTY(x) DETAIL_PX_IS_EMPTY_I((x))

#endif

#endif	/* EMPTY_H */


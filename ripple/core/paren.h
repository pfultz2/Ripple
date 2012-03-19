/* 
 * File:   is_paren.h
 * Author: paul
 *
 * Created on January 19, 2012, 12:43 AM
 */

#ifndef IS_PAREN_H
#define	IS_PAREN_H

#include "config.h"

#define PX_PAREN_EAT(...)

#define DETAIL_PX_IS_PAREN_PROBE(...) ~, 1,

#define DETAIL_PX_IS_PAREN(x, ...) PX_CHECK(DETAIL_PX_IS_PAREN_PROBE x)

#ifdef PX_CONFIG_STD

#define PX_IS_PAREN(...) DETAIL_PX_IS_PAREN(__VA_ARGS__, ~)

#else

#define DETAIL_PX_IS_PAREN_RES(x) x
#define DETAIL_PX_IS_PAREN_I(x) DETAIL_PX_IS_PAREN_RES(DETAIL_PX_IS_PAREN x)
#define PX_IS_PAREN(...) DETAIL_PX_IS_PAREN_I((__VA_ARGS__, ~))

#endif

#endif	/* IS_PAREN_H */


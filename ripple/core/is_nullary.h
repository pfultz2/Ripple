 /* 
 * File:   is_nullary.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 1:31 PM
 */

#ifndef IS_NULLARY_H
#define	IS_NULLARY_H

#define DETAIL_PX_IS_NULLARY_PROBE() ~, 1,

#define DETAIL_PX_IS_NULLARY(x, ...) PX_CHECK(DETAIL_PX_IS_NULLARY_PROBE x)

#ifdef PX_CONFIG_STD

#define PX_IS_NULLARY(...) DETAIL_PX_IS_NULLARY(__VA_ARGS__, ~)

#else

#define DETAIL_PX_IS_NULLARY_RES(x) x
#define DETAIL_PX_IS_NULLARY_I(x) DETAIL_PX_IS_NULLARY_RES(DETAIL_PX_IS_NULLARY x)
#define PX_IS_NULLARY(...) DETAIL_PX_IS_NULLARY_I((__VA_ARGS__, ~))

#endif

#endif	/* IS_NULLARY_H */


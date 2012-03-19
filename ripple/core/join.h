/* 
 * File:   join.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 12:34 PM
 */

#ifndef JOIN_H
#define	JOIN_H

#define DETAIL_PX_JOIN_00(x, y) PX_CAT(x, y)
#define DETAIL_PX_JOIN_00(x, y) x y
#define DETAIL_PX_JOIN_10(x, y) x y
#define DETAIL_PX_JOIN_11(x, y) x y
#define PX_JOIN(x, y) \
PX_CAT(DETAIL_PX_JOIN_, PX_CAT(PX_IS_PAREN(x), PX_IS_PAREN(y)))(x, y)

#endif	/* JOIN_H */


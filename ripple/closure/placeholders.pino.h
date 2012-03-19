/* 
 * File:   placeholders.h
 * Author: paul
 *
 * Created on January 19, 2012, 1:51 AM
 */

#ifndef PLACEHOLDERS_H
#define	PLACEHOLDERS_H

#include "config.h"


#define PX_BIND_IS_PLACEHOLDER(x) PX_CHECK(PX_JOIN(DETAIL_PX_BIND_PROBE_, x))

#define PX_BIND_PLACEHOLDER_ID(x) PX_FIRST(PX_JOIN(DETAIL_PX_BIND_PROBE_, x))

#define DETAIL_PX_BIND_REPLACE_MAKE_ARGS_I(...) (__VA_ARGS__,~)
#define DETAIL_PX_BIND_REPLACE_MAKE_ARGS(args) DETAIL_PX_BIND_REPLACE_MAKE_ARGS_I args
#define DETAIL_PX_BIND_REPLACE_I_0(p, args) p
#define DETAIL_PX_BIND_REPLACE_I_1(p, args) PX_CAT(DETAIL_PX_BIND_REPLACE_, PX_BIND_PLACEHOLDER_ID(p)) DETAIL_PX_BIND_REPLACE_MAKE_ARGS(args) 
#define DETAIL_PX_BIND_REPLACE(p, args) PX_CAT(DETAIL_PX_BIND_REPLACE_I_, PX_BIND_IS_PLACEHOLDER(p))(p, args)

#define DETAIL_PX_BIND_PLACE(args, ...)  PX_CAT(DETAIL_PX_PLACE_ARGS_, PX_NARGS(__VA_ARGS__))(__VA_ARGS__)

//DETAIL_PX_PLACE_ARGS_(args, placeholders...)
$for x in range(64)
{
#define DETAIL_PX_PLACE_ARGS_$(x)(args, $for y in range(x+1) { p$(y), } ...) ($for y in range(x+1) { DETAIL_PX_BIND_REPLACE(p$(y), args) $if y is not x {,} })
}

$for x in range(8)
{
#define DETAIL_PX_BIND_PROBE_$(x) $(x), 1, 
#define DETAIL_PX_BIND_REPLACE_$(x)($for y in range(x+1) { x$(y), } ...) x$(x)
}

#endif	/* PLACEHOLDERS_H */


#include <ripple/ripple.h>

//RPP_CAT
#define MACRO() MACRO_
#define MACRO_CAT() CAT_SUCCESS
RPP_CAT(MACRO(), CAT)() // CAT_SUCCESS
#undef MACRO
#undef MACRO_CAT

//RPP_IIF
RPP_IIF(0)(FAIL, SUCCESS) // SUCCESS
RPP_IIF(1)(SUCCESS, FAIL) // SUCCESS

//RPP_MACRO_INVOKE
#define MACRO(x) x
RPP_INVOKER(MACRO) //INVOKER
RPP_MACRO_INVOKE(MACRO, SUCCESS) //SUCCESS
RPP_INVOKE(MACRO, SUCCESS) //SUCCESS
DETAIL_RPP_MACRO_INVOKE_STATE()  // 1
#undef MACRO

//RPP_FOR
#define PRED(s, x) RPP_BOOL(x)
#define OP(s, x) RPP_DEC(x)
#define MACRO(s, x) { x }
RPP_EXPR(RPP_FOR(PRED, OP, MACRO, 15)) // { 15 } { 14 } { 13 } { 12 } { 11 } { 10 } { 9 } { 8 } { 7 } { 6 } { 5 } { 4 } { 3 } { 2 } { 1 }
#undef PRED
#undef OP
#undef MACRO


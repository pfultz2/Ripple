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

//RPP_INVOKER
#define MACRO(x) x
RPP_INVOKER(MACRO)
#undef MACRO 

//RPP_MACRO_INVOKE
#define MACRO(x) x
RPP_EXPR(RPP_INVOKER(MACRO)()(1, MACRO, SUCCESS)) //SUCCESS
RPP_EXPR(RPP_MACRO_INVOKE()(1, MACRO, SUCCESS)) //SUCCESS
RPP_EXPR(RPP_INVOKE(MACRO, SUCCESS)) //SUCCESS
#undef MACRO


//RPP_BIND_DATA
RPP_EXPR(RPP_INVOKER(RPP_BIND_DATA(RPP_PRIMITIVE_CAT, CESS))()(1, RPP_BIND_DATA(RPP_PRIMITIVE_CAT, CESS), SUC))// SUCCESS
RPP_EXPR(RPP_BIND_DATA_INVOKE()(1, RPP_BIND_DATA(RPP_PRIMITIVE_CAT, CESS), SUC))// SUCCESS
RPP_EXPR(RPP_INVOKE(RPP_BIND_DATA(RPP_PRIMITIVE_CAT, CESS), SUC))// SUCCESS


//RPP_DELINIEATE
#define MACRO(s, n, var) var ## n
#define COUNT(s, n) n
RPP_EXPR(RPP_DELINEATE(3, RPP_COMMA, COUNT)) // 0, 1, 2
RPP_EXPR(RPP_DELINEATE(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x))) // x0 x1 x2
RPP_EXPR(RPP_DELINEATE(3, RPP_COMMA,RPP_BIND_DATA(MACRO, y))) // y0, y1, y2
RPP_EXPR(RPP_DELINEATE(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, x))) // z0 + z1 + z2
#undef MACRO

//RPP_DELINEATE_FROM_TO
#define MACRO(s, n) n
RPP_EXPR(RPP_DELINEATE_FROM_TO(5, 10, RPP_IDENTITY(+), MACRO)) // 5 + 6 + 7 + 8 + 9
#undef MACRO

//RPP_DELINEATE_PARAMS
RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T) // class T0, class T1, class T2
RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T, = U) // class T0 = U0, class T1 = U1, class T2 = U2
RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T, = void RPP_INTERCEPT) // class T0 = void, class T1 = void, class T2 = void

//RPP_DELINEATE_SHIFTED
#define MACRO(s, n, var) var ## n
RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x))) // x1 x2
RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_COMMA, RPP_BIND_DATA(MACRO, y))) // y1, y2
RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, z))) // z1 + z2
#undef MACRO

// //RPP_DELINEATE_SHIFTED_PARAMS
// RPP_DELINEATE_SHIFTED_PARAMS(3, RPP_COMMA, class T) // class T1, class T2
// RPP_DELINEATE_SHIFTED_PARAMS(3, RPP_COMMA, class T, = U) // class T1 = U1, class T2 = U2
// RPP_DELINEATE_SHIFTED_PARAMS(3, RPP_COMMA, class T, = void RPP_INTERCEPT)// class T1 = void, class T2 = void

//RPP_ENUM
#define FIXED(s, n) class
#define TTP(s, n) \
    template< \
        RPP_EXPR_S(s)(RPP_ENUM_S( \
            s, RPP_INC(n), FIXED \
        )) \
    > class T ## n \
    /**/
RPP_EXPR(RPP_ENUM(3, TTP))
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// template<class> class T0,
// template<class, class> class T1,
// template<class, class, class> class T2
#undef FIXED
#undef TTP

#define FIXED(s, n, text) text
#define TTP(s, n, id) \
    template< \
        RPP_EXPR_S(s)(RPP_ENUM_S( \
            s, RPP_INC(n), RPP_BIND_DATA(FIXED, class) \
        )) \
    > class id ## n \
    /**/
RPP_EXPR(RPP_ENUM(3, RPP_BIND_DATA(TTP, T)))
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// template<class> class T0,
// template<class, class> class T1,
// template<class, class, class> class T2
#undef FIXED
#undef TTP

// //RPP_FOR
// #define PRED(s, x) RPP_BOOL(x)
// #define OP(s, x) RPP_DEC(x)
// #define MACRO(s, x) { x }
// RPP_EXPR(RPP_FOR(PRED, OP, MACRO, 10)) // { 10 } { 9 } { 8 } { 7 } { 6 } { 5 } { 4 } { 3 } { 2 } { 1 } 
// #undef PRED
// #undef OP
// #undef MACRO


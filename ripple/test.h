#include <ripple/ripple.h>

//RPP_CAT
#define MACRO() MACRO_
#define MACRO_CAT() CAT_SUCCESS
RPP_CAT(MACRO(), CAT)() // CAT_SUCCESS
#undef MACRO
#undef MACRO_CAT

//RPP_IS_1
RPP_IS_1(1) //1
RPP_IS_1(0) //0

//RPP_IS_PAREN
RPP_IS_PAREN(()) //1
RPP_IS_PAREN((RPP_IS_PAREN)) //1
RPP_IS_PAREN(~) //0

//RPP_IIF
RPP_IIF(0)(FAIL, SUCCESS) // SUCCESS
RPP_IIF(1)(SUCCESS, FAIL) // SUCCESS

//RPP_IF
RPP_IF(0)(FAIL, SUCCESS) // SUCCESS
RPP_IF(SUCCESS)(SUCCESS, FAIL) // SUCCESS


//RPP_NOT_EQUAL
RPP_IF(RPP_NOT_EQUAL(1,1))(FAIL, SUCCESS) // SUCCESS
RPP_IF(RPP_PRIMITIVE_COMPARE(1,1))(TRUE, FALSE) // FALSE
RPP_IF(RPP_PRIMITIVE_COMPARE(0,1))(TRUE, FALSE) // TRUE

//RPP_EQUAL
RPP_IF(RPP_EQUAL(0,1))(FAIL, SUCCESS) // SUCCESS
RPP_IF(RPP_EQUAL(1,xxx))(FAIL, SUCCESS) // SUCCESS
RPP_IF(RPP_EQUAL(xxx,xxx))(FAIL, SUCCESS) // SUCCESS
RPP_IF(RPP_EQUAL(1,1))(SUCCESS, FAIL) // SUCCESS

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

//RPP_INC
RPP_INC(1) //2

//RPP_DEC
RPP_DEC(3) //2


//RPP_DELINIEATE
#define MACRO(s, n, var) var ## n
#define COUNT(s, n) n
RPP_EXPR_S(0)(DETAIL_RPP_DELINEATE_U(0, 3, RPP_COMMA, COUNT, RPP_MACRO_INVOKE)) // 0, 1, 2
RPP_EXPR(DETAIL_RPP_DELINEATE_U(RPP_STATE(), 3, RPP_COMMA, COUNT, RPP_INVOKER(COUNT))) // 0, 1, 2
RPP_EXPR(RPP_DELINEATE(3, RPP_COMMA, COUNT)) // 0, 1, 2
RPP_EXPR(RPP_DELINEATE(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x))) // x0 x1 x2
RPP_EXPR(RPP_DELINEATE(3, RPP_COMMA,RPP_BIND_DATA(MACRO, y))) // y0, y1, y2
RPP_EXPR(RPP_DELINEATE(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, x))) // z0 + z1 + z2
#undef MACRO

//RPP_DELINEATE_FROM_TO
#define MACRO(s, n) n
RPP_EXPR(RPP_DELINEATE_FROM_TO(5, 10, RPP_IDENTITY(+), MACRO)) // 5 + 6 + 7 + 8 + 9
#undef MACRO

// //RPP_DELINEATE_PARAMS
// RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T) // class T0, class T1, class T2
// RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T, = U) // class T0 = U0, class T1 = U1, class T2 = U2
// RPP_DELINEATE_PARAMS(3, RPP_COMMA, class T, = void RPP_INTERCEPT) // class T0 = void, class T1 = void, class T2 = void

// //RPP_DELINEATE_SHIFTED
// #define MACRO(s, n, var) var ## n
// RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x))) // x1 x2
// RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_COMMA, RPP_BIND_DATA(MACRO, y))) // y1, y2
// RPP_EXPR(RPP_DELINEATE_SHIFTED(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, z))) // z1 + z2
// #undef MACRO

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

//RPP_FOR
#define PRED(s, x) RPP_BOOL(x)
#define OP(s, x) RPP_DEC(x)
#define MACRO(s, x) { x }
RPP_EXPR(RPP_FOR(PRED, OP, MACRO, 10)) // { 10 } { 9 } { 8 } { 7 } { 6 } { 5 } { 4 } { 3 } { 2 } { 1 } 
#undef PRED
#undef OP
#undef MACRO

//RPP_REPEAT
#define MACRO(s, n, id) RPP_COMMA_IF(n) class id ## n
RPP_EXPR(RPP_REPEAT(3, RPP_BIND_DATA(MACRO, T))) // class T0, class T1, class T2
#undef MACRO

//RPP_WHILE
#define PRED(s, state) RPP_BOOL(state)
#define OP(s, state) RPP_DEC(state)
RPP_EXPR(RPP_WHILE(PRED, OP, 100)) // 0
#undef PRED
#undef OP

// //auto
// //RPP_AUTO_DELINEATE
// #define MACRO(s, n, var) var ## n
// #define COUNT(s, n) n
// RPP_AUTO_DELINEATE(3, RPP_COMMA, COUNT) // 0, 1, 2
// RPP_AUTO_DELINEATE(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x)) // x0 x1 x2
// RPP_AUTO_DELINEATE(3, RPP_COMMA,RPP_BIND_DATA(MACRO, y)) // y0, y1, y2
// RPP_AUTO_DELINEATE(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, x)) // z0 + z1 + z2
// #undef MACRO

// //RPP_AUTO_DELINEATE_FROM_TO
// #define MACRO(s, n) n
// RPP_AUTO_DELINEATE_FROM_TO(5, 10, RPP_IDENTITY(+), MACRO) // 5 + 6 + 7 + 8 + 9
// #undef MACRO

// //RPP_AUTO_DELINEATE_SHIFTED
// #define MACRO(s, n, var) var ## n
// RPP_AUTO_DELINEATE_SHIFTED(3, RPP_EMPTY, RPP_BIND_DATA(MACRO, x)) // x1 x2
// RPP_AUTO_DELINEATE_SHIFTED(3, RPP_COMMA, RPP_BIND_DATA(MACRO, y)) // y1, y2
// RPP_AUTO_DELINEATE_SHIFTED(3, RPP_IDENTITY(+), RPP_BIND_DATA(MACRO, z)) // z1 + z2
// #undef MACRO

// //RPP_AUTO_ENUM
// #define FIXED(s, n, text) text
// #define TTP(s, n, id) \
//     template< \
//         RPP_EXPR_S(s)(RPP_ENUM_S( \
//             s, RPP_INC(n), RPP_BIND_DATA(FIXED, class) \
//         )) \
//     > class id ## n \
//     /**/
// RPP_AUTO_ENUM(3, RPP_BIND_DATA(TTP, T))
// // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// // template<class> class T0,
// // template<class, class> class T1,
// // template<class, class, class> class T2
// #undef FIXED
// #undef TTP


// #define FIXED(s, n, text) text
// #define TTP(s, n, id) \
//     template \
//     < \
//         RPP_AUTO_ENUM(RPP_INC(n), RPP_BIND_DATA(FIXED, class)) \
//     > class id ## n \
//     /**/
// RPP_AUTO_ENUM(3, RPP_BIND_DATA(TTP, T))
// // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// // template<class> class T0,
// // template<class, class> class T1,
// // template<class, class, class> class T2
// #undef FIXED
// #undef TTP

// //RPP_AUTO_FOR
// #define PRED(s, x) RPP_BOOL(x)
// #define OP(s, x) RPP_DEC(x)
// #define MACRO(s, x) { x }
// RPP_AUTO_FOR(PRED, OP, MACRO, 10) // { 10 } { 9 } { 8 } { 7 } { 6 } { 5 } { 4 } { 3 } { 2 } { 1 } 
// #undef PRED
// #undef OP
// #undef MACRO

// //RPP_REPEAT
// #define MACRO(s, n, id) RPP_COMMA_IF(n) class id ## n
// RPP_AUTO_REPEAT(3, RPP_BIND_DATA(MACRO, T)) // class T0, class T1, class T2
// #undef MACRO

/**
  * RPP_TUPLE
  */

//RPP_TUPLE_NIL RPP_TUPLE_CONS
RPP_TUPLE_NIL()                         //
RPP_TUPLE_CONS(RPP_TUPLE_NIL(), a) // (a)
RPP_TUPLE_CONS(, a)                     // (a)
RPP_TUPLE_CONS((), a)                   // (a, )

//RPP_TUPLE_HEAD
#define DATA() (a, b, c)
RPP_TUPLE_HEAD(DATA()) // a
#undef DATA

//RPP_TUPLE_TAIL
#define DATA() (a, b, c)
RPP_TUPLE_TAIL(DATA()) // (b, c)
RPP_TUPLE_TAIL((a)) //
#undef DATA

//RPP_TUPLE_IS_CONS
RPP_TUPLE_IS_CONS()                     // 0
RPP_TUPLE_IS_CONS(RPP_TUPLE_NIL()) // 0
RPP_TUPLE_IS_CONS(())            // 1
RPP_TUPLE_IS_CONS((x, y, z))            // 1

//RPP_TUPLE_IS_NIL
RPP_TUPLE_IS_NIL()                     // 1
RPP_TUPLE_IS_NIL(RPP_TUPLE_NIL()) // 1
RPP_TUPLE_IS_NIL((x, y, z))            // 0

//RPP_TUPLE_SIZE
RPP_TUPLE_SIZE((a, b, c))       // 3
RPP_TUPLE_SIZE((a, b, c, d, e)) // 5

// //RPP_TUPLE_AS_ARGS
// #define APPLY(prefix, tuple) \
//     RPP_CAT(prefix, RPP_TUPLE_QUICK_SIZE(tuple)) \
//     RPP_TUPLE_AS_ARGS(tuple) \
//     /**/
// #define MACRO_0()
// #define MACRO_1(a) a
// #define MACRO_2(a, b) a * b
// #define MACRO_3(a, b, c) a * b * c
// #define MACRO(args) RPP_EXPR(APPLY(MACRO_, args))
// MACRO()       //
// MACRO((1))    // 1
// MACRO((1, 2)) // 1 * 2
// #undef MACRO_0
// #undef MACRO_1
// #undef MACRO_2
// #undef MACRO_3
// #undef MACRO




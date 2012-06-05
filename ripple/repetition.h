/* ********************************************************************
 *                                                                    *
 *    (C) Copyright Paul Fultz II 2012.                               *
 *                                                                    *
 *    Distributed under the Boost Software License, Version 1.0.      *
 *    (See accompanying file LICENSE).                                *
 *                                                                    *
 *    See http://github.com/pfultz2/Ripple for most recent version.   *
 *                                                                    *
 ******************************************************************** */

#ifndef RIPPLE_PREPROCESSOR_REPETITION_H
#define RIPPLE_PREPROCESSOR_REPETITION_H
#include <ripple/config.h>
#include <ripple/basic.h>
#include <ripple/recursion.h>
#include <ripple/compare.h>


// #define REPEAT_S(s, n, m, ...) \
//         REPEAT_I(OBSTRUCT(), INC(s), DEC(n), m, __VA_ARGS__)
// //This is the implementation
// #define REPEAT_INDIRECT() REPEAT_S
// #define REPEAT_I(_, s, n, m, ...) \
//         WHEN _(n) \
//         ( \
//             EXPR_S _(s)(REPEAT_INDIRECT _()(s, n, m, __VA_ARGS__) ) \
//         ) \
//         m _(s, n, __VA_ARGS__)

#define RPP_DELINEATE(n, sep, m) RPP_DELINEATE_S(RPP_STATE(), n, sep, m)
#define RPP_DELINEATE_S(s, n, sep, m) DETAIL_RPP_DELINEATE_U(s, n, sep, m, RPP_INVOKER(m))

#define DETAIL_RPP_DELINEATE_U(s, n, sep, m, _m) DETAIL_RPP_DELINEATE_I(RPP_OBSTRUCT(), RPP_INC(s), RPP_DEC(n), sep, m, _m)
#define DETAIL_RPP_DELINEATE_INDIRECT() DETAIL_RPP_DELINEATE_U
#define DETAIL_RPP_DELINEATE_I(_, s, n, sep, m, _m) \
        RPP_WHEN _(n) \
        ( \
            RPP_EXPR_S _(s)(DETAIL_RPP_DELINEATE_INDIRECT _()(s, n, sep, m, _m) sep _()) \
        ) \
        _m()(s, m, s, n)



#define RPP_DELINEATE_FROM_TO(from, to, sep, m) RPP_DELINEATE_FROM_TO_S(RPP_STATE(), from, to, sep, m)
#define RPP_DELINEATE_FROM_TO_S(s, from, to, sep, m) DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, m, RPP_INVOKER(m))

#define DETAIL_RPP_DELINEATE_FROM_TO_U(s, from, to, sep, m, _m) DETAIL_RPP_DELINEATE_FROM_TO_I(RPP_OBSTRUCT(), RPP_INC(s), from, RPP_DEC(to), sep, m, _m)
#define DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT() DETAIL_RPP_DELINEATE_FROM_TO_U
#define DETAIL_RPP_DELINEATE_FROM_TO_I(_, s, from, to, sep, m, _m) \
        RPP_WHEN _(RPP_NOT_EQUAL(from, to)) \
        ( \
            RPP_EXPR_S _(s)(DETAIL_RPP_DELINEATE_FROM_TO_INDIRECT _()(s, from, to, sep, m, _m) sep _()) \
        ) \
        _m()(s, m, s, to)

#define RPP_ENUM(n, m) RPP_ENUM_S(RPP_STATE(), n, m)
#define RPP_ENUM_S(s, n, m) RPP_DELINEATE_S(s, n, RPP_COMMA, m)

#define RPP_ENUM_FROM_TO(from, to, m) RPP_ENUM_FROM_TO_S(RPP_STATE(), from, to, m)
#define RPP_ENUM_FROM_TO_S(s, from, to, m) RPP_DELINEATE_FROM_TO_S(s, from, to, RPP_COMMA, m)

#define RPP_REPEAT(n, m) RPP_REPEAT_S(RPP_STATE(), n, m)
#define RPP_REPEAT_S(s, n, m) RPP_DELINEATE_S(s, n, RPP_EMPTY, m)

#define RPP_REPEAT_FROM_TO(from, to, m) RPP_REPEAT_FROM_TO_S(RPP_STATE(), from, to, m)
#define RPP_REPEAT_FROM_TO_S(s, from, to, m) RPP_DELINEATE_FROM_TO_S(s, from, to, RPP_EMPTY, m)


#define RPP_FOR(pred, op, macro, ...) RPP_FOR_S(RPP_STATE(), pred, op, macro, __VA_ARGS__)
#define RPP_FOR_S(s, pred, op, macro, ...) \
        RPP_FOR_I(RPP_OBSTRUCT(), RPP_INC(s), pred, RPP_INVOKER(pred), op, RPP_INVOKER(op), macro, RPP_INVOKER(macro), __VA_ARGS__) \

#define RPP_FOR_INDIRECT() RPP_FOR_I
#define RPP_FOR_I(_, s, pred, _p, op, _o, macro, _m, ...) \
        RPP_WHEN _(_p()(s, pred, s, __VA_ARGS__)) \
        ( \
            _m()(s, macro, s, __VA_ARGS__) \
            RPP_EXPR_S(s) _\
            ( \
                RPP_FOR_INDIRECT _()(RPP_OBSTRUCT _(), RPP_INC(s), pred, _p, op, _o, macro, _m, _o()(s, op, s, __VA_ARGS__) )\
            ) \
        )

#define RPP_WHILE(pred, op, ...) RPP_WHILE_S(RPP_STATE(), pred, op, __VA_ARGS__)
#define RPP_WHILE_S(s, pred, op, ...) \
        RPP_WHILE_I(RPP_OBSTRUCT(), RPP_INC(s), pred, RPP_INVOKER(pred), op, RPP_INVOKER(op), __VA_ARGS__) \

#define RPP_WHILE_INDIRECT() RPP_WHILE_I
#define RPP_WHILE_I(_, s, pred, _p, op, _o, ...) \
        RPP_IF _(_p()(s, pred, s, __VA_ARGS__)) \
        ( \
            RPP_EXPR_S(s) _\
            ( \
                RPP_WHILE_INDIRECT _()(RPP_OBSTRUCT _(), RPP_INC(s), pred, _p, op, _o, _o()(s, op, s, __VA_ARGS__) )\
            ), \
            __VA_ARGS__ \
        )







#endif
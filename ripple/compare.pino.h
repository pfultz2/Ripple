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

#ifndef RIPPLE_PREPROCESSOR_COMPARE_H
#define RIPPLE_PREPROCESSOR_COMPARE_H
#include <ripple/config.h>
#include <ripple/detection.h>
#include <ripple/logic.h>

#define RPP_IS_COMPARABLE(x) RPP_PRIMITIVE_IS_COMPARABLE(x)

#define RPP_PRIMITIVE_IS_COMPARABLE(x) RPP_IS_PAREN( RPP_COMPARE_ ## x (()) )

#define RPP_PRIMITIVE_COMPARE(x, y) RPP_IS_PAREN \
 ( \
    RPP_COMPARE_ ## x ( RPP_COMPARE_ ## y (()) ) \
 )

#define RPP_NOT_EQUAL(x, y)  \
 RPP_IIF(RPP_BITAND( RPP_PRIMITIVE_IS_COMPARABLE(x), RPP_PRIMITIVE_IS_COMPARABLE(y) )) \
 (\
    RPP_PRIMITIVE_COMPARE(x, y), \
    1 \
 )

#define RPP_EQUAL(x, y) RPP_COMPL(RPP_NOT_EQUAL(x, y))

#define RPP_COMPARE__(x) x

#define RPP_COMPARE_a(x) x
#define RPP_COMPARE_b(x) x
#define RPP_COMPARE_c(x) x
#define RPP_COMPARE_d(x) x
#define RPP_COMPARE_e(x) x
#define RPP_COMPARE_f(x) x
#define RPP_COMPARE_g(x) x
#define RPP_COMPARE_h(x) x
#define RPP_COMPARE_i(x) x
#define RPP_COMPARE_j(x) x
#define RPP_COMPARE_k(x) x
#define RPP_COMPARE_l(x) x
#define RPP_COMPARE_m(x) x
#define RPP_COMPARE_n(x) x
#define RPP_COMPARE_o(x) x
#define RPP_COMPARE_p(x) x
#define RPP_COMPARE_q(x) x
#define RPP_COMPARE_r(x) x
#define RPP_COMPARE_s(x) x
#define RPP_COMPARE_t(x) x
#define RPP_COMPARE_u(x) x
#define RPP_COMPARE_v(x) x
#define RPP_COMPARE_w(x) x
#define RPP_COMPARE_x(x) x
#define RPP_COMPARE_y(x) x
#define RPP_COMPARE_z(x) x

#define RPP_COMPARE_A(x) x
#define RPP_COMPARE_B(x) x
#define RPP_COMPARE_C(x) x
#define RPP_COMPARE_D(x) x
#define RPP_COMPARE_E(x) x
#define RPP_COMPARE_F(x) x
#define RPP_COMPARE_G(x) x
#define RPP_COMPARE_H(x) x
#define RPP_COMPARE_I(x) x
#define RPP_COMPARE_J(x) x
#define RPP_COMPARE_K(x) x
#define RPP_COMPARE_L(x) x
#define RPP_COMPARE_M(x) x
#define RPP_COMPARE_N(x) x
#define RPP_COMPARE_O(x) x
#define RPP_COMPARE_P(x) x
#define RPP_COMPARE_Q(x) x
#define RPP_COMPARE_R(x) x
#define RPP_COMPARE_S(x) x
#define RPP_COMPARE_T(x) x
#define RPP_COMPARE_U(x) x
#define RPP_COMPARE_V(x) x
#define RPP_COMPARE_W(x) x
#define RPP_COMPARE_X(x) x
#define RPP_COMPARE_Y(x) x
#define RPP_COMPARE_Z(x) x

#define RPP_COMPARE_asm(x) x
#define RPP_COMPARE_and(x) x
#define RPP_COMPARE_and_eq(x) x
#define RPP_COMPARE_auto(x) x
#define RPP_COMPARE_bitand(x) x
#define RPP_COMPARE_bitor(x) x
#define RPP_COMPARE_bool(x) x
#define RPP_COMPARE_break(x) x
#define RPP_COMPARE_case(x) x
#define RPP_COMPARE_catch(x) x
#define RPP_COMPARE_char(x) x
#define RPP_COMPARE_class(x) x
#define RPP_COMPARE_compl(x) x
#define RPP_COMPARE_const(x) x
#define RPP_COMPARE_const_cast(x) x
#define RPP_COMPARE_continue(x) x
#define RPP_COMPARE_default(x) x
#define RPP_COMPARE_define(x) x
#define RPP_COMPARE_defined(x) x
#define RPP_COMPARE_delete(x) x
#define RPP_COMPARE_do(x) x
#define RPP_COMPARE_double(x) x
#define RPP_COMPARE_dynamic_cast(x) x
#define RPP_COMPARE_else(x) x
#define RPP_COMPARE_elif(x) x
#define RPP_COMPARE_endif(x) x
#define RPP_COMPARE_enum(x) x
#define RPP_COMPARE_error(x) x
#define RPP_COMPARE_explicit(x) x
#define RPP_COMPARE_export(x) x
#define RPP_COMPARE_extern(x) x
#define RPP_COMPARE_false(x) x
#define RPP_COMPARE_float(x) x
#define RPP_COMPARE_for(x) x
#define RPP_COMPARE_friend(x) x
#define RPP_COMPARE_goto(x) x
#define RPP_COMPARE_if(x) x
#define RPP_COMPARE_ifdef(x) x
#define RPP_COMPARE_ifndef(x) x
#define RPP_COMPARE_include(x) x
#define RPP_COMPARE_inline(x) x
#define RPP_COMPARE_int(x) x
#define RPP_COMPARE_line(x) x
#define RPP_COMPARE_long(x) x
#define RPP_COMPARE_mutable(x) x
#define RPP_COMPARE_namespace(x) x
#define RPP_COMPARE_new(x) x
#define RPP_COMPARE_not(x) x
#define RPP_COMPARE_not_eq(x) x
#define RPP_COMPARE_operator(x) x
#define RPP_COMPARE_or(x) x
#define RPP_COMPARE_or_eq(x) x
#define RPP_COMPARE_pragma(x) x
#define RPP_COMPARE_private(x) x
#define RPP_COMPARE_protected(x) x
#define RPP_COMPARE_public(x) x
#define RPP_COMPARE_register(x) x
#define RPP_COMPARE_reinterpret_cast(x) x
#define RPP_COMPARE_restrict(x) x
#define RPP_COMPARE_return(x) x
#define RPP_COMPARE_short(x) x
#define RPP_COMPARE_signed(x) x
#define RPP_COMPARE_sizeof(x) x
#define RPP_COMPARE_static(x) x
#define RPP_COMPARE_static_cast(x) x
#define RPP_COMPARE_struct(x) x
#define RPP_COMPARE_switch(x) x
#define RPP_COMPARE_template(x) x
#define RPP_COMPARE_this(x) x
#define RPP_COMPARE_throw(x) x
#define RPP_COMPARE_true(x) x
#define RPP_COMPARE_try(x) x
#define RPP_COMPARE_typedef(x) x
#define RPP_COMPARE_typeid(x) x
#define RPP_COMPARE_typename(x) x
#define RPP_COMPARE_undef(x) x
#define RPP_COMPARE_union(x) x
#define RPP_COMPARE_unsigned(x) x
#define RPP_COMPARE_using(x) x
#define RPP_COMPARE_virtual(x) x
#define RPP_COMPARE_void(x) x
#define RPP_COMPARE_volatile(x) x
#define RPP_COMPARE_wchar_t(x) x
#define RPP_COMPARE_while(x) x
#define RPP_COMPARE_xor(x) x
#define RPP_COMPARE_xor_eq(x) x

$for i in range(65537)
{
#define RPP_COMPARE_$(i)(x) x
}


#endif
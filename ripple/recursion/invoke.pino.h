

#ifndef RIPPLE_GUARD_REC_INVOKE_H
#define RIPPLE_GUARD_REC_INVOKE_H

#define DETAIL_PX_REC_INVOKE_X(x) x, 1,
#define DETAIL_PX_REC_INVOKE_P(n) PX_CHECK(PX_REC_INVOKE_ ## n(DETAIL_PX_REC_INVOKE_X, PX_NIL))

#define PX_REC_INVOKE_S(s) PX_CAT(PX_REC_INVOKE_, s)

#define PX_REC_INVOKE PX_REC_INVOKE_S(PX_REC_STATE())

// #define PX_REC_INVOKE_INDIRECT(s, m) PX_CAT(PX_REC_INVOKE_INDIRECT_, m)
// #define PX_REC_INVOKE_INDIRECT_macro_(...) PX_REC_INVOKE(m, (__VA_ARGS__))
//
$for recursion_max in [1024]
{
#define PX_REC_STATE() PX_BINARY_SEARCH(DETAIL_PX_REC_INVOKE_P, $(recursion_max))
//
$for x in range(1, recursion_max+1)
{
#define PX_REC_INVOKE_$(x)(m, args) m ## $(x) args
}
}

#endif
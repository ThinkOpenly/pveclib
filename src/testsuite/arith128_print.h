/*
 Copyright [2017] IBM Corporation.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 arith128_print.h

 Contributors:
      IBM Corporation, Steven Munroe
      Created on: May 10, 2015
 */

#ifndef ARITH128_PRINT_H_
#define ARITH128_PRINT_H_

#include "arith128.h"
#include "vec_f128_ppc.h"

extern long tcount;

extern void
print_dfp128 (char *prefix, _Decimal128 val128);

extern void
print_dfp128e (char *prefix, _Decimal128 val128);

extern int
check_dfp128 (char *prefix, _Decimal128 val128, _Decimal128 shouldbe);

extern void
print_dfp64 (char *prefix, _Decimal64 val64);

extern int
check_dfp64 (char *prefix, _Decimal64 val64, _Decimal64 shouldbe);

extern void
print_dfp32 (char *prefix, _Decimal32 val32);

extern int
check_dfp32 (char *prefix, _Decimal32 val32, _Decimal32 shouldbe);

extern void
print_ibm128 (char *prefix, long double ldbl);

extern void
print_ibm128x (char *prefix, long double ldbl);

extern void
print_uint128 (char *prefix, unsigned __int128 val128);

extern int
check_sdiv128_64 (__int128 numerator, int64_t divisor, int64_t exp_q,
                  int64_t exp_r);

extern int
check_sdiv128_64x (__int128 numerator, int64_t divisor, int64_t exp_q,
                   int64_t exp_r);

extern int
check_udiv128_64 (unsigned __int128 numerator, uint64_t divisor, uint64_t exp_q,
                  uint64_t exp_r);

extern void
print_int128 (char *prefix, __int128 val128);

extern void
print_int128x (char *prefix, unsigned __int128 val128);

extern void
print_int64 (char *prefix, long val64);

extern void
print_uint64 (char *prefix, unsigned long val64);

extern void
print_int64x (char *prefix, unsigned long val64);

extern void
print_v2int64 (char *prefix, vui64_t val128);

extern void
print_v2xint64 (char *prefix, vui64_t val128);

extern int
check_udiv128_64x (unsigned __int128 numerator, uint64_t divisor,
                   uint64_t exp_q, uint64_t exp_r);

extern void
print_int128_sum (char *prefix, unsigned __int128 r, unsigned __int128 a,
                  unsigned __int128 b);

extern void
print_int128_carry (char *prefix, unsigned __int128 r, unsigned __int128 a,
                    unsigned __int128 b, unsigned __int128 c);

extern void
print_vint128 (char *prefix, vui128_t val);

extern void
print_vint128x (char *prefix, vui128_t val);

extern void
print_vfloat128x (char *prefix, __float128 val128);

extern void
print_vint256 (char *prefix, vui128_t val0, vui128_t val1);

extern void
print_vint384 (char *prefix, vui128_t val0, vui128_t val1, vui128_t val2);

extern void
print_vint128_sum (char *prefix, vui32_t r, vui32_t a, vui32_t b);

extern void
print_vint128x_sum (char *prefix, vui32_t r, vui32_t a, vui32_t b);

extern void
print_vint128_carry (char *prefix, vui32_t r, vui32_t a, vui32_t b, vui32_t c);

extern void
print_vint128x_carry (char *prefix, vui32_t r, vui32_t a, vui32_t b, vui32_t c);

extern void
print_vint128_prod (char *prefix, vui32_t r, vui32_t a, vui32_t b, vui32_t c);

extern void
print_vint128_extend (char *prefix, vui32_t r, vui32_t co, vui32_t a, vui32_t b,
                      vui32_t c);

extern void
print_vint128x_extend (char *prefix, vui32_t r, vui32_t co, vui32_t a,
                       vui32_t b, vui32_t c);

extern void
print_vint8 (char *prefix, vui8_t val);

extern void
print_vchar (char *prefix, vui8_t val);

extern void
print_vbool8 (char *prefix, vui8_t val);

extern int
check_isf128_priv (char *prefix, __float128 val128, int val, int shouldbe);

static inline int
check_isf128 (char *prefix, __float128 val128, int val, int shouldbe)
{
  int rc = 0;
  if (__builtin_expect ((val != shouldbe), 0))
    {
      rc = check_isf128_priv (prefix, val128, val, shouldbe);
    }

  return (rc);
}

extern int
check_f128bool_priv (char *prefix, __float128 val128, __f128_bool boolis,
                     __f128_bool shouldbe);

static inline int
check_f128bool (char *prefix, __float128 val128, __f128_bool boolis,
                __f128_bool shouldbe)
{
  int rc = 0;
  if (!vec_all_eq(boolis, shouldbe))
    {
      rc = check_f128bool_priv (prefix, val128, boolis, shouldbe);
    }

  return (rc);
}

static inline int
check_f128 (char *prefix, __float128 val128, __float128 f128is,
            __float128 shouldbe)
{
  VF_128 xfer;
  __f128_bool boolis, boolshould;
  int rc = 0;

  xfer.vf1 = f128is;
  boolis = xfer.vbool1;
  xfer.vf1 = shouldbe;
  boolshould = xfer.vbool1;

  if (!vec_all_eq(boolis, boolshould))
    {
      rc = check_f128bool_priv (prefix, val128, boolis, boolshould);
    }

  return (rc);
}

extern int
check_uint128_priv (char *prefix, unsigned __int128 val128,
                    unsigned __int128 shouldbe);

extern int
check_int128_priv (char *prefix, __int128 val128, __int128 shouldbe);

extern int
check_vuint128_priv (char *prefix, vui128_t val128, vui128_t shouldbe);

extern int
check_vuint128x_priv (char *prefix, vui128_t val128, vui128_t shouldbe);

extern int
check_vuint128c_priv (char *prefix, vui128_t val128, vui128_t carry128,
                      vui128_t shouldbe, vui128_t shouldcarry);

extern int
check_vint256_priv (char *prefix, vui128_t val0_128, vui128_t val1_128,
                    vui128_t sb0_128, vui128_t sb1_128);

extern int
check_vint384_priv (char *prefix, vui128_t val0_128, vui128_t val1_128,
                    vui128_t val2_128, vui128_t sb0_128, vui128_t sb1_128,
                    vui128_t sb2_128);

static inline int
check_vint384 (char *prefix, vui128_t val0_128, vui128_t val1_128,
               vui128_t val2_128, vui128_t sb0_128, vui128_t sb1_128,
               vui128_t sb2_128)
{
  int rc = 0;
  if (vec_any_ne(
      (vui32_t )val0_128,
      (vui32_t )sb0_128) || vec_any_ne ((vui32_t)val1_128, (vui32_t)sb1_128)
      || vec_any_ne ((vui32_t)val2_128, (vui32_t)sb2_128))
    {
      rc = check_vint384_priv (prefix, val0_128, val1_128, val2_128, sb0_128,
                               sb1_128, sb2_128);
    }

  return (rc);
}

static inline int
check_vint256 (char *prefix, vui128_t val0_128, vui128_t val1_128,
               vui128_t sb0_128, vui128_t sb1_128)
{
  int rc = 0;
  if (vec_any_ne(
      (vui32_t )val0_128,
      (vui32_t )sb0_128) || vec_any_ne ((vui32_t)val1_128, (vui32_t)sb1_128))
    {
      rc = check_vint256_priv (prefix, val0_128, val1_128, sb0_128, sb1_128);
    }

  return (rc);
}

static inline int
check_vuint128c (char *prefix, vui128_t val128, vui128_t carry128,
                 vui128_t shouldbe, vui128_t shouldcarry)
{
  int rc = 0;
  if (vec_any_ne(
      (vui32_t )val128,
      (vui32_t )shouldbe) || vec_any_ne ((vui32_t)carry128, (vui32_t)shouldcarry))
    {
      rc = check_vuint128c_priv (prefix, val128, carry128, shouldbe,
                                 shouldcarry);
    }

  return (rc);
}

static inline int
check_vuint128 (char *prefix, vui128_t val128, vui128_t shouldbe)
{
  int rc = 0;
  if (vec_any_ne((vui32_t )val128, (vui32_t )shouldbe))
    {
      rc = check_vuint128_priv (prefix, val128, shouldbe);
    }

  return (rc);
}

static inline int
check_vuint128x (char *prefix, vui128_t val128, vui128_t shouldbe)
{
  int rc = 0;
  if (vec_any_ne((vui32_t )val128, (vui32_t )shouldbe))
    {
      rc = check_vuint128x_priv (prefix, val128, shouldbe);
    }

  return (rc);
}

static inline int
check_uint128 (char *prefix, unsigned __int128 val128,
               unsigned __int128 shouldbe)
{
  int rc = 0;
  if (val128 != shouldbe)
    {
      rc = check_uint128_priv (prefix, val128, shouldbe);
    }

  return (rc);
}

static inline int
check_int128 (char *prefix, __int128 val128, __int128 shouldbe)
{
  int rc = 0;
  if (val128 != shouldbe)
    {
      rc = check_int128_priv (prefix, val128, shouldbe);
    }

  return (rc);
}
extern int
check_uint64 (char *prefix, unsigned long val64, unsigned long shouldbe);

extern int
check_int64 (char *prefix, long val64, long shouldbe);

extern int
check_frexptftd_priv (char *prefix, _Decimal128 val128, long exp,
                      _Decimal128 shouldbe, long shouldexp);

static inline int
check_frexptftd (char *prefix, _Decimal128 val128, long exp,
                 _Decimal128 shouldbe, long shouldexp)
{
  int rc = 0;
  if ((val128 != shouldbe) || (exp != shouldexp))
    {
      rc = check_frexptftd_priv (prefix, val128, exp, shouldbe, shouldexp);
    }

  return (rc);
}

extern int
check_frexptfkf_priv (char *prefix, vui128_t val128, long exp,
                      vui128_t shouldbe, long shouldexp);

static inline int
check_frexptfkf (char *prefix, vui128_t val128, long exp, vui128_t shouldbe,
                 long shouldexp)
{
  int rc = 0;
  if ((!vec_all_eq((vui32_t )val128, (vui32_t )shouldbe)) || (exp != shouldexp))
    {
      rc = check_frexptfkf_priv (prefix, val128, exp, shouldbe, shouldexp);
    }

  return (rc);
}

extern int
check_kf_priv (char *prefix, vui128_t val128, vui128_t shouldbe);

static inline int
check_kf (char *prefix, vui128_t val128, vui128_t shouldbe)
{
  int rc = 0;
  if (!vec_all_eq((vui32_t )val128, (vui32_t )shouldbe))
    {
      rc = check_kf_priv (prefix, val128, shouldbe);
    }

  return (rc);
}

extern int
check_frexptfvti_priv (char *prefix, vui128_t val128, long exp,
                       vui128_t shouldbe, long shouldexp);

extern int
check_frexptfti_priv (char *prefix, __int128 val128, long exp,
                      __int128 shouldbe, long shouldexp);

static inline int
check_frexptfvti (char *prefix, vui128_t val128, long exp, vui128_t shouldbe,
                  long shouldexp)
{
  int rc = 0;
  if ((!vec_all_eq((vui32_t )val128, (vui32_t )shouldbe)) || (exp != shouldexp))
    {
      rc = check_frexptfvti_priv (prefix, val128, exp, shouldbe, shouldexp);
    }

  return (rc);
}

static inline int
check_frexptfti (char *prefix, __int128 val128, long exp, __int128 shouldbe,
                 long shouldexp)
{
  int rc = 0;
  if ((val128 != shouldbe) || (exp != shouldexp))
    {
      rc = check_frexptfti_priv (prefix, val128, exp, shouldbe, shouldexp);
    }

  return (rc);
}

extern void
print_dfp128p2 (char *prefix, _Decimal128 val128, long exp);

extern vui128_t
db_shift_rightq (vui128_t vra, vui128_t vrb);

extern vui128_t
db_shift_leftq (vui128_t vra, vui128_t vrb);

#ifdef __DEBUG_PRINT__

extern int64_t
db_sdiv_qrnnd (int64_t *remainder,
    int64_t high_num, int64_t low_num,
    int64_t denom);

extern vui128_t
db_vec_clzq (vui128_t vra);

extern vui8_t
db_vec_tolower (vui8_t vec_str);

extern vui8_t
db_vec_toupper (vui8_t vec_str);

extern vui8_t
db_vec_isalpha (vui8_t vec_str);

extern vui32_t
db_vec_addeuqm (vui32_t a, vui32_t b, vui32_t c);

extern vui32_t
db_vec_addeq (vui32_t *cout, vui32_t a, vui32_t b, vui32_t c);

extern vui32_t
db_vec_mulluq (vui32_t a, vui32_t b);

extern vui32_t
db_vec_muludq (vui32_t *mulu, vui32_t a, vui32_t b);
#endif

extern vui128_t
db_vec_mul10uq (vui128_t a);

extern vui128_t
db_vec_mul10cuq (vui128_t a);

#endif /* ARITH128_PRINT_H_ */

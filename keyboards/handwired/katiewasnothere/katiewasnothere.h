#pragma once

#include "quantum.h"

// This macro is an example of using a non-standard row-column matrix. The
// keyboard in question had 11 rows and 8 columns, but the rows were not all
// horizontal, and the columns were not all vertical. For example, row 2
// contained "Print Screen", "N", "M", ",", ".", "/", "Right Shift", and
// "Left Alt". Column 0 contained "F6", "7", "O", "'", "Q", "D", "B",
// "Left Alt", "Up Arrow", and "Down Arrow".
//
// The macro makes programming the keys easier and in a more straight-forward
// manner because it realigns the keys into a 6x15 sensible keyboard layout
// instead of the obtuse 11x8 matrix.

//15 X 5 each
#define LAYOUT_katie(                                        \
    k00,k01,k02,k03,k04,k05,k06,                             \
    k10,k11,k12,k13,k14,k15,                                 \
    k20,k21,k22,k23,k24,k25,                                 \
    k30,k31,k32,k33,k34,k35,k36,                             \
    k40,k41,k42,k43,k44,                                     \
                                                             \
    k07,k08,k09,k0A,k0B,k0C,k0D,k0E,                         \
    k16,k17,k18,k19,k1A,k1B,k1C,                             \
    k26,k27,k28,k29,k2A,k2B,k2C,k2D,                         \
    k37,k38,k39,k3A,k3B,k3C,k3D,k3E,                         \
    k45,k46,k47,k48,k49,k4A,k4B                              \
    )                                                           \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    {k00,k01,    k02,k03,    k04,k05,k06,     KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},                              \
    {k10, KC_NO, k11,k12,   k13,k14,k15,      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},                        \
    {k20, KC_NO, k21,k22,   k23,k24,k25,      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},                        \
    {k30,k31,    k32,k33,    k34,k35,k36,     KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},                              \
    {k40,k41,    k42,KC_NO,  k43,k44,         KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},                  \
                                                                                                                 \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,        k07,k08,k09,k0A,k0B,k0C,k0D,k0E},                         \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,      k16,k17,k18,k19,k1A,k1B,k1C,KC_NO},                         \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,        k26,k27,k28,k29,k2A,k2B,k2C,k2D},                         \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,        k37,k38,k39,k3A,k3B,k3C,k3D,k3E},                         \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,      k45,k46,k47,k48,k49,k4A,k4B}                          \
   }

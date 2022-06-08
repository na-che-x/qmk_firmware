#pragma once

#include "babhandwire.h"

#define LAYOUT_split_3x5_3( \
              R05, R06, R07, R08, R09, \
              R15, R16, R17, R18, R19, \
              R25, R26, R27, R28, R29, \
              R33, R34, R35 \
) \
{ \
    { KC_NO, R05,   R06,   R07,   R08,   R09,   }, \
    { KC_NO, R15,   R16,   R17,   R18,   R19,   }, \
    { KC_NO, R25,   R26,   R27,   R28,   R29,   }, \
    { R33,   R34,   R35,   KC_NO, KC_NO, KC_NO, } \
}

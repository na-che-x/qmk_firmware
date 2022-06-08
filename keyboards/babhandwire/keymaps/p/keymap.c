#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_3(
         KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,
         KC_H,    KC_J,   KC_K,     KC_L,    KC_QUOT,
         KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,
 KC_Q,   KC_ENT,   KC_BSPC
    ),
};

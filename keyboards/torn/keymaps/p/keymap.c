/* Torn Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com) */

#include QMK_KEYBOARD_H

#define WINTAB LWIN_T(KC_TAB)
#define WINLFT LGUI(LSFT(KC_LEFT))
#define WINRHT LGUI(LSFT(KC_RGHT))

enum combos {
  SDEL_EXLM,
  LPARAN,
  RPARAN
};

const uint16_t PROGMEM shftdel_combo[] = {KC_LSFT, KC_DEL, COMBO_END};
const uint16_t PROGMEM lparan_combo[] = {KC_LSFT, KC_COMM, COMBO_END};
const uint16_t PROGMEM rparan_combo[] = {KC_LSFT, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SDEL_EXLM] = COMBO(shftdel_combo, KC_EXLM),
  [LPARAN] = COMBO(lparan_combo, KC_LPRN),
  [RPARAN] = COMBO(rparan_combo, KC_RPRN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_split_3x6_4(
      KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,  KC_BSPC,
     KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_DEL,
    KC_LCTRL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_QUOT,
                       WINTAB, KC_RALT,  KC_SPC,   MO(1),   _______,  KC_ENT,   MO(2),   MO(3)
),

[1] = LAYOUT_split_3x6_4(
    KC_GRV,  KC_RABK, KC_RCBR, KC_RBRC, KC_RPRN, KC_BSLS,   KC_UNDS, KC_CIRC, _______, _______, _______, _______,
    _______, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH,   KC_MINS, KC_ASTR, KC_PERC, _______, _______, _______,
    _______, KC_HASH,  KC_DLR, KC_BSLS, KC_EXLM, KC_PIPE,  KC_TILDE,   KC_AT, KC_AMPR, _______, _______, _______,
                       WINTAB, KC_RALT,  KC_SPC,   MO(1),   _______,  KC_ENT,   MO(2),   MO(3)
),

[2] = LAYOUT_split_3x6_4(
    _______, KC_PLUS,    KC_7,    KC_8,    KC_9,  KC_EQL,   _______, _______, _______, _______, _______, _______,
    _______,    KC_0,    KC_4,    KC_5,    KC_6,  KC_DOT,   _______, _______, _______, _______, _______, _______,
    _______, KC_MINS,    KC_1,    KC_2,    KC_3, KC_COMM,   _______, _______, _______, _______, _______, _______,
                       WINTAB, KC_RALT,  KC_SPC,   MO(1),   _______,  KC_ENT,   MO(2),   MO(3)
),

[3] = LAYOUT_split_3x6_4(
    _______, _______, _______,   KC_UP, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,   _______, _______, _______, _______, _______, _______,
    _______, _______,  WINLFT,  WINRHT, _______, _______,   _______, _______, _______, _______, _______, _______,
                       WINTAB, KC_RALT,  KC_SPC,   MO(1),   _______,  KC_ENT,   MO(2),   MO(3)
)

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [0] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_VOLU,      KC_VOLD } }
};

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, 1));
    torn_set_led(1, IS_LAYER_ON_STATE(state, 2));
    torn_set_led(2, IS_LAYER_ON_STATE(state, 3));
    return state;
}

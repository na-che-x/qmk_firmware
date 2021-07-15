/* Torn Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com) */

/* Blank Template
 * ,-----------------------------------------.                         ,-----------------------------------------.
 * |      |      |      |      |      |      |                         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                         |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                         |      |      |      |      |      |      |
 * `-----------------------------------------|---------     -----------------------------------------------------|
 *                        |      |      |      |      |    |       |       |       |      |
 *                        `---------------------------'    `-----------------------------'
 */

#include QMK_KEYBOARD_H

enum torn_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

#define S_BSPC LSFT_T(KC_BSPC)
#define R_DEL LT(_RAISE, KC_DEL)
#define G_ENT LGUI_T(KC_ENT)
#define L_SPC LT(_LOWER, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.                         ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |                         |   H  |   J  |   K  |   L  |   ;  |  Del |
 * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |                         |   N  |   M  |   ,  |   .  |   /  |  '   |
 * `-----------------------------------------|---------     -----------------------------------------------------|
 *                        | Win  | Alt  | Spce |  L1  |    |  enc  | Enter |  L2  | Leader |
 *                        `---------------------------'    `------------------------------'
 */

[_QWERTY] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    S_BSPC,
    KC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, R_DEL,
    KC_LCTRL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                KC_LWIN, KC_RALT, KC_SPC,  MO(_LOWER),     KC_ESC,   KC_ENT, MO(_RAISE), KC_LEAD
),

/* KC_LSPO (Left Shift, Parenthesis Open) */

 /* Lower
  * ,-----------------------------------------.                         ,-----------------------------------------.
  * |  `   |   !  |   @  |   #  |   $  |   %  |                         |   ^  |   &  |   *  |   (  |   )  |  =   |
  * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
  * | Shift|   1  |   2  |   3  |   4  |   5  |                         |   6  |   7  |   8  |   9  |   0  |  -   |
  * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
  * | _    | Tab  |   ~  |  \|  |      |      |                         |   [  |  ]   |   ,  |   .  |   /  |  +   |
  * `-----------------------------------------|---------     -----------------------------------------------------|
  *                        | Win  | Alt  | Spce |  L1  |    |  enc  | Enter |  L2  | Leader |
  *                        `---------------------------'    `------------------------------'
  */

[_LOWER] = LAYOUT_split_3x6_4(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
    KC_LSFT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PMNS,
    KC_UNDS, KC_TAB, KC_TILD, KC_BSLS, _______, _______,   KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_PPLS,
                KC_LWIN, KC_LALT, KC_SPC,  MO(_LOWER),     _______,   KC_ENT, MO(_RAISE), MO(_ADJUST)
),

 /* Raise
  * ,-----------------------------------------.                         ,-----------------------------------------.
  * |      |      |      |      |      |      |                         |      |      |  Up  |      |      |      |
  * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                         | Home | Left | Down | Right| End  |      |
  * |------+------+------+------+------+------|                         |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                         |      |WnLft |WnRght|      |      |      |
  * `-----------------------------------------|---------     -----------------------------------------------------|
  *                        | Win  | Alt  | Spce |  L1  |    |  enc  | Enter |  L2  | Leader |
  *                        `---------------------------'    `------------------------------'
  */

[_RAISE] = LAYOUT_split_3x6_4(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     _______, S(A(KC_LEFT)), KC_UP, S(A(KC_RGHT)), _______, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGUP,
    _______, KC_F11,  KC_F12,  _______, _______, _______,   A(KC_BSPC), LGUI(LSFT(KC_LEFT)), LGUI(LSFT(KC_RGHT)), A(KC_RGHT), _______, KC_PGDN ,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_ADJUST] = LAYOUT_split_3x6_4(
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_VOLU,      KC_VOLD } },
    [_LOWER]  =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC__VOLDOWN,  KC__VOLUP } },
    [_RAISE]  =  { { KC_TRNS,      KC_TRNS },       { G(KC_TAB),    G(S(KC_TAB)) } },
    [_ADJUST] =  { { KC_TRNS,      KC_TRNS },       { KC_TRNS,      KC_TRNS } },
};

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _LOWER));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _RAISE));
    torn_set_led(2, IS_LAYER_ON_STATE(state, _ADJUST));
    return state;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
      LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        SEQ_ONE_KEY(KC_N) {
            SEND_STRING("Nancy Xia");
        }
        SEQ_TWO_KEYS(KC_N, KC_N) {
            SEND_STRING("nancy.c.xia@gmail.com");
        }
    }
}

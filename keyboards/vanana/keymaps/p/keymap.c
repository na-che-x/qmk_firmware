/* Copyright 2020 noclew
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define WINTAB LWIN_T(KC_TAB)
#define WINLFT LGUI(LSFT(KC_LEFT))
#define WINRHT LGUI(LSFT(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_vanana(
    KC_ESC,     KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5 ,                      KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_BSPC,
    KC_TAB,     KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T ,                      KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_DEL ,
    KC_LSFT,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G ,       KC_VOLU,       KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOT,
    KC_LCTL,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B ,       KC_VOLD,       KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    KC_QUOT,
                KC_LGUI,    KC_LALT,    _______,    MO(1)  ,    KC_SPC,                     KC_ENT ,    MO(2)  ,    MO(3)  ,    _______,    _______
    ),
    [1] = LAYOUT_vanana(
    _______,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,                    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
    _______,    KC_RABK,    KC_RCBR,    KC_RBRC,    KC_RPRN,    KC_BSLS,                    KC_UNDS,    KC_CIRC,    KC_QUOT,    KC_DQUO,    KC_BSLS,    _______,
    _______,    KC_LABK,    KC_LCBR,    KC_LBRC,    KC_LPRN,    KC_SLSH,     KC_LEFT,       KC_MINS,    KC_ASTR,    KC_PERC,    _______,    _______,    _______,
    KC_DLR ,    KC_HASH,    KC_DLR ,    KC_BSLS,    KC_EXLM,    KC_PIPE,     KC_RGHT,       KC_TILDE,   KC_AT  ,    KC_AMPR,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______
    ),

    [2] = LAYOUT_vanana(
    _______,    _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_PLUS,    KC_7   ,    KC_8   ,    KC_9   ,    KC_EQL ,                    _______,    KC_HOME,    KC_BSPC,    KC_DEL ,    KC_END ,    _______,
    _______,    KC_0   ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_DOT ,    KC_UP  ,        KC_LEFT,    KC_DOWN,    KC_UP  ,    KC_RGHT,    KC_QUOT,    _______,
    _______,    KC_MINS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_COMM,    KC_DOWN,        _______,    KC_PGUP,    _______,    KC_PGDN,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______
    ),
    [3] = LAYOUT_vanana(
    RESET  ,    _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______,    DEBUG  ,
    _______,    _______,    WINLFT ,    KC_UP  ,    WINRHT ,    RGB_VAD,                    _______,    _______,    _______,    _______,    _______,    _______,
    KC_CAPS,    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_END ,    KC_VOLU,        _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    C(KC_C),    C(KC_X),    C(KC_V),    KC_PSCR,    KC_VOLD,        _______,    _______,    _______,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    /* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        /* And with another if statement we can check the direction. */
        if (clockwise) {
            if (IS_LAYER_ON(1)){
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_RIGHT);
            }
        } else {
            if (IS_LAYER_ON(1)){
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_LEFT);
            }
        }

    } else if (index == 1) { /* Second encoder. Only supported by Elite-C */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}

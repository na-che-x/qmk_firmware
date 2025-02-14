 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    |       |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |  L1  | Space| /Space  /       \Enter \  |  L2  |  L3  |  L4  |  L5  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[0] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_DEL,
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_LALT,MO(1), KC_SPC, KC_SPC,            KC_ENT,  MO(3), KC_RCTRL, KC_RALT, KC_RGUI
),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |      |      |      |      |      |                    |      |      |      |      |      |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |   +  |
 * |------+------+------+------+------+------|  Mute |    |       |------+------+------+------+------+------|
 * |   _  |      |   ~  |      |      |      |-------|    |-------|   [  |   ]  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  KC_GRV,  KC_TILD, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_PEQL,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_MINUS,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_EQUAL,
  KC_UNDS, _______, KC_TILD,    KC_C,    KC_V, _______, KC_MUTE,   _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Home | Left | Down |Right | End  | PgUp |
 * |------+------+------+------+------+------|  Mute |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |WnLft |      |      |      | PgDn |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______,   KC_UP, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, KC_PGUP,
  _______, _______, _______, _______, _______, _______, KC_MUTE,   _______, _______, LGUI(LSFT(KC_LEFT)), LGUI(LSFT(KC_RGHT)), _______, _______, KC_PGDN,
                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Mute |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_MUTE,   _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
)
};

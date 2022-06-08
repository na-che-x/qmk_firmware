/* Copyright 2019 gtips
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

enum layers{
  _BASE,
  _NUM,
	_SYM,
  _NAV
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};

#define NUMENT LT(_NUM, KC_ENT)
#define SYMSPC LT(_SYM, KC_SPC)
#define KC_SA LSFT_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_GF LGUI_T(KC_F)
#define KC_GJ RGUI_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_SSCLN RSFT_T(KC_SCLN)
#define WINLFT LGUI(LSFT(KC_LEFT))
#define WINRHT LGUI(LSFT(KC_RGHT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q   ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,          KC_Y  ,  KC_U  , KC_I   , KC_O   , KC_P    ,
    KC_SA  ,  KC_AS ,  KC_CD ,  KC_GF ,  KC_G  ,          KC_H  ,  KC_GJ , KC_CK  , KC_AL  , KC_SSCLN,
    KC_Z   ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,          KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH ,
                               _______,  SYMSPC,          NUMENT, MO(_NAV)
  ),

	[_NUM] = LAYOUT_reviung34(
    KC_PLUS, KC_7   , KC_8   , KC_9   , KC_EQL ,          _______, _______, _______, _______, _______,
    KC_0   , KC_4   , KC_5   , KC_6   , KC_DOT ,          _______, _______, _______, _______, _______,
    KC_MINS, KC_1   , KC_2   , KC_3   , KC_COMM,          _______, _______, _______, _______, _______,
                               _______, _______,          _______, _______
  ),

  [_SYM] = LAYOUT_reviung34(
    KC_RABK, KC_RCBR, KC_RBRC, KC_RPRN, KC_BSLS,          KC_UNDS, KC_CIRC, KC_QUOT, KC_DQUO, _______,
		KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH,          KC_MINS, KC_ASTR, KC_PERC, KC_SCLN, _______,
    KC_HASH, KC_DLR , KC_BSLS, KC_EXLM, KC_PIPE,          KC_TILDE, KC_AT  , KC_AMPR, KC_COLN, _______,
                               _______, _______,          _______, _______
  ),

  [_NAV] = LAYOUT_reviung34(
    _______,  WINLFT,   KC_UP,  WINRHT, _______,          _______, _______, _______, _______, _______,
    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,          _______, _______, _______, _______, _______,
    _______, C(KC_C), C(KC_X), C(KC_V), KC_PSCR,          _______, _______, _______, _______, _______,
                               _______, _______,          _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case _NUM:
			if (record->event.pressed) {
				layer_on(_NUM);
				update_tri_layer(_NUM, _SYM, _NAV);
			} else {
				layer_off(_NUM);
				update_tri_layer(_NUM, _SYM, _NAV);
			}
			return false;
		case _SYM:
			if (record->event.pressed) {
				layer_on(_SYM);
				update_tri_layer(_NUM, _SYM, _NAV);
			} else {
				layer_off(_SYM);
				update_tri_layer(_NUM, _SYM, _NAV);
			}
			return false;
		}
	return true;
}

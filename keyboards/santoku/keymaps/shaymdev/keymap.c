#include QMK_KEYBOARD_H
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif
#include "ps2_mouse.h"
extern keymap_config_t keymap_config;
//#include "LUFA/Drivers/Peripheral/TWI.h"

//#define TAPPING_FORCE_HOLD


enum santoku_layers
{
	_DVORAK,
	_LOWER,
	_RAISE,
	_ADJUST,

	_QWERTY,
	_SYMBOL,
	_NAVIGATION,
	_FUNC
};

enum santoku_keycodes
{
	DVORAK = SAFE_RANGE,
	QWERTY,
	ONETAPALTTAB,
	TAPHOLDKEYTEST,
};

enum combos //match combo_count in config.h
{
	AO_ESC,
	EU_ENT,
};

#define TO_DV TO(_DVORAK)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SFT_U SFT_T(KC_U) //TO SHORTEN THINGS UP IN LAYOUT MAP? MAKE A BUNCH OF THESE

const uint16_t PROGMEM ao_combo[]     = {GUI_T(KC_A), ALT_T(KC_O), COMBO_END};
const uint16_t PROGMEM eu_combo[]     = {KC_E, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[AO_ESC]                = COMBO_ACTION(ao_combo),
	[EU_ENT]                = COMBO_ACTION(eu_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case AO_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case EU_ENT:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
  }
}

static bool in_alttab = false; // does an ALT-TAB, for windows cycling, without an alt key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT( \
			//Consider miryoku style modifiers... homerow left->right super(aka gui), alt, ctrl, shift
			KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,	  KC_P,    KC_Y,         KC_F,    KC_G,   KC_C,      KC_R,   KC_L,    KC_SLSH, \
			KC_TAB, GUI_T(KC_A), ALT_T(KC_O), KC_E, KC_U,  KC_I,         KC_D,    KC_H,   KC_T,      KC_N,   KC_S,    KC_MINS, \
//MIRYOKU KC_TAB, GUI_T(KC_A), ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), KC_I,         KC_D, SFT_T(KC_H), CTL_T(KC_T), ALT_T(KC_N), GUI_T(KC_S),    KC_MINS, !ADD SLASH CHAR!
			KC_EQL,  KC_SCLN, KC_Q,    KC_J,  	  KC_K,    KC_X,         KC_B,    KC_M,   KC_W,      KC_V,   KC_Z,    KC_BSLS, \
			 						   TT(LOWER), KC_LSFT, KC_LCTL,      KC_BSPC, ALT_T(KC_SPC), TT(RAISE)
//!MIRYOKU* XXXXXXX, XXXXXXX, XXXXXXX, TT(LOWER), KC_LSFT, KC_ENT,       KC_BSPC, KC_SPC, TT(RAISE), XXXXXX, XXXXXXX, XXXXXXX
			),

	[_QWERTY] = LAYOUT( \
			KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    	  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC, \
			KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    	  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
			KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    	  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_LGUI,\
			                           _______, _______, _______,     _______, _______, _______
			),

	[_LOWER] = LAYOUT( \
			_______, 	  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,     _______, KC_P7,   KC_P8,   KC_P9,  KC_PMNS, _______, \
			ONETAPALTTAB, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR, 	   _______, KC_P4,   KC_P5,   KC_P6,  KC_PPLS, _______, \
			_______, 	  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV,      _______, KC_P1,   KC_P2,   KC_P3,  KC_PENT, _______, \
		                               _______, _______, _______,          KC_DEL,  _______, KC_KP_0
			),

	[_RAISE] = LAYOUT( \
			_______, KC_PSCR, KC_HOME, KC_UP,   KC_END,  KC_PGUP,     KC_VOLU, KC_F7,   KC_F8,   KC_F9,  KC_F10,  XXXXXXX,\
			KC_CAPS, KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,     KC_VOLD, KC_F4,   KC_F5,   KC_F6,  KC_F11,  XXXXXXX,\
			_______, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MUTE, KC_F1,   KC_F2,   KC_F3,  KC_F12,  XXXXXXX,\
			                           _______, _______, _______,     _______, _______, _______
			),

	[_ADJUST] =  LAYOUT( \
			TO_DV, RESET,   _______, _______, _______, _______,       _______, _______, _______, _______, _______, KC_DEL,  \
			RGB_TOG, RGB_MOD, VLK_TOG, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP,  QWERTY,  DVORAK, _______, _______, _______, \
			RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,  \
			                           _______, _______, _______,     _______, _______, _______
			)
};


bool encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
	return true;
}


void keyboard_post_init_user(void) {
	// Customise these values to desired behaviour
	debug_enable=false;
	debug_matrix=false;
	debug_keyboard=false;
	debug_mouse=false;
	//ps2_mouse_set_remote_mode();
}

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);
//
// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &delete_key_override,
//     NULL // Null terminate the array of overrides!
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint16_t key_timer;
	//static bool in_cursor_mode = false;

	switch (keycode) {
		case TAPHOLDKEYTEST:
			if (record->event.pressed) {
				key_timer = timer_read();  // start the timer
				return false;              // return false to keep anything from being sent
			} else {
                // If key was held
				if (timer_elapsed(key_timer) > 250) {
						SEND_STRING(SS_TAP(X_G));
    					return false;
    				} else {
                        // if key was tapped
						SEND_STRING(SS_TAP(X_B));
    					return false;
    				}
    			}
			break;

		case RESET:
			oled_write_ln_P(PSTR("RESETORFLASH"), true);
			_delay_ms(1500);
			break;

		case ONETAPALTTAB:
			// Macro to handle lower-tab as alt-tab
			if (record->event.pressed) {
				if (!in_alttab) {
					SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB));
					in_alttab = true;
				} else {
					SEND_STRING(SS_TAP(X_TAB));
					// Do not release Alt here, or it will be impossible to switch more than one window:
					// alt-tab-tab will be interpreted as alt-tab, then tab
				}
			}
			return false;
			break;

		default:
			if ((keycode != ONETAPALTTAB) && in_alttab) {
				// Exit alt tab before treating normally the keycode
				SEND_STRING(SS_UP(X_LALT));
				in_alttab = false;
				return false;
			}

	}
	return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_O):
        case GUI_T(KC_A):
        case ALT_T(KC_SPC):
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

void matrix_init_user(void) {
#ifdef USE_I2C
	i2c_master_init();
#ifdef SSD1306OLED
	// calls code for the SSD1306 OLED
	_delay_ms(400);
	TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
	iota_gfx_init();   // turns on the display
#endif
#endif
}

//#ifdef OLED_DRIVER_ENABLE
#ifdef OLED_ENABLE
void oled_task_user(void) {
	// Vanity Text
	static bool show_vanity_text = true;
	if (show_vanity_text) {
		oled_write_ln_P(PSTR("  Santoku Keyboard"), false);
		oled_write_ln_P(PSTR("       by Tye"), false);
		oled_write_ln_P(PSTR(""), false);
		oled_write_ln_P(PSTR("    Hello, Shay."), false);
		if (timer_read() > 7500) {
			show_vanity_text = false;
		}
	}
	else if (in_alttab ) {
		oled_write_ln_P(PSTR("   ALT-TAB ACTIVE   "), true);

	}
	else {
		uint8_t wpm = get_current_wpm();
		if (wpm < 20) {
			oled_write("      ", false);
		}
		else {
			char wpm_display[9];
			sprintf(wpm_display, "WPM:%d ", get_current_wpm());
			oled_write(wpm_display, false);
		}

		// Host Keyboard Layer Status
		switch (get_highest_layer(layer_state)) {
			case _DVORAK:
				oled_write_P(PSTR("DVORAK\n"), false); //maybe just list the tap mods and combos
				oled_write_ln_P(PSTR(""), false);
				oled_write_ln_P(PSTR("ES  ',.py | fgcrl/"), false);
				oled_write_ln_P(PSTR("TB  aoeui | dhtns-"), false);
				oled_write_ln_P(PSTR("=   ;qjkx | bmwvz\\"), false);
				break;
			case _QWERTY:
				oled_write_P(PSTR("QWERTY\n"), false);
				oled_write_ln_P(PSTR(""), false);
				oled_write_ln_P(PSTR("TB  qwert | yuiop\\"), false);
				oled_write_ln_P(PSTR("ES  asdfg | hjkl;'"), false);
				oled_write_ln_P(PSTR("SH  zxcvb | nm,./"), false);
				break;
			case _LOWER:
				oled_write_P(PSTR("   Lower   \n"), true);
				oled_write_ln_P(PSTR(""), false);
				oled_write_ln_P(PSTR(" `  !@{}& |  789-"), false);
				oled_write_ln_P(PSTR("ES  #$()* |  456+"), false);
				oled_write_ln_P(PSTR("SH  %^[]` |  123E"), false);
				break;
			case _RAISE:
				oled_write_P(PSTR(" Raise \n"), true);
				oled_write_ln_P(PSTR(""), false);
				oled_write_ln_P(PSTR("Pr H ^ E PU|V+ F789"), false);
				oled_write_ln_P(PSTR("In < V > PD|V- F456"), false);
				oled_write_ln_P(PSTR("NL         |Mu F123"), false);
				break;
			case _ADJUST:
				oled_write_P(PSTR("  Adjust  \n"), true);
				oled_write_ln_P(PSTR(""), false);
				oled_write_ln_P(PSTR("esc rst |"), false);
				oled_write_ln_P(PSTR("        |  qw dv"), false);
				oled_write_ln_P(PSTR("        |"), false);
				break;
			default:
				oled_write_ln_P(PSTR("Undefined"), false);
		}
	}

	/*
	// Host Keyboard LED Status
	led_t led_state = host_keyboard_led_state();
	oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
	oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
	oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	*/
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
	state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	return state;
}

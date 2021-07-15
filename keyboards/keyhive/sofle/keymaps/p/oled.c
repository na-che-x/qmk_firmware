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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}


static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    // 'canadiangoose3left', 32x128px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x08, 0x70, 0x80, 0x00, 0x00, 0x18, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x0c, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc1, 0x00, 0x00, 0x03, 0x00, 0x00, 0x08, 0x06, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
    0xc0, 0x30, 0x0c, 0x82, 0x01, 0x7f, 0x80, 0x60, 0x10, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
    0xe0, 0x08, 0x31, 0xf1, 0xe0, 0xc0, 0xc0, 0xc0, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c,
    0x03, 0x00, 0x00, 0x80, 0x61, 0x19, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x1f, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
    0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10,
    0x08, 0x07, 0x02, 0xe4, 0x08, 0x08, 0x08, 0x08, 0x88, 0x04, 0x32, 0xc1, 0x0e, 0x70, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0x0c, 0x12, 0x22, 0x25, 0xe8, 0x00, 0x10, 0x40, 0x80, 0x80,
    0x00, 0x00, 0xc0, 0x61, 0x1e, 0x80, 0x00, 0x00, 0xc3, 0x3c, 0x00, 0x00, 0xff, 0x00, 0x01, 0xfe,
    0xc0, 0x20, 0x1c, 0x03, 0x98, 0x66, 0x11, 0x89, 0xc7, 0xc8, 0x50, 0x71, 0xa2, 0x52, 0x0c, 0x84,
    0x24, 0x83, 0x90, 0x00, 0x48, 0x00, 0x92, 0x08, 0x47, 0x00, 0x00, 0xd2, 0x21, 0x10, 0x0c, 0x03,
    0x7f, 0xc0, 0x20, 0x91, 0x48, 0x46, 0xf1, 0xef, 0xb5, 0x5b, 0xed, 0xba, 0xaa, 0xfc, 0x49, 0x9c,
    0xb4, 0xe6, 0x60, 0x4c, 0x32, 0x22, 0x10, 0x0a, 0x09, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x68, 0xf0, 0x7f, 0x7e, 0x2d, 0x2f, 0x97, 0xf6, 0x3b, 0x0d, 0x06, 0x03, 0x07,
    0x0c, 0x18, 0x70, 0x70, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0x20, 0x30, 0x48, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xb8, 0x0e, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x1d, 0x0a, 0x0a, 0x09, 0x0d, 0x0b, 0x08, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x3f, 0xc3, 0x25, 0x25, 0x29, 0x72, 0x0e, 0x04, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_right(void) {
  static const char PROGMEM my_logo_right[] = {
    // 'canadiangoose3', 32x128px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x00, 0x00, 0x80, 0x70, 0x08, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x06, 0x08, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x10, 0x60, 0x80, 0x7f, 0x01, 0x82, 0x0c, 0x30, 0xc0,
    0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0xc0, 0xc0, 0xc0, 0xe0, 0xf1, 0x31, 0x08, 0xe0,
    0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x05, 0x19, 0x61, 0x80, 0x00, 0x00, 0x03,
    0x0c, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x10, 0x0c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x70, 0x0e, 0xc1, 0x32, 0x04, 0x88, 0x08, 0x08, 0x08, 0x08, 0xe4, 0x02, 0x07, 0x08,
    0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0x01, 0x00, 0xff, 0x00, 0x00, 0x3c, 0xc3, 0x00, 0x00, 0x80, 0x1e, 0x61, 0xc0, 0x00, 0x00,
    0x80, 0x80, 0x40, 0x10, 0x00, 0xe8, 0x25, 0x22, 0x12, 0x0c, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
    0x03, 0x0c, 0x10, 0x21, 0xd2, 0x00, 0x00, 0x47, 0x08, 0x92, 0x00, 0x48, 0x00, 0x90, 0x83, 0x24,
    0x84, 0x0c, 0x52, 0xa2, 0x71, 0x50, 0xc8, 0xc7, 0x89, 0x11, 0x66, 0x98, 0x03, 0x1c, 0x20, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x09, 0x0a, 0x10, 0x22, 0x32, 0x4c, 0x60, 0xe6, 0xb4,
    0x9c, 0x49, 0xfc, 0xaa, 0xba, 0xed, 0x5b, 0xb5, 0xef, 0xf1, 0x46, 0x48, 0x91, 0x20, 0xc0, 0x7f,
    0x00, 0x80, 0x80, 0x80, 0x48, 0x30, 0x20, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x70, 0x18, 0x0c,
    0x07, 0x03, 0x06, 0x0d, 0x3b, 0xf6, 0x97, 0x2f, 0x2d, 0x7e, 0x7f, 0xf0, 0x68, 0x07, 0x00, 0x00,
    0x00, 0x10, 0x08, 0x0b, 0x0d, 0x09, 0x0a, 0x0a, 0x1d, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0e, 0xb8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x04, 0x0e, 0x72, 0x29, 0x25, 0x25, 0xc3, 0x3f, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(my_logo_right, sizeof(my_logo_right));
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to put your image on the master side, put your function call here:
    render_logo();
  } else {
    // And if you want to put your image on the slave side, put it here instead:
    render_logo_right();
  }
}

//
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_270;
// }
//
// #define MIN_WALK_SPEED 10
// #define MIN_RUN_SPEED 60
// #define FELIX_FRAMES 2
// #define FELIX_FRAME_DURATION 200
// #define FELIX_SIZE 96
//
// uint32_t felix_anim_timer = 0;
// uint32_t felix_anim_sleep = 0;
// uint8_t felix_current_frame = 0;
// uint8_t felix_prev_wpm = 0;
// bool felix_typing = false;
//
// static void render_felix_sit(void) {
// 	static const char PROGMEM sit[FELIX_FRAMES][FELIX_SIZE] = { {
// #ifndef FELIX
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
// 		0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x68,0x10,0x08,0x04,0x03,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x02,0x06,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
// 		0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
// 		0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0xe0,0x90,0x08,0x18,0x60,0x10,0x08,0x04,0x03,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x02,0x0e,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
// 		0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #else
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xfc,
// 		0xfe,0xfd,0xfe,0xdc,0xfc,0xfc,0xfe,0x5d,0xfe,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf0,0xf8,0x1c,0xf0,0xf8,0xfc,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xfd,0xf9,0xfd,0x7f,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0f,0x1f,0x1f,0x3f,0x3f,0x3f,0x37,
// 		0x21,0x13,0x3f,0x3f,0x3f,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xfe,
// 		0xfd,0xfe,0xfc,0xdc,0xfc,0xfe,0xfd,0x5e,0xfc,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0xe0,0xf0,0xf8,0xfc,0x80,0xf0,0xf8,0xfc,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xfd,0xf1,0xfd,0x7f,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0f,0x1f,0x1f,0x3f,0x3f,0x3f,0x37,
// 		0x21,0x13,0x3f,0x3f,0x3f,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #endif
// 	} };
//
// 	felix_current_frame = (felix_current_frame + 1) % FELIX_FRAMES;
// 	oled_write_raw_P(sit[abs(1 - felix_current_frame)], FELIX_SIZE);
// }
//
// static void render_felix_walk(void) {
// 	static const char PROGMEM walk[FELIX_FRAMES][FELIX_SIZE] = { {
// #ifndef FELIX
// 		0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x90,0x90,0x90,0xa0,0xc0,0x80,0x80,
// 		0x80,0x70,0x08,0x14,0x08,0x90,0x10,0x10,0x08,0xa4,0x78,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x07,0x08,0xfc,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
// 		0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x18,0xea,0x10,0x0f,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1c,0x20,0x20,0x3c,0x0f,0x11,0x1f,0x03,
// 		0x06,0x18,0x20,0x20,0x3c,0x0c,0x12,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x20,0x20,0x40,0x80,0x00,0x00,0x00,
// 		0x00,0xe0,0x10,0x28,0x10,0x20,0x20,0x20,0x10,0x48,0xf0,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x1f,0x20,0xf8,0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
// 		0x03,0x00,0x00,0x00,0x00,0x01,0x00,0x10,0x30,0xd5,0x20,0x1f,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x20,0x30,0x0c,0x02,0x05,0x09,0x12,0x1e,
// 		0x02,0x1c,0x14,0x08,0x10,0x20,0x2c,0x32,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #else
// 		0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xf0,0xf0,0x70,0x30,0x20,0x00,0x80,0xc0,
// 		0xc0,0xf0,0xf8,0xf4,0xf8,0x70,0xf0,0xf0,0xf8,0x74,0xf8,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x07,0x0f,0xff,0xfd,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xe7,0xf5,0x1f,0x0f,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1f,0x3f,0x3f,0x3f,0x0f,0x11,0x1f,0x1f,
// 		0x03,0x07,0x1f,0x3f,0x3f,0x0f,0x13,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xe0,0xe0,0xc0,0x80,0x00,0x00,0x00,
// 		0x00,0xe0,0xf0,0xe8,0xf0,0xe0,0xe0,0xe0,0xf0,0xe8,0xf0,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x1f,0x3f,0xfb,0xfd,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,
// 		0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xef,0xcf,0xea,0x3f,0x1f,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x3f,0x3f,0x0f,0x03,0x07,0x0f,0x1f,0x03,
// 		0x1f,0x1f,0x17,0x0f,0x1f,0x3f,0x3f,0x33,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #endif
// 	} };
//
// 	felix_current_frame = (felix_current_frame + 1) % FELIX_FRAMES;
// 	oled_write_raw_P(walk[abs(1 - felix_current_frame)], FELIX_SIZE);
// }
//
// static void render_felix_run(void) {
// 	static const char PROGMEM run[FELIX_FRAMES][FELIX_SIZE] = { {
// #ifndef FELIX
// 		0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x08,0xc8,0xb0,0x80,0x80,0x80,0x80,0x80,0x80,
// 		0x80,0x40,0x40,0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x01,0x02,0xc4,0xa4,0xfc,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc8,0x58,0x28,0x2a,0x10,0x0f,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x0e,0x09,0x04,0x04,0x04,0x04,0x02,0x03,0x02,0x01,0x01,
// 		0x02,0x02,0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
// 		0x80,0x80,0x78,0x28,0x08,0x10,0x20,0x30,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x10,0xb0,0x50,0x55,0x20,0x1f,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,
// 		0x02,0x1e,0x20,0x20,0x18,0x0c,0x14,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #else
// 		0x00,0x00,0x00,0x00,0xe0,0xf0,0xf8,0xf8,0xf8,0xb0,0xa0,0x80,0x80,0x80,0x80,0x80,
// 		0x80,0xc0,0xc0,0xfc,0xf4,0xe4,0xf8,0x70,0xf8,0xe4,0xf8,0x70,0xc0,0x80,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x01,0x63,0xe7,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0x67,0x37,0x35,0x1f,0x0f,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x0e,0x0f,0x07,0x07,0x07,0x07,0x03,0x03,0x03,0x01,0x01,
// 		0x03,0x03,0x07,0x0f,0x1f,0x3f,0x3b,0x33,0x07,0x07,0x06,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0xe0,0xf0,0xf0,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
// 		0x80,0x80,0xf8,0xe8,0xc8,0xf0,0xe0,0xf0,0xc8,0xf0,0xe0,0xc0,0x80,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x03,0x07,0x0f,0x1f,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xef,0xcf,0x6f,0x6a,0x3f,0x1f,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0f,0x1f,0x3f,0x3f,0x37,
// 		0x03,0x1f,0x3f,0x3f,0x1f,0x0f,0x1f,0x3f,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #endif
// 	} };
//
// 	felix_current_frame = (felix_current_frame + 1) % FELIX_FRAMES;
// 	oled_write_raw_P(run[abs(1 - felix_current_frame)], FELIX_SIZE);
// }
//
// static void render_felix_bark(void) {
// 	static const char PROGMEM bark[FELIX_FRAMES][FELIX_SIZE] = { {
// #ifndef FELIX
// 		0x00,0xc0,0x20,0x10,0xd0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
// 		0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x80,0xc8,0x48,0x28,0x2a,0x10,0x0f,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
// 		0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
// 		0x40,0x2c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0x48,0x28,0x2a,0x10,0x0f,0x20,0x4a,0x09,0x10,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
// 		0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #else
// 		0x00,0xc0,0xe0,0xf0,0xf0,0x30,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xc0,
// 		0xfc,0xf4,0xe4,0xf8,0x70,0xf8,0xe4,0xf8,0x70,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x03,0x07,0x0f,0x1f,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xf7,0xf7,0x37,0x35,0x1f,0x0f,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0f,0x1f,0x3f,0x3f,0x37,0x03,0x03,
// 		0x07,0x0f,0x1f,0x3f,0x3b,0x33,0x07,0x07,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0xe0,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xc0,
// 		0xc0,0xec,0xf4,0xe4,0xf8,0x70,0xf8,0xe4,0xf8,0x70,0xc0,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x03,0x07,0x0f,0x1f,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
// 		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0x37,0x35,0x1f,0x0f,0x20,0x4a,0x09,0x10,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0f,0x1f,0x3f,0x3f,0x37,0x03,0x03,
// 		0x07,0x0f,0x1f,0x3f,0x3b,0x33,0x07,0x07,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00
// #endif
// 	} };
//
// 	felix_current_frame = (felix_current_frame + 1) % FELIX_FRAMES;
// 	oled_write_raw_P(bark[abs(1 - felix_current_frame)], FELIX_SIZE);
// }
//
// static void render_felix_sneak(void) {
// 	static const char PROGMEM sneak[FELIX_FRAMES][FELIX_SIZE] = { {
// #ifndef FELIX
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0xc0,0x40,0x40,0x80,0x00,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x1e,0x21,0xf0,0x04,0x02,0x02,0x02,0x02,0x03,0x02,0x02,0x04,
// 		0x04,0x04,0x03,0x01,0x00,0x00,0x09,0x01,0x80,0x80,0xab,0x04,0xf8,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1c,0x20,0x20,0x3c,0x0f,0x11,0x1f,0x02,0x06,
// 		0x18,0x20,0x20,0x38,0x08,0x10,0x18,0x04,0x04,0x02,0x02,0x01,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0xe0,0xa0,0x20,0x40,0x80,0xc0,0x20,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x3e,0x41,0xf0,0x04,0x02,0x02,0x02,0x03,0x02,0x02,0x02,0x04,
// 		0x04,0x02,0x01,0x00,0x00,0x00,0x04,0x00,0x40,0x40,0x55,0x82,0x7c,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x20,0x30,0x0c,0x02,0x05,0x09,0x12,0x1e,0x04,
// 		0x18,0x10,0x08,0x10,0x20,0x28,0x34,0x06,0x02,0x01,0x01,0x00,0x00,0x00,0x00,0x00
// #else
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0xc0,0x40,0x40,0x80,0x00,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x1e,0x3f,0xff,0xfb,0xfd,0xfd,0xfd,0xfd,0xfd,0xfc,0xfc,0xfc,
// 		0xfc,0xfe,0xff,0xff,0xfe,0xff,0xf7,0xff,0x7e,0x7f,0x57,0xfc,0xf8,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1f,0x3f,0x3f,0x3f,0x0f,0x1f,0x1f,0x03,0x07,
// 		0x1f,0x3f,0x3f,0x3f,0x0f,0x1f,0x1f,0x07,0x07,0x03,0x03,0x01,0x00,0x00,0x00,0x00
// 	}, {
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xc0,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0xe0,0xa0,0x20,0xc0,0x80,0xc0,0x20,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x3e,0x7f,0xf7,0xfb,0xfd,0xfd,0xfd,0xfd,0xfc,0xfc,0xfc,0xfc,
// 		0xfc,0xfe,0xff,0xff,0xff,0xff,0xfb,0xff,0xbf,0xbf,0xab,0xfe,0x7c,0x00,0x00,0x00,
// 		0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x3f,0x3f,0x0f,0x03,0x07,0x0f,0x1f,0x1f,0x07,
// 		0x1f,0x1f,0x0f,0x1f,0x3f,0x3f,0x37,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00
// #endif
// 	} };
//
// 	felix_current_frame = (felix_current_frame + 1) % FELIX_FRAMES;
// 	oled_write_raw_P(sneak[abs(1 - felix_current_frame)], FELIX_SIZE);
// }
//
// static void render_felix_status(void) {
//     oled_set_cursor(0, 107);
// 	void render_phase(void) {
// 		oled_clear();
// 		if (get_mods() & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock) { render_felix_bark(); }
// 		else if (get_mods() & MOD_MASK_CAG) { render_felix_sneak(); }
// 		else if (get_current_wpm() >MIN_RUN_SPEED && felix_typing) { render_felix_run(); }
// 		else if (get_current_wpm() >MIN_WALK_SPEED && felix_typing) { render_felix_walk(); }
// 		else { render_felix_sit(); }
//
// 		if (!(felix_anim_timer%2)) {
// 			if (get_current_wpm() >=felix_prev_wpm) {
// 				felix_prev_wpm = get_current_wpm();
// 				felix_typing = true;
// 			} else {
// 				felix_prev_wpm = get_current_wpm()+1;
// 				felix_typing = false;
// 			}
// 		}
// 	}
//
// 	if (get_current_wpm() >0 || get_mods() & MOD_MASK_CSAG) {
// 		oled_on();
// 		if (timer_elapsed32(felix_anim_timer) >FELIX_FRAME_DURATION) {
// 			felix_anim_timer = timer_read32();
// 			render_phase();
// 		}
// 		felix_anim_sleep = timer_read32();
// 	} else {
// 		if (timer_elapsed32(felix_anim_sleep) >OLED_TIMEOUT) {
// 			oled_off();
// 		} else {
// 			if (timer_elapsed32(felix_anim_timer) >FELIX_FRAME_DURATION) {
// 				felix_anim_timer = timer_read32();
// 				render_phase();
// 			}
// 		}
// 	}
// }
//
//
// void oled_task_user(void) {
//     render_felix_status();
// }

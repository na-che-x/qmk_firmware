#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0x0000
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    yunjieshi
#define PRODUCT         ya36

#define MATRIX_ROWS 4
#define MATRIX_COLS 10

// wiring
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3 }
#define MATRIX_ROW_PINS_RIGHT { D4, C6, D7, E6 }
#define MATRIX_COL_PINS_RIGHT { B3, B1, F7, F6, F5 }

#define SOFT_SERIAL_PIN D2
#define SPLIT_USB_DETECT

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

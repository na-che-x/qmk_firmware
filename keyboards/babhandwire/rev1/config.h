#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0x0000
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    perce
#define PRODUCT         babhandwire

#define MATRIX_ROWS 4
#define MATRIX_COLS 6

// wiring
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B5, D7, B4, E6, C6, D4 }

#define SOFT_SERIAL_PIN D1
#define SPLIT_USB_DETECT

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

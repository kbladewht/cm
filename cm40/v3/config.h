#pragma once


#define ENCODER_A_PINS { A8 } //M.2 
#define ENCODER_B_PINS { B13 } //M.2 
#define ENCODER_RESOLUTIONS { 2 }

#define QF_ADC_PIN B1

#define USB_PIN_LED B15
#define WK_PIN B9

#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B14

#define QF_LED_COUNT 38

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#undef RGBLED_NUM
#define RGBLED_NUM 38

#define POWER_PIN A1
#define POWER_LED -1

#define MATRIX_ROWS 5
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS     { A0, A3, A4, A5, A6 }
#define MATRIX_COL_PINS     { A15, B4, B5, B6, B7, C13, C14, C15}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_COUNT 32

#define SLEEP_MS 500

#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28
#define RGB_BLE_LED
// #define BLINK_BLE_LED

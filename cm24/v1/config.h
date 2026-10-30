#pragma once
// #define QF_COL_FAILING_EDGE_EVENT
#define ENCODER_A_PINS { B2 } //v3 A2
#define ENCODER_B_PINS { B12 } //v3 A3
#define ENCODER_RESOLUTIONS { 2 }

#define QF_ADC_PIN B1

//#define LED_CAPS_LOCK_PIN C5
#define USB_PIN_LED B15
#define WK_PIN B9
#define POWER_PIN A1
#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B14

#define QF_LED_COUNT 28

#undef RGBLED_NUM
#define RGBLED_NUM 28

#define POWER_LED -1

#define MATRIX_ROWS 4
#define MATRIX_COLS 7

#    define BACKLIGHT_PIN C11
#    define BACKLIGHT_LEVELS 9
#    define BACKLIGHT_LIMIT_VAL 220

#define MATRIX_ROW_PINS     { B7, C0, A0, A2 }
#define MATRIX_COL_PINS     { B8, D2, B4, B5, C12, C10, B3 }


#define SLEEP_MS 500


#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28
#define RGB_BLE_LED
// #define BLINK_BLE_LED

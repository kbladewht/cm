#pragma once
#define QF_COL_FAILING_EDGE_EVENT
#define ENCODER_A_PINS { A6 } 
#define ENCODER_B_PINS { A7 } 
#define ENCODER_RESOLUTIONS { 2 }

#define QF_ADC_PIN B1

//#define LED_CAPS_LOCK_PIN C5
#define USB_PIN_LED B15
#define WK_PIN B9
#define POWER_PIN A1
#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B14

#define QF_LED_COUNT 38

#undef RGBLED_NUM
#define RGBLED_NUM 38

#define POWER_LED -1

#define MATRIX_ROWS 5
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS     { A0, A2, A3, A4, A5 }
#define MATRIX_COL_PINS     { C10, C11, C12, D2, B4, B5, B8, B3 }


#define SLEEP_MS 60000


#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28
#define RGB_BLE_LED
// #define BLINK_BLE_LED

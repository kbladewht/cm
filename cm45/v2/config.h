#pragma once
#define QF_COL_FAILING_EDGE_EVENT
#define ENCODER_A_PINS { A2 } //M.2 PIN10
#define ENCODER_B_PINS { A3 } //M.2 PIN8
#define ENCODER_RESOLUTIONS { 2 }

#define QF_ADC_PIN B1

//#define LED_CAPS_LOCK_PIN C5
#define USB_PIN_LED B15
#define WK_PIN B9

#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B13

#define QF_LED_COUNT 67

#undef RGBLED_NUM
#define RGBLED_NUM 67

#define POWER_LED -1

#define MATRIX_ROWS 6
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS     { A8, A6, A5, A4, B0, B12 }
#define MATRIX_COL_PINS     { C12, D2, B8, B3, B6, B7, C0, C14}


#define SLEEP_MS 500


#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28
#define RGB_BLE_LED
// #define BLINK_BLE_LED
//#define RTT_DEBUG_QF

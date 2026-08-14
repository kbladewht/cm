#pragma once

#define SERIAL_USART_DRIVER SD2

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7

#define I2C1_ERRATA_FIX  // 如果使用STM32
#define OLED_I2C_TIMEOUT 1000
#define OLED_ENABLE_QF
#define OLED_DISPLAY_128X32


#define OLED_DISPLAY_128X32
#define OLED_FONT_H "keyboards/pivot/cm30/v1/f4/glcdfont.c"
#define OLED_TIMEOUT 5000
#define I2C1_TIMEOUT 5000  // I2C超时设置

#define OLED_BRIGHTNESS 40
#define OLED_UPDATE_INTERVAL 50
#define I2C1_CLOCK_SPEED 100000

#define ANIM_SIZE 512


#    define BACKLIGHT_PIN A0
#    define BACKLIGHT_LEVELS 9
#    define BACKLIGHT_LIMIT_VAL 220


#define ENCODER_A_PINS { C14, C1, C6 }
#define ENCODER_B_PINS { C15, C9, C7 }
#define ENCODER_RESOLUTION 2

#define QF_ADC_PIN B1

#define USB_PIN_LED B15
#define WK_PIN B9

#undef HAND_WIRE_DETECT
#define HAND_WIRE_DETECT B14

#define QF_LED_COUNT 53

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

#undef RGBLED_NUM
#define RGBLED_NUM 53


#define POWER_LED -1

#define MATRIX_ROWS 5
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS     { A3, B5, C8, A0, A2 }
#define MATRIX_COL_PINS     { B4, B3, B8, D2, C12, C10, C0, A5 }


#define SLEEP_MS 5000

#define RADIO_LED_INDEX 18
#define BLE1_LED_INDEX 15
#define BLE2_LED_INDEX 16
#define BLE3_LED_INDEX 17

#define CAPS_LED_INDEX 28 
#define RGB_BLE_LED

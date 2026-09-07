#include <stdint.h>
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "uart.h"
#include "dynamic_keymap.h"
#include "main_master.h"
#include "hal_pal.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
{ \
	{ QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC}, \
	{ KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, KC_NO}, \
	{ KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_LSFT, KC_NO, MO(1), MO(2), MO(3), KC_NO} \
},
{ \
	{ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL}, \
	{ KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO}, \
	{ KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, RGB_MODE_REVERSE, RGB_MODE_FORWARD, RGB_TOG, KC_NO}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_LSFT, KC_NO, MO(1), MO(2), MO(3), KC_NO} \
},
{ \
	{ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12}, \
	{ KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_SCLN, KC_QUOT, KC_ENT, KC_NO}, \
	{ KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, RGB_VAD, RGB_VAI, KC_SLSH, KC_NO}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_LSFT, KC_NO, MO(1), MO(2), MO(3), KC_NO} \
},
{ \
	{ QK_GESC, BL_SW_1, BL_SW_2, BL_SW_3, RADIO, ADC_SHOW, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL}, \
	{ KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, KC_NO}, \
	{ KC_CAPS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, BLE_DEL, KC_NO}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_NO, KC_LSFT, KC_NO, MO(1), MO(2), MO(3), KC_NO} \
}
};


void release_PB3_and_set_high(void)
{
    // 1. 禁用 SWO (TRACE_IOEN)
    DBGMCU->CR &= ~DBGMCU_CR_TRACE_IOEN;

    // 2. 禁用 STOP 模式下的 Debug (防止 Debug 模块占用 IO)
    DBGMCU->CR &= ~DBGMCU_CR_DBG_STOP;

    // 3. 将 PB3 设置为普通 GPIO 推挽输出
    GPIOB->MODER &= ~(0b11 << (3 * 2));  // 清除 PB3 模式
    GPIOB->MODER |=  (0b01 << (3 * 2));  // 设置 PB3 为输出模式

    // 4. 设置 PB3 为推挽输出类型
    GPIOB->OTYPER &= ~(1 << 3);          // 推挽

    // 5. 将 PB3 输出高电平
    GPIOB->ODR |= (1 << 3);
}
extern uint8_t tmp_max_sleep_one_time;
extern uint32_t        counterD ;

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
{ 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11},
{22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  NO_LED},
{23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  NO_LED},
{41,  40,  39,  38, NO_LED, NO_LED, 37, NO_LED, 36,  35,  34,  NO_LED}

    },
    {
      // LED Index to Physical Position
{0,0},{20,0},{40,0},{60,0},{80,0},{100,0},{122,0},{140,0},{160,0},{180,0},{200,0},{224,0},
{213,21},{185,21},{165,21},{145,21},{125,21},{105,21},{85,21},{65,21},{45,21},{25,21},{2,21},
{7,43},{35,43},{55,43},{75,43},{95,43},{115,43},{135,43},{155,43},{175,43},{195,43},{218,43},
{224,64},{200,64},{180,64},{143,64},{88,64},{47,64},{25,64},{2,64},
//U_RGB
{15,64},{65,64},{115,64},{165,64},{205,64},
{224,42},{224,21},
{200,0},{164,0},{125,0},{91,0},{56,0},{20,64},
{0,21},{0,42}
    },
    {
      // LED Index to Flag
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      //U_RGB
      2,  2,  2,  2,  2,  2,
      2,
      2,
      2,  2,  2,  2,  2,
      2,
      2

    }
};
bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(23, 255, 215, 0);
    }
    if (layer_state_is(1)) {
        rgb_matrix_set_color(36, 0, 255, 0);
        }
    if (layer_state_is(2)) {
        rgb_matrix_set_color(35, 0, 0, 255);
        }
    if (layer_state_is(3)) {
        rgb_matrix_set_color(34, 255, 255, 255);
        }
    return true;
}
#endif
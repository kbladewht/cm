#include <stdint.h>
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "uart.h"
#include "dynamic_keymap.h"
#include "main_master.h"
#include "hal_pal.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = { \
	{ KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RGB_TOG}, \
	{ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, MO(1)}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, KC_M}, \
    { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT}  \
},
  [1] = { \
	{ KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RGB_TOG}, \
	{ KC_GRV, BL_SW_1,BL_SW_2,BL_SW_3, RADIO, ADC_SHOW, KC_6}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, BLE_DEL}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, MO(1)}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, KC_M}, \
    { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT}  \
},
[2] = { \
	{ KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RGB_TOG}, \
	{ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, MO(1)}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, KC_M}, \
    { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT}  \
},
[3] = { \
	{ KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RGB_TOG}, \
	{ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSLS}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, MO(1)}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, KC_M}, \
    { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT}  \
}
};

extern uint8_t tmp_max_sleep_one_time;
extern uint32_t        counterD ;
// #ifdef ENCODERS_PAD_A
bool encoder_update_user(uint8_t index, bool clockwise) {
    xprintf("xxxxx clockwise %d\n", clockwise);
     tmp_max_sleep_one_time=8;
     counterD=0;
    return true;
}
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
{0,  1,  2,  3,  4,  5,  6,  NO_LED,},
{13,  12,  11,  10,  9,  8,  7,  NO_LED,},
{14,  15,  16,  17,  18,  19,  20,  21},
{29,  28,  27,  26,  25,  24,  23,  22},
{30,  31,  32,  33,  34,  35,  36,  37},
{44,  43,  42,  41,  NO_LED,   40,  39,  38}

    },
    {
      // LED Index to Physical Position
{0,0},{28,0},{56,0},{84,0},{112,0},{140,0},{168,0},
{168,12},{140,12},{112,12},{84,12},{56,12},{28,12},{0,12},
{6,25},{42,25},{60,25},{88,25},{116,25},{144,25},{172,25}, {214,25},
{218,38},{189,38},{161,38},{133,38},{105,38},{77,38},{49,38}, {9,38},
{13,51},{56,51},{84,51},{112,51},{140,51},{168,51},{196,51}, {222,51},
{222,64},{196,64},{168,64},          {115,64},{62,64},{34,64}, {3,64},
//U_RGB
       {208,64},
{190,62},      {222,62},
{190,60},      {222,60},
       {208,58},

      {25,64},{70,64},{115,64},{160,64},{195,64},
{0,48},                                        {224,48},
{0,32},                                        {224,32},
{0,16},                                        {224,16},
      {25,0}, {70,0}, {115,0}, {160,0},  {195,0}

    },
    {
      // LED Index to Flag
      4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4,
      //U_RGB
           4,
        4,    4,
        4,    4,
           4,
      2,2,2,2,2,
    2,          2,
    2,          2,
    2,          2,
      2,2,2,2,2
    }
};
bool rgb_matrix_indicators_user(void) {
   // if (host_keyboard_led_state().caps_lock) {
        //rgb_matrix_set_color(15, 255, 215, 0);
   //}
    if (layer_state_is(1)) {
        for(uint8_t i=45;
        i<51;i++)
        {rgb_matrix_set_color(i,0, 255, 0);}
        }
    if (layer_state_is(2)) {
        for(uint8_t i=45;
        i<51;i++)
        {rgb_matrix_set_color(i,0, 0, 255);}
        }
    if (layer_state_is(3)) {
        for(uint8_t i=45;
        i<51;i++)
        {rgb_matrix_set_color(i,255, 255, 255);}
        }
    return true;
};
#endif

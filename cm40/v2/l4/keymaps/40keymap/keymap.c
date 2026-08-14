#include QMK_KEYBOARD_H

#include "quantum.h"

#include "dynamic_keymap.h"
#include "main_master.h"
#include "hal_pal.h"



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  { \
	{ KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_DEL}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSPC}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_ENT}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, MO(1)}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT} \
},
{ \
	{ RGB_TOG, BL_SW_1,BL_SW_2,BL_SW_3, RADIO, ADC_SHOW, KC_6, BLE_DEL}, \
	{ USB_QF, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSPC}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_ENT}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, MO(1)}, \
	{ KC_LCTL, KC_LGUI, KC_LALT,KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT} \
},
{ \
	{ KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_DEL}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSPC}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_ENT}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, MO(1)}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT} \
},
{ \
	{ KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_DEL}, \
	{ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_BSPC}, \
	{ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_ENT}, \
	{ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_UP, MO(1)}, \
	{ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT} \
}
};
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
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


#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
{NO_LED,  0,  1,  2,  3,  4,  5,  6},
{14,  13,  12,  11,  10,  9,  8,  7},
{15,  16,  17,  18,  19,  20,  21,  22},
{30,  29,  28,  27,  26,  25,  24,  23},
{31,  32,  33,  34,  NO_LED,   35,  36,  37}
    },
    {
      // LED Index to Physical Position
       {31,0},{59,0},{87,0},{115,0},{143,0},{171,0},{224,0},
{209,16},{171,16},{143,16},{115,16},{87,16},{59,16},{31,16}, {0,16},   
{3,32},{39,32},{66,32},{94,32},{122,32},{150,32},{178,32}, {213,32},
{224,48},{192,48},{164,48},{136,48},{108,48},{81,48},{52,48}, {11,48},
{0,64},{31,64},{59,64},{112,64},             {164,64},{192,64}, {224,64}

    },
    {
      // LED Index to Flag
         4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4,    4, 4, 4
    }
};
bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) { 
        rgb_matrix_set_color(15, 255, 215, 0);
    }
    if (layer_state_is(1)) {
        rgb_matrix_set_color(0, 0, 255, 0);
        }
    if (layer_state_is(2)) {
        rgb_matrix_set_color(1, 0, 0, 255);
        }
    if (layer_state_is(3)) {
        rgb_matrix_set_color(2, 255, 255, 255);
        }
    return true;
}
#endif
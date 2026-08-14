#pragma once

#include <stdbool.h>
#include <stdint.h>
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

#define QF_RESET do { __set_FAULTMASK(1); NVIC_SystemReset(); } while (0)




typedef void (*TypeCallbackshort)(void);
typedef void (*TypeCallbacklong)(void);

uint8_t eeconfig_read_MANUAL_MODE_QF(void) ;
void eeconfig_write_MANUAL_MODE_QF(uint8_t from_mode);

uint8_t eeconfig_read_CURRENT_MODE(void) ;

void eeconfig_write_CURRENT_MODE(uint8_t from_mode);
void process_hold_keys_cb(bool hold_pressed,TypeCallbackshort short_cb,TypeCallbacklong long_cb);

void poll_hold_keys_scan(void);
void qf_bootloader_jump(void) ;


#define DUMP_HEX(data, len)                \
    do {                                   \
        for (uint8_t i = 0; i < (len); i++) { \
            xprintf("%02X ", (data)[i]);   \
        }                                  \
        xprintf("\n");                     \
    } while(0)

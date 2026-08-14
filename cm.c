#include "pivot.h"
#include "bootmagic.h"


void bootmagic_scan(void) {
    // We need multiple scans because debouncing can't be turned off.
    // matrix_scan();
    // wait_ms(BOOTMAGIC_DEBOUNCE);
    // matrix_scan();

    // if (bootmagic_should_reset()) {
    //     bootmagic_reset_eeprom();

    //     // Jump to bootloader.
    //     bootloader_jump();
    // }
}
#include "host_driver.h"
#include "report.h"
/* declarations */
uint8_t keyboard_leds(void);
void    send_keyboard(report_keyboard_t *report);
void    send_nkro(report_nkro_t *report);
void    send_mouse(report_mouse_t *report);
void    send_extra(report_extra_t *report);

// #include "main_master.h"
// host_driver_t chibios_driver_qf = {keyboard_leds, send_keyboard_qf, send_nkro,send_mouse, send_extra_qf};
// extern void host_set_driver(host_driver_t *d);
// void host_set_driver_qf(void) {
//     host_set_driver(&chibios_driver_qf);
// }

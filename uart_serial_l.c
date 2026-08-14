
#include "uart.h"
#include "quantum.h"
#include "outputselect.h"
#include "actionuart.h"


#ifndef UART_DRIVER
#    define UART_DRIVER SD1
#endif

#ifndef UART_TX_PIN
#    define UART_TX_PIN A9
#endif

#ifndef UART_TX_PAL_MODE
#    ifdef USE_GPIOV1
#        define UART_TX_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#    else
#        define UART_TX_PAL_MODE 7
#    endif
#endif

#ifndef UART_RX_PIN
#    define UART_RX_PIN A10
#endif

#ifndef UART_RX_PAL_MODE
#    ifdef USE_GPIOV1
#        define UART_RX_PAL_MODE PAL_MODE_INPUT
#    else
#        define UART_RX_PAL_MODE 7
#    endif
#endif

#ifndef UART_CTS_PIN
#    define UART_CTS_PIN A11
#endif

#ifndef UART_CTS_PAL_MODE
#    ifdef USE_GPIOV1
#        define UART_CTS_PAL_MODE PAL_MODE_INPUT
#    else
#        define UART_CTS_PAL_MODE 7
#    endif
#endif

#ifndef UART_RTS_PIN
#    define UART_RTS_PIN A12
#endif

#ifndef UART_RTS_PAL_MODE
#    ifdef USE_GPIOV1
#        define UART_RTS_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#    else
#        define UART_RTS_PAL_MODE 7
#    endif
#endif

#ifndef UART_CR1
#    define UART_CR1 0
#endif

#ifndef UART_CR2
#    define UART_CR2 0
#endif

#ifndef UART_CR3
#    define UART_CR3 0
#endif

#ifndef UART_WRDLEN
#    define UART_WRDLEN 3
#endif

#ifndef UART_STPBIT
#    define UART_STPBIT 0
#endif

#ifndef UART_PARITY
#    define UART_PARITY 0
#endif

#ifndef UART_ATFLCT
#    define UART_ATFLCT 0
#endif
static SerialConfig serialConfig = {
    SERIAL_DEFAULT_BITRATE,
    UART_CR1,
    UART_CR2,
    UART_CR3,
};


 static bool is_initialised = false;

 void set_init_raw(void){
    is_initialised = false;
 }
void uart_init(uint32_t baud) {


    if (!is_initialised) {
        is_initialised = true;

        serialConfig.speed = baud;

#if defined(USE_GPIOV1)
        palSetLineMode(SD1_TX_PIN, PAL_MODE_ALTERNATE_OPENDRAIN);
        palSetLineMode(SD1_RX_PIN, PAL_MODE_ALTERNATE_OPENDRAIN);
#else
        palSetLineMode(UART_TX_PIN, PAL_MODE_ALTERNATE(UART_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL);
        palSetLineMode(UART_RX_PIN, PAL_MODE_ALTERNATE(UART_RX_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
#endif
        sdStart(&UART_DRIVER, &serialConfig);
    }
}

#ifdef UART3_DEBUG_QF
#define UART_DRIVER3 SD3

void uart_init3(uint32_t baud) {

    serialConfig.speed = baud;

    // palSetLineMode(C4, PAL_MODE_ALTERNATE(UART_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL);
    // palSetLineMode(C11, PAL_MODE_ALTERNATE(UART_RX_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
    palSetLineMode(B10, PAL_MODE_ALTERNATE(UART_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL);
    palSetLineMode(C11, PAL_MODE_ALTERNATE(UART_RX_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);

    sdStart(&UART_DRIVER3, &serialConfig);
}
#endif

void uart_write(uint8_t data) { sdPut(&UART_DRIVER, data); }

uint8_t uart_read(void) {
    msg_t res = sdGet(&UART_DRIVER);

    return (uint8_t)res;
}

void uart_transmit(const uint8_t *data, uint16_t length)
{
     sdWrite(&UART_DRIVER, data, length);
 }

void uart_receive(uint8_t *data, uint16_t length) { sdRead(&UART_DRIVER, data, length); }

size_t uart_receive_timeout(uint8_t *data, uint16_t length,uint32_t  timeout_ms) {
    return   sdReadTimeout(&UART_DRIVER, data, length,TIME_MS2I(timeout_ms));
}

bool uart_available(void) { return !sdGetWouldBlock(&UART_DRIVER); }
uint32_t count_uart=0;
void uart_task(void){
// count_uart++;
 //raw_hid_receive(buffer, size);
    #ifndef DIS_RX_NRF
    if(!uart_available()){
        // if(count_uart % 1000 == 0){
        //     xprintf("uart_available is not avaible 000000 \n");
        // }
        return ;
    }
    //   xprintf("uart_available is true, start to read data 2222222\n");


         process_LED_status();
    #endif


}


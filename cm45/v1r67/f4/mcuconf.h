

#pragma once

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE


#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE


#undef STM32_PLLM_VALUE
#undef STM32_PLLN_VALUE
#undef STM32_PLLP_VALUE
#undef STM32_PLLQ_VALUE

#define STM32_PLLM_VALUE                    8
#define STM32_PLLN_VALUE                    120
#define STM32_PLLP_VALUE                    4
#define STM32_PLLQ_VALUE                    5  //Only for usb frequency

// #undef STM32_HPRE
// #undef STM32_PPRE1
// #undef STM32_PPRE2

// // AHB预分频器值。这个设置将系统时钟除以2以获得AHB时钟频率。
// #define STM32_HPRE                          STM32_HPRE_DIV2
// // APB1预分频器值。这个设置将AHB时钟频率除以4以获得APB1时钟频率。例如UART、I2C、SPI
// #define STM32_PPRE1                         STM32_PPRE1_DIV4
// // APB2预分频器值。这个设置将AHB时钟频率除以2以获得APB2时钟频率.APB2总线通常连接高速外设，例如ADC、USART、TIM等
// //在STM32微控制器中，GPIO (通用输入输出) 通常连接到APB2总线。因此，GPIO的配置受STM32_PPRE2预分频器的影响。
// #define STM32_PPRE2                         STM32_PPRE2_DIV2

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

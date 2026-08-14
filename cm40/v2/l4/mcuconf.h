/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include_next <mcuconf.h>

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 FALSE

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE


#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_PLLR_VALUE
#undef STM32_HPRE

#define STM32_PLLR_VALUE                    8
#define STM32_HPRE                          STM32_HPRE_DIV1


#undef STM32_PWM_USE_ADVANCED
#define STM32_PWM_USE_ADVANCED              TRUE


#undef STM32_ADC_USE_ADC1
#undef STM32_ADC_ADC1_DMA_PRIORITY
#undef STM32_ADC_IRQ_PRIORITY
#undef STM32_ADC_ADC1_DMA_IRQ_PRIORITY

#define STM32_ADC_USE_ADC1                  TRUE
#define STM32_ADC_ADC1_DMA_PRIORITY         2
#define STM32_ADC_IRQ_PRIORITY              6
#define STM32_ADC_ADC1_DMA_IRQ_PRIORITY     6


/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "mgos_ina219.h"

#ifdef __cplusplus
extern "C" {
#endif

// INA219 I2C address
#define MGOS_INA219_I2C_ADDR          (0x40)

// Registers
#define MGOS_INA219_REG_CONFIG        (0x00)
#define MGOS_INA219_REG_MANID         (0xfe)
#define MGOS_INA219_REG_DIEID         (0xff)
#define MGOS_INA219_REG_SHUNTVOLTS    (0x01)
#define MGOS_INA219_REG_BUSVOLTS      (0x02)
#define MGOS_INA219_REG_POWER         (0x03)
#define MGOS_INA219_REG_CURRENT       (0x04)
#define MGOS_INA219_REG_CALIB         (0x05)

#define MGOS_INA219_CONF_FSR_16V      (0)
#define MGOS_INA219_CONF_FSR_32V      (1 << 13)

enum mgos_ina219_conf_gain {
  DIV_1 = 0,    // 40 mV range
  DIV_2 = 1,    // 80 mV range
  DIV_4 = 2,    // 160 mV range
  DIV_8 = 3,    // 320 mV range, Default
};


enum mgos_ina219_conf_adc {
  ADC_9BIT_1X    = 0,  // 84 usec
  ADC_10BIT_1X   = 1,  // 184 usec
  ADC_11BIT_1X   = 2,  // 276 usec
  ADC_12BIT_1X   = 3,  // 532 usec, Default
  ADC_12BIT_2X   = 9,  // 1.06 msec
  ADC_12BIT_4X   = 10, // 2.13 msec
  ADC_12BIT_8X   = 11, // 4.26 msec
  ADC_12BIT_16X  = 12, // 8.51 msec
  ADC_12BIT_32X  = 13, // 8.51 msec
  ADC_12BIT_64X  = 14, // 8.51 msec
  ADC_12BIT_128X = 15, // 8.51 msec
};

#define MGOS_INA219_CONF_MODE_OFF                 (0)
#define MGOS_INA219_CONF_MODE_SINGLE_SHUNT        (1)
#define MGOS_INA219_CONF_MODE_SINGLE_BUS          (2)
#define MGOS_INA219_CONF_MODE_SINGLE_SHUNT_BUS    (3)
#define MGOS_INA219_CONF_MODE_POWERDOWN           (4)
#define MGOS_INA219_CONF_MODE_CONT_SHUNT          (5)
#define MGOS_INA219_CONF_MODE_CONT_BUS            (6)
#define MGOS_INA219_CONF_MODE_CONT_SHUNT_BUS      (7)

#define MGOS_INA219_DEFAULT_SHUNT_OHMS            (0.1) // Ohms

struct mgos_ina219 {
  struct mgos_i2c *i2c;
  uint8_t          i2caddr;
  float            shunt_resistance;
};

/* Mongoose OS initializer */
bool mgos_ina219_i2c_init(void);

#ifdef __cplusplus
}
#endif

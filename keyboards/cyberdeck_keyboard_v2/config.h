// Copyright 2024 Alex Seiger (@Alex Seiger)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP20
#define I2C1_SCL_PIN GP21

#define LED_PIN_ON_STATE 0
#define LED_CAPS_LOCK_PIN GP27

#define PIMORONI_TRACKBALL_SCALE 1
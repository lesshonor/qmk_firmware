/* Copyright 2021 Mike Tsao
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

// config.h

#pragma once

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0x45D4 // ID
#define PRODUCT_ID      0x1001
#define DEVICE_VER      0x0001
#define MANUFACTURER    MT
#define PRODUCT         NCRH 
#undef STM32_HSECLK
#define STM32_HSECLK 8000000

#define LED_SCROLL_LOCK_PIN A14
#define LED_CAPS_LOCK_PIN A8
#define LED_NUM_LOCK_PIN A0
#define LED_PIN_ON_STATE    0
// key matrix size
#define MATRIX_ROWS 6
#define MATRIX_COLS 18

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

#define MATRIX_ROW_PINS \
    { A1, A2, A3, A4, A5, A6 }
#define MATRIX_COL_PINS \
    { B0, B1, B2, B3 ,B4, B5, B6, B7, B8, B9, B10, B12, B13, B14, B15, C13, B11,A7 }

// COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW


#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
#define TAPPING_TOGGLE 2
// Want backlighting and RGB Matrix patterns? See the note in the readme,
// apply the patches, and then uncomment the line below as well as the ones
// in rules.mk.
//
// #define BACKLIGHT_PIN rgb_matrix
#define SOLENOID_PIN C14
#define SOLENOID_ACTIVE true
#define SOLENOID_DEFAULT_DWELL 20 

#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 7

// VIA lighting is handled by the keyboard-level code
#define VIA_CUSTOM_LIGHTING_ENABLE

#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 8
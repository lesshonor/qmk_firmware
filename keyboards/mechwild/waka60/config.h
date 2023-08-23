/*
Copyright 2021 Kyle McCreery

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define AUDIO_PIN B5
#define AUDIO_PWM_DRIVER PWMD3
#define AUDIO_PWM_CHANNEL 2
#define AUDIO_PWM_PAL_MODE 2

#define WS2812_PWM_DRIVER PWMD5
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM6
#define WS2812_DMA_CHANNEL 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// If you don't want to use one of these, #undef it in your keymap.
#define CAPS_LOCK_INDICATOR 0
#define MODIFIER_INDICATOR 1
#define LAYER_INDICATOR 2

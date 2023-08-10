// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#if defined(OLED_ENABLE)
#    if !defined(OLED_UPDATE_INTERVAL)
#        define OLED_UPDATE_INTERVAL 5
#    endif

#    if !defined(OLED_SECTION_BREAK)
#        define OLED_SECTION_BREAK "-----"
#    endif
#endif

#if defined(RGB_MATRIX_ENABLE)
    #if !defined(INDICATOR_MIN_SAT)
    #define INDICATOR_MIN_SAT 96
    #endif

    #if !defined(LIGHTING_FLAGS)
    #define LIGHTING_FLAGS (LED_FLAG_UNDERGLOW | LED_FLAG_INDICATOR)
    #endif
#endif

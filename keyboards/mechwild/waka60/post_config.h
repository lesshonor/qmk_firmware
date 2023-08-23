// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#if defined(RGB_MATRIX_ENABLE)
    #if !defined(INDICATOR_MIN_SAT)
    #define INDICATOR_MIN_SAT 96
    #endif

    #if !defined(LIGHTING_FLAGS)
    #define LIGHTING_FLAGS LED_FLAG_INDICATOR
    #endif
#endif

// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "waka60.h"
#include "keymap_introspection.h"

#if defined(RGB_MATRIX_ENABLE) && defined(RGB_INDICATORS_ENABLE)

/* TRACKERS */
static bool indicators_enabled                      = true;
static uint8_t orig_led_flags[RGB_MATRIX_LED_COUNT] = { 0 };
/* END TRACKERS */

uint8_t keymap_layer_count(void) {
#if defined(DYNAMIC_KEYMAP_ENABLE)
    return dynamic_keymap_get_layer_count();
#else
    return keymap_layer_count_raw();
#endif
}

/* BEGIN STANDARD QMK FUNCTIONS */
void keyboard_post_init_kb() {
    for(uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        orig_led_flags[i] = g_led_config.flags[i];
    }
    // Remove flags that are irrelevant.
    led_flags_t curr_lighting_mode = rgb_matrix_get_flags();
    if (HAS_ANY_FLAGS(curr_lighting_mode, (LIGHTING_FLAGS ^ LED_FLAG_ALL))) {
        rgb_matrix_set_flags_noeeprom(LIGHTING_FLAGS);
    }
    // g_led_config flags have been reset, so indicators won't darken
    process_lighting_mode(curr_lighting_mode);
    keyboard_post_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    int8_t offset;
    led_flags_t curr_lighting_mode;

    if (!process_record_user(keycode, record)) {
        return false;
    }
    curr_lighting_mode = rgb_matrix_get_flags();
    switch (keycode) {
        case C_LIGHF: // cycle lighting mode forward
        case C_LIGHB: // cycle lighting mode back
            if (record->event.pressed) {
                if (keycode == C_LIGHF && curr_lighting_mode < LIGHTING_FLAGS) {
                    offset = 1;
                } else if (keycode == C_LIGHB && curr_lighting_mode > LED_FLAG_NONE) {
                    offset = -1;
                } else {
                    break; // invalid, bail out
                }
                curr_lighting_mode += offset;
                while (HAS_ANY_FLAGS(curr_lighting_mode, (LIGHTING_FLAGS ^ LED_FLAG_ALL))) {
                    curr_lighting_mode += offset;
                }
                rgb_matrix_set_flags(curr_lighting_mode);
                process_lighting_mode(curr_lighting_mode);
            }
            break;
        case C_INDTG: // enable/disable indicator lighting
            if (record->event.pressed) {
                indicators_enabled ^= 1;
                process_lighting_mode(curr_lighting_mode);
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_kb(void) {
    if (!(rgb_matrix_indicators_user() && indicators_enabled)) {
        return false;
    }

    HSV base_hsv = rgb_matrix_config.hsv;
    // under certain parameters, the indicators won't be obvious enough
    if (base_hsv.s < INDICATOR_MIN_SAT) {
        base_hsv.s = INDICATOR_MIN_SAT;
    }
    if (base_hsv.v < RGB_MATRIX_VAL_STEP) {
        base_hsv.v = RGB_MATRIX_VAL_STEP;
    }
    uint8_t scaled_val = base_hsv.v / 3;

#if defined(CAPS_LOCK_INDICATOR) // CAPS LOCK INDICATOR
    if (host_keyboard_led_state().caps_lock) {
        RGB caps_clr;
        if (rgb_matrix_config.hsv.s > INDICATOR_MIN_SAT) {
            caps_clr = (RGB){ .r = scaled_val, .g = scaled_val, .b = scaled_val };
        } else {
            caps_clr = hsv_to_rgb(base_hsv);
        }
        rgb_matrix_set_color(CAPS_LOCK_INDICATOR, caps_clr.r, caps_clr.g, caps_clr.b);
    } else if (g_led_config.flags[CAPS_LOCK_INDICATOR] == LED_FLAG_NONE) {
        rgb_matrix_set_color(CAPS_LOCK_INDICATOR, 0, 0, 0);
    }
#endif // END CAPS LOCK INDICATOR

#if defined(MODIFIER_INDICATOR) // MODIFIER INDICATOR
    uint8_t curr_mods = get_mods() | get_oneshot_mods();
    if (curr_mods & MOD_MASK_CAG) {
        // If the modifer is not pressed, scaling relative to the current color's saturation level will look better than just setting 0.
        uint8_t scaled_sat = (scaled_val - ((uint16_t)scaled_val * base_hsv.s >> 8)) >> 1;
        RGB mod_clr = {
            // inexact but the bitshift results in higher matrix scan frequency than dividing by 255
            .r = (curr_mods & MOD_MASK_GUI) ? scaled_val : scaled_sat,
            .g = (curr_mods & MOD_MASK_ALT) ? scaled_val : scaled_sat,
            .b = (curr_mods & MOD_MASK_CTRL) ? scaled_val : scaled_sat
        };
        rgb_matrix_set_color(MODIFIER_INDICATOR, mod_clr.r, mod_clr.g, mod_clr.b);
    } else if (g_led_config.flags[MODIFIER_INDICATOR] == LED_FLAG_NONE) {
        rgb_matrix_set_color(MODIFIER_INDICATOR, 0, 0, 0);
    }
#endif // END MODIFIER INDICATOR

#if defined(LAYER_INDICATOR) // LAYER INDICATOR
    layer_state_t top_layer = get_highest_layer(layer_state | default_layer_state);
    // don't modify color on base layer
    if (top_layer > 0) {
        uint8_t layer_color_break = UINT8_MAX / keymap_layer_count();

        // Calculate hue shift
        uint8_t hue_change = layer_color_break * top_layer;
        base_hsv.h         = (hue_change + base_hsv.h) & 255;

        RGB layer_clr = hsv_to_rgb(base_hsv);
        rgb_matrix_set_color(LAYER_INDICATOR, layer_clr.r, layer_clr.g, layer_clr.b);
    } else if (g_led_config.flags[LAYER_INDICATOR] == LED_FLAG_NONE) {
        rgb_matrix_set_color(LAYER_INDICATOR, 0, 0, 0);
    }
#endif // LAYER INDICATOR

    return true;
}

/* END STANDARD QMK FUNCTIONS */

/* BEGIN CUSTOM HELPER FUNCTIONS FOR RGB */
void process_lighting_mode(led_flags_t curr_lighting_mode) {
    for(uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        g_led_config.flags[i] = (curr_lighting_mode & orig_led_flags[i]);
        if (g_led_config.flags[i] == LED_FLAG_NONE) {
            rgb_matrix_set_color(i, RGB_BLACK);
        }
    }
}
/* END CUSTOM HELPER FUNCTIONS FOR RGB */

#endif // RGB_MATRIX_ENABLE && RGB_INDICATORS_ENABLE

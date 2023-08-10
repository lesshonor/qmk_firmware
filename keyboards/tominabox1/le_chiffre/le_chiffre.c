// Copyright 2020 tominabox1 (@tominabox1)
// Copyright 2019 @foostan
// Copyright 2020 Drashna Jaelre <@drashna>
// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "le_chiffre.h"
#include "keymap_introspection.h"

#if defined(RGB_MATRIX_ENABLE) && defined(RGB_INDICATORS_ENABLE)

/* TRACKERS */
static bool indicators_enabled_kb                      = true;
static uint8_t orig_led_flags_kb[RGB_MATRIX_LED_COUNT] = { 0 };
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
        orig_led_flags_kb[i] = g_led_config.flags[i];
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
                indicators_enabled_kb ^= 1;
                process_lighting_mode(curr_lighting_mode);
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_kb(void) {
    if (!(rgb_matrix_indicators_user() && indicators_enabled_kb)) {
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
#endif // CAPS LOCK INDICATOR

#if defined(MODIFIER_INDICATOR) // MODIFIER INDICATOR
    uint8_t curr_mods = get_mods() | get_oneshot_mods();
    if (curr_mods & MOD_MASK_CAG) {
        // If the modifer is not pressed, scaling relative to the current color's saturation level will look better than just setting 0.
        uint8_t scaled_sat = (scaled_val - ((uint16_t)scaled_val * base_hsv.s >> 8)) >> 1;
        RGB mod_clr = {
            // inexact but the bitshift results in higher matrix scan frequency than dividing by 255, and AVR needs all the help it can get here
            .r = (curr_mods & MOD_MASK_GUI) ? scaled_val : scaled_sat,
            .g = (curr_mods & MOD_MASK_ALT) ? scaled_val : scaled_sat,
            .b = (curr_mods & MOD_MASK_CTRL) ? scaled_val : scaled_sat
        };
        rgb_matrix_set_color(MODIFIER_INDICATOR, mod_clr.r, mod_clr.g, mod_clr.b);
    } else if (g_led_config.flags[MODIFIER_INDICATOR] == LED_FLAG_NONE) {
        rgb_matrix_set_color(MODIFIER_INDICATOR, 0, 0, 0);
    }
#endif // MODIFIER INDICATOR

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
        g_led_config.flags[i] = (curr_lighting_mode & orig_led_flags_kb[i]);
        if (g_led_config.flags[i] == LED_FLAG_NONE) {
            rgb_matrix_set_color(i, RGB_BLACK);
        }
    }
}
/* END CUSTOM HELPER FUNCTIONS FOR RGB */

#endif // RGB_MATRIX_ENABLE

#if defined(OLED_ENABLE) // Special thanks to Sickbabies for this great OLED widget!

/* CONSTANTS */
const char PROGMEM code_to_name[53] = {
    'a', 'b', 'c', 'd', 'e', 'f',  'g', 'h', 'i',  'j',
    'k', 'l', 'm', 'n', 'o', 'p',  'q', 'r', 's',  't',
    'u', 'v', 'w', 'x', 'y', 'z',  '1', '2', '3',  '4',
    '5', '6', '7', '8', '9', '0',  'R', 'E', 'B',  'T',
    '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`',
    ',', '.', '/'
};

const char PROGMEM lechiffre_logo[96] = {
    // 'lechiffre_logo', 32x20px
    0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
    0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
    0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
    0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
    0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
    0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

const char PROGMEM oled_section_break[6] = OLED_SECTION_BREAK;
/* END CONSTANTS */

/* TRACKERS */
static char     keylog_str[KEYLOG_LEN] = {};
static uint16_t log_timer              = 0;
/* END TRACKERS */

/* BEGIN STANDARD QMK FUNCTIONS */

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
    oled_set_cursor(0, 3);
    oled_write_P(oled_section_break, false);
    render_layer_status(get_u8_str(get_highest_layer(layer_state | default_layer_state), ' '));
    oled_write_P(oled_section_break, false);
    render_mod_status(get_mods() | get_oneshot_mods());
    oled_write_P(oled_section_break, false);
    render_keylock_status(host_keyboard_led_state());
    return true;
}

/* END STANDARD QMK FUNCTIONS */
/* BEGIN CUSTOM HELPER FUNCTIONS FOR OLED */

/**
 * Sickbabies deserves credit for the original OLED implementation,
 * however most of the keylogging code appears to have been lifted from crkbd
 * -- which is why @foostan and @drashna are now credited here as well.
 *
 * Improvements were lifted from crkbd again in 2023, with gratitude.
 */
void add_keylog(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_MOD_TAP(keycode) && record->tap.count) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode) && record->tap.count) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_MODS(keycode)) {
        keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    }

    if (keycode >= KC_A && keycode < KC_CAPS) {
        keycode -= KC_A; // shift to first letter of alphabet
        for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
            keylog_str[i] = keylog_str[i - 1];
        }
        keylog_str[0] = pgm_read_byte(&(code_to_name[keycode]));
        keylog_str[KEYLOG_LEN - 1] = 0x00;
    }

    log_timer = timer_read();
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_advance_char();
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_advance_char();
    oled_write_P(PSTR("S"), led_state.scroll_lock);
}

void render_keylogger_status(void) {
    // zero out log after 30s idle time
    if (strlen(keylog_str) > 0 && timer_elapsed(log_timer) > 30000) {
        keylog_str[0] = 0x00;
        oled_advance_page(true);
        oled_advance_page(true);
    }
    oled_write(keylog_str, false);
}

void render_layer_status(const char* layer_name) {
    oled_write(layer_name, false);
    if (strlen(layer_name) < oled_max_chars()) {
        oled_advance_page(true);
    }
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
    oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}
#endif // OLED_ENABLE

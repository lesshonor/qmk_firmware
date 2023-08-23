// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

/**
 * Keyboard-level keycodes allow user to:
 * - Choose which lights are normally lit.
 * - Toggle RGB indicators for modifiers & layers.
 */
enum custom_kb_keycodes {
    C_LIGHF = QK_KB,
    C_LIGHB,
    C_INDTG
};

#if defined(RGB_MATRIX_ENABLE)
void process_lighting_mode(led_flags_t curr_lighting_mode);
#endif

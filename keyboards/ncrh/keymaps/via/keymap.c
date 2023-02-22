#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

LAYOUT_ortho_6x18( \
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8 ,   KC_9,   KC_0,   KC_MINS,   KC_EQL,KC_BSPC,KC_INS,KC_HOME,KC_NO,KC_NO, \
    KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,   KC_RBRC,KC_BSLS,KC_DEL,KC_END,KC_NO,KC_NO,  \
    KC_CAPS,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,   KC_ENT,KC_BSLS,KC_NO,KC_NO,KC_NO,KC_NO, \
    KC_LSFT,  KC_BSLS,   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,   KC_COMM,   KC_DOT,   KC_SLSH,   KC_RSFT,KC_RSFT,KC_UP,KC_NO,KC_NO,KC_NO,  \
    KC_LCTL, KC_LGUI, KC_LALT,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   MO(1),   KC_RALT,   KC_RGUI,   KC_RCTL,   KC_LEFT,   KC_DOWN,KC_RGHT,KC_PGDN,KC_PGUP,KC_NO,KC_NO),
LAYOUT_ortho_6x18( \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, \
    HF_ON,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,  \
    HF_TOGG,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO, \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,KC_VOLU,KC_NO,KC_NO,KC_NO,  \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE,   KC_VOLD,KC_MPLY,KC_NO,KC_NO,KC_NO,KC_NO),

};

#define MAGIC_BOOT 0x544F4F42UL
#define MAGIC_REG *(volatile uint32_t*)0x20004000
void bootloader_jump(void) {
    MAGIC_REG = MAGIC_BOOT;
    NVIC_SystemReset();
}

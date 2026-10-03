#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _LAYER4,
    _LAYER5
};

#define CORVO_TRANSPARENT_LAYER LAYOUT( \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______  \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
        KC_LGUI, KC_LALT, KC_LCTL, MO(1),   KC_SPC,  KC_ENT,                       KC_BSPC, MO(2),   KC_RCTL, KC_RALT, KC_RGUI, KC_DEL
    ),

    [_LOWER] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        _______, _______, _______, _______, _______, _______,                      _______, MO(3),   _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGUP, KC_PGDN, KC_INS,  KC_DEL,  KC_HOME, KC_END,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ESC,
        _______, _______, _______, MO(3),   _______, _______,                      _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,                      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_LAYER4] = CORVO_TRANSPARENT_LAYER,
    [_LAYER5] = CORVO_TRANSPARENT_LAYER
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [_LOWER]  = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_RAISE]  = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_ADJUST] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_LAYER4] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_LAYER5] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif

#ifdef OLED_ENABLE

#    include "oled_images.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 0);

    if (is_keyboard_left()) {
        oled_write_raw_P((const char *)oled_logo_left, sizeof(oled_logo_left));
    } else {
        oled_write_raw_P((const char *)oled_logo_right, sizeof(oled_logo_right));
    }

    return false;
}

#endif

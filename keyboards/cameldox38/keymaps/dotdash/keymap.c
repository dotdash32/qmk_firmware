// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _NAV_SIM,
    _NAV,
    _SYM,
    _NUM,
    _BLANK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │    │ Y │ U │ I │ P │ P │
     * ├───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │    │ H │ J │ K │ L │ B │
     * ├───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┤
     * |   │ Z │ X │ C │ V │    │ N │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┘

     *     ┌───┬───┬───┬───┐    ┌───┬───┬───┬───┐
     *     │LT1|LT2|LT3|LT4|    |RT4|RT3|RT2|RT1|
     *     └───┴───┴───┴───┘    └───┴───┴───┴───┘
     */
    [_QWERTY] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |             |             |             |              |             |
        KC_Q,         KC_W,         KC_E,           KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,          KC_O,         KC_P,
        LSFT_T(KC_A), LGUI_T(KC_S), LT(_SYM, KC_D), LCTL_T(KC_F), LALT_T(KC_G), LALT_T(KC_H), LCTL_T(KC_J), LT(_SYM,KC_K), LGUI_T(KC_L), RSFT_T(KC_B),
        KC_Z,         KC_X,           KC_C,         LGUI_T(KC_V), KC_B,         KC_N,         LGUI_T(KC_M), KC_COMM,       KC_DOT,       RSFT_T(KC_SLSH),
                      // Left then right Thumbs
                      KC_LALT,      LSFT_T(KC_SPC), LT(_NUM, KC_BSPC),  RGUI_T(KC_ESC),
                      RCTL_T(KC_ESC),  LT(_SYM, OS_RGUI), LT(_NAV, KC_SPC),  MO(_NAV_SIM)
                    ),

    [_NAV_SIM] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |              |                |                |                 |                 |
        _______,      _______,      QK_BOOT,        _______,      _______,       KC_PGUP,         KC_HOME,         KC_UP,            KC_END,           KC_DEL,
        _______,      _______,      _______,        KC_TRNS,      _______,       RALT_T(KC_PGDN), RCTL_T(KC_LEFT), LT(_SYM,KC_DOWN), RALT_T(KC_RIGHT), RSFT_T(KC_ENT),
        _______,      _______,      _______,        _______,      _______,       KC_MPRV,         KC_MNXT,         KC_MPLY,          KC_VOLU,          KC_VOLD,
                      _______,      _______,        _______,      _______,       _______,         _______,         _______,          _______
    ),
    [_NAV] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |               |                |                |                 |                 |
        KC_Q,         KC_BSPC,      KC_DEL,         KC_ESC,       KC_T,           KC_HOME,         KC_PGDN,         KC_PGUP,          KC_END,            KC_NO,
        LSFT_T(KC_A), LGUI_T(KC_S), LT(_SYM, KC_D), LCTL_T(KC_F), LALT_T(KC_TAB), RALT_T(KC_LEFT), RCTL_T(KC_DOWN), LT(_SYM,KC_UP),   RALT_T(KC_RIGHT),  RSFT_T(KC_ENT),
        KC_Z,         KC_X,         KC_C,           LGUI_T(KC_V), KC_B,           KC_LBRC,         RGUI_T(KC_RBRC), _______,          _______,           _______,
                      _______,      _______,        _______,      _______,        _______,         _______,      _______,       _______
    ),

    [_SYM] = LAYOUT_ortho_3x10_8(
    //  |             |             |             |             |             |             |             |             |                |
        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,            KC_0,
        _______,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_TRNS,      _______,      LGUI_T(KC_SCLN), RSFT_T(KC_QUOTE),
        KC_GRV,       KC_MINS,      KC_EQL,       KC_BSLS,      _______,      KC_LPRN,      KC_RPRN,      _______,      _______,      _______,
                      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_NUM] = LAYOUT_ortho_3x10_8(
    //  |             |             |             |             |             |             |             |             |             |
        _______,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_TRNS,      _______,      KC_SCLN,      KC_QUOTE,
        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,
        _______,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_TRNS,      _______,      KC_SCLN,      KC_QUOTE,
                      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
    [_BLANK] = LAYOUT_ortho_3x10_8(
    //  |             |             |             |             |             |             |             |             |             |
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_TRNS,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
                      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______
    ),
};

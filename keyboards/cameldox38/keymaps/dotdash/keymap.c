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
     * │ A │ S │ D │ F │ G │    │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │    │ N │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┘

     *     ┌───┬───┬───┬───┐    ┌───┬───┬───┬───┐
     *     │LT1|LT2|LT3|LT4|    |RT4|RT3|RT2|RT1|
     *     └───┴───┴───┴───┘    └───┴───┴───┴───┘
     */
    [_QWERTY] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |             |             |             |              |             |
        KC_Q,         KC_W,         KC_E,           KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,          KC_O,         KC_P,
        LSFT_T(KC_A), LGUI_T(KC_S), LT(_SYM, KC_D), LCTL_T(KC_F), LALT_T(KC_G), RALT_T(KC_H), RCTL_T(KC_J), LT(_SYM,KC_K), RALT_T(KC_L), RSFT_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,           LGUI_T(KC_V), KC_B,         RGUI_T(KC_N), KC_M,         KC_COMM,       KC_DOT,       KC_SLSH,
                      // Left then right Thumbs
                      KC_LALT,        KC_LSFT, LT(_NUM, KC_BSPC), LGUI_T(KC_ESC),
                      LALT_T(KC_ESC), KC_ENT,  LT(_NAV, KC_SPC),  MO(_NAV)
                    ),

    [_NAV_SIM] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |             |                |                |                 |                 |
        _______,      _______,      _______,        _______,      _______,      KC_PGUP,         KC_HOME,         KC_UP,            KC_END,           KC_DEL,
        _______,      _______,      _______,        KC_TRNS,      _______,      RALT_T(KC_PGDN), RCTL_T(KC_LEFT), LT(_SYM,KC_DOWN), RALT_T(KC_RIGHT), RSFT_T(KC_ENT),
        _______,      _______,      _______,        _______,      _______,      KC_MPRV,         KC_MNXT,         KC_MPLY,          KC_VOLU,          KC_VOLD,
                      _______,      _______,        _______,      _______,      _______,         _______,         _______,          _______
    ),
    [_NAV] = LAYOUT_ortho_3x10_8(
    //  |             |             |               |             |               |               |                |                 |                 |
        KC_Q,         KC_BSPC,      KC_DEL,         KC_ESC,      KC_T,            KC_HOME,        KC_PGDN,         KC_PGUP,          KC_END,            KC_NO,
        LSFT_T(KC_A), LGUI_T(KC_S), LT(_SYM, KC_D), LCTL_T(KC_F), LALT_T(KC_TAB), RALT_T(KC_LEFT), RCTL_T(KC_DOWN), LT(_SYM,KC_UP), RALT_T(KC_RIGHT), RSFT_T(KC_ENT),
        KC_Z,         KC_X,         KC_C,           LGUI_T(KC_V), _______,        _______,      _______,      _______,       _______,      _______,
                      _______,      _______,        _______,      _______,        _______,      _______,      _______,       _______
    ),

    [_SYM] = LAYOUT_ortho_3x10_8(
    //  |             |             |             |             |             |             |             |             |             |
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
        _______,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_TRNS,      _______,      _______,      KC_QUOTE,
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,
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

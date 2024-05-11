#include QMK_KEYBOARD_H
#include <stdio.h>
char wpm_str[10];

enum layers {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _Layer1,
    _Layer2,
    _Layer3,
    _Layer4
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PSSWD,
    PSSWD2,
};

#define L1_ENT LT(_Layer1, KC_ENT)
#define L2_ENT LT(_Layer2, KC_ENT)
#define L1_BSPC LT(_Layer1, KC_BSPC)
#define L2_SPC LT(_Layer2, KC_SPC)
#define Layer1 MO(_Layer1)
#define Layer2 MO(_Layer2)
#define Layer3 MO(_Layer3)
#define L3_ESC LT(_Layer3, KC_ESC)
#define L2_ESC LT(_Layer2, KC_ESC)

#define C_SCLN LCTL_T(KC_SCLN)
#define A_Q LALT_T(KC_Q)
#define G_J LGUI_T(KC_J)
#define S_K LSFT_T(KC_K)

#define S_M LSFT_T(KC_M)
#define G_W LGUI_T(KC_W)
#define A_V LALT_T(KC_V)
#define C_Z LCTL_T(KC_Z)

#define C_Z LCTL_T(KC_Z)
#define A_X LALT_T(KC_X)
#define G_C LGUI_T(KC_C)
#define S_V LSFT_T(KC_V)

#define S_M LSFT_T(KC_M)
#define G_COMM LGUI_T(KC_COMM)
#define A_DOT LALT_T(KC_DOT)
#define C_SLSH LCTL_T(KC_SLSH)

#define S_D LSFT_T(KC_D)
#define S_H LSFT_T(KC_H)

#define A_PIPE LALT_T(KC_PIPE)
#define G_LBRC LGUI_T(KC_LBRC)
#define S_RBRC LSFT_T(KC_RBRC)

#define SS1 SGUI(KC_4)
#define SS2 SGUI(KC_5)

#define WF A(KC_RIGHT)
#define WB A(KC_LEFT)

#define LF G(KC_RIGHT)
#define LB G(KC_LEFT)

#define SF S(KC_RIGHT)
#define SB S(KC_LEFT)

#define DLEFT C(KC_LEFT)
#define DRIGHT C(KC_RIGHT)

#define TABLEFT S(C(KC_TAB))
#define TABRIGHT C(KC_TAB)

#define BACK G(KC_LBRC)
#define FORWARD G(KC_RBRC)

#define C_GRV LCTL_T(KC_GRV)
#define C_DEL LCTL_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_65_with_macro(
    KC_F1, KC_F2,     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_MUTE,
    KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
    KC_F5, KC_F6,     L2_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGUP,
    KC_F7, KC_F8,     KC_LSFT, C_Z,     A_X,     G_C,     S_V,     KC_B, KC_N,    S_M,    G_COMM,  A_DOT,   C_SLSH,  KC_LSFT, KC_UP,                     KC_PGDN,
    KC_F9, KC_F10,    Layer1,  KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,       XXXXXXX, KC_SPC, KC_LGUI, KC_LALT, Layer3,  KC_LEFT, KC_DOWN,                   KC_RGHT
  ),

  [_COLEMAK] = LAYOUT_65_with_macro(
    KC_F1, KC_F2,     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_MUTE,
    KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
    KC_F5, KC_F6,     L2_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G, KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,                    KC_PGUP,
    KC_F7, KC_F8,     KC_LSFT, C_Z,     A_X,     G_C,     S_D,     KC_V, KC_K,    S_H,    G_COMM,  A_DOT,   C_SLSH,  KC_LSFT, KC_UP,                     KC_PGDN,
    KC_F9, KC_F10,    Layer1,  KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,       XXXXXXX, KC_SPC, KC_LGUI, KC_LALT, Layer3,  KC_LEFT, KC_DOWN,                   KC_RGHT
  ),

  [_DVORAK] = LAYOUT_65_with_macro(
    KC_F1, KC_F2,     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, XXXXXXX, KC_BSPC, KC_MUTE,
    KC_F3, KC_F4,     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y, KC_F,    KC_G,   KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,          KC_DEL,
    KC_F5, KC_F6,     L2_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I, KC_D,    KC_H,   KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,                    KC_PGUP,
    KC_F7, KC_F8,     KC_LSFT, C_SCLN,  A_Q,     G_J,     S_K,     KC_X, KC_B,    S_M,    G_W,     A_V,     C_Z,     KC_LSFT, KC_UP,                     KC_PGDN,
    KC_F9, KC_F10,    Layer1,  KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC,       XXXXXXX, KC_SPC, KC_LGUI, KC_LALT, Layer3,  KC_LEFT, KC_DOWN,                   KC_RGHT
  ),

  [_Layer1] = LAYOUT_65_with_macro(
    _______, _______,     PSSWD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_0,    _______, _______, _______, _______, _______,
    _______, _______,     PSSWD2,  _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_7,    KC_8,  KC_9,    KC_PAST, KC_PEQL, _______, _______,          _______,
    _______, _______,     KC_CAPS, _______, KC_BSLS, KC_LPRN, KC_RPRN, _______, KC_DOT,  KC_4,    KC_5,  KC_6,    KC_PPLS, KC_MINS, _______,                   _______,
    _______, _______,     _______, KC_LCTL, KC_PIPE,  G_LBRC,  S_RBRC, _______, KC_COMM, KC_1,    KC_2,  KC_3,    KC_PSLS, _______, _______,                   _______,
    _______, _______,     _______, _______, _______, _______, _______,          _______, _______, KC_0,  _______, _______, _______, _______,                   _______
  ),

  [_Layer2] = LAYOUT_65_with_macro(
    _______, _______,     _______, _______, _______, _______, SS1,     SS2,        _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______,     _______, KC_BTN1, _______, _______, _______, _______,    _______, BACK,    TABLEFT, TABRIGHT, FORWARD, _______, _______, _______,          _______,
    _______, _______,     _______, _______, _______, _______, _______, HYPR(KC_G), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, DLEFT,   DRIGHT,  _______,                   _______,
    _______, _______,     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,    LB,      WB,      WF,      LF,       _______, _______, _______,                   _______,
    _______, _______,     _______, _______, _______, _______, _______,             _______, _______, _______, _______,  _______, _______, _______,                   _______
  ),

  [_Layer3] = LAYOUT_65_with_macro(
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, KC_MS_U, KC_BTN1, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______, _______, _______,          _______,
    _______, _______,     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_TILD, KC_UNDS, _______,                   _______,
    _______, _______,     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_GRV,  _______, _______,                   _______,
    _______, _______,     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,                   _______
  ),

  [_Layer4] = LAYOUT_65_with_macro(
    _______, _______,     QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUD, RGB_HUI, _______, _______, _______, _______,          _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, _______,                   _______,
    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    _______, _______,     _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,                   _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _Layer1, _Layer3, _Layer4);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case PSSWD:
            if (record->event.pressed) {
                SEND_STRING("Zaibun786\n");
            }
            return false;
        case PSSWD2:
            if (record->event.pressed) {
                SEND_STRING("QadCha1@\n");
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1_ENT:
            return TAPPING_TERM - 110;
        case L2_ENT:
            return TAPPING_TERM - 110;
        case L3_ESC:
            return TAPPING_TERM - 110;
        default:
            return TAPPING_TERM;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

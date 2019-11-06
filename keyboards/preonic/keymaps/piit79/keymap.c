/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "piit79.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_preonic_1x2uC( \
        KC_GESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,      KC_8,     KC_9,     KC_0,    KC_BSPC, \
        THRD_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,      KC_I,     KC_O,     KC_P,    KC_DEL,  \
        LCTL_ESC,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOT, \
        KC_LSFT,   KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,  \
        CZECH,    KC_LCTL,  KC_LGUI,  KC_LALT,  LOWER,       NAV_SPC,         RAISE,    KC_LEFT,  KC_DOWN,   KC_UP,   KC_RGHT  \
    ),
    [_CZECH] = LAYOUT_preonic_1x2uC( \
        _______,  UC(0x11b),_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______  \
    ),
    [_LOWER] = LAYOUT_preonic_1x2uC( \
        KC_TILD,  KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,    KC_ASTR,   KC_LPRN,  KC_RPRN,  KC_BSPC, \
        KC_TILD,  KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,    KC_ASTR,   KC_LPRN,  KC_RPRN,  KC_DEL,  \
        KC_DEL,    KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_UNDS,    KC_PLUS,   KC_LCBR,  KC_RCBR,  KC_PIPE, \
        _______,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,   KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME,  KC_END,   _______, \
        _______,  _______,  _______,  _______,  _______,       KC_SPC,        _______,    KC_MPLY,   KC_VOLD,  KC_VOLU,  KC_MNXT  \
    ),
    [_RAISE] = LAYOUT_preonic_1x2uC( \
        KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,    KC_BSPC, \
        KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,    KC_DEL,  \
        KC_DEL,    KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS, \
        _______,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,   KC_F12,   KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN,  _______, \
        _______,  _______,  _______,  _______,  _______,       KC_SPC,        _______,  KC_MPLY,  KC_VOLD,  KC_VOLU,  KC_MNXT  \
    ),
    [_NAV] = LAYOUT_preonic_1x2uC( \
        KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGDN,   KC_UP,   KC_PGUP,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  _______,  KC_END,   _______,  _______, \
        _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______  \
    ),
    [_THIRD] = LAYOUT_preonic_1x2uC( \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  _______,  KC_END,   _______,  _______, \
        _______,  _______,  _______,  _______,  _______,       _______,       _______,  _______,  _______,  _______,  _______  \
    ),
    [_ADJ] = LAYOUT_preonic_1x2uC( \
        _______,  _______,  _______,  _______,  KC_POWER, _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
        _______,  _______,   DEBUG,   _______,  _______,  _______,  _______,  TERM_ON,  KC_VOLU,  _______,  _______,  KC_DEL,  \
        _______,  _______,   MU_MOD,   AU_ON,    AU_OFF,  AG_NORM,  AG_SWAP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  _______, \
        _______,   MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,    MI_OFF,  _______,  KC_VOLD,  _______,  _______,  _______, \
        _______,  _______,  _______,  _______,  _______,        KC_SPC,       _______,  _______,  _______,  VERSION,   RESET   \
    )
};

void encoder_update(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
}

void dip_update(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJ);
            } else {
                layer_off(_ADJ);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
                #ifdef AUDIO_ENABLE
                stop_all_notes();
                #endif
            }
    }
}

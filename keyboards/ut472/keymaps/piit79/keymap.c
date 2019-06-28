/* Copyright 2018 Carlos Filoteo
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
#include QMK_KEYBOARD_H

enum piit79_keycodes {
    LOWER = SAFE_RANGE,
    RAISE
};

enum piit79_layers {
	_BASE,
    _CZECH,
	_LOWER,
	_RAISE,
	_NAV,
	_THIRD,
	_ADJUST
};

// Keycode shortcuts
#define CTRL_ESC LCTL_T(KC_ESC)
#define CZECH MO(_CZECH)
#define NAV_SPC LT(_NAV,KC_SPC)
#define THRD_TAB LT(_THIRD, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Alt | Gui | App |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

[_BASE] = LAYOUT( \
    THRD_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   \
    CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
    CZECH,    KC_LCTL, KC_LGUI, KC_LALT, LOWER,     NAV_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT    \
),

[_CZECH] = LAYOUT( \
    _______,     _______,  _______,  _______,  _______,     _______,    _______,    _______,     _______,   _______,  _______,  _______, \
    _______,     _______,  _______,  _______,  _______,     _______,    _______,    _______,     _______,   _______,  _______,  _______, \
    _______,     _______,  _______,  _______,  _______,     _______,    _______,    _______,     _______,   _______,  _______,  _______, \
    _______,     _______,  _______,  _______,  _______,          _______,           _______,     _______,   _______,  _______,  _______  \
),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_LOWER] = LAYOUT( \
    KC_TILD,     KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,     KC_ASTR,   KC_LPRN,  KC_RPRN,  KC_DEL,  \
    KC_DEL,       KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,      KC_F6,      KC_UNDS,     KC_PLUS,   KC_LCBR,  KC_RCBR,  KC_PIPE, \
    _______,      KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,     KC_F12,   S(KC_NUHS),  S(KC_NUBS),  KC_HOME,  KC_END,   _______, \
    _______,     _______,  _______,  _______,  _______,          KC_SPC,            _______,     KC_MPLY,   KC_VOLD,  KC_VOLU,  KC_MNXT  \
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_RAISE] = LAYOUT(
    KC_GRV,       KC_1,     KC_2,     KC_3,     KC_4,       KC_5,        KC_6,       KC_7,        KC_8,      KC_9,     KC_0,    KC_DEL,  \
    KC_DEL,       KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,      KC_F6,      KC_MINS,     KC_EQL,    KC_LBRC,  KC_RBRC,  KC_BSLS, \
    _______,      KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,     KC_F12,     KC_NUHS,     KC_NUBS,   KC_PGUP,  KC_PGDN,  _______, \
    _______,     _______,  _______,  _______,  _______,          KC_SPC,            _______,     KC_MPLY,   KC_VOLD,  KC_VOLU,  KC_MNXT  \
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

[_NAV] = LAYOUT( \
    KC_GRV,      _______,  _______,  _______,  _______,     _______,    _______,    KC_PGDN,      KC_UP,    KC_PGUP,  _______,  _______, \
    _______,     _______,  _______,  _______,  _______,     _______,    _______,    KC_LEFT,     KC_DOWN,   KC_RGHT,  _______,  _______, \
    _______,     _______,  _______,  _______,  _______,     _______,    _______,    KC_HOME,     _______,   KC_END,   _______,  _______, \
    _______,     _______,  _______,  _______,  _______,          _______,           _______,     _______,   _______,  _______,  _______  \
),

[_THIRD] = LAYOUT( \
  _______, KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSCR, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______  \
),

[_ADJUST] = LAYOUT( \
  RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE, \
  _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,   \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,   \
  _______, _______, _______, KC_CAPS, _______,     _______,      _______, _______, _______, _______, _______    \
),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

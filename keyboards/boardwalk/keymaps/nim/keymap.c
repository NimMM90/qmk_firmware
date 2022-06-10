/*
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

// Layer shorthand
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define CAPW LCTL(LALT(KC_2))	        // Capture whole screen
#define CAPA LCTL(LALT(KC_3))  	        // Capture active window
#define CAPP LCTL(LALT(KC_4))           // Capture portion of screen
#define ALT_TAB LALT(KC_TAB)
#define TAB_NXT LCTL(KC_TAB)            // Go to next browser tab
#define TAB_PRV LSFT(LCTL(KC_TAB))   // Go to previous browser tab

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWE: Base Layer (Default Layer) */
  [_QWERTY] = LAYOUT_ortho_hhkb(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, KC_RBRC, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP, KC_RALT, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGDN, KC_SFTENT, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL, \
           LOWER,   RAISE, KC_LALT, KC_LGUI,       KC_SPC,         KC_BSPC,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT           \
  ),

  /* Keymap LOWER: Lower Layer */
  [_LOWER] = LAYOUT_ortho_hhkb(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_LCBR, KC_RCBR,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, \
  _______,   KC_P7,   KC_P8,   KC_P9,  KC_EQL, _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______, \
  _______,   KC_P4,   KC_P5,   KC_P6, KC_PLUS, _______, _______, _______, KC_UNDS, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU, _______, \
  _______,   KC_P1,   KC_P2,   KC_P3,   KC_P0, _______,  KC_END, _______, KC_PIPE,    CAPW,    CAPA,    CAPP, KC_VOLD, _______, \
           _______, _______, _______, _______,       XXXXXXX,       _______,       _______, _______, _______, _______
  ),

  /* Keymap RAISE: Raise Layer */
  [_RAISE] = LAYOUT_ortho_hhkb(
  _______,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16, _______, _______,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22, \
  _______, _______, _______, _______, _______, _______, TAB_NXT, _______, _______, _______, _______, _______, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_NLCK, _______, _______, KC_PAUS, KC_APP,  KC_INS,  TAB_PRV, _______, _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______,       _______,       XXXXXXX,       _______, _______, _______, _______
  ),
    /* Keymap ADJUST: ADJUST Layer */
    [_ADJUST] = LAYOUT_ortho_hhkb(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NK_TOGG, \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, _______, \
    _______, _______, RGB_M_G, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, RGB_M_K, RGB_M_X,  RGB_M_G, RGB_M_SN, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______,       _______,       XXXXXXX,       _______, _______, _______, _______
    ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

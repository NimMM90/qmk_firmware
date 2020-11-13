#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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

  [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LALT,  LOWER,   KC_SPC,                   KC_BSPC,KC_SFTENT,  RAISE
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_LOWER] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                           KC_RBRC,  KC_PLUS, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLU,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_P1,  KC_P2,   KC_P3,   KC_P4,  KC_DOWN, KC_LCBR, KC_LPRN,           KC_RPRN, KC_RCBR,  KC_PIPE,  CAPW,    CAPA,   CAPP,    KC_VOLD,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______,  _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                             KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       ALT_TAB, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_CAPS, _______, _______, _______, _______,  KC_INS,                            KC_EQL,  KC_UNDS, KC_HOME, KC_PGUP, TAB_NXT, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_NLCK, _______, _______, _______,  KC_APP, KC_PAUS, _______,          _______, KC_PLUS, KC_MINS, KC_END , KC_PGDN, TAB_PRV, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

      [_ADJUST] = LAYOUT(
      //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
          _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, NK_TOGG,
      //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, BL_STEP,                           RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, _______,
      //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
          _______, RGB_M_G, RGB_HUD, RGB_SAD, RGB_VAD, BL_TOGG,                           RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_SN, _______, _______,
      //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
          _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
      //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                          _______, _______, _______,                  _______, _______, _______
      //                                `--------+--------+--------'                `--------+--------+--------'
      )

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

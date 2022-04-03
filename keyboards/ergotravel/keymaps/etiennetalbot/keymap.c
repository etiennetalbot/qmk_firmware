#include QMK_KEYBOARD_H

#include "process_unicode.h"
#include "keymap_extras/keymap_canadian_multilingual.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MY_APPOS,
  MY_ACIRC,
  MY_ECIRC,
  MY_ICIRC,
  MY_OCIRC,
  MY_UCIRC,
  MY_SS,
};

// #define KC_ KC_TRNS
#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,           KC_VOLU, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MY_SS,            KC_VOLD, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MY_APPOS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS,          KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_F6  , KC_LALT, KC_LGUI,          LOWER,   KC_LSFT,          KC_SPC,  RAISE,    ALTGR(KC_SLASH), KC_LEFT, KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W, CSA_EGRV, S(KC_DOT), KC_EXLM, KC_LBRC,          KC_RBRC, CSA_QEST, CSA_SLSH, KC_7,  KC_8,    KC_9,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  CSA_AGRV, KC_S,   KC_D,    CSA_DCRC, CSA_DGRV, KC_A,           KC_A,    KC_ASTR, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z, KC_X, CSA_CCED, S(KC_MINS), ALTGR(KC_RBRC), KC_A,        KC_SPC,  KC_EQL,  KC_MINS, KC_1,    KC_2,    KC_3,    KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_F6  , KC_LALT, KC_LGUI,          LOWER,   KC_LSFT,          KC_SPC,  RAISE,            KC_0,    KC_COMM, KC_DOT,  KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_PGUP, _______, CSA_ECUT, KC_AMPR, KC_LPRN, KC_A,            KC_B, KC_RPRN, ALTGR(KC_MINS), _______, _______, _______, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_PGDN, _______,  _______, CSA_LESS, CSA_LCBR, KC_C,          KC_D,    CSA_RCBR, CSA_GRTR, KC_MPLY, KC_MNXT, KC_VOLU, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,   CSA_CCED, KC_MINS, CSA_LBRC, KC_A,            KC_SPC, CSA_RBRC, KC_PLUS, KC_MUTE, KC_MPRV, KC_VOLD, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_F1,   KC_F2,   MY_ECIRC, CSA_DTRM, KC_EXLM, KC_F6,            KC_F7,   KC_AT, MY_UCIRC, MY_ICIRC, MY_OCIRC, KC_F3, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  MY_ACIRC, KC_W,   KC_E,    KC_AMPR, KC_HASH, KC_C,             KC_D,    KC_DLR, ALTGR(KC_MINS), KC_F4, KC_F5, KC_F6, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_PERC, KC_A,          KC_SPC, CSA_DCRC, KC_M,    KC_F7,   KC_F8,   KC_F9,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_F10,  KC_F11,  KC_F12,  KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )

};





void matrix_init_user(void) {
  #if (defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE) || defined(UCIS_ENABLE))
    set_unicode_input_mode(UC_OSX);
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  inline void tap(uint16_t keycode) {
    register_code(keycode);
    unregister_code(keycode);
  };

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
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
    case MY_APPOS:
      if (!record->event.pressed) {
        register_code(KC_RSFT);
        tap(KC_COMMA);
        unregister_code(KC_RSFT);
      }
      break;
    case MY_ACIRC:
      if (!record->event.pressed) {
        tap(CSA_DCRC);
        tap(KC_A);
      }
      break;
    case MY_ECIRC:
      if (!record->event.pressed) {
        tap(CSA_DCRC);
        tap(KC_E);
      }
      break;
    case MY_ICIRC:
      if (!record->event.pressed) {
        tap(CSA_DCRC);
        tap(KC_I);
      }
      break;
    case MY_OCIRC:
      if (!record->event.pressed) {
        tap(CSA_DCRC);
        tap(KC_O);
      }
      break;
    case MY_UCIRC:
      if (!record->event.pressed) {
        tap(CSA_DCRC);
        tap(KC_U);
      }
      break;
    case MY_SS:
      if (!record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap(KC_4);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
  }
  return true;
}

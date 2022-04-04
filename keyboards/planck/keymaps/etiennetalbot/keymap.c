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

#include QMK_KEYBOARD_H
#include "planck.h"
#include "action_layer.h"
#include "process_unicode.h"
#include "keymap_extras/keymap_canadian_multilingual.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _ARROW,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MY_APPOS,
  EXT_PLV,
  MY_ACIRC,
  MY_ECIRC,
  MY_ICIRC,
  MY_OCIRC,
  MY_UCIRC,
  MY_SS3,
  MY_SS4,
  MY_SS5,
};

#define ARROW MO(_ARROW)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MTSHFTA MT(MOD_LSFT, KC_A)
#define MTSHFTSC MT(MOD_LSFT, KC_SCLN)
#define MTSHFTSP MT(MOD_LSFT, KC_SPC)
#define MTCTRLS MT(MOD_LCTL, KC_S)
#define MTCTRLL MT(MOD_LCTL, KC_L)
#define MTCTRLZ MT(MOD_LCTL, KC_Z)
#define MTALTD MT(MOD_LALT, KC_D)
#define MTALTK MT(MOD_LALT, KC_K)
#define MTALTX MT(MOD_LALT, KC_X)
#define MTCMDF MT(MOD_LGUI, KC_F)
#define MTCMDJ MT(MOD_LGUI, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |Lower |    Space    |Raise |Arrow |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,           KC_BSPC,
    KC_ESC,  MTSHFTA, MTCTRLS, MTALTD,  MTCMDF, KC_G,     KC_H,     MTCMDJ, MTALTK,  MTCTRLL, MTSHFTSC,       MY_APPOS,
    KC_LSFT, MTCTRLZ, MTALTX,  KC_C,    KC_V,   KC_B,     KC_N,     KC_M,   KC_COMM, KC_DOT,  ALGR(KC_SLASH), KC_ENT,
    _______, _______, _______, KC_LGUI, LOWER,  MTSHFTSP, MTSHFTSP, RAISE,  ARROW,   _______, _______,        _______
),

/* Arrow
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | ScSh3|      |      |  Up  |      |      |  F6  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Shift| Ctrl | Alt  | GUI  | ScSh4|      | Left | Down |Right |      |  F11 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Ctrl | Alt  |      |      | ScSh5|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROW] = LAYOUT_planck_grid(
    _______,  _______,  _______, _______,  _______,  MY_SS3,       _______,  _______,  KC_UP,   _______,  _______,  KC_F6,
    _______,  KC_LSFT,  KC_LCTL, KC_LALT,  KC_LGUI,  MY_SS4,       _______,  KC_LEFT,  KC_DOWN, KC_RGHT,  _______,  KC_F11,
    KC_LSFT,  KC_LCTL,  KC_LALT, _______,  _______,  MY_SS5,       _______,  _______,  _______, _______,  _______,  _______,
    _______,  _______,  _______, KC_LGUI,  _______,  KC_SPC,       KC_SPC,   _______,  _______, _______,  _______,  _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   È  |   "  |   !  |   ?  |   Ù  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   À  |      |      |   ^  |   `  |   *  |   +  |   4  |   5  |   6  |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   Ç  |   _  |   ~  |   =  |   -  |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | F11  |      |             |      |   0  |   ,  |   .  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,  _______,  _______, CA_EGRV, S(KC_DOT),  KC_EXLM,         CA_QUES, CA_SLSH, KC_7, KC_8,    KC_9,   KC_BSPC,
    _______,  CA_AGRV, _______, _______,  CA_CIRC,   CA_GRV,        KC_ASTR,  KC_PLUS,  KC_4, KC_5,    KC_6,   KC_EQL,
    _______,  _______,  _______, CA_CCED, S(KC_MINS), ALGR(KC_RBRC),  KC_EQL,   KC_MINS,  KC_1, KC_2,    KC_3,   KC_ENT,
    _______,   _______,  _______, KC_F11,  _______,    _______,         _______,  _______,  KC_0, KC_COMM, KC_DOT, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |Pg Up |      |   É  |   &  |  (   |   )  |   |  |  \   |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Pg Dn |      |      |   <  |  {   |   }  |   >  | Play | Next | Vol+ |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   Ç  |   -  |  [   |   ]  |   +  | Mute | Prev | Vol- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_PGUP, _______, CA_EACU,  KC_AMPR,  KC_LPRN,  KC_RPRN, ALGR(KC_MINS), CA_PIPE, _______, _______,  KC_DEL,
    _______, KC_PGDN, _______,  _______, CA_LABK, CA_LCBR, CA_RCBR, CA_RABK, KC_MPLY, KC_MNXT, KC_VOLU, _______,
    _______, _______, _______, CA_CCED,  KC_MINS, CA_LBRC, CA_RBRC,  KC_PLUS, KC_MUTE, KC_MPRV, KC_VOLD, _______,
    _______, _______, _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |   Ê  |  ¨   |  !   |  @   |  Û   |  Î   |  Ô   |  F3  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Â  |      |      |  &   |  #   |  $   |  |   |  F4  |  F5  |  F6  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |  %   |  ^   |      |  F7  |  F8  |  F9  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  F10 |  F11 |  F12 |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_F1,    KC_F2,   MY_ECIRC, CA_DIAE, KC_EXLM, KC_AT,    MY_UCIRC,       MY_ICIRC, MY_OCIRC, KC_F3,  _______,
    _______, MY_ACIRC, _______,   RGB_VAI,  KC_AMPR,  KC_HASH, KC_DLR,   ALGR(KC_MINS), KC_F4,    KC_F5,    KC_F6,  _______,
    _______, RGB_HUD,  RGB_SAD, RGB_VAD,  _______,  KC_PERC, CA_CIRC, _______,        KC_F7,    KC_F8,    KC_F9,  _______,
    _______, _______,  _______, _______,  _______,  _______, _______,  _______,        KC_F10,   KC_F11,   KC_F12, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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
        print("mode just switched to qwerty and this is a huge string\n");
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
    case MY_APPOS:
      if (!record->event.pressed) {
        register_code(KC_RSFT);
        tap(KC_COMMA);
        unregister_code(KC_RSFT);
      }
      break;
    case MY_ACIRC:
      if (!record->event.pressed) {
        tap(CA_CIRC);
        tap(KC_A);
      }
      break;
    case MY_ECIRC:
      if (!record->event.pressed) {
        tap(CA_CIRC);
        tap(KC_E);
      }
      break;
    case MY_ICIRC:
      if (!record->event.pressed) {
        tap(CA_CIRC);
        tap(KC_I);
      }
      break;
    case MY_OCIRC:
      if (!record->event.pressed) {
        tap(CA_CIRC);
        tap(KC_O);
      }
      break;
    case MY_UCIRC:
      if (!record->event.pressed) {
        tap(CA_CIRC);
        tap(KC_U);
      }
      break;
    case MY_SS3:
      if (!record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap(KC_3);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
    case MY_SS4:
      if (!record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap(KC_4);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
    case MY_SS5:
      if (!record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap(KC_5);
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
  }
  return true;
}

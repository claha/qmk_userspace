/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "claha.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     XXXXXXX,
    XXXXXXX,  HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,     KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,XXXXXXX,
    XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
                                  THUMB_L2, THUMB_L1, THUMB_L0, THUMB_R0, THUMB_R1, THUMB_R2
  ),

  [NAV] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
    XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_NO,    XXXXXXX,
    XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,   XXXXXXX,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [NUM] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,
    XXXXXXX,  KC_LSFT,  KC_NUHS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  XXXXXXX,
    XXXXXXX,  KC_RALT,  KC_DOT,   KC_RBRC,  KC_PLUS,  KC_NO,    KC_NO,    KC_LBRC,  KC_QUOT,  KC_SCLN,  KC_RALT,  XXXXXXX,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [SYM] = LAYOUT_split_3x6_3(
    XXXXXXX,  SE_BSLS,  SE_LABK,  SE_RABK,  SE_MINS,  SE_PIPE,  SE_CIRC,  SE_LCBR,  SE_RCBR,  SE_DLR,   SE_QUES,  XXXXXXX,
    XXXXXXX,  SE_EXLM,  SE_ASTR,  SE_SLSH,  SE_EQL,   SE_AMPR,  SE_HASH,  SE_LPRN,  SE_RPRN,  SE_SCLN,  SE_DQUO,  XXXXXXX,
    XXXXXXX,  SE_TILD,  SE_PLUS,  SE_LBRC,  SE_RBRC,  SE_PERC,  SE_AT,    SE_COLN,  SE_COMM,  SE_DOT,   SE_QUOT,  XXXXXXX,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [FUN] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   XXXXXXX,
    XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F11,   KC_F12,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
    XXXXXXX,  KC_NO,    KC_N,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [SYS] = LAYOUT_split_3x6_3(
    XXXXXXX,  QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
    XXXXXXX,  RM_TOGG,  RM_HUEU,  RM_SATU,  RM_VALU,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
    XXXXXXX,  RM_NEXT,  RM_HUED,  RM_SATD,  RM_VALD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,
                                  KC_NO,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO
  )
};

const uint16_t PROGMEM combo_capsword[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM combo_syslayer[] = {THUMB_R0, THUMB_R1, COMBO_END};
combo_t key_combos[] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_syslayer, MO(SYS)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SE_TILD:
    if (record->event.pressed) {
      register_code(KC_RALT);
      tap_code(SE_DIAE);
      unregister_code(KC_RALT);
      tap_code(KC_SPC);
    }
    return false;
  case SE_CIRC:
    if (record->event.pressed) {
      register_code(KC_LSFT);
      tap_code(SE_DIAE);
      unregister_code(KC_LSFT);
      tap_code(KC_SPC);
    }
    return false;
  }
  return true;
}

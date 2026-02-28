// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "claha.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_planck_mit(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     XXXXXXX,  XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,     XXXXXXX,  XXXXXXX,  KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  THUMB_L1, THUMB_L0, XXXXXXX,            THUMB_R0, THUMB_R1, XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [NAV] = LAYOUT_planck_mit(
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,    XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  XXXXXXX,            KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [NUM] = LAYOUT_planck_mit(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_LSFT,  KC_NUHS,  KC_NUBS,  KC_MINS,  KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,
    KC_RALT,  KC_DOT,   KC_RBRC,  KC_PLUS,  KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_LBRC,  KC_QUOT,  KC_SCLN,  KC_RALT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  XXXXXXX,            KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [SYM] = LAYOUT_planck_mit(
    SE_BSLS,  SE_LABK,  SE_RABK,  SE_MINS,  SE_PIPE,  XXXXXXX,  XXXXXXX,  SE_CIRC,  SE_LCBR,  SE_RCBR,  SE_DLR,   SE_QUES,
    SE_EXLM,  SE_ASTR,  SE_SLSH,  SE_EQL,   SE_AMPR,  XXXXXXX,  XXXXXXX,  SE_HASH,  SE_LPRN,  SE_RPRN,  SE_SCLN,  SE_DQUO,
    SE_TILD,  SE_PLUS,  SE_LBRC,  SE_RBRC,  SE_PERC,  XXXXXXX,  XXXXXXX,  SE_AT,    SE_COLN,  SE_COMM,  SE_DOT,   SE_QUOT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  XXXXXXX,            KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [FUN] = LAYOUT_planck_mit(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F11,   XXXXXXX,  XXXXXXX,  KC_F12,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TRNS,  KC_TRNS,  XXXXXXX,            KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [SYS] = LAYOUT_planck_mit(
    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    RM_TOGG,  RM_HUEU,  RM_SATU,  RM_VALU,  KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    RM_NEXT,  RM_HUED,  RM_SATD,  RM_VALD,  KC_NO,    XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,    KC_NO,    XXXXXXX,            KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )

};

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

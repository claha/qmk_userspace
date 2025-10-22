/* Copyright 2023
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
#include "keymap_swedish.h"
#include "gpio.h"

#define HOME_A SFT_T(KC_A)
#define HOME_S CTL_T(KC_S)
#define HOME_D GUI_T(KC_D)
#define HOME_F ALT_T(KC_F)
#define HOME_J ALT_T(KC_J)
#define HOME_K GUI_T(KC_K)
#define HOME_L CTL_T(KC_L)
#define HOME_SCLN SFT_T(KC_NO)

#define THUMB_L1 LT(4, KC_TAB)
#define THUMB_L0 LT(2, KC_SPC)
#define THUMB_R0 LT(5, KC_ENT)
#define THUMB_R1 LT(3, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,     KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                  THUMB_L1, THUMB_L0, THUMB_R0, THUMB_R1
),

[1] = LAYOUT(
    KC_Q,     KC_W,        KC_F,        KC_P,        KC_B,     KC_J,     KC_L,        KC_U,        KC_Y,        KC_NO,
    HOME_A,   CTL_T(KC_R), GUI_T(KC_S), ALT_T(KC_T), KC_G,     KC_M,     ALT_T(KC_N), GUI_T(KC_E), CTL_T(KC_I), SFT_T(KC_O),
    KC_Z,     KC_X,        KC_C,        KC_D,        KC_V,     KC_K,     KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,
                                        THUMB_L1,    THUMB_L0, THUMB_R0, THUMB_R1
),

[2] = LAYOUT(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
                                  KC_ESC,   KC_TRNS,  KC_TRNS,  KC_TRNS
),

[3] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_LSFT,  KC_NUHS,  KC_NUBS,  KC_MINUS, KC_NO,    KC_NO,    KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,
    KC_RALT,  KC_DOT,   KC_RBRC,  KC_PLUS,  KC_NO,    KC_NO,    KC_LBRC,  KC_QUOT,  KC_SCLN,  KC_RALT,
                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[4] = LAYOUT(
    KC_NO,    KC_NO,    SE_LABK,  SE_RABK,  SE_PIPE,  KC_NO,    SE_LCBR,  SE_RCBR,  KC_NO,    KC_NO,
    SE_TILD,  SE_ASTR,  SE_LBRC,  SE_RBRC,  KC_NO,    SE_QUOT,  SE_LPRN,  SE_RPRN,  SE_SCLN,  SE_DQUO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    SE_COMM,  SE_DOT,   SE_MINS,
                                  KC_NO,    KC_NO,    KC_TRNS,  KC_NO
),

[5] = LAYOUT(
    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    DF(0),    DF(1),    KC_NO,    KC_NO,
    RM_TOGG,  RM_HUEU,  RM_SATU,  RM_VALU,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    RM_NEXT,  RM_HUED,  RM_SATD,  RM_VALD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
)
};

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

const uint16_t PROGMEM combo_capsword[] = {KC_B, KC_N, COMBO_END};
combo_t key_combos[] = {
  COMBO(combo_capsword, CW_TOGG),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SE_TILD:
    if (record->event.pressed) {
      register_code(KC_RALT);
      tap_code(KC_RBRC);
      unregister_code(KC_RALT);
      tap_code(KC_SPC);
    }
    return false;
  }
  return true;
}

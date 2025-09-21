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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
      KC_ESC,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,             KC_Y,           KC_U,            KC_I,           KC_O,          KC_P,          KC_BSPC,
      KC_TAB,    SFT_T(KC_A),    CTL_T(KC_S),    GUI_T(KC_D),    ALT_T(KC_F),    KC_G,             KC_H,           ALT_T(KC_J),     GUI_T(KC_K),    CTL_T(KC_L),   SFT_T(KC_NO),  KC_ENT,
      KC_NO,     KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,             KC_N,           KC_M,            KC_COMM,        KC_DOT,        KC_SLSH,       KC_NO,
                                                 KC_NO,          LT(3, KC_TAB),  LT(1, KC_SPC),    KC_ENT,         LT(2, KC_BSPC),  KC_NO
  ),

    [1] = LAYOUT_split_3x6_3(
      KC_TRNS,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,         KC_NO,           KC_NO,    	    KC_NO,         KC_NO,         KC_TRNS,
      KC_TRNS,   KC_LSFT,        KC_LCTL,        KC_LGUI,        KC_LALT,        KC_NO,             KC_LEFT,       KC_DOWN,         KC_UP,    	    KC_RIGHT,      KC_NO,         KC_TRNS,
      KC_TRNS,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_HOME,       KC_PGDN,         KC_PGUP,  	    KC_END,        KC_NO,         KC_TRNS,
                                                 KC_TRNS,        KC_TRNS,        KC_TRNS,           KC_TRNS,       KC_TRNS,         KC_TRNS
  ),

    [2] = LAYOUT_split_3x6_3(
      KC_TRNS,   KC_1,           KC_2,           KC_3,           KC_4,           KC_5,              KC_6,         KC_7,             KC_8,           KC_9,          KC_0,          KC_TRNS,
      KC_TRNS,   KC_LSFT,        KC_NUHS,        KC_NUBS,        KC_MINUS,       KC_NO,             KC_NO,        KC_LALT,          KC_LGUI,        KC_LCTL,       KC_LSFT,       KC_TRNS,
      KC_TRNS,   KC_RALT,        KC_DOT,         KC_RBRC,        KC_PLUS,        KC_NO,             KC_NO,        KC_LBRC,          KC_QUOT,        KC_SCLN,       KC_RALT,       KC_TRNS,
                                                 KC_TRNS,        KC_ESC,         KC_TRNS,           KC_TRNS,      KC_TRNS,          KC_TRNS
  ),

    [3] = LAYOUT_split_3x6_3(
      KC_NO,    QK_BOOT,         KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,        KC_NO,            KC_NO,         KC_NO,         KC_NO,          KC_NO,
      KC_NO,    RM_TOGG,         RM_HUEU,        RM_SATU,        RM_VALU,        KC_NO,             KC_NO,        KC_NO,            KC_NO,         KC_NO,         KC_NO,          KC_NO,
      KC_NO,    RM_NEXT,         RM_HUED,        RM_SATD,        RM_VALD,        KC_NO,             KC_NO,        KC_NO,            KC_NO,         KC_NO,         KC_NO,          KC_NO,
                                                 KC_NO,          KC_TRNS,        KC_NO,             KC_NO,        KC_NO,            KC_NO
  )
};

const uint16_t PROGMEM combo_capsword[] = {KC_B, KC_N, COMBO_END};
combo_t key_combos[] = {
  COMBO(combo_capsword, CW_TOGG),
};

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_QUOT:  // å
    case KC_SCLN:  // ä
    case KC_RALT:  // ö
    case KC_SLSH:  // -
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

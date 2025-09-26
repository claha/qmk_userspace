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

#define QHME_L3 SFT_T(KC_A)
#define QHME_L2 CTL_T(KC_S)
#define QHME_L1 GUI_T(KC_D)
#define QHME_L0 ALT_T(KC_F)
#define QHME_R0 ALT_T(KC_J)
#define QHME_R1 GUI_T(KC_K)
#define QHME_R2 CTL_T(KC_L)
#define QHME_R3 SFT_T(KC_NO)

#define CHME_L3 SFT_T(KC_A)
#define CHME_L2 CTL_T(KC_R)
#define CHME_L1 GUI_T(KC_S)
#define CHME_L0 ALT_T(KC_T)
#define CHME_R0 ALT_T(KC_N)
#define CHME_R1 GUI_T(KC_E)
#define CHME_R2 CTL_T(KC_I)
#define CHME_R3 SFT_T(KC_O)

#define THMB_L1 LT(4, KC_TAB)
#define THMB_L0 LT(2, KC_SPC)
#define THMB_R0 KC_ENT
#define THMB_R1 LT(3, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   QHME_L3,  QHME_L2,  QHME_L1,  QHME_L0,  KC_G,     KC_H,     QHME_R0,  QHME_R1,  QHME_R2,  QHME_R3,  KC_ENT,
    XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  THMB_L1,  THMB_L0,            THMB_R0,  THMB_R1,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[1] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     XXXXXXX,  KC_BSPC,
    KC_TAB,   CHME_L3,  CHME_L2,  CHME_L1,  CHME_L0,  KC_G,     KC_M,     CHME_R0,  CHME_R1,  CHME_R2,  CHME_R3,  KC_ENT,
    XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  THMB_L1,  THMB_L0,            THMB_R0,  THMB_R1,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[2] = LAYOUT_planck_mit(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  _______,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______
),

[3] = LAYOUT_planck_mit(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_LSFT,  KC_NUHS,  KC_NUBS,  KC_MINS,  XXXXXXX,  XXXXXXX,  KC_LALT,  KC_LGUI,  KC_LCTL,  KC_LSFT,  _______,
    _______,  KC_RALT,  KC_DOT,   KC_RBRC,  KC_PLUS,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_QUOT,  KC_SCLN,  KC_RALT,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
),

[4] = LAYOUT_planck_mit(
    _______,  QK_BOOT,  _______,  _______,  _______,  _______,  _______,  DF(0),    DF(1),    _______,  _______,  _______,
    _______,  RM_TOGG,  RM_HUEU,  RM_SATU,  RM_VALU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RM_NEXT,  RM_HUED,  RM_SATD,  RM_VALD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______   
)

};

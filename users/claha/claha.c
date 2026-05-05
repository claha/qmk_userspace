#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

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

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case SE_LPRN: return SE_RPRN;  // ( -> )
        case SE_RPRN: return SE_LPRN;  // ) -> (
        case SE_LBRC: return SE_RBRC;  // [ -> ]
        case SE_RBRC: return SE_LBRC;  // ] -> [
        case SE_LCBR: return SE_RCBR;  // { -> }
        case SE_RCBR: return SE_LCBR;  // } -> {
        case SE_LABK: return SE_RABK;  // < -> >
        case SE_RABK: return SE_LABK;  // > -> <
    }
    return KC_TRNS;
}

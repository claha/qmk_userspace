#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 200

enum layer_names {
    BASE,
    NAV,
    NUM,
    SYM,
    FUN,
    SYS
};

#define HOME_A SFT_T(KC_A)
#define HOME_S CTL_T(KC_S)
#define HOME_D GUI_T(KC_D)
#define HOME_F ALT_T(KC_F)
#define HOME_J ALT_T(KC_J)
#define HOME_K GUI_T(KC_K)
#define HOME_L CTL_T(KC_L)
#define HOME_SCLN SFT_T(KC_NO)

#define THUMB_L2 KC_ESC
#define THUMB_L1 LT(SYM, KC_TAB)
#define THUMB_L0 LT(NAV, KC_SPC)
#define THUMB_R0 LT(FUN, KC_ENT)
#define THUMB_R1 LT(NUM, KC_BSPC)
#define THUMB_R2 KC_DEL

enum combos {
    COMBO_CAPSWORD,
    COMBO_SYSLAYER,
    COMBO_REPEAT_LEFT,
    COMBO_REPEAT_RIGHT,
    COMBO_ALT_REPEAT_LEFT,
    COMBO_ALT_REPEAT_RIGHT,
};

static const uint16_t PROGMEM combo_capsword[] = {KC_B, KC_N, COMBO_END};
static const uint16_t PROGMEM combo_syslayer[] = {THUMB_R0, THUMB_R1, COMBO_END};
static const uint16_t PROGMEM combo_repeat_left[] = {KC_W, KC_E, COMBO_END};
static const uint16_t PROGMEM combo_repeat_right[] = {KC_I, KC_O, COMBO_END};
static const uint16_t PROGMEM combo_alt_repeat_left[] = {KC_X, KC_C, COMBO_END};
static const uint16_t PROGMEM combo_alt_repeat_right[] = {KC_COMM, KC_DOT, COMBO_END};

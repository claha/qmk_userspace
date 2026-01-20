# Agent Instructions

## Critical Rules

### 1. ALWAYS Use Context7 MCP for QMK Documentation
Before implementing ANY QMK feature or using keycodes:
- Use the Context7 MCP tool to look up official QMK documentation
- Use it to find correct keycode names and syntax
- Use it to understand feature implementation details
- Do NOT guess or rely on memory for QMK-specific syntax

The Context7 MCP tool is your source of truth for:
- Keycode definitions (basic, modifiers, layer switching, etc.)
- QMK features (tap dance, combos, macros, leader key, etc.)
- Configuration options and available settings
- Correct function signatures and callbacks
- Feature-specific behaviors and requirements

### 2. ALWAYS Compile After Changes
After making ANY changes to keyboard configuration or keymap files, you MUST compile to verify the changes:
```bash
qmk compile -kb <keyboard_path> -km <keymap_name>
```

**Arguments:**
- `-kb <keyboard_path>`: Path to the keyboard (relative to QMK's keyboards directory)
  - Example: `crkbd/rev4_1/standard`
  - Look in the `keyboards/` folder to find available keyboard paths
- `-km <keymap_name>`: The keymap name (typically the username)
  - Example: `claha`

**Finding keyboard paths:**
All available keyboards are defined in the `keyboards/` folder. Check this folder to determine the correct path for the `-kb` argument.

This is not optional. Compile every single time you modify the code to catch errors immediately.

### 3. ALWAYS Follow Keymap Formatting Style
When writing or modifying keymap arrays, use this exact formatting style:
```c
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
};
```

**Formatting rules:**
- Each layer's keycodes must be aligned in columns
- Use consistent spacing between keycodes (align all keycodes to the longest one in each column)
- Keep one row per physical keyboard row
- Indent thumb cluster keys appropriately to show their separation
- Add a comma after each layer definition (including the last one for easier future additions)
- Keep the closing `);` on its own line

**Why this matters:**
This formatting makes the keymap visually represent the physical keyboard layout, making it much easier to understand and modify.

## Workflow
1. **Look up** the feature/keycode using Context7 MCP
2. **Implement** the changes in the appropriate files
3. **Format** the keymap following the alignment rules above
4. **Compile** to verify: `qmk compile -kb <keyboard_path> -km <keymap_name>`
5. **Fix** any compilation errors that appear
6. **Verify** successful compilation before considering the task complete

## Common QMK Elements to Look Up
- Keycodes (e.g., `KC_A`, `KC_LSFT`, `KC_TRNS`)
- Layer switching (e.g., `MO()`, `LT()`, `TG()`)
- Mod-tap keys (e.g., `MT()`, `LCTL_T()`)
- Features (tap dance, combos, leader key, auto shift)
- Configuration options in `config.h` and `rules.mk`

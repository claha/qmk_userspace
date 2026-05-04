---
name: qmk-workflow
description: Standard QMK development workflow including Context7 MCP lookup, edit, compile, and keymap formatting rules.
---

# QMK Development Workflow Skill

## Workflow

1. **Look up unknown features in Context7 MCP** – Before implementing new keycodes or features, search Context7 docs. No guessing.
2. **Implement changes** – Edit keymap or config files with proper formatting.
3. **Compile** – Run `qmk compile -kb <keyboard_path> -km <keymap_name>` after every change.
4. **Fix errors** – Address any compilation failures before proceeding.
5. **Verify formatting** – Ensure keymap follows the style guide below.

---

## Keymap Formatting Style

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HOME_A,   HOME_S,   HOME_D,   HOME_F,   KC_G,     KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                  THUMB_L1, THUMB_L0, THUMB_R0, THUMB_R1
),
};
```

**Rules:**
- Align keycodes in columns
- One row per physical keyboard row
- Indent thumb cluster keys to show separation
- Trailing comma on last layer definition

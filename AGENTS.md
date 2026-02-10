# Agent Instructions

## 🔴 MANDATORY COMMANDS

### After EVERY code change:
```bash
qmk compile -kb <keyboard> -km <keymap>
```
**Do this BEFORE committing or telling the user you're done.**

---

## Critical Rules

### 1. Use Context7 MCP for QMK docs
Before implementing any feature or keycodes, look them up in Context7 MCP. Do not guess.

### 2. Compile after every change
See command above. No exceptions.

### 3. Follow keymap formatting
Align keycodes in columns, one row per physical row. See full style guide at bottom of file.

---

## Workflow
1. Look up feature in Context7 MCP
2. Implement changes
3. **Compile** (`qmk compile -kb <keyboard> -km <keymap>`)
4. Fix any errors
5. Complete task

---

## ✅ Completion Checklist
Before responding "Done", verify:
- [ ] Code compiles without errors
- [ ] Keymap formatting follows style guide
- [ ] Context7 MCP was used for any new keycodes/features

---

## Appendix: Detailed Style Guide

### Keymap Formatting
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

### Compile Command Reference
```bash
qmk compile -kb <keyboard_path> -km <keymap_name>
```

- `-kb`: Path relative to `keyboards/` folder (e.g., `cheapino`, `crkbd/rev4_1/standard`)
- `-km`: Keymap name (typically username, e.g., `claha`)

### Common QMK Elements to Look Up
- Keycodes: `KC_A`, `KC_LSFT`, `KC_TRNS`
- Layer switching: `MO()`, `LT()`, `TG()`
- Mod-tap: `MT()`, `LCTL_T()`
- Features: tap dance, combos, macros, leader key

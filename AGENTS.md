# QMK Keymap Development

## Commands

### Compile
```bash
qmk compile -kb <keyboard_path> -km <keymap_name>
```
Run after every keymap change.

### Keyboards
Examples: `cheapino`, `crkbd/rev4_1/standard`

### Keymaps
Your username (e.g., `claha`)

## Testing
- Code compiles without errors
- Keymap formatting follows the style guide
- Used Context7 MCP for new keycodes/features

## Environment
- QMK firmware toolchain
- Context7 MCP for documentation lookups

## Workflow
The `qmk-workflow` skill defines the complete development workflow, keymap formatting rules, and QMK feature patterns.

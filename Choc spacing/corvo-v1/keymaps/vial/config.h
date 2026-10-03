#pragma once

#define VIAL_KEYBOARD_UID {0x43, 0x4F, 0x52, 0x56, 0x4F, 0x56, 0x31, 0x01}

/* Segure as duas teclas externas da fileira superior para desbloquear o Vial. */
#define VIAL_UNLOCK_COMBO_ROWS {0, 4}
#define VIAL_UNLOCK_COMBO_COLS {0, 0}

#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#undef DYNAMIC_KEYMAP_MACRO_COUNT
#define DYNAMIC_KEYMAP_MACRO_COUNT 30

/*
 * O RP2040 usa parte da flash como EEPROM virtual. A area fisica de 16 KiB
 * fornece 8 KiB logicos e preserva 32 Tap Dances, 32 Combos, 32 Key Overrides
 * e QMK Settings. Destes, exatamente 3072 bytes ficam reservados aos macros.
 */
#define WEAR_LEVELING_BACKING_SIZE 16384
#define WEAR_LEVELING_LOGICAL_SIZE 8192
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 3072

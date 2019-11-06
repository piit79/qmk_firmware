#include QMK_KEYBOARD_H

#include "version.h"
#ifdef AUDIO_ENABLE
    #include "muse.h"
#endif

#pragma once

// Layers
enum piit79_layers {
    _BASE,
    _CZECH,
    _LOWER,
    _RAISE,
    _NAV,
    _THIRD,
    _ADJ
};

// Keycode shortcuts
#define LCTL_ESC LCTL_T(KC_ESC)
#define CZECH TT(_CZECH)
#define NAV_SPC LT(_NAV, KC_SPC)
#define THRD_TAB LT(_THIRD, KC_TAB)

// Custom keycodes
enum piit79_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    VERSION,
    MAKE,
    SAFE_RANGE_KEYMAP   // To be used as the starting custom keymap-specific keycode
};

// Variables
extern bool muse_mode;
extern uint8_t last_muse_note;
extern uint16_t muse_counter;
extern uint8_t muse_offset;
extern uint16_t muse_tempo;

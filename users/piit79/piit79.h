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
    _ADJ,
    _FN1,
    _FN2
};

#undef C
#undef S
#define C(kc) LCTL(KC_##kc)
#define S(kc) LSFT(KC_##kc)

// Keycode shortcuts
#define LCTL_ESC LCTL_T(KC_ESC)
#define CZECH TT(_CZECH)
#define NAV_SPC LT(_NAV, KC_SPC)
#define FN1_WAKE LT(_FN1, KC_SYSTEM_WAKE)
#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define THRD_TAB LT(_THIRD, KC_TAB)

// Custom keycodes
enum piit79_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    SLEEP,
    WAKE,
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

#include "piit79.h"

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

__attribute__ ((weak))
void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
#endif
    eeconfig_init_keymap();
}


__attribute__ ((weak))
void matrix_init_keymap(void) {}

void matrix_init_user(void) {
    matrix_init_keymap();
}


__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
    matrix_scan_keymap();
}


__attribute__ ((weak))
bool music_mask_keymap(uint16_t keycode) {
    return true;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
    }
    return music_mask_keymap(keycode);
}


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJ);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJ);
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJ);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJ);
            }
            return false;
            break;

        case SLEEP:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SYSTEM_SLEEP));
            }
            return false;
            break;

        case WAKE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SYSTEM_WAKE));
            }
            return false;
            break;

        case VERSION:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;

        case MAKE:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP ":");
                #if defined(__arm__)  // only run for ARM boards
                    SEND_STRING(":dfu-util");
                #elif defined(BOOTLOADER_DFU) // only run for DFU boards
                    SEND_STRING(":dfu");
                #elif defined(BOOTLOADER_HALFKAY) // only run for teensy boards
                    SEND_STRING(":teensy");
                #elif defined(BOOTLOADER_CATERINA) // only run for Pro Micros
                    SEND_STRING(":avrdude");
                #endif // bootloader options
            }
            // Send reset_keyboard command instead of pressing reset button
            #if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
            //reset_keyboard();
            #endif
            return false;
            break;
    }
    return process_record_keymap(keycode, record);
};


__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
    return layer_state_set_keymap (state);
}


__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}

void led_set_user(uint8_t usb_led) {
   led_set_keymap(usb_led);
}


__attribute__ ((weak))
void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void)
{
    suspend_power_down_keymap();
}



__attribute__ ((weak))
void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void)
{
    suspend_wakeup_init_keymap();
}


__attribute__ ((weak))
void startup_keymap(void) {}

void startup_user (void) {
    startup_keymap();
}


__attribute__ ((weak))
void shutdown_keymap(void) {}

void shutdown_user (void) {
    shutdown_keymap();
}

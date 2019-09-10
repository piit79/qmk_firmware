#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

// Put normal config.h settings here:
#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_LNX, UC_OSX, UC_WINC

#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#endif // !USERSPACE_CONFIG_H

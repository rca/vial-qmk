/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// clang-format off

#pragma once

#ifdef OLED_ENABLE
#   define OLED_FONT_H "keyboards/splitkb/aurora/sofle_v2/glcdfont.c"
#endif

#define TAPPING_TERM 135

// trying out home row mods and need to setup permissive hold so that key presses
// don't assume i'm holding down the modifier key when typing fast
// https://docs.qmk.fm/tap_hold
#define PERMISSIVE_HOLD

// Vial Support
#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }

// Adding buffer for computer reboot.  You wont be able to get into bios with this delay.  remove if youd rather unplug/replug keyboard on reboot.
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// The four corners
//#define VIAL_UNLOCK_COMBO_ROWS { 0, 5, 3, 8 }
//#define VIAL_UNLOCK_COMBO_COLS { 0, 0, 0, 0 }

// The first two keys on the top left
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_LED_COUNT 72
#    define RGB_MATRIX_SPLIT \
        { 36, 36 }
#    define SPLIT_TRANSPORT_MIRROR

#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
#   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_BAND_SAT
#   define ENABLE_RGB_MATRIX_BAND_VAL
#   define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   define ENABLE_RGB_MATRIX_CYCLE_ALL
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   define ENABLE_RGB_MATRIX_RAINDROPS
#   define ENABLE_RGB_MATRIX_HUE_BREATHING
#   define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   define ENABLE_RGB_MATRIX_SPLASH
#   define ENABLE_RGB_MATRIX_SOLID_SPLASH
#   define RGB_MATRIX_RAINBOW_PINWHEELS
#   define RGB_MATRIX_FLOWER_BLOOMING
#   define RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_STARLIGHT
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#define ENABLE_RGB_MATRIX_RIVERFLOW

/**
 * define EE_HANDS in order to be able to plug the right half of the keyboard to the computer.
 * otherwise that half thinks it's the left side and the entire keyboard is a mirror image of
 * what it should be.
 *
 * in order to use this, each half of the firmware needs to be compile specifically for the
 * right or left halves:
 *
 * ```
 * qmk flash -kb sofle/rev1 -km berto -e CONVERT_TO=promicro_rp2040 -bl uf2-split-left
 * qmk flash -kb sofle/rev1 -km berto -e CONVERT_TO=promicro_rp2040 -bl uf2-split-right
 * ```
 */
#define EE_HANDS

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 127
#define RGB_MATRIX_DEFAULT_HUE 32
#define RGB_MATRIX_DEFAULT_SAT 127
#define RGB_MATRIX_DEFAULT_SPD 32

#endif

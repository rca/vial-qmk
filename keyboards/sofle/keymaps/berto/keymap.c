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

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"
#include "sofle_v2.c"

// Tap Dance declarations
enum {
    TD_ESC_CAPS_WORD,
    TD_TAB_LAYER_LOCK,
};

#define KC_L2_ENT            LT(2, KC_ENT)
#define KC_CAPS_WORD         0x7c73
#define KC_LAYER_LOCK        0x7c7b

// these are supposed to point to tapdance, but since using VIAL here, there is no way to setup tapdance
// in code without losing the ability to edit in the GUI
//#define KC_TD_ESC_CAPS_WORD  TD(TD_ESC_CAPS_WORD)
//#define KC_TD_TAB_LAYER_LOCK TD(TD_TAB_LAYER_LOCK)
#define KC_TD_ESC_CAPS_WORD  KC_ESC
#define KC_TD_TAB_LAYER_LOCK KC_TAB


// Tap Dance definitions
/*
tap_dance_action_t tap_dance_actions[VIAL_TAP_DANCE_ENTRIES] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS_WORD] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS_WORD),
};
*/


// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
//_______,               _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,
  KC_TD_ESC_CAPS_WORD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
  KC_TD_ESC_CAPS_WORD,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_TD_TAB_LAYER_LOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                              KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MUTE,       XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                   _______,  KC_LALT,  KC_LCTL,  KC_LGUI,  KC_LSFT,       KC_L2_ENT,KC_SPC,   MO(2),    _______,  _______
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
//_______,               _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,
  KC_TD_ESC_CAPS_WORD,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
  KC_TD_ESC_CAPS_WORD,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                              KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
  KC_TD_TAB_LAYER_LOCK,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,                              KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
  KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_MUTE,       XXXXXXX,  KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                   _______,  KC_LALT,  KC_LCTL,  KC_LGUI,  KC_LSFT,       KC_L2_ENT,KC_SPC,   MO(2),    _______,  _______
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BSPC  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   \  |   -  |   [  |   ]  | PGUP |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |DF(0) |DF(1) |MO(3) |      | PGDN |-------|    |-------|   =  |      |      |      |      | ENTER|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
//_______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                             KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
  KC_GRV,   KC_PIPE,  KC_MINS,  KC_LBRC,  KC_RBRC,  KC_PGUP,                           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
  _______,  DF(0),    DF(1),    MO(3),    MO(4),    KC_PGDN, _______,        _______,  KC_EQL,   _______,  _______,  _______,  _______,  KC_ENT,
                      _______,  _______,  _______,  _______, _______,        _______,  _______,  _______,  _______,  _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
//_______,  _______,  _______,  _______,  _______,  _______,                           _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                           _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                           _______,  KC_7,     KC_8,     KC_9,     KC_PAST,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                           KC_PDOT,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_MINS,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  KC_0,     KC_1,     KC_2,     KC_3,     KC_SLSH,  KC_PEQL,
                      _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______
),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};

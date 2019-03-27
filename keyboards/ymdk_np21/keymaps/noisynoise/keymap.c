#include QMK_KEYBOARD_H

#define _NP 0
#define _BL  1
#define _RGB 2

enum custom_keycodes {
  NP = SAFE_RANGE,
  BL,
  RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.
 * |   0  |   1  |   4  |   7  | NUM  | ESC  |
 * |------+------+------+------+------+------|
 * |   .  |   2  |   5  |   8  |   /  | TAB  |---,
 * |------+------+------+------+------+------|USB|
 * |  DOT |   3  |   6  |   9  |   *  | BS   |---'
 * |------+------+------+------+------+------|
 * | Enter| Enter|   +  |   +  |   -  | FN   |
 * `-----------------------------------------'
 */
[_NP] = LAYOUT( \
  KC_KP_0,     KC_KP_1,     KC_KP_4,    KC_KP_7,    KC_NUMLOCK,     RGB_MODE_FORWARD,    \
  KC_DOT,      KC_KP_2,     KC_KP_5,    KC_KP_8,    KC_KP_SLASH,    RGB_MODE_RAINBOW,    \
  KC_KP_DOT,   KC_KP_3,     KC_KP_6,    KC_KP_9,    KC_KP_ASTERISK, MO(_RGB), \
  KC_KP_ENTER, KC_KP_ENTER, KC_KP_PLUS, KC_KP_PLUS, KC_KP_MINUS,    MO(_BL)     \
),
/* Qwerty
 * ,---------------------------------------------.
 * | BL_BRTG |        |         |        |   |   |
 * |---------+--------+---------+--------+---+---|
 * |         | BL_OFF | BL_TOGG | BL_ON  |   |   |---,
 * |---------+--------+---------+--------+---+---|USB|
 * |         |        |         |        |   |   |---'
 * |---------+--------+---------+--------+---+---|
 * | BL_DEC  | BL_DEC | BL_INC  | BL_INC |   |   |
 * `---------------------------------------------'
 */
[_BL] = LAYOUT( \
  BL_BRTG, _______, _______, _______, _______, _______, \
  BL_BRTG, BL_OFF,  BL_TOGG, BL_ON,   _______, _______, \
  BL_BRTG, _______, _______, _______, _______, _______, \
  BL_DEC,  BL_DEC,  BL_INC,  BL_INC,  _______, _______  \
),
/* RGB
 * ,---------------------------------------------.
 * | RGB_TOG | RGB_HUI| RGB_SAI | RGB_VAI |   |   |
 * |---------+--------+---------+--------+---+---|
 * | RGB_TOG | RGB_HUD |RGB_SAD | RGB_VAD |   |   |---,
 * |---------+--------+---------+--------+---+---|USB|
 * | RGB_M_P | RGB_M_SW | RGB_M_SN | RGB_M_T |   |   |---'
 * |---------+--------+---------+--------+---+---|
 * | RGB_M_G  | RGB_M_G  |  RGB_M_B  | RGB_M_B |   |   |
 * `---------------------------------------------'
 */
[_RGB] = LAYOUT( \
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, \
  RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, \
  RGB_M_P, RGB_M_SW, RGB_M_SN, RGB_M_T, _______, _______, \
  RGB_M_G, RGB_M_G, RGB_M_B, RGB_M_B,  _______, _______  \
) };

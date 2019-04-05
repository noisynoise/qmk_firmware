#include QMK_KEYBOARD_H

#define _NP 0
#define _ROR 1


enum custom_keycodes {
  NP = SAFE_RANGE,
  ROR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Reversed numpad 
 * ,-----------------------------------------.
 * |  ent |   .  |   3  |   2  |  1   | ctrl |
 * |------+------+------+------+------+------|
 * |  ent |   *  |   6  |   5  |   4  | Shift|---,
 * |------+------+------+------+------+------|USB|
 * |   -  |   /  |   9  |   8  |   7  | TAB  |---'
 * |------+------+------+------+------+------|
 * |   0  |   0  |   +  |   +  |  num | TG(ROR)  |
 * `-----------------------------------------'
 */
[_NP] = LAYOUT( \
  KC_KP_ENTER, KC_KP_DOT, KC_KP_3, KC_KP_2, KC_KP_1, KC_LCTRL, \
  KC_KP_ENTER, KC_KP_ASTERISK, KC_KP_6, KC_KP_5, KC_KP_4, KC_LSHIFT, \
  KC_KP_MINUS, KC_KP_SLASH, KC_KP_9, KC_KP_8, KC_KP_7, KC_TAB, \
  KC_KP_0, KC_KP_0, KC_KP_PLUS, KC_KP_PLUS, KC_NUMLOCK, TG(_ROR) \
  ),
/* ROR 
 * ,-----------------------------------------.
 * |space |   V  |  C   |  X   |  W   | ctrl |
 * |------+------+------+------+------+------|
 * |space |   R  |   D  |   S  |   Q  | Shift|---,
 * |------+------+------+------+------+------|USB|
 * |   -  |   R  |   E  |   Z  |   A  | TAB  |---'
 * |------+------+------+------+------+------|
 * |   0  |   0  |   F  |   F  |  num | TG(ROR)  |
 * `-----------------------------------------'
 */
[_ROR] = LAYOUT( \
  KC_SPACE, KC_V, KC_C, KC_X, KC_Z, KC_LCTRL, \
  KC_SPACE, KC_R, KC_D, KC_S, KC_A, KC_LSHIFT, \
  KC_MINUS, KC_R, KC_E, KC_W, KC_Q, KC_TAB, \
  KC_KP_0, KC_KP_0, KC_F, KC_F, KC_NUMLOCK, TG(_ROR)  \
  )
};

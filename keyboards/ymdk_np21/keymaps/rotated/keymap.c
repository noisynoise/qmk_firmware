#include QMK_KEYBOARD_H

#define _NP 0
#define _ROR 1
#define _LED 2


enum custom_keycodes {
  NP = SAFE_RANGE,
  ROR,
  LED
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
 * |  MO(_LED)-0  |   +  |   +  |  num | TG(ROR)  |
 * `-----------------------------------------'
 */
[_NP] = LAYOUT( \
  KC_KP_ENTER, KC_KP_DOT, KC_KP_3, KC_KP_2, KC_KP_1, KC_LCTRL, \
  KC_KP_ENTER, KC_KP_ASTERISK, KC_KP_6, KC_KP_5, KC_KP_4, KC_LSHIFT, \
  KC_KP_MINUS, KC_KP_SLASH, KC_KP_9, KC_KP_8, KC_KP_7, KC_TAB, \
  MO(_LED), MO(_LED), KC_KP_PLUS, KC_KP_PLUS, KC_NUMLOCK, TG(_ROR) \
  ),
/* ROR 
 * ,-----------------------------------------.
 * |space |   V  |  C   |  X   |  W   | ctrl |
 * |------+------+------+------+------+------|
 * |space |   R  |   D  |   S  |   Q  | Shift|---,
 * |------+------+------+------+------+------|USB|
 * |   -  |   R  |   E  |   Z  |   A  | TAB  |---'
 * |------+------+------+------+------+------|
 * |   MO(_LED)-0|   F  |   F  |  num | TG(ROR)  |
 * `-----------------------------------------'
 */
[_ROR] = LAYOUT( \
  KC_SPACE, KC_V, KC_C, KC_X, KC_Z, KC_LCTRL, \
  KC_SPACE, KC_R, KC_D, KC_S, KC_A, KC_LSHIFT, \
  KC_MINUS, KC_R, KC_E, KC_W, KC_Q, KC_TAB, \
  MO(_LED), MO(_LED), KC_F, KC_F, KC_NUMLOCK, TG(_ROR)  \
  ),
/* LED mgmt layer - BL=> Backlit / RGB => underglow
 * ,---------------------------------------------.
 * |  | | |  |   |   |
 * |---------+--------+---------+--------+---+---|
 * |  | | | |   |   |---,
 * |---------+--------+---------+--------+---+---|USB|
 * |  |  |  |  |   |   |---'
 * |---------+--------+---------+--------+---+---|
 * |   |   |    |  |   |   |
 * `---------------------------------------------'
 */
[_LED] = LAYOUT( \
  _______, RGB_TOG, RGB_M_P,  RGB_M_SN,  RGB_M_SW, _______, 
  _______, BL_DEC, RGB_VAD, RGB_SAD, RGB_HUD, _______, \
  BL_BRTG, BL_INC, RGB_VAI, RGB_SAI, RGB_HUI, _______, \
  _______, _______, BL_TOGG, BL_TOGG, _______, _______  \
) 
};


// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#keyboard-post-initialization-code
void keyboard_post_init_user(void) {
  // Call the post init code.
//  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
//  rgblight_sethsv_noeeprom(255, 255, 255); // sets the color to teal/cyan without saving
//  rgblight_sethsv_cyan(); // sets the color to teal/cyan without saving
//  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
  rgblight_enable(); // Enable RGB by default

// list of colors : https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
  rgblight_sethsv_cyan();
//
// Changing one pecific led color (not working)
//  rgblight_sethsv_at(50, 200, 200, 0);
//
//  define rgb mode (working)
//  rgblight_mode(1); // set to solid by default
};

// Simple change layer => change RGB color
uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
  switch (biton32(state)) {
  case _NP:
    rgblight_sethsv_noeeprom_cyan();
    break;
  case _ROR:
    rgblight_sethsv_noeeprom_purple();
    break;
  case _LED:
    rgblight_sethsv_noeeprom_red();
    break;
  }
  return state;
#endif
}


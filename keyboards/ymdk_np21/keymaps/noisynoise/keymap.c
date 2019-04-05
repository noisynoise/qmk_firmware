#include QMK_KEYBOARD_H

#define _NP 0
#define _BL  1
#define _RGB 2
#define _TT 3
#define _ROR 4


enum custom_keycodes {
  NP = SAFE_RANGE,
  BL,
  RGB,
  TT
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
  KC_KP_0,     KC_KP_1,     KC_KP_4,    KC_KP_7,    KC_NUMLOCK,     TT(_ROR),    \
  KC_DOT,      KC_KP_2,     KC_KP_5,    KC_KP_8,    KC_KP_SLASH,    TT(_TT),    \
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
), 
/* TEST TT(layer)
 * ,---------------------------------------------.
 * | KC_A |  KC_Z      |         |  KC_A  |   |   |
 * |---------+--------+---------+--------+---+---|
 * |         | BL_OFF | BL_TOGG | KC_Z  |   |   |---,
 * |---------+--------+---------+--------+---+---|USB|
 * |         |        |         | KC_E   |   |   |---'
 * |---------+--------+---------+--------+---+---|
 * | BL_DEC  | BL_DEC | BL_INC  | BL_INC |   |   |
 * `---------------------------------------------'
 */
[_TT] = LAYOUT(\
  LCTL(KC_INS), KC_W, KC_Q, KC_A, _______, _______, \
  LCTL(KC_INS), KC_X, KC_S, KC_Z, _______, _______, \
  LGUI(KC_SPACE), KC_C, KC_D, KC_E, _______, _______, \
  LSFT(KC_INS), LSFT(KC_INS), LGUI(KC_1), LGUI(KC_1),  _______, _______  \
),
/* TEST TT(layer)
 * ,-----------------------------.
 * |  0  |  W |  Q  | A | NumOnOff  | TT  |
 * |     +----+----------+--------+---+---|
 * |  0  |  X  |  S  | Z |  T | TT        |---,
 * |-----+----+-----------+--------+--   -+---|USB|
 * |  V  |  C  | D  | E   | Y  | MO  |-- -'
 * |-----+----+-----------+-------+-+--  -|
 * |   Space      |   R        |  F   | MO    |
 * `-----------------------------------  -'
 */
[_ROR] = LAYOUT(\
  KC_KP_0, KC_Z, KC_A, KC_Q, _______, _______, \
  KC_KP_0, KC_X, KC_S, KC_W, KC_T, _______, \
  KC_V, KC_C, KC_D, KC_E, KC_Y, _______, \
  KC_SPACE, KC_SPACE, KC_R, KC_R, KC_F, _______  \
)
};


/* TEST RGB color / layer
 * https://www.reddit.com/r/olkb/comments/8bzipp/qmk_help_rgb_layers_and_additional_questions/
 */
// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls

uint8_t prev = _NP;
uint32_t check;
uint32_t desired = 9;

void matrix_init_user() {
	rgblight_mode(desired);
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_TT) {
	  switch (layer) {
		case _NP:
		  rgblight_mode(desired);
		  break;
		
		case _RGB: // If we're in swirl mode, then speed up the swirls, otherwise breathe
		  check = rgblight_get_mode();
		  if (check > 8 && check < 15) {
			rgblight_mode(14);
		  } else {
			rgblight_mode(5);
		  }
		  break;
		
		case _BL: // Same as above but reverse direction, otherwise nightrider
		  check = rgblight_get_mode();
		  if (check > 8 && check < 15) {
			rgblight_mode(13);
		  } else {
			rgblight_mode(23);
		  }
		  break;
		
		case _TT:
		  break;
	  }
  } else {
	  desired = rgblight_get_mode();
  }
  prev = layer;
  return state;
}

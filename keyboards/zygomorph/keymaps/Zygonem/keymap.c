#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ,
    _NUM,
    _MOVE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN,
  ADJ,
  RGBRST,
  NUM,
  MOVE
};

#define FN_CAPS  LT(_FN, KC_CAPS)

// Define your non-alpha grouping in this define's LAYOUT, and all your BASE_LAYERS will share the same mod/macro columns
  /*  / Base Layout \
   * /-----------------------------------------\  /-----------------------------------------\
   * | GESC |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | BkSp |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Tab  |      |      |      |      |      |  |      |      |      |      |      |   \  |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |FNCAPS|      |      |      |      |      |  |      |      |      |      |      |   '  |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |  |      |      |      |      |      |Shift |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space|  | Space|  FN  | Left | Down | Up   |Right |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
#define BASE_LAYOUT( \
  _00, _01, _02, _03, _04,  _05, _06, _07, _08, _09, \
  _10, _11, _12, _13, _14,  _15, _16, _17, _18, _19, \
  _20, _21, _22, _23, _24,  _25, _26, _27, _28, _29 \
) \
LAYOUT_5x12( \
      KC_TAB,  _00,    _01,     _02,     _03,     _04,    _05,     _06,     _07,     _08,     _09,     KC_BSPC, \
      KC_ESC, _10,     _11,     _12,     _13,     _14,    _15,     _16,     _17,     _18,     _19,     LT(_NUM,KC_QUOT), \
      KC_LSFT, _20,     _21,     _22,     _23,     _24,    _25,     _26,     _27,     _28,     _29,     KC_RSFT, \
      MOVE, KC_LCTL, KC_LALT, KC_LGUI,     ADJ,  KC_SPC,  KC_ENT,      FN,    MOVE, KC_RALT, KC_RCTL,    ADJ, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*  / QWERTY \
   * /-----------------------------------------\  /-----------------------------------------\
   * |      |      |      |      |      |      |  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   O  |   P  |   \  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |  |      |      |      |      |      |      |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_QWERTY] = BASE_LAYOUT( \
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH  \
  ),

  /*  / Colemak \
   * /-----------------------------------------\  /-----------------------------------------\
   * |      |      |      |      |      |      |  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   Q  |   W  |   F  |   P  |   G  |  |   J  |   L  |   U  |   Y  |   ;  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   A  |   R  |   S  |   T  |   D  |  |   H  |   N  |   E  |   I  |   O  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  |  |   K  |   M  |   ,  |   .  |   /  |      |
   * |------+------+------+------+------+------|  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |  |      |      |      |      |      |      |
   * \------+------+------+------+------+------/  \------+------+------+------+------+------/
   */
  [_COLEMAK] = BASE_LAYOUT( \
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
      KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    \
      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH  \
  ),

  /*  / FN \
   */
  [_FN] = LAYOUT_5x12( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
    
  /*  / NUM \
   */
  [_NUM] = LAYOUT_5x12( \
    RESET, _______, KC_PGUP,   KC_UP, KC_HOME,  KC_INS, _______, KC_P7, KC_P8, KC_P9,   KC_PSLS, _______, \
    _______, _______, KC_LEFT, _______, KC_RGHT, _______, _______, KC_P4, KC_P5, KC_P6,   KC_PAST, _______, \
    _______, _______, KC_PGDOWN,KC_DOWN, KC_END,  KC_APP, _______, KC_P1, KC_P2, KC_P3,   KC_PMNS, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_P0, KC_PDOT, KC_PPLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),    
 
  /*  / MOVE \
   */
  [_MOVE] = LAYOUT_5x12( \
  KC_MS_ACCEL2, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, KC_PGUP,   KC_UP,   KC_HOME, KC_INS,  _______, \
  RESET,        RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, KC_LEFT,   _______, KC_RGHT, _______, _______, \
  RGB_TOG,      RGB_M_P, RGB_M_R, RGB_M_SN, RGB_M_G, _______, _______, KC_PGDOWN, KC_DOWN, KC_END,  KC_APP,  _______, \
  _______,      RGB_M_B, RGB_M_SW, RGB_M_K, _______, _______, _______, _______,   _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  /*  / ADJ \
   */
  [_ADJ] =  LAYOUT_5x12( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if(record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;    
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      return false;
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
      } else {
        layer_off(_MOVE);
      }
      return false;
    case ADJ:
      if (record->event.pressed) {
        layer_on(_ADJ);
      } else {
        layer_off(_ADJ);
      }
      return false;
    case RGBRST:
#ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
#endif
      break;
  }
  return true;
}

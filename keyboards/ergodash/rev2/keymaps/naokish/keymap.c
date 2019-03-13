#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _CODING 8
#define _MOUSE 12
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  CODING,
  MOUSE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   \  |                    |   "  |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | EISU |                    |  Bksp|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Lower|  ALt |  GUI | Shift|||||||| Ctrl | Lower|   -  |||||||| Space| Raise|Coding|||||||| Shift|  GUI |  ALt | Lower|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_BSLS,                        KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT , \
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    EISU,                           KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    LOWER,   KC_LALT,KC_LGUI, KC_LSFT,          KC_RCTL, LOWER,  KC_MINS,      KC_SPC,   RAISE  , CODING,           KC_RSFT, KC_RGUI, KC_RALT, LOWER    \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |  F11 |  F12 | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |   |  |                    |   "  |   H  |   J  |   K  |  Up  |      | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |  ESC |                    |  Del |   N  |   M  | Left | Down | Right| Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Lower|  ALt |  GUI | Shift|||||||| Ctrl | Lower| EISU |||||||| Space| Raise|Coding|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  KC_BSPC, \
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PIPE,                        KC_DQT,  KC_H,    KC_J,    KC_K,    KC_UP,   _______, KC_ENT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,                         KC_DEL , KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, \
    LOWER,   KC_LALT, KC_LGUI, KC_LSFT,          KC_RCTL, LOWER,  EISU,         KC_SPC,   RAISE  , CODING,           KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |  (   |   )  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |   |  |                    |   "  | Left | Down |  Up  | Right|      | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |  ESC |                    |  Del |      |      |      |      |      | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Lower|  ALt |  GUI | Shift|||||||| Ctrl | Lower| EISU |||||||| Space| Raise|Coding|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PIPE,                        KC_DQT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ENT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,                         KC_DEL , _______, _______, _______, _______, _______, KC_RSFT, \
    LOWER,   KC_LALT, KC_LGUI, KC_LSFT,          KC_RCTL, LOWER,   EISU,        KC_SPC,   RAISE , CODING,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

    /* Coding
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |   _  |                    |   =  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   !  |   =  |   <  |                    |   >  |   (  |   )  |   ,  |   _  |  F12 | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   4  |   5  |   6  |   +  |   -  |   '  |                    |   "  |   {  |   }  |   .  |   :  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   7  |   8  |   9  |   *  |   /  |  ESC |                    |  Del |   [  |   ]  |   &  |   |  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Lower|  ALt |   0  | Shift|||||||| Ctrl | Lower|   -  |||||||| Space| Raise|Coding|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_CODING] = LAYOUT(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_UNDS,                        KC_EQL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_EXLM, KC_EQL,  KC_LT,                          KC_GT,   KC_LPRN, KC_RPRN, KC_COMM, KC_UNDS, KC_F12,  KC_BSPC, \
    KC_LCTL, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_MINS, KC_QUOT,                        KC_DQT,  KC_LCBR, KC_RCBR, KC_DOT,  KC_COLN, KC_SCLN, KC_ENT , \
    KC_LSFT, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, KC_ESC,                         KC_DEL , KC_LBRC, KC_RBRC, KC_AMPR, KC_PIPE, KC_QUES, KC_RSFT, \
    LOWER,   KC_LALT, KC_0, KC_LSFT,             KC_RCTL, LOWER,  KC_MINS,      KC_SPC,   RAISE,   CODING,           KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Mouse
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3,XXXXXXX,                       XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,XXXXXXX,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______,  _______,     _______,   _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD,  RGB_SAI,     RGB_VAD,   RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______,  _______,     _______,   _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,               _______,   _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
static bool coding_pressed = false;
static uint16_t coding_pressed_time = 0;
static bool right_ctl_pressed = false;
static uint16_t right_ctl_pressed_time = 0;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
        coding_pressed = false;
        right_ctl_pressed = false;

        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case CODING:
      if (record->event.pressed) {
        coding_pressed = true;
        coding_pressed_time = record->event.time;

        layer_on(_CODING);
        update_tri_layer(_LOWER, _CODING, _MOUSE);
      } else {
        layer_off(_CODING);
        update_tri_layer(_LOWER, _CODING, _MOUSE);

        if (coding_pressed && (TIMER_DIFF_16(record->event.time, coding_pressed_time) < TAPPING_TERM)) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        }
        coding_pressed = false;
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case KC_RCTL:
      if (record->event.pressed) {
        right_ctl_pressed = true;
        right_ctl_pressed_time = record->event.time;
        register_code(KC_RCTL);
      } else {
        unregister_code(KC_RCTL);
        if (right_ctl_pressed && (TIMER_DIFF_16(record->event.time, right_ctl_pressed_time) < TAPPING_TERM)) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
        right_ctl_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
        coding_pressed = false;
        right_ctl_pressed = false;
      }
      break;
  }
  return true;
}

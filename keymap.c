/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers{
    _DEFAULT,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _MACROPAD,
    _LAYER_NUM
};
char layers[_LAYER_NUM][6]={
    "BASE ",
    "LOWER",
    "RAISE",
    "ADJUS",
    "NUMPD",
    "MACRO"
};
int current_layer(void){
    for(int i=0;i<_LAYER_NUM;i++){
        if(layer_state_is(i)){
            return i;
        }
    }
    return -1;
}
#ifdef TAP_DANCE_ENABLE
enum tapdance_id{
    TD_LOWER_LAYER,
    TD_RAISE_LAYER
};
#endif
enum my_keycodes{
    MO_LOWER=0x5F10,
    MO_TO_DEFAULT
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, MO_LOWER,  KC_SPC,     KC_ENT, TD(TD_RAISE_LAYER), KC_RCTL
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,LCTL(KC_Q),   KC_MS_UP, KC_MS_BTN4,     KC_MS_BTN5, LCTL(KC_T),         KC_APP, KC_F7, KC_F8, KC_F9, KC_F10, KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_BTN1, KC_MS_BTN2,        KC_PGUP, KC_F4, KC_F5, KC_F6, KC_F11, KC_F14,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,LCTL(KC_Z), LCTL(KC_X),  LCTL(KC_C),    LCTL(KC_V), LCTL(KC_B),        KC_PGDN, KC_F1, KC_F2, KC_F3, KC_F12, KC_F13,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,  _______, MO_TO_DEFAULT, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F20,   KC_F21,   KC_F22,  KC_F23,   KC_F24,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F15,   KC_F16,   KC_F17,  KC_F18,   KC_F19,                      KC_BSPC,  KC_DEL, KC_HOME,  KC_END,  KC_GRV, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI,                      RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX,                      XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX,                      KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX,                      KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, KC_PDOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TG(_MACROPAD),  _______,    _______,_______, KC_COMM
                                      //`--------------------------'  `--------------------------'
  ),
  [_MACROPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  
}
bool should_process_keypress(void){
    return true;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_ln(layers[get_highest_layer(layer_state)],false);
    oled_write_ln_P(PSTR(" "),false);
}



char keylog_str[24] = {};
void set_keylog(uint16_t keycode, keyrecord_t *record) {
  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d\nKC:\n%2d",
           record->event.key.row, record->event.key.col,
           keycode);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

bool oled_task_user(void) {
    oled_render_layer_state();
    oled_render_keylog();
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  switch(keycode){
      case MO_LOWER:
        if(record->event.pressed){
            layer_on(_LOWER);
        }else{
            layer_off(_LOWER);
        }
        update_tri_layer(_LOWER,_RAISE,_ADJUST);
        break;
      case MO_TO_DEFAULT:
        if(record->event.pressed){
            layer_on(_RAISE);
            layer_off(_NUMPAD);
            layer_off(_MACROPAD);
        }else{
            layer_off(_RAISE);
        }
        update_tri_layer(_LOWER,_RAISE,_ADJUST);
        break;
  }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_default_layer[] = {RGBLIGHT_END_SEGMENTS};
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_CYAN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {33, 1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_CYAN},
    {33, 1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13,1,HSV_GOLD},
    {33, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_macropad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13,1,HSV_GOLD},
    {33, 1, HSV_RED}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_default_layer,
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer,
    my_numpad_layer,
    my_macropad_layer
);
void keyboard_post_init_user(void){
    rgblight_layers = my_rgb_layers;
}

#endif


#ifdef TAP_DANCE_ENABLE
enum {
  SINGLE_TAP,
  SINGLE_INTERRUPT,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_INTERRUPT,
  DOUBLE_HOLD,
  OTHER
};
typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap tap_state_raise = {
  .is_press_action = true,
  .state = -1,
};
int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
      if(state->interrupted){
          return SINGLE_INTERRUPT;
      }else if(!state->pressed){
          return SINGLE_TAP;
      }
      return SINGLE_HOLD;
  }
  else if (state->count == 2) {
      if(state->interrupted){
          return DOUBLE_INTERRUPT;
      }else if(!state->pressed){
          return DOUBLE_TAP;
      }
      return DOUBLE_HOLD;
  }
  else return OTHER;
}
void tap_finished_raise(qk_tap_dance_state_t *state, void *user_data) {
  tap_state_raise.state = cur_dance(state);
  switch (tap_state_raise.state) {
    case SINGLE_TAP:
    case SINGLE_INTERRUPT:
    case SINGLE_HOLD:
    case OTHER:
        layer_on(_RAISE);
        update_tri_layer(_LOWER,_RAISE,_ADJUST);
        break;
    case DOUBLE_TAP:
    case DOUBLE_INTERRUPT:
    case DOUBLE_HOLD:
        layer_on(_NUMPAD);
        break;
  }
}
void tap_reset_raise(qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_state_raise.state) {
    case SINGLE_TAP:
    case SINGLE_INTERRUPT:
    case SINGLE_HOLD:
    case OTHER:
        layer_off(_RAISE);
        update_tri_layer(_LOWER,_RAISE,_ADJUST);
    case DOUBLE_INTERRUPT:
    case DOUBLE_HOLD:
        layer_off(_NUMPAD);
        layer_off(_MACROPAD);
        break;
    case DOUBLE_TAP:
        break;
  }
  tap_state_raise.state = -1;
}
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RAISE_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, tap_finished_raise, tap_reset_raise)
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef RGBLIGHT_ENABLE
    for(int i=0;i<_LAYER_NUM;i++){
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    #endif
    return state;
}
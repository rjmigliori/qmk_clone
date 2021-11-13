#include QMK_KEYBOARD_H

enum custom_keycodes {
  TAB_LEFT = SAFE_RANGE,
  TAB_RIGHT,
  WIN_RIGHT, 
  WIN_LEFT,
};

// Tap Dance declarations 
enum  tapdance_actions {
    EB, //TD_ESC_BACKTICK
};

// Tap Dance Definitions 
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Escape, twice for backtick (`)
    [EB] = ACTION_TAP_DANCE_DOUBLE(KC_ESC,KC_GRV),
};

/* LAYOUT 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │1.5U │   │   │   │   │   │   │   │   │   │   │   │   │1.5U │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │1.75U │   │   │   │   │   │   │   │   │   │   │   │2.25U   │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │2.25U   │   │   │   │   │   │   │   │   │   │   │1.75U │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴──┬───┼───┼───┤
 * │1.25│1.25│1.25│6.25U                   │1.5U │1.5U │1U │1U │1U │
 * └────┴────┴────┴────────────────────────┴─────┴─────┴───┴───┴───┘
 */

    // /* Physical/Visual */
    // [0] = LAYOUT_all(
    //     KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO, KC_HOME,
    //     KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    //     KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_NO, KC_ENT, KC_O,
    //     KC_LSFT, KC_NO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_RSFT, KC_UP, KC_MINS,
    //     KC_LCTRL, KC_LGUI, KC_LALT, KC_NO,KC_SPC,          KC_NO, KC_RALT,                         KC_NO, KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT), 


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer 0: qwerty */
    [0] = LAYOUT_all(
        TD(EB),  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, _______, TAB_RIGHT,
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TAB_LEFT,
        KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, _______, KC_ENT, KC_O,
        KC_LSFT, _______,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_RSFT, KC_UP, MO(1),
        KC_LCTRL, KC_LGUI, KC_LALT, _______,KC_SPC,          _______, KC_RALT,                         _______, MO(2), KC_LEFT, KC_DOWN, KC_RGHT), 

    /* layer 1: Functions */
    [1] = LAYOUT_all(
        KC_ESC,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,RGB_TOG,RGB_HUD,RGB_HUI,RGB_SAD,RGB_SAI,RGB_VAD,RGB_MODE_PLAIN,RGB_MODE_RAINBOW,_______,_______,_______,_______,_______,
        _______,_______,_______, _______,_______,_______,_______,_______,_______, KC_HOME, KC_DEL, KC_END), 

    /* layer 1: Utils */
    [2] = LAYOUT_all(
        RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WIN_RIGHT,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WIN_LEFT,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______, _______,_______,_______,_______,_______,_______, _______,_______,_______), 

    // [1] = LAYOUT_all(
    //     KC_GRV,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,
    //     BL_TOGG, BL_STEP,  BL_INC,  BL_DEC,  RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS,  KC_TRNS,                KC_TRNS,                            WIN_LEFT, WIN_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS), 
    };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case TAB_LEFT:
      if (record->event.pressed){
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_TAB));     
      } else {
        //When keycode TAB_LEFT is released 
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
      }
      break;          
    case TAB_RIGHT:
      if (record->event.pressed){
        register_code(KC_LCTL);
        SEND_STRING(SS_TAP(X_TAB));     
      } else {
        //When keycode TAB_RIGHT is released 
        unregister_code(KC_LCTL);
      }
      break;   
    //Prolly not the best way of doing this but it works so whatever 
    case WIN_RIGHT:
      if (record->event.pressed){
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_RGHT);        
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_RGHT);    
      }
      break;
    case WIN_LEFT:
      if (record->event.pressed){
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_LEFT);        
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_LEFT);    
      }
      break;      
  }
  return true;
}
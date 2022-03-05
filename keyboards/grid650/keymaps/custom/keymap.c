/* Copyright 2020 grid
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
#include QMK_KEYBOARD_H

// #define LED_DEBUG

enum cusom_keycodes {
  // Grid's:   
  LED_BLE = SAFE_RANGE,
  BLE_PWR_OFF,
  BLE_PWR_ON,
  BLE_DFU,  
  WHITE,  
  BLUE,  
  // Mine: 
  TAB_LEFT,
  TAB_RIGHT,
  WIN_RIGHT, 
  WIN_LEFT
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

#ifdef LED_DEBUG
enum LED_STAT{  
//   WHITE_ON,  
//   BLE_ON,  
  WHITE_LED,  
  BLUE_LED, 
};

void set_status_led(enum LED_STAT led_stat,enum LED_STAT current_stat);
#endif

    // [n] = LAYOUT(
    //     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______),
    //

// BLE keymap for user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |GSC|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |TbRt|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |TbLf|
   * |----------------------------------------------------------------|
   * |Fn1   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | ---|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Fn1 |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space               |Alt|Fn2|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
    /* Base */    
    [0] = LAYOUT(
        TD(EB),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, _______, KC_BSPC,   _______,
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,TAB_LEFT,    TAB_RIGHT,     
        MO(1),    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, BLUE,
        KC_LSFT,    _______,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  MO(1),
        KC_LCTL,    KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  KC_RALT,_______,MO(2),    KC_LEFT,KC_DOWN,KC_RGHT,
        _______,      _______,  _______,  _______
    ),
    [1] = LAYOUT(
        KC_ESC,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,KC_F12,_______,_______,_______,
        _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,
        _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,_______,
        _______,    _______,WHITE,BLUE,_______,_______,_______,  _______,_______,_______,_______,_______,   _______,_______,_______,
        _______,    _______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,KC_HOME,KC_DEL,KC_END,
        _______,    _______,_______,_______        
    ),
    [2] = LAYOUT(
        RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WIN_RIGHT,
        BLE_DFU,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,WIN_LEFT,
        BLE_PWR_ON,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        BLE_PWR_OFF,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        LED_BLE,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______
    ),    
};

// Defines names for use in layer keycodes and the keymap
// Needs layer_names enum: 
// enum layer_names {
//     _BASE,
//     _FN
// };
//
//keymap for test
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         RESET,    BLE_PWR_OFF,   BLE_PWR_ON,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_GRV, KC_BSPC,    KC_BSPC,
//         OUT_USB,    OUT_AUTO,  OUT_BT,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,KC_PGUP,    KC_DEL,     
//         KC_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, KC_PGDN,
//         KC_LSFT,    KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  KC_PSCR,
//         BLE_DFU,    KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  KC_RALT,KC_RCTL,MO(_FN),    KC_LEFT,KC_DOWN,KC_RGHT
//     )
//     // ,
//     // [_FN] = LAYOUT(
//     //     KC_GRV,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12, _______,KC_DEL,     KC_DEL,
//     //     _______,    KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,OUT_USB,BL_TOGG,BL_BRTG, _______,_______, LED_BLE,_______,KC_HOME,    KC_BSPC,
//     //     KC_MS_L,    KC_MS_D,KC_MS_R,_______,_______,_______,OUT_AUTO,_______,_______,_______,_______,_______,   _______,_______,KC_END,
//     //     _______,    _______,_______,_______,_______,_______,OUT_BT,  _______,_______,_______,_______,_______,   _______,KC_VOLU,KC_INS,
//     //     _______,    _______,_______,_______,_______,_______,_______, _______,_______,_______,KC_MPRV,KC_VOLD,   KC_MNXT,_______,_______        
//     // )
// };

//led debug keymap
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         RESET,    BLE_PWR_OFF,   BLE_PWR_ON,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_GRV, KC_BSPC,    KC_BSPC,
//         OUT_USB,    OUT_AUTO,  OUT_BT,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,KC_PGUP,    KC_DEL,     
//         KC_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, KC_PGDN,
//         BREATHING,    ON,RED,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  KC_PSCR,
//         BLE_DFU,    ORANGE,BLUE,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  KC_RALT,KC_RCTL,MO(_FN),    KC_LEFT,KC_DOWN,KC_RGHT
//     )
// };


// uint8_t white_led = 1;
uint8_t orange_led = 1;
uint8_t red_led = 1;
uint8_t ble_led = 1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef LED_DEBUG
    static enum LED_STAT current_stat = WHITE_BREATHING;
    #endif

    switch (keycode) {
        #ifdef LED_DEBUG
        case WHITE:
        if (record->event.pressed) {
            set_status_led(WHITE_ON,current_stat);
            current_stat = WHITE_ON;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true;    
        case BLUE:
        if (record->event.pressed) {
            set_status_led(BLE_ON,current_stat);
            current_stat = BLE_ON;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true;
                             
        case LED_BLE:
        if (record->event.pressed) {                
            if(ble_led) {
                ble_led = 0;
                print("BLE LED OFF\n");
                adafruit_ble_set_mode_leds(0);
            } else {
                ble_led = 1;
                print("BLE LED ON\n");
                adafruit_ble_set_mode_leds(1);                                
            }
        } else {
            // Do something else when release
        }
            return true; 
        #endif   
        case BLE_PWR_OFF:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) LOW
            PORTD &= ~(1<<5);

            //BLE_OE(PD2) HIGH
            PORTD |= (1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
            
        } else {
            // Do something else when release
        }
            return true;      
        case BLE_PWR_ON:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) HIGH
            // PORTD &= ~(1<<5);
            PORTD |= (1<<5);

            //BLE_OE(PD2) LOW
            // PORTD |= (1<<2);
            PORTD &= ~(1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
                
        } else {
            // Do something else when release
        }
            return true;         
        case BLE_DFU:
        if (record->event.pressed) {
            //DFU_MCU(PC6) HIGH
            PORTC |= 1 << 6;   //set high
              
        } else {
            // Do something else when release
            //DFU_MCU(PC6) LOW
            PORTC &= ~(1 << 6);   //set high
        }
        // My Keycodes: 
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
    return true; // Process all other keycodes normally           
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

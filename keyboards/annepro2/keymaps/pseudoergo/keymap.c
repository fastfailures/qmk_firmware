// Forked from codetector
//
// Docs:
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN_LAYER,
  _KEYPAD_LAYER,
};

// This is ROW*MATRIX_COLS + COL
#define CAPS_LOCATION (MATRIX_COLS * 2 + 0)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * Layer _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * |    Fn   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |               Space             | Alt ) |   Fn  |  Esc  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | FnLayer |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |FnLayer|       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LAPO,      KC_SPC,             KC_RAPC, MO(_FN_LAYER), KC_ESC, KC_RCTL
  ),
  /* Layer _FN_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | BaseLayer |
  * |-----------------------------------------------------------------------------------------+
  * | MsBut3 |     | MsU |MsWhl|MsWUp|VolUp|L_Int|L_Frq|L_Off| L_On|  PS | Home| End |Keypad_L|
  * |-----------------------------------------------------------------------------------------+
  * |         | MsL | MsD | MsR |MsWDw|VolDw| Left| Down| Up  |Right| PgU | PgD |  BlockFn_L  |
  * |-----------------------------------------------------------------------------------------+
  * | MsButton1  |Sleep|MNext|MPlay| Mute| Bt1 | Bt2 |BtUnp| USB | Ins | Del |    CapsLock    |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |       |  Alt  |       MsAccel1                  |RecMacr|       | Menu  | Macro |
  * \-----------------------------------------------------------------------------------------/
  */
  [_FN_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DF(_BASE_LAYER),
    KC_MS_BTN3, XXXXXXX, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_UP, KC_VOLU, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_AP_LED_OFF, KC_AP_LED_ON, KC_PSCR, KC_HOME, KC_END, DF(_KEYPAD_LAYER),
    XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_VOLD, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, DF(_FN_LAYER),
    KC_MS_BTN1, KC_SYSTEM_SLEEP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MUTE, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT_UNPAIR, KC_AP2_USB, KC_INSERT, KC_DELETE, KC_CAPSLOCK,
    KC_LCTL, _______, KC_LALT,      KC_MS_ACCEL1,             DYN_REC_START1, XXXXXXX, KC_MENU, DYN_MACRO_PLAY1
  ),
  /*
  * Layer _KEYPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |  %  |  =  |  /  |  *  |     |     |     |     | BaseLayer |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | Up  |     |     |  ,  |  7  |  8  |  9  |  -  |     |     |     | NumLock|
  * |-----------------------------------------------------------------------------------------+
  * |    Fn   | Left| Down|Right|     |Enter|  4  |  5  |  6  |  +  |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     | Bksp|  1  |  2  |  3  |  .  |     |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |                 0               | Alt ) |   Fn  |  Esc  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _KEYPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | FnLayer |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |FnLayer|       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_KEYPAD_LAYER] = KEYMAP( /* Base */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERCENT, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_BASE_LAYER),
    KC_TAB, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_KP_COMMA, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUMLOCK,
    MO(_FN_LAYER),  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_KP_ENTER, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, XXXXXXX, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LAPO,      KC_KP_0,             KC_RAPC, MO(_FN_LAYER), KC_ESC, KC_RCTL
  ),
};

const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"
    annepro2LedEnable();
    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    annepro2LedSetProfile(14);
    annepro2LedNextAnimationSpeed(); // Slower animation speed, call it up to 3 times for even slower speed
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN_LAYER: // FIXME: persistent
        annepro2LedSetForegroundColor(0x20, 0xff, 0x4c);
        // annepro2LedSetForegroundColor(0x60, 0xff, 0x60);
        // annepro2LedSetForegroundColor(0x00, 0xff, 0x66);
        // annepro2LedSetForegroundColor(0x20, 0xff, 0x79);
        break;
    case _KEYPAD_LAYER: // FIXME: persistent
        annepro2LedSetForegroundColor(0x00, 0xf0, 0xf0);
        break;
    default:
        annepro2LedResetForegroundColor();  // Reset back to the current profile
        break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the Shifts to red
    const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0xff
    };
    annepro2LedMaskSetKey(3, 0, color); // L Shift
    annepro2LedMaskSetKey(3, 12, color); // R Shift
    /* NOTE: Instead of colouring the capslock only, you can change the whole
       keyboard with annepro2LedSetForegroundColor */
  } else {
    // Reset the colors if there is no layer active
    if(!layer_state_is(_FN_LAYER) && !layer_state_is(_KEYPAD_LAYER)) {
      const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0x00
      };
      annepro2LedMaskSetKey(3, 0, color);
      annepro2LedMaskSetKey(3, 12, color);
    }
  }
  return true;
}

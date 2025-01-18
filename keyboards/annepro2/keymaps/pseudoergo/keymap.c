// Docs: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  BASE_LAYER,
  EXTRA_LAYER,
  KEYPAD_LAYER,
  MEDIA_LAYER,
};

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * Layer BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * |   Esc   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |               Space             | Alt ) | MEDIA | EXTRA |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [BASE_LAYER] = LAYOUT_60_ansi(
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, SC_LAPO,      KC_SPC,       SC_RAPC, MO(MEDIA_LAYER), MO(EXTRA_LAYER), XXXXXXX
  ),
  /*
  * Layer EXTRA_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Ins | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
  * |-----------------------------------------------------------------------------------------+
  * | MsBut3 |     | MsU |MsWhl|MsWUp|     | Home| PgUp|PgDwn| End |  PS |     |     |KEYPADLk|
  * |-----------------------------------------------------------------------------------------+
  * |Back2BASE| MsL | MsD | MsR |MsWDw|     | Left| Down| Up  |Right| PgU | PgD |  EXTRALock  |
  * |-----------------------------------------------------------------------------------------+
  * | MsButton1  |     |     |     |     |     |     |MsAcc|     |     |     |    CapsLock    |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |           Enter                 | Alt ) |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [EXTRA_LAYER] = LAYOUT_60_ansi(
    KC_INSERT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE,
    KC_MS_BTN3, XXXXXXX, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_UP, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_PSCR, XXXXXXX, XXXXXXX, DF(KEYPAD_LAYER),
    DF(BASE_LAYER), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, DF(EXTRA_LAYER),
    KC_MS_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_ACCEL1, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS_LOCK,
    _______, _______, _______,      KC_ENT,             _______, XXXXXXX, _______, XXXXXXX
  ),
  /* 
  * Layer MEDIA_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     | BT1 | BT2 | BT3 | BT4 |     |     |     |     |LEDTG|LEDI+|LEDPV|LEDNX|           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |VolUp|     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |MPlay|VolDw|MNext|     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     | Mute|     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [MEDIA_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_MEDIA_PLAY_PAUSE, KC_VOLD, KC_MEDIA_NEXT_TRACK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT_UNPAIR, KC_AP2_USB, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  /*
  * Layer KEYPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |  %  |     |     |  *  |     |     |     |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | Up  |     |     |     |  7  |  8  |  9  |  -  |     |     |     | NumLock|
  * |-----------------------------------------------------------------------------------------+
  * |Back2BASE| Left| Down|Right|     |     |  4  |  5  |  6  |  +  |     |     |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |  1  |  2  |  3  |  .  |  /  |                |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI | Alt ( |                 0               | Alt ) | MEDIA | EXTRA |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [KEYPAD_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERCENT, XXXXXXX, XXXXXXX, KC_KP_ASTERISK, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_EQUAL, KC_BSPC,
    KC_TAB, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM_LOCK,
    DF(BASE_LAYER),  KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, XXXXXXX, XXXXXXX, KC_KP_ENTER,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, KC_KP_SLASH, XXXXXXX,
    _______, _______, _______,      KC_KP_0,             _______, MO(MEDIA_LAYER), MO(EXTRA_LAYER), XXXXXXX
  ),
};
// clang-format on

void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(7); // TODO 14
    /*annepro2LedNextAnimationSpeed(); // Slower animation speed, call it up to 3 times for even slower speed*/
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case EXTRA_LAYER:
            ap2_led_set_foreground_color(0x20, 0xff, 0x4c);
            // (0x60, 0xff, 0x60); (0x00, 0xff, 0x66); (0x20, 0xff, 0x79);
            break;
        case MEDIA_LAYER:
            ap2_led_set_foreground_color(0xf0, 0x00, 0x00); // TODO: only interested keys
            break;
        case KEYPAD_LAYER:
            ap2_led_set_foreground_color(0x00, 0xf0, 0xf0); // TODO: only interested keys
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
        ap2_led_sticky_set_key(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with ap2_led_mask_set_mono */
    } else {
        // Reset the capslock if there is no layer active
        ap2_led_unset_sticky_key(2, 0);
    }

    return true;
}

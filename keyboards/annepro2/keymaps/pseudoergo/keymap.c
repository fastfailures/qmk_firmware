// Docs: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  LBASE,   // Base layer
  LMOV, // Movements layer
  LKPAD, // Keypad layer
  LMEDIA, // Media layer
};

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Layer LBASE
    * ,-----------------------------------------------------------------------------------------.
    * |` FN1|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
    * |-----------------------------------------------------------------------------------------+
    * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
    * |-----------------------------------------------------------------------------------------+
    * |   Esc   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  | L_GUI |  Alt  |               Space             |  Alt  | MEDIA |  MOV  | MsWDw |
    * \-----------------------------------------------------------------------------------------/
    */
    [LBASE] = LAYOUT_60_ansi(
 LT(LMOV,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT, MO(LMEDIA),TT(LMOV), MS_WHLD),
    // NOTE:
    // both Shifts: Caps Word
    // MOV multiple times: lock it

    /*
    * Layer LMOV
    * ,-----------------------------------------------------------------------------------------.
    * | Ins | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
    * |-----------------------------------------------------------------------------------------+
    * | MsBut3 |     | MsU |MsWhl|MsWUp|     | Home| PgUp|PgDwn| End |  Ps |     |     | KEYPAD |
    * |-----------------------------------------------------------------------------------------+
    * |  Esc    | MsL | MsD | MsR |MsWDw|     | Left| Down| Up  |Right| PgU | PgD |    Right    |
    * |-----------------------------------------------------------------------------------------+
    * | MsButton1  |     |     |     |     |     |     |     |     |     |     |      Down      |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  | L_GUI |  Alt  |           Enter                 |  Alt  | BASE  |       | MsWUp |
    * \-----------------------------------------------------------------------------------------/
    */
    [LMOV] = LAYOUT_60_ansi(
        KC_INS,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        MS_BTN3, XXXXXXX,  MS_UP,    MS_BTN2, MS_WHLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  XXXXXXX,  XXXXXXX,  TO(LKPAD),
        _______, MS_LEFT,  MS_DOWN,  MS_RGHT, MS_WHLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            KC_RGHT,
        MS_BTN1,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_DOWN,
        _______, _______,  _______,                             KC_ENT,                             _______,  TO(LBASE),_______,  MS_WHLU),

    /*
    * Layer LMEDIA
    * ,-----------------------------------------------------------------------------------------.
    * |     | BT1 | BT2 | BT3 | BT4 |     |     |     |     |RGBTg|     |     |     | MediaPrev |
    * |-----------------------------------------------------------------------------------------+
    * |        |     |VolUp|     |     |     |     |     |     |     |     | NKT |     | MStop  |
    * |-----------------------------------------------------------------------------------------+
    * |         | Mute|VolDw|     |     |     |     |     |     |     |     |     |  MediaNext  |
    * |-----------------------------------------------------------------------------------------+
    * |            |     |     |     |     |     |     |     |     |     |     | MediaPlayPause |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                 |       |       |       |       |
    * \-----------------------------------------------------------------------------------------/
    */
    [LMEDIA] = LAYOUT_60_ansi(
        XXXXXXX,KC_AP2_BT1,KC_AP2_BT2,KC_AP2_BT3,KC_AP2_BT4,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_AP_LED_TOG,XXXXXXX,XXXXXXX,XXXXXXX,KC_MPRV,
        XXXXXXX, XXXXXXX,  KC_VOLU,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NK_TOGG,  XXXXXXX,  KC_MSTP,
        XXXXXXX, KC_MUTE,  KC_VOLD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MNXT,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MPLY,
        XXXXXXX, XXXXXXX,  XXXXXXX,                             XXXXXXX,                            XXXXXXX,  _______,  _______,  _______),

    /*
    * Layer LKPAD
    * ,-----------------------------------------------------------------------------------------.
    * |     |     |     |     |     |  %  |     |     |  *  |     |     |     |  =  |    Bksp   |
    * |-----------------------------------------------------------------------------------------+
    * |  Tab   |     | Up  |     |     |     |  7  |  8  |  9  |  -  |     |     |     | NumLock|
    * |-----------------------------------------------------------------------------------------+
    * |  Esc    | Left| Down|Right|     |     |  4  |  5  |  6  |  +  |     |     |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * |            |     |     |     |     |     |  1  |  2  |  3  |  .  |  /  |                |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  | L_GUI |  Alt  |                 0               |  Alt  |  BASE |  FN1  |       |
    * \-----------------------------------------------------------------------------------------/
    */
    [LKPAD] = LAYOUT_60_ansi(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX, KC_PAST, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_PEQL,  KC_BSPC,
        KC_TAB,  XXXXXXX,  KC_UP,    XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM_LOCK,
        KC_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,  XXXXXXX,            KC_PENT,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_PSLS,  XXXXXXX,            XXXXXXX,
        _______, _______,  _______,                             KC_KP_0,                            _______,  TO(LBASE),_______,  _______),
};
// clang-format on

void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(14);
    // Slower animation speed, call it up to 3 times for even slower speed:
    ap2_led_next_animation_speed();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    const ap2_led_t cyan = {.p.red = 0x20, .p.green = 0xff, .p.blue = 0x4c, .p.alpha = 0xff};
    // alt: (0x60, 0xff, 0x60); (0x00, 0xff, 0x66); (0x20, 0xff, 0x79);
    const ap2_led_t purple = {.p.red = 0x30, .p.green = 0x21, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t orange = {.p.red = 0xff, .p.green = 0xb6, .p.blue = 0x21, .p.alpha = 0xff};
    const ap2_led_t green = {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
    const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
    const ap2_led_t white = {.p.red = 0xff, .p.green = 0xff, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
    switch (get_highest_layer(state)) {
        case LMOV:
            ap2_led_mask_set_mono(cyan);
            ap2_led_mask_set_key(1, 13, orange); // Backslash
            ap2_led_mask_set_key(4, 10, green); // Back to Base
	    // TODO: turn off unused, color differently movements, F, Ps, mouse
            break;
        case LMEDIA:
            ap2_led_mask_set_key(0, 1, white); // 1
            ap2_led_mask_set_key(0, 2, white); // 2
            ap2_led_mask_set_key(0, 3, white); // 3
            ap2_led_mask_set_key(0, 4, white); // 4
            ap2_led_mask_set_key(0, 9, white); // 9
            ap2_led_mask_set_key(1, 2, purple); // W
            ap2_led_mask_set_key(2, 1, purple); // A
            ap2_led_mask_set_key(2, 2, purple); // S
            ap2_led_mask_set_key(0, 13, purple); // Backspace
            ap2_led_mask_set_key(1, 13, purple); // Backslash
            ap2_led_mask_set_key(2, 12, purple); // Enter
            ap2_led_mask_set_key(3, 12, purple); // RShift
            ap2_led_mask_set_key(1, 11, white); // [
            break;
        case LKPAD:
            ap2_led_mask_set_mono(orange);
            ap2_led_mask_set_key(1, 13, red); // Backslash
            ap2_led_mask_set_key(4, 10, green); // Back to Base
	    // TODO: color differently stuff, show NumLock status
            break;
        default:
            ap2_led_mask_set_mono(color_reset);
            break;
    }
    return state;
}

// Show Caps Word status
void caps_word_set_user(bool active) {
    const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
    const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
    if (active) {
        ap2_led_mask_set_key(3, 0, red); // L Shift
        ap2_led_mask_set_key(3, 12, red); // R Shift
        ap2_led_mask_set_key(4, 6, red); // Space
    } else {
        ap2_led_mask_set_key(3, 0, color_reset); // L Shift
        ap2_led_mask_set_key(3, 12, color_reset); // R Shift
        ap2_led_mask_set_key(4, 6, color_reset); // Space
    }
}

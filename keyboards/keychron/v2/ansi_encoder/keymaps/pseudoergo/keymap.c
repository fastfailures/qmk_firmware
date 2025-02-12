// Docs: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  LBASE,   // Base layer
  LFN1,    // Extra layer
  LKPAD,   // Keypad layer
  LMEDIA,  // Media layer
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_ansi_67(
 LT(LFN1,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MS_BTN3,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          MS_BTN2,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           MS_BTN1,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, MS_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT, MO(LMEDIA),MO(LFN1), MS_LEFT, MS_DOWN, MS_RGHT),
    // NOTE: both Shifts: Caps Word

    [LFN1] = LAYOUT_ansi_67(
        KC_INS,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           _______,
        MS_BTN3, XXXXXXX,  MS_UP,    MS_BTN2, MS_WHLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  XXXXXXX,  XXXXXXX,  TO(LKPAD),        _______,
        TO(LFN1),MS_LEFT,  MS_DOWN,  MS_RGHT, MS_WHLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            KC_RGHT,          _______,
        MS_BTN1,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_DOWN, _______,
        _______, _______,  _______,                             KC_ENT,                             _______,  TO(LBASE),_______,  _______, _______, _______),

    [LMEDIA] = LAYOUT_ansi_67(
        RM_SATD, RM_SATU,  RM_VALD,  RM_VALU, RM_SPDD, RM_SPDU, RM_HUED, RM_HUEU, RM_NEXT, RM_TOGG, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPRV,          KC_MUTE,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NK_TOGG,  XXXXXXX,  KC_MSTP,          KC_MUTE,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MNXT,          XXXXXXX,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MPLY, _______,
        XXXXXXX, XXXXXXX,  XXXXXXX,                             XXXXXXX,                            XXXXXXX,  _______,  _______,  _______, _______, _______),

    [LKPAD] = LAYOUT_ansi_67(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX, KC_PAST, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_PEQL,  KC_BSPC,          _______,
        KC_TAB,  XXXXXXX,  KC_UP,    XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM_LOCK,      _______,
        KC_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,  XXXXXXX,            KC_PENT,          _______,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_PSLS,  XXXXXXX,            XXXXXXX, _______,
        _______, _______,  _______,                             KC_KP_0,                            _______,  TO(LBASE),_______,  _______, _______, _______),
  /*
  * Layer LKPAD
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |  %  |     |     |  *  |     |     |     |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | Up  |     |     |     |  7  |  8  |  9  |  -  |     |     |     | NumLock|
  * |-----------------------------------------------------------------------------------------+
  * | Esc     | Left| Down|Right|     |     |  4  |  5  |  6  |  +  |     |     |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |  1  |  2  |  3  |  .  |  /  |                |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  | L_GUI |  Alt  |                 0               |  Alt  | BaseL | Fn1L  |       |
  * \-----------------------------------------------------------------------------------------/
  */
};
// CapsLock and RGUI rationale: it could be Canc, but it's too dangerous

// Encoder
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LBASE]   = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [LFN1]  = {ENCODER_CCW_CW(_______, _______)},
    [LMEDIA]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LKPAD] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
// clang-format on


// TODO: https://github.com/qmk/qmk_firmware/blob/master/docs/features/rgb_matrix.md

// void keyboard_post_init_user(void) {
//     ap2_led_enable();
//     ap2_led_set_profile(14);
//     // Slower animation speed, call it up to 3 times for even slower speed:
//     ap2_led_next_animation_speed();
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     const ap2_led_t cyan = {.p.red = 0x20, .p.green = 0xff, .p.blue = 0x4c, .p.alpha = 0xff};
//     // alt: (0x60, 0xff, 0x60); (0x00, 0xff, 0x66); (0x20, 0xff, 0x79);
//     const ap2_led_t purple = {.p.red = 0x30, .p.green = 0x21, .p.blue = 0xff, .p.alpha = 0xff};
//     const ap2_led_t orange = {.p.red = 0xff, .p.green = 0xb6, .p.blue = 0x21, .p.alpha = 0xff};
//     const ap2_led_t green = {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
//     const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
//     const ap2_led_t white = {.p.red = 0xff, .p.green = 0xff, .p.blue = 0xff, .p.alpha = 0xff};
//     const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
//     switch (get_highest_layer(state)) {
//         case LFN1: // TODO FIXME keep color on lock
//             ap2_led_mask_set_mono(cyan);
//             ap2_led_mask_set_key(1, 13, orange); // Backslash
//             ap2_led_mask_set_key(2, 12, green); // Enter
//             ap2_led_mask_set_key(3, 12, red); // RShift
//             ap2_led_mask_set_key(2, 0, white); // CapsLock(Esc)
//             break;
//         case LMEDIA:
//             ap2_led_mask_set_key(0, 1, purple); // 1
//             ap2_led_mask_set_key(0, 2, purple); // 2
//             ap2_led_mask_set_key(0, 3, purple); // 3
//             ap2_led_mask_set_key(0, 4, purple); // 4
//             ap2_led_mask_set_key(0, 9, purple); // 9
//             ap2_led_mask_set_key(1, 2, purple); // W
//             ap2_led_mask_set_key(2, 1, purple); // A
//             ap2_led_mask_set_key(2, 2, purple); // S
//             ap2_led_mask_set_key(2, 3, purple); // D
//             ap2_led_mask_set_key(3, 3, purple); // X
//             ap2_led_mask_set_key(2, 0, white); // CapsLock(Esc)
//             break;
//         case LKPAD: // TODO FIXME
//             ap2_led_mask_set_mono(orange);
//             ap2_led_mask_set_key(1, 13, red); // Backslash
//             ap2_led_mask_set_key(2, 0, white); // CapsLock(Esc)
//             break;
//         default:
//             ap2_led_mask_set_mono(color_reset);
//             break;
//     }
//     return state;
// }

// // The function to handle the Caps Lock logic
// // It's called after the capslock changes state or after entering layers 1 and 2
// bool led_update_user(led_t leds) {
//     const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
//     const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
//     if (leds.caps_lock) {
//         ap2_led_mask_set_key(3, 0, red); // L Shift
//         ap2_led_mask_set_key(3, 12, red); // R Shift
//         ap2_led_mask_set_key(4, 11, red); // EXTRA
//     } else if (layer_state_is(LBASE)) {
//         ap2_led_mask_set_key(3, 0, color_reset); // L Shift
//         ap2_led_mask_set_key(3, 12, color_reset); // R Shift
//         ap2_led_mask_set_key(4, 11, color_reset); // EXTRA
//     }
//     return true;
// }

// // Show Caps Word status
// void caps_word_set_user(bool active) {
//     const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
//     const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
//     if (active) {
//         ap2_led_mask_set_key(3, 0, red); // L Shift
//         ap2_led_mask_set_key(3, 12, red); // R Shift
//         ap2_led_mask_set_key(4, 6, red); // Space
//     } else {
//         ap2_led_mask_set_key(3, 0, color_reset); // L Shift
//         ap2_led_mask_set_key(3, 12, color_reset); // R Shift
//         ap2_led_mask_set_key(4, 6, color_reset); // Space
//     }
// }

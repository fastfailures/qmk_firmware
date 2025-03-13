// Docs:
// https://docs.qmk.fm/
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  LBASE,   // Base layer
  LMOV,    // Movements layer
  LNUM,    // Home-numbers layer
  LMEDIA,  // Media layer
  LKPAD,   // Keypad layer
};

// clang-format off
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_60_ansi(
 LT(LMOV,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LGUI,  KC_LALT,                             LT(LNUM,KC_SPC),                    KC_RALT, MO(LMEDIA),TT(LMOV), MS_WHLD),
    // NOTE:
    // both Shifts: Caps Word
    // MOV 5 times: lock it
    // CapsLock and RGUI rationale: it could be Canc, but it's too dangerous
    [LMOV] = LAYOUT_60_ansi(
       TO(LBASE),KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        MS_BTN3, MS_BTN2,  MS_UP,    MS_BTN1, MS_WHLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  XXXXXXX,  KC_INS,   TO(LKPAD),
        _______, MS_LEFT,  MS_DOWN,  MS_RGHT, MS_WHLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            TO(LBASE),
        _______,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            _______,
        _______, _______,  _______,                             KC_ENT,                             _______,  XXXXXXX,  _______,  MS_WHLU),
    [LNUM] = LAYOUT_60_ansi(
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  _______,  _______,
        _______, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DOT,            _______,
        _______,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,  _______,            _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______),
    [LMEDIA] = LAYOUT_60_ansi(
        NK_TOGG,KC_AP2_BT1,KC_AP2_BT2,KC_AP2_BT3,KC_AP2_BT4,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_AP_LED_TOG,XXXXXXX,KC_VOLD,KC_VOLU,KC_MUTE,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPRV,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MSTP,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MNXT,
        XXXXXXX, XXXXXXX,  XXXXXXX,                             XXXXXXX,                            XXXXXXX,  _______,  _______,  KC_MPLY),
    [LKPAD] = LAYOUT_60_ansi(
       TO(LBASE),XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX, KC_PAST, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_PEQL,  KC_BSPC,
        KC_TAB,  XXXXXXX,  KC_UP,    XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM_LOCK,
        KC_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,  XXXXXXX,            KC_PENT,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_PSLS,  XXXXXXX,            XXXXXXX,
        _______, _______,  _______,                             KC_KP_0,                            _______,  XXXXXXX,  _______,  _______),
};
// clang-format on

// Send Delete when Shift + Backspace are pressed
// https://docs.qmk.fm/features/key_overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
    &delete_key_override
};

// Colors
void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(14);
    // Slower animation speed, call it up to 3 times for even slower speed:
    ap2_led_next_animation_speed();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    const ap2_led_t cyan = {.p.red = 0x20, .p.green = 0xff, .p.blue = 0x4c, .p.alpha = 0xff};
    // alt: (0x60, 0xff, 0x60); (0x00, 0xff, 0x66); (0x20, 0xff, 0x79);
    const ap2_led_t blue = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t magenta = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t pink = {.p.red = 0x99, .p.green = 0x00, .p.blue = 0x99, .p.alpha = 0xff};
    const ap2_led_t purple = {.p.red = 0x30, .p.green = 0x21, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t orange = {.p.red = 0xff, .p.green = 0xb6, .p.blue = 0x21, .p.alpha = 0xff};
    const ap2_led_t green = {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
    const ap2_led_t red = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};
    const ap2_led_t white = {.p.red = 0xff, .p.green = 0xff, .p.blue = 0xff, .p.alpha = 0xff};
    const ap2_led_t color_reset = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
    switch (get_highest_layer(state)) {
        case LMOV:
            ap2_led_mask_set_key(0, 0, green);   // ` (Back to Base)
            ap2_led_mask_set_key(2, 12, green);  // Enter (Back to Base)
            ap2_led_mask_set_key(0, 1, purple);    // 1 (F1)
            ap2_led_mask_set_key(0, 2, purple);    // 2 (F2)
            ap2_led_mask_set_key(0, 3, purple);    // 3 (F3)
            ap2_led_mask_set_key(0, 4, purple);    // 4 (F4)
            ap2_led_mask_set_key(0, 5, purple);    // 5 (F5)
            ap2_led_mask_set_key(0, 6, purple);    // 6 (F6)
            ap2_led_mask_set_key(0, 7, purple);    // 7 (F7)
            ap2_led_mask_set_key(0, 8, purple);    // 8 (F8)
            ap2_led_mask_set_key(0, 9, purple);    // 9 (F9)
            ap2_led_mask_set_key(0, 10, purple);   // 0 (F10)
            ap2_led_mask_set_key(0, 11, purple);   // - (F11)
            ap2_led_mask_set_key(0, 12, purple);   // = (F12)
            ap2_led_mask_set_key(0, 13, red);    // Backspace (Del)
            ap2_led_mask_set_key(1, 6, blue);    // y (Home)
            ap2_led_mask_set_key(1, 7, blue);    // u (PgUp)
            ap2_led_mask_set_key(1, 8, blue);    // i (PgDown)
            ap2_led_mask_set_key(1, 9, blue);    // o (End)
            ap2_led_mask_set_key(1, 10, magenta);  // p (Print)
            ap2_led_mask_set_key(1, 12, pink);   // ] (Ins)
            ap2_led_mask_set_key(1, 13, orange); // \ (LKPAD)
            ap2_led_mask_set_key(1, 0, cyan);    // Tab
            ap2_led_mask_set_key(1, 1, cyan);    // q
            ap2_led_mask_set_key(1, 2, cyan);    // w
            ap2_led_mask_set_key(1, 3, cyan);    // e
            ap2_led_mask_set_key(1, 4, cyan);    // r
            ap2_led_mask_set_key(2, 1, cyan);    // a
            ap2_led_mask_set_key(2, 2, cyan);    // s
            ap2_led_mask_set_key(2, 3, cyan);    // d
            ap2_led_mask_set_key(2, 4, cyan);    // f
            ap2_led_mask_set_key(2, 6, cyan);    // h
            ap2_led_mask_set_key(2, 7, cyan);    // j
            ap2_led_mask_set_key(2, 8, cyan);    // k
            ap2_led_mask_set_key(2, 9, cyan);    // l
            ap2_led_mask_set_key(4, 6, blue);    // Space (Enter)
            ap2_led_mask_set_key(4, 12, blue);   // CtrlDx (WhUp)
            break;
        case LNUM:
            ap2_led_mask_set_key(2, 1, cyan);    // a
            ap2_led_mask_set_key(2, 2, cyan);    // s
            ap2_led_mask_set_key(2, 3, cyan);    // d
            ap2_led_mask_set_key(2, 4, cyan);    // f
            ap2_led_mask_set_key(2, 5, cyan);    // g
            ap2_led_mask_set_key(2, 6, cyan);    // h
            ap2_led_mask_set_key(2, 7, cyan);    // j
            ap2_led_mask_set_key(2, 8, cyan);    // k
            ap2_led_mask_set_key(2, 9, cyan);    // l
            ap2_led_mask_set_key(2, 10, cyan);   // ;
            ap2_led_mask_set_key(2, 11, cyan);   // '
            break;
        case LMEDIA:
            ap2_led_mask_set_key(0, 0, red);     // `
            ap2_led_mask_set_key(0, 1, blue);    // 1
            ap2_led_mask_set_key(0, 2, blue);    // 2
            ap2_led_mask_set_key(0, 3, blue);    // 3
            ap2_led_mask_set_key(0, 4, blue);    // 4
            ap2_led_mask_set_key(0, 9, white);   // 9
            ap2_led_mask_set_key(0, 11, purple); // -
            ap2_led_mask_set_key(0, 12, purple); // =
            ap2_led_mask_set_key(0, 13, purple); // Backspace
            ap2_led_mask_set_key(1, 13, purple); // \ (prev)
            ap2_led_mask_set_key(2, 12, purple); // Enter (stop)
            ap2_led_mask_set_key(3, 12, purple); // RShift (next)
            ap2_led_mask_set_key(4, 12, purple); // CtrlDx (play)
            break;
        case LKPAD:
            ap2_led_mask_set_mono(orange);
            ap2_led_mask_set_key(1, 13, red);    // \ (NumLock)
            ap2_led_mask_set_key(0, 0, green);   // ` (Back to Base)
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

// Docs:
// https://docs.qmk.fm/
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum layers {
  // First layer = switch in Mac position
  LBASE,   // Base layer (Mac) - mouse on arrows
  // Second layer = switch in Win position
  LWBASE,   // Base layer (Win) - arrows on arrows
  //
  LMOV,    // Movements layer
  LNUM,    // Home-numbers layer
  LMEDIA,  // Media layer
  LKPAD,   // Keypad layer
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_ansi_67(
 LT(LMOV,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MS_BTN3,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          MS_BTN2,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           MS_BTN1,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, MS_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             LT(LNUM,KC_SPC),                    KC_RALT, MO(LMEDIA),TT(LMOV), MS_LEFT, MS_DOWN, MS_RGHT),
    // NOTE:
    // both Shifts: Caps Word
    // MOV 5 times: lock it
    // CapsLock and RGUI rationale: it could be Canc, but it's too dangerous

    [LWBASE] = LAYOUT_ansi_67(
 LT(LMOV,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_MNXT,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_MPLY,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             LT(LNUM,KC_SPC),                    KC_RALT, MO(LMEDIA),TT(LMOV), KC_LEFT, KC_DOWN, KC_RGHT),

    [LMOV] = LAYOUT_ansi_67(
       TO(LBASE),KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           _______,
        MS_BTN3, MS_BTN2,  MS_UP,    MS_BTN1, MS_WHLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  XXXXXXX,  KC_INS,   TO(LKPAD),        _______,
        _______, MS_LEFT,  MS_DOWN,  MS_RGHT, MS_WHLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            TO(LBASE),        _______,
        _______,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            _______, _______,
        _______, _______,  _______,                             KC_ENT,                             _______,  XXXXXXX,  _______,  _______, _______, _______),

    [LNUM] = LAYOUT_ansi_67(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,          _______,
        _______, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          _______,
        _______, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,            _______,          _______,
        _______,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  XXXXXXX,  XXXXXXX,  _______, _______, _______),

    [LMEDIA] = LAYOUT_ansi_67(
        NK_TOGG, XXXXXXX,  DM_PLY1,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RM_HUED, RM_HUEU, RM_ON,   RM_OFF,   XXXXXXX,  XXXXXXX,  KC_MPRV,          KC_MUTE,
        XXXXXXX, DM_REC1,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MSTP,          KC_MNXT,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MNXT,          KC_MPLY,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            KC_MPLY, _______,
        XXXXXXX, XXXXXXX,  XXXXXXX,                             XXXXXXX,                            XXXXXXX,  _______,  _______,  _______, _______, _______),

    [LKPAD] = LAYOUT_ansi_67(
       TO(LBASE),XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PERC, XXXXXXX, XXXXXXX, KC_PAST, XXXXXXX, XXXXXXX,  XXXXXXX,  KC_PEQL,  KC_BSPC,          _______,
        KC_TAB,  XXXXXXX,  KC_UP,    XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM_LOCK,      _______,
        KC_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,  XXXXXXX,            KC_PENT,          _______,
        XXXXXXX,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_PSLS,  XXXXXXX,            XXXXXXX, _______,
        _______, _______,  _______,                             KC_KP_0,                            _______,  XXXXXXX,  _______,  _______, _______, _______),

};

// TODO
// Shortcut in MOV layer per ctrl alt f1 f2 f7
// tasto media tap dance: tap = media per il prossimo keypress, doppio tap = del, hold = media
// shift tap dance: frecce (single: right, double, down) ...sarebbe fico: tap+hold = mov

// Encoder
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LBASE]   = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [LWBASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LMOV]  = {ENCODER_CCW_CW(_______, _______)},
    [LNUM]  = {ENCODER_CCW_CW(_______, _______)},
    [LMEDIA]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LKPAD] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
// clang-format on

// Send Delete when Shift + Backspace are pressed
// https://docs.qmk.fm/features/key_overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
    &delete_key_override
};

// Colors
// https://docs.qmk.fm/features/rgb_matrix#callbacks
// https://docs.qmk.fm/features/rgb_matrix#colors
// https://github.com/qmk/qmk_firmware/blob/master/docs/features/rgb_matrix.md
// See config.h
//
// Key Matrix to LED Index:
// { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14 },
// { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
// { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 65, 42, 43 },
// { 44, __, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, __, 55, 56 },
// { 57, 58, 59, __, __, __, 60, __, __, __, 61, 62, 63, 64, 66 }
//
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    // Show Caps Word status
    // https://docs.qmk.fm/features/caps_word
    if (is_caps_word_on()) {
        rgb_matrix_set_color_all(RGB_RED);
    }

    // Layer colors
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case LMOV:
            rgb_matrix_set_color(1, RGB_TEAL);
            rgb_matrix_set_color(2, RGB_TEAL);
            rgb_matrix_set_color(3, RGB_TEAL);
            rgb_matrix_set_color(4, RGB_TEAL);
            rgb_matrix_set_color(5, RGB_TEAL);
            rgb_matrix_set_color(6, RGB_TEAL);
            rgb_matrix_set_color(7, RGB_TEAL);
            rgb_matrix_set_color(8, RGB_TEAL);
            rgb_matrix_set_color(9, RGB_TEAL);
            rgb_matrix_set_color(10, RGB_TEAL);
            rgb_matrix_set_color(11, RGB_TEAL);
            rgb_matrix_set_color(12, RGB_TEAL);
            rgb_matrix_set_color(13, RGB_RED);     // Backspace (Del)
            rgb_matrix_set_color(21, RGB_BLUE);    // y (Home)
            rgb_matrix_set_color(22, RGB_BLUE);    // u (PgUp)
            rgb_matrix_set_color(23, RGB_BLUE);    // i (PgDown)
            rgb_matrix_set_color(24, RGB_BLUE);    // o (End)
            rgb_matrix_set_color(25, RGB_PURPLE);  // p (Print)
            rgb_matrix_set_color(27, RGB_CORAL);   // ] (Ins)
            rgb_matrix_set_color(28, RGB_ORANGE);  // Backslash (LKPAD)
            rgb_matrix_set_color(36, RGB_SPRINGGREEN);    // h
            rgb_matrix_set_color(37, RGB_SPRINGGREEN);    // j
            rgb_matrix_set_color(38, RGB_SPRINGGREEN);    // k
            rgb_matrix_set_color(39, RGB_SPRINGGREEN);    // l
            rgb_matrix_set_color(15, RGB_SPRINGGREEN);    // Tab
            rgb_matrix_set_color(16, RGB_SPRINGGREEN);    // q
            rgb_matrix_set_color(17, RGB_SPRINGGREEN);    // w
            rgb_matrix_set_color(18, RGB_SPRINGGREEN);    // e
            rgb_matrix_set_color(19, RGB_SPRINGGREEN);    // r
            rgb_matrix_set_color(31, RGB_SPRINGGREEN);    // a
            rgb_matrix_set_color(32, RGB_SPRINGGREEN);    // s
            rgb_matrix_set_color(33, RGB_SPRINGGREEN);    // d
            rgb_matrix_set_color(34, RGB_SPRINGGREEN);    // f
            rgb_matrix_set_color(60, RGB_BLUE);    // Space (Enter)
            rgb_matrix_set_color(0, RGB_GREEN);    // ` (Back to Base)
            rgb_matrix_set_color(42, RGB_GREEN);   // Enter (Back to Base)
            break;
        case LNUM:
            rgb_matrix_set_color(31, RGB_SPRINGGREEN);    // a
            rgb_matrix_set_color(32, RGB_SPRINGGREEN);    // s
            rgb_matrix_set_color(33, RGB_SPRINGGREEN);    // d
            rgb_matrix_set_color(34, RGB_SPRINGGREEN);    // f
            rgb_matrix_set_color(35, RGB_SPRINGGREEN);    // g
            rgb_matrix_set_color(36, RGB_SPRINGGREEN);    // h
            rgb_matrix_set_color(37, RGB_SPRINGGREEN);    // j
            rgb_matrix_set_color(38, RGB_SPRINGGREEN);    // k
            rgb_matrix_set_color(39, RGB_SPRINGGREEN);    // l
            rgb_matrix_set_color(40, RGB_SPRINGGREEN);    // ;
            rgb_matrix_set_color(41, RGB_SPRINGGREEN);    // '
            rgb_matrix_set_color(60, RGB_SPRINGGREEN);    // Space
            break;
        case LMEDIA:
            rgb_matrix_set_color(0, RGB_RED);      // ` (NK)
            rgb_matrix_set_color(7, RGB_CORAL);    // 7
            rgb_matrix_set_color(8, RGB_CORAL);    // 8
            rgb_matrix_set_color(9, RGB_CORAL);    // 9
            rgb_matrix_set_color(10, RGB_CORAL);   // 0
            rgb_matrix_set_color(2, RGB_PURPLE);   // 2
            rgb_matrix_set_color(16, RGB_PURPLE);   // q
            rgb_matrix_set_color(13, RGB_PURPLE);  // Backspace
            rgb_matrix_set_color(28, RGB_PURPLE);  // Backslash
            rgb_matrix_set_color(42, RGB_PURPLE);  // Enter
            rgb_matrix_set_color(55, RGB_PURPLE);  // ShiftDx
            rgb_matrix_set_color(29, RGB_PURPLE);  // PgUp
            rgb_matrix_set_color(43, RGB_PURPLE);  // PgDn
            break;
        case LKPAD:
            rgb_matrix_set_color_all(RGB_ORANGE);
            rgb_matrix_set_color(28, RGB_RED);    // Backslash (NumLock)
            rgb_matrix_set_color(0, RGB_GREEN);   // ` (Back to Base)
            // TODO: color differently stuff, show NumLock status
            break;
        default:
            break;
    }
    return true;
}

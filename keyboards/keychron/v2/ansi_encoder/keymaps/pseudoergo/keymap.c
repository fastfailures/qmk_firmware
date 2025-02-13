// Docs: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

enum anne_pro_layers {
  LBASE,   // Base layer
  LMOV,    // Movements layer
  LKPAD,   // Keypad layer
  LMEDIA,  // Media layer
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_ansi_67(
 LT(LMOV,KC_GRV),KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          MS_BTN3,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          MS_BTN2,
        KC_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           MS_BTN1,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, MS_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT, MO(LMEDIA),TT(LMOV), MS_LEFT, MS_DOWN, MS_RGHT),
    // NOTE:
    // both Shifts: Caps Word
    // MOV multiple times: lock it

    [LMOV] = LAYOUT_ansi_67(
        KC_INS,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,           _______,
        MS_BTN3, XXXXXXX,  MS_UP,    MS_BTN2, MS_WHLU, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  XXXXXXX,  XXXXXXX,  TO(LKPAD),        _______,
        _______, MS_LEFT,  MS_DOWN,  MS_RGHT, MS_WHLD, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,  XXXXXXX,            KC_RGHT,          _______,
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

// CapsLock and RGUI rationale: it could be Canc, but it's too dangerous
};

// Encoder
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LBASE]   = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [LMOV]  = {ENCODER_CCW_CW(_______, _______)},
    [LMEDIA]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LKPAD] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
// clang-format on


// TODO: https://github.com/qmk/qmk_firmware/blob/master/docs/features/rgb_matrix.md

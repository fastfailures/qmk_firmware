// Mouse Key
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md#combined-mode
#define MK_COMBINED

// Caps Word
// https://github.com/qmk/qmk_firmware/blob/master/docs/features/caps_word.md
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

// RGB Matrix
// https://docs.qmk.fm/features/rgb_matrix
// https://github.com/qmk/qmk_firmware/blob/master/docs/features/rgb_matrix.md

//#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
//#define RGB_MATRIX_SLEEP // turn off effects when suspended
//#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
//#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set

//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // short splash
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // long cross
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // short cross
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // long splash
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_MULTISPLASH // Sets the default mode, if none has been set

// Color selection: https://docs.qmk.fm/features/rgblight#usage (0 = red, 85 = green, 169 = blue)
#define RGB_MATRIX_DEFAULT_HUE 97 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 175 // Sets the default saturation value, if none has been set
//#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
//#define RGB_MATRIX_DEFAULT_SPD 127 // Sets the default animation speed, if none has been set
//#define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL // Sets the default LED flags, if none has been set

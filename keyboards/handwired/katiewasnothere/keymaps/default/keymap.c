#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum unicode_name {
  GRIN,
  SMILE,
  BEAMING, 
  SWEAT,
  TJOY, 
  UPSIDE,
  ANGEL,
  HEARTEYE,
  KISS,
  TONGUE,
  THINKING,
  NOMOUTH,
  EYEROLL,
  YIKES,
  SIGH,
  SLEEPY,
  COWBOY,
  SUNGLASSES,
  SHOCK,
  CRYING,
  DEVIL,
};

const uint32_t PROGMEM unicode_map[] = {
  [GRIN] = 0x1F503,
  [SMILE] = 0x1F642,
  [BEAMING] = 0x1F601, 
  [SWEAT] = 0x1F605,
  [TJOY] = 0x1F602, 
  [UPSIDE] = 0x1F643,
  [ANGEL] = 0x1F607,
  [HEARTEYE] = 0x1F60D,
  [KISS] = 0x1F618,
  [TONGUE] = 0x1F61B,
  [THINKING] = 0x1F914,
  [NOMOUTH] = 0x1F636,
  [EYEROLL] = 0x1F644,
  [YIKES] = 0x1F62C,
  [SIGH] = 0x1F62A,
  [SLEEPY] = 0x1F63A,
  [COWBOY] = 0x1F920,
  [SUNGLASSES] = 0x1F60E,
  [SHOCK] = 0x1F62E,
  [CRYING] = 0x1F62D,
  [DEVIL] = 0x1F47F,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------------.
 * |   Esc  | `/~  |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |  -   |  +/= |Bkspce|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+------+------|
 * | tab       |   Q  |   W  |   E  |   R  |  T   |            |  Y   |   U  |   I  |   O  |   P  |   {   |   }   |       |
 * |-----------+------+------+------+------+------|            |------+------+------+------+------+-------+-------+       |
 * | Caps        |   A  |   S  |   D  |   F  |   G  |            |  H   |   J  |   K  |   L  |   ;  |  "   |   \| |enter  |
 * |-------------+------+------+------+------+------|            |------+------+------+------+------+------+-------+------|
 * |     |  LShift |   Z  |   X  |   C  |   V  |   B  |             |  N  |  M  |  ,  |  . |   / | RShift |  Up  | Undo   |
 * |-----+---------+------+------+------+-------------|             |-------+-------+------+------+-------+------+--------|
 * | Fn    |  Ctrl   |Alt/Opt |   CMD   |    Space    |             |    Space  | CMD | alt | Ctrl | LEFT | DOWN | RIGHT  |
 * `--------------------------------------------------|              `----------------------------------------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_katie(  // layer 0 : default
        // left hand
        KC_ESCAPE,    KC_GRAVE ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,
        KC_TAB          ,    KC_Q   ,   KC_W  ,  KC_E ,   KC_R  ,   KC_T ,  
        KC_CAPS            ,   KC_A   ,   KC_S  ,   KC_D ,   KC_F ,   KC_G ,
        KC_NO,  KC_LSFT    ,  KC_Z   ,  KC_X   ,   KC_C ,   KC_V ,   KC_B ,
        LT(SYMB,KC_NO) ,   KC_LCTL  ,    KC_LALT  ,   KC_LCMD ,    KC_SPACE  ,

        // right hand
             KC_6,   KC_7,  KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPACE,
             KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,   KC_LBRACKET, KC_RBRACKET, 
             KC_H,   KC_J,  KC_K,   KC_L,   KC_SCOLON , KC_QUOTE, KC_BSLASH, KC_ENTER,
             KC_N,   KC_M,  KC_COMM , KC_DOT , KC_SLSH , KC_RSFT, KC_UP , LGUI(KC_Z),
             KC_SPACE, KC_RCMD , KC_RALT , KC_RCTL,  KC_LEFT,  KC_DOWN, KC_RIGHT
    ),
/* Keymap 1: 
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------------.
 * | RESET  |      |   F1 |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 |Bkspce|
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+------+------|
 * |           |      |      |      |      |      |            | SWEAT| SIGH| UPSIDE|YIKES   | SHOCK| CRYING|NOMOUTH|     |
 * |-----------+------+------+------+------+------|            |------+------+------+------+------+-------+-------+       |
 * |             |      |      |      |      |      |            | GRIN| SMILE| BEAMING|SUNGLA| TJOY|COWBOY|ANGEL|HEARTEYE|
 * |-------------+------+------+------+------+------|            |------+------+------+------+------+------+-------+------|
 * |      |      |     |Vol Down |Vol up|     |       |             |TONG|KIS|THINK|EYER|SLEEP|DEVIL|  |  |bright up|     |
 * |------+------+-----+---------+------+-----+-------|             |-------+-------+------+------+-------+------+--------|
 * |       |         |        |         |             |             |           |     |     |      |      |bright down|   |
 * `--------------------------------------------------|              `----------------------------------------------------'
 *
 */
// SYMBOLS
[SYMB] = LAYOUT_katie(
       // left hand
       RESET, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______,
       _______, _______, _______, _______, _______,

       // right hand
       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPACE,
       X(SWEAT), X(SIGH), X(UPSIDE), X(YIKES), X(SHOCK), X(CRYING), X(NOMOUTH),
       X(GRIN), X(SMILE), X(BEAMING), X(SUNGLASSES), X(TJOY), X(COWBOY), X(ANGEL), X(HEARTEYE),
       X(TONGUE), X(KISS), X(THINKING), X(EYEROLL), X(SLEEPY), X(DEVIL), KC_BRIU, _______,
       _______, _______, _______, _______, _______, KC_BRID, _______
       
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}


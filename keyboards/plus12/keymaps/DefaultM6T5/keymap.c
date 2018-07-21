#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _FUNS 3
#define _NUMS 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  FUNS,
  NUMS,
  ESC1,
  ESC2,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Old style layer commands

#define FUNS LT(_FUNS, KC_SPC) // Function layer and space
#define NUMS LT(_NUMS, KC_BSPC) // Numbers and backspacd
#define ESC1 MT(MOD_LCTL, KC_ESC) //control and esc
#define ENTI MT(MOD_LSFT, KC_ENT) //shift and enter
#define LEDT MO(_FUNS) // left handed editing

//#define ESC2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.   .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |      |  GUI | Alt  | Nums |Shift | Esc  |   | Esc  | Shift| Funs |  Tab | Ctrl |      |
 * `-----------------------------------------'   '-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
   KC_TAB  ,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC  ,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT ,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
            LEDT,    KC_LALT, KC_LSFT, NUMS,    ESC1,        ESC1,   ENTI,    FUNS,    KC_TAB, KC_LGUI            \
),
    
/* Colemak
* ,------------------------------------------.   .-----------------------------------------.
* | Tab  |   Q  |   W  |   F  |   P  |   G   |   |   J  |   L  |   U  |   Y  |   ;  | Bksp |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* | Esc  |   A  |   R  |   S  |   T  |   D   |   |   H  |   N  |   E  |   I  |   O  |  '   |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B   |   |   K  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* |      |  GUI | Alt  | Nums |Shift | Esc   |   | Esc  | Shift| Funs |  Tab | Ctrl |      |
* `------------------------------------------'   '-----------------------------------------'
*/
[_COLEMAK] = LAYOUT( \
   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
   KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
            LEDT,    KC_LALT, KC_LSFT, NUMS,    ESC1,        ESC1,   ENTI,    FUNS,    KC_TAB, KC_LGUI         \
),

/* Dvorak
* ,------------------------------------------.   .-----------------------------------------.
* | Tab  |   '  |   ,  |   .  |   P  |   Y   |   |   F  |   G  |   C  |   R  |   L  | Bksp |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* | Esc  |   A  |   O  |   E  |   U  |   I   |   |   D  |   H  |   T  |   N  |   S  |  /   |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* | Shift|   ;  |   Q  |   J  |   K  |   X   |   |   B  |   M  |   W  |   V  |   Z  |Enter |
* |------+------+------+------+------+-------|   |------+------+------+------+------+------|
* |      |  GUI | Alt  | Nums |Shift | Esc   |   | Esc  | Shift| Funs |  Tab | Ctrl |      |
* `------------------------------------------'   '-----------------------------------------'
*/
[_DVORAK] = LAYOUT( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
           LEDT,    KC_LALT, KC_LSFT, NUMS,    ESC1,        ESC1,   ENTI,    FUNS,    KC_TAB, KC_LGUI         \
),

    
/* Function (funs)
 * ,-----------------------------------------.  .-----------------------------------------.
 * |QWERTY|  `~  |      |  Up  | Bksp |      |  | Home | PgUp |  Up  | PgDn | Bksp |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |DVORAK| Caps | Left | Down | Right| Del  |  |  End | Left | Down | Right|   "  | Enter|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |COLMAK| PrScr|ScrlLk| Pause|      |      |  |   [  |   ]  |   \  |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |      |      |      |
 * `-----------------------------------------'  '-----------------------------------------'
 */

[_FUNS] = LAYOUT( \
    _______,KC_GRV ,_______,KC_UP  ,KC_BSPC,_______,    KC_HOME,KC_PGUP,KC_UP  ,KC_PGDN,KC_BSPC,_______, \
    _______,KC_CAPS,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL ,    KC_END ,KC_LEFT,KC_DOWN,KC_RGHT,KC_QUOT,_______, \
    _______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,    KC_LBRC,KC_RBRC,KC_BSLS,_______,_______,_______, \
            _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______          \
 ),
    
/* Numbers (Nums)
* ,-----------------------------------------.  .-----------------------------------------.
* |      |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
* |------+------+------+------+------+------|  |------+------+------+------+------+------|
* |      |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |      |
* |------+------+------+------+------+------|  |------+------+------+------+------+------|
* |      |  F11 |  F12 |      |      |      |  |      |      |   -  |   =  |      |      |
* |------+------+------+------+------+------|  |------+------+------+------+------+------|
* |      |      |      |      |      |      |  |      |      |      |      |      |      |
* `-----------------------------------------'  '-----------------------------------------'
*/

[_NUMS] = LAYOUT( \
     _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______, \
     _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______, \
     _______,KC_F11 ,KC_F12 ,_______,_______,_______,    _______,_______,KC_MINS,KC_EQL ,_______,_______, \
             _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______          \
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

//Store default layer states in EEPROM
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

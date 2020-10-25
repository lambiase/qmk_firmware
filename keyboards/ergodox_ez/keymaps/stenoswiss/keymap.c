#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german_ch.h"
#include "keymap_plover.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAVI 2 // media/navigation keys
#define MOUS 3 // mouse keys
#define STEN 4 // Steno Qwerty


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  | TG2  |           | TG4  |   6  |   7  |   8  |   9  |   0  |   '    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | TG1  |           | TG3  |   Z  |   U  |   I  |   O  |   P  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   <  |   ^    |
 * |--------+------+------+------+------+------| OSL1 |           | Alt  |------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |           | Gr   |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LGui | Alt  |                                       | Shft | Left | Down | Up   | Rght |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      | Menu | Ins  |           | Prnt |AltSh |
 *                               ,------|------|------|           |------+------+------.
 *                               |Bksp  |      | Home |           | PgUp |      | CtrT |
 *                               |      | Del  |------|           |------| Entr | Spc  |
 *                               |      |      | End  |           | PgDn |      |      |
 *                               `--------------------'           `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,               CH_1,      CH_2,            CH_3,         CH_4,           CH_5, TG(NAVI),
        KC_TAB,               CH_Q,      CH_W,            CH_E,         CH_R,           CH_T, TG(SYMB),
        CTL_T(KC_NO),         CH_A,      CH_S,            CH_D,         LT(NAVI, CH_F), CH_G,
        KC_LSHIFT,            CH_Y,      CH_X,            CH_C,         CH_V,           CH_B, OSL(SYMB),
        _______,              _______,   _______,         KC_LGUI,      KC_LALT,
        KC_APP,               KC_INS,
        KC_HOME,
        KC_BSPACE,            KC_DELETE, KC_END,
        // right hand
        TG(STEN),      CH_6,             CH_7,    CH_8,     CH_9,        CH_0,            CH_QUOT,
        TG(MOUS),      CH_Z,             CH_U,    CH_I,     CH_O,        CH_P,            CH_DIER,
                       CH_H,             CH_J,    CH_K,     CH_L,        CH_LESS,         CH_CARR,
        ALGR_T(KC_NO), CH_N,             CH_M,    KC_COMMA, KC_DOT,      RCTL_T(CH_MINS), KC_RSHIFT,
        KC_LSHIFT,     KC_LEFT,          KC_DOWN, KC_UP,     KC_RIGHT,
        KC_PSCR,       LALT(KC_LSFT),
        KC_PGUP,
        KC_PGDOWN,     KC_ENTER,         CTL_T(KC_SPACE)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    §    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   #  |   =  |   &  |   [  |   '  |      |           |      |   "  |   ]  |   |  |   '  |   ~  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   @  |   $  |   -  |   (  |   \  |------|           |------|   /  |   )  |   _  |   ^  |   "  |   F13  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   +  |   *  |   <  |   {  |   ?  |      |           |      |   !  |   }  |   >  |   `  |   %  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |   "  |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.          ,-------------.
 *                                        |      |      |          |      |      |
 *                                 ,------|------|------|          |------+------+------.
 *                                 |      |      |      |          |      |      |      |
 *                                 |      |      |------|          |------|      |      |
 *                                 |      |      |      |          |      |      |      |
 *                                 `--------------------'          `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       CH_PARA , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,
       _______ , CH_HASH , CH_EQL  , CH_AMPR , CH_LBRC , CH_QUOT , _______ ,
       _______ , CH_AT   , CH_DLR  , CH_MINS , CH_LPRN , CH_BSLS ,
       _______ , CH_PLUS , CH_PAST , CH_LESS , CH_LCBR , CH_QST  , _______ ,
       EPRM    , CH_DIER , _______ , _______ , _______ ,
                                                         _______ , _______ ,
                                                                   _______ ,
                                               _______ , _______ , _______ ,
       // right hand
       _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
       _______ , CH_DQOT , CH_RBRC , CH_PIPE , CH_ACUT , CH_TILD , KC_F12  ,
                 CH_SLSH , CH_RPRN , CH_UNDS , CH_CARR , CH_DIER , KC_F13  ,
       _______ , CH_EXLM , CH_RCBR , CH_MORE , CH_GRV  , CH_PERC , _______ ,
                           _______ , _______ , _______ , _______ , _______ ,
       _______ , _______ ,
       _______ ,
       _______ , _______ , _______
),
/* Keymap 2: Media and navigation keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PGUP |  UP  | PGDN |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| HOME | LEFT | DOWN | RGTH | END  | Play   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Vol+ | Vol- | Mute | Prev | Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
// MEDIA AND NAVIGATION
[NAVI] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_PGUP, KC_UP  , KC_PGDN, _______, _______,
                 KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_MPLY,
       _______,  _______, _______, _______, _______, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE,KC_MPRV, KC_MNXT,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Keymap 3: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | WhU  | MsU  | WhD  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Btn3 | Btn2 | Btn1 |      |------|           |------|      | MsL  | MsD  | MsR  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Acl0 | Acl1 | Acl2 |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
// MOUSE
[MOUS] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
                 _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______,  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 4: Steno for Plover
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |   #  |           |  #   |  #   |  #   |   #  |   #  |  #   |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   T  |   P  |   H  |      |------|           |------|      |  F   |   P  |   L  |  T   |   D    |
 * |--------+   S  +------+------+------+   *  |   *  |           |  *   |  *   +------+------+------+------+--------|
 * |        |      |   K  |   W  |   R  |      |      |           |      |      |  R   |   B  |   G  |  S   |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |   A  |   O  |------|           |------|  E   |  U   |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */

[STEN] = LAYOUT_ergodox(
// left hand
      _______,  _______,  _______,  _______,   _______,  _______,   _______,
      _______,  PV_NUM, PV_NUM, PV_NUM,  PV_NUM, PV_NUM,  PV_NUM,
      _______,  PV_LS,  PV_LT,  PV_LP,   PV_LH,  PV_STAR,
      _______,  PV_LS,  PV_LK,  PV_LW,   PV_LR,  PV_STAR, PV_STAR,
      _______,  _______,  _______,  _______,   _______,
                                       _______, _______,
                                       _______,
                                       PV_A,  PV_O,  _______,

      // right hand
      _______,   _______,   _______,   _______,   _______,   _______,   _______,
      _______,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,
               _______, PV_RF,   PV_RP,   PV_RL,   PV_RT,   PV_RD,
      _______, PV_STAR, PV_RR,   PV_RB,   PV_RG,   PV_RS,   PV_RZ,
                        _______,   _______,   _______,   _______,   _______,
                                          _______,      _______,
                                          _______,
                                          _______,PV_E, PV_U
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

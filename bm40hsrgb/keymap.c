#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

// Mod-Tap shortcuts
#define CT(kc) LCTL_T(kc)
#define ST(kc) LSFT_T(kc)
#define AT(kc) LALT_T(kc)
#define GT(kc) LGUI_T(kc)

#define U_UND   LGUI(KC_Z)
#define U_RDO   SGUI(KC_Z)
#define U_CUT   LGUI(KC_X)
#define U_CPY   LGUI(KC_C)
#define U_PST   LGUI(KC_V)

// Multifunction layer toggle and simple keycode
#define SYM_ENT  LT(SYMS, KC_ENT)
#define NAV_TAB  LT(NAV, KC_TAB)

// MacOS control
#define QUAKE_CONSOLE    LCTL(LSFT(ES_NTIL))   // Show/Hide quake console
#define LOCK_SCREEN      LCTL(LGUI(KC_Q))      // Lock current user session
#define SUSPEND          LALT(LGUI(KC_POWER))  // Suspend computer
#define SCREENSHOT       LSFT(LGUI(KC_5))      // Open screenshot app
#define MISSION_CONTROL  LCTL(KC_UP)
#define APP_WINS         LCTL(KC_DOWN)
#define PRV_DSK          LCTL(KC_LEFT)
#define NXT_DSK          LCTL(KC_RIGHT)
#define SPOTLIGHT        LGUI(KC_SPC)

enum custom_keycodes {
  APP_CYCLING = SAFE_RANGE,
};

enum layers {
  BASE,
  NAV,
  NUMPAD,
  SYMS,
  MEDIA,
  FUNC,
};

  /* [LAYER_NAME] = LAYOUT_planck_mit( */
  /*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
  /*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
  /*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
  /*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX */
  /* ), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_planck_mit(
    KC_LALT,     KC_Q,     KC_W,      KC_E,        KC_R,     KC_T,     KC_Y,     KC_U,      KC_I,      KC_O,      KC_P,     KC_BSPACE,
    CT(KC_ESC),  KC_A,     KC_S,      KC_D,        KC_F,     KC_G,     KC_H,     KC_J,      KC_K,      KC_L,      ES_NTIL,  ES_ACUT,
    KC_LSFT,     KC_Z,     KC_X,      KC_C,        KC_V,     KC_B,     KC_N,     KC_M,      KC_COMMA,  KC_DOT,    ES_MINS,  XXXXXXX,
    XXXXXXX,     XXXXXXX,  KC_LGUI,   MO(NUMPAD),  NAV_TAB,  KC_SPC,             SYM_ENT,   MO(FUNC),  XXXXXXX,   XXXXXXX,  XXXXXXX
  ),

  [NAV] = LAYOUT_planck_mit(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QUAKE_CONSOLE,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,  XXXXXXX,  XXXXXXX,
    _______,  U_UND,    U_CUT,    U_CPY,    U_PST,          U_RDO,    KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,    XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  _______,        _______,            XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX
  ),

  [NUMPAD] = LAYOUT_planck_mit(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PERC,  KC_7,     KC_8,    KC_9,    KC_PSLS,  KC_BSPACE,
    _______,  XXXXXXX,  XXXXXXX,  KC_LGUI,  XXXXXXX,  XXXXXXX,  ES_LPRN,  KC_4,     KC_5,    KC_6,    KC_PPLS,  KC_PAST,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ES_RPRN,  KC_1,     KC_2,    KC_3,    KC_PMNS,  ES_EQL,
    XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  _______,            XXXXXXX,  KC_0,    KC_DOT,  XXXXXXX,  XXXXXXX
  ),

  [SYMS] = LAYOUT_planck_mit(
    ES_CIRC,        ES_PIPE,  ES_AT,    KC_PERC,  KC_DLR,     XXXXXXX,  XXXXXXX,  ES_LBRC,  ES_RBRC,  ES_IQUE,  ES_QUES,  KC_DELETE,
    LALT(ES_NTIL),  ES_AMPR,  ES_HASH,  ES_BSLS,  ES_SLSH,    XXXXXXX,  XXXXXXX,  ES_LPRN,  ES_RPRN,  ES_EQL,   ES_PLUS,  ES_ASTR,
    XXXXXXX,        ES_LESS,  ES_GRTR,  ES_DQUO,  ES_APOS,    ES_GRV,   XXXXXXX,  ES_LCBR,  ES_RCBR,  ES_IEXL,  KC_EXLM,  XXXXXXX,
    XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(MEDIA),  XXXXXXX,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [MEDIA] = LAYOUT_planck_mit(
    RESET,    XXXXXXX,  RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_MUTE,  KC_VOLU,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [FUNC] = LAYOUT_planck_mit(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,     SPOTLIGHT,        APP_CYCLING,  LOCK_SCREEN,  XXXXXXX,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  PRV_DSK,  APP_WINS,    MISSION_CONTROL,  NXT_DSK,      SUSPEND,      XXXXXXX,
    XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  SCREENSHOT,  XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,     _______,          XXXXXXX,      XXXXXXX,      XXXXXXX
  ),
};

/**
 * APP CYCLING
 */
bool is_app_cycling_active = false;
uint16_t app_cycling_timer = 0;

void app_cycling_activate(void) {
  if (!is_app_cycling_active) {
    is_app_cycling_active = true;
    register_code(KC_LGUI);
  }

  app_cycling_timer = timer_read();
}

void app_cycling_deactivate(void) {
  if (is_app_cycling_active) {
    if (timer_elapsed(app_cycling_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_app_cycling_active = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case APP_CYCLING:
      if (record->event.pressed) {
        app_cycling_activate();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }

  return true;
}

void matrix_scan_user(void) {
  app_cycling_deactivate();
}

/**
 * Define tapping term per key.
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_ENT:
    case NAV_TAB:
      return 50;
    default:
      return TAPPING_TERM;
  }
}

/* ************************************************************************************ */
/* INITIALIZATION                                                                       */
/* ************************************************************************************ */

/* void keyboard_post_init_user(void) { */
/*   // Set default underglow color */
/*   rgblight_enable_noeeprom();   // Enable RGB without saving settings */
/*   rgblight_sethsv_noeeprom(HSV_AZURE);  // Set default color */
/* } */


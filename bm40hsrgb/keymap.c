#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

// Mod-tap keys
#define A_CTL     LCTL_T(KC_A)
#define S_ALT     LALT_T(KC_S)
#define D_GUI     LGUI_T(KC_D)
#define F_SFT     LSFT_T(KC_F)

#define J_SFT     LSFT_T(KC_J)
#define K_GUI     LGUI_T(KC_K)
#define L_ALT     LALT_T(KC_L)
#define NTIL_CTL  LCTL_T(ES_NTIL)

// #ifdef OS_MAC

// // Edit commands
// #define U_UND   LGUI(KC_Z)
// #define U_RDO   SGUI(KC_Z)
// #define U_CUT   LGUI(KC_X)
// #define U_CPY   LGUI(KC_C)
// #define U_PST   LGUI(KC_V)

// // Control
// #define LOCK_SCREEN       LCTL(LGUI(KC_Q))      // Lock current user session
// #define SUSPEND           LALT(LGUI(KC_POWER))  // Suspend computer
// #define SCREENSHOT        LSFT(LGUI(KC_5))      // Open screenshot app
// #define MISSION_CONTROL   LCTL(KC_UP)           // Open Mission Control
// #define APP_WINS          LCTL(KC_DOWN)         // Show application windows
// #define PRV_DSK           LCTL(KC_LEFT)         // Show previous desktop
// #define NXT_DSK           LCTL(KC_RIGHT)        // Show next desktop
// #define SEARCH            LGUI(KC_SPC)          // Show Spotlight

// #endif // OS_MAC

// Multifunction layer toggle and simple keycode
#define NAV_TAB   LT(NAV, KC_TAB)
/* #define NUM_ENT   LT(NUM, KC_ENT) */

enum custom_keycodes {
  BBL_COPY = SAFE_RANGE,
  BBL_CUT,
  BBL_PASTE,
  BBL_UNDO,
  BBL_REDO,
  BBL_LOCK,
  BBL_SUSPEND,
  BBL_POWER_DOWN,
  BBL_SCREENSHOT,
  BBL_MULTI_TASK_VIEW,
  BBL_APP_WINDOWS,
  BBL_DESKTOP_NEXT,
  BBL_DESKTOP_PREV,
  BBL_OS_SEARCH,
  BBL_TERMINAL
};

enum layers {
  BASE,
  GAMING,
  NAV,
  NUM,
  SYM,
  MEDIA,
  FUNC,
};

/* [LAYER_NAME] = LAYOUT_planck_mit( */
/*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
/*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
/*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, */
/*   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX  */
/* ), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_planck_mit(
    BBL_TERMINAL,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,  KC_U,     KC_I,      KC_O,     KC_P,      KC_BSPACE,
    KC_ESC,   A_CTL,    S_ALT,    D_GUI,    F_SFT,    KC_G,    KC_H,  J_SFT,    K_GUI,     L_ALT,    NTIL_CTL,  ES_ACUT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,  KC_M,     KC_COMMA,  KC_DOT,   ES_MINS,   KC_ENT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(NUM),  NAV_TAB,  KC_SPC,         MO(SYM),  MO(FUNC),  XXXXXXX,  XXXXXXX,   XXXXXXX
  ),

  [GAMING] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,  KC_U,     KC_I,      KC_O,     KC_P,      KC_BSPACE,
    KC_TAB,   KC_A,     KC_S,    KC_D,     KC_F,     KC_G,    KC_H,  KC_J,     KC_K,      KC_L,     ES_NTIL,   ES_ACUT,
    KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,    KC_N,  KC_M,     KC_COMMA,  KC_DOT,   ES_MINS,   KC_ENT,
    KC_LCTL,  KC_LGUI,  KC_LALT, MO(NUM),  NAV_TAB,  KC_SPC,         MO(SYM),  MO(FUNC),  XXXXXXX,  XXXXXXX,   XXXXXXX
  ),

  [NAV] = LAYOUT_planck_mit(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  BBL_UNDO, BBL_CUT,  BBL_COPY, BBL_PASTE,    BBL_REDO,    KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,    XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SPC,             XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX
  ),

  [NUM] = LAYOUT_planck_mit(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PERC,  KC_7,  KC_8,    KC_9,     KC_PSLS,  KC_BSPACE,
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,  ES_LPRN,  KC_4,  KC_5,    KC_6,     KC_PPLS,  KC_PAST,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ES_RPRN,  KC_1,  KC_2,    KC_3,     KC_PMNS,  ES_EQL,
    XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  _______,            KC_0,  KC_DOT,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [SYM] = LAYOUT_planck_mit(
    ES_CIRC,  ES_PIPE,  ES_AT,    KC_PERC,  KC_DLR,     XXXXXXX,  XXXXXXX,  ES_LBRC,  ES_RBRC,  ES_IQUE,  ES_QUES,  KC_DELETE,
    ES_TILD,  ES_AMPR,  ES_HASH,  ES_BSLS,  ES_SLSH,    XXXXXXX,  XXXXXXX,  ES_LPRN,  ES_RPRN,  ES_EQL,   ES_PLUS,  ES_ASTR,
    XXXXXXX,  ES_LESS,  ES_GRTR,  ES_DQUO,  ES_APOS,    ES_GRV,   XXXXXXX,  ES_LCBR,  ES_RCBR,  ES_IEXL,  KC_EXLM,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(MEDIA),  XXXXXXX,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [MEDIA] = LAYOUT_planck_mit(
    RESET,    XXXXXXX,  RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(GAMING),  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,     XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_MUTE,  KC_VOLU,  XXXXXXX,     XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX
  ),

  [FUNC] = LAYOUT_planck_mit(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,     BBL_OS_SEARCH,           XXXXXXX,  BBL_LOCK,     XXXXXXX,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  BBL_DESKTOP_PREV,  BBL_APP_WINDOWS,    BBL_MULTI_TASK_VIEW,  BBL_DESKTOP_NEXT,  BBL_SUSPEND,      XXXXXXX,
    KC_LSFT,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  BBL_SCREENSHOT,  XXXXXXX,          XXXXXXX,  BBL_POWER_DOWN,      XXXXXXX,
    KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,     _______,          XXXXXXX,  XXXXXXX,      XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BBL_UNDO:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("z"));
        return true;
      }
    case BBL_CUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("x"));
        return false;
      }
    case BBL_COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c"));
        return true;
      }
    case BBL_PASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("v"));
        return true;
      }
    case BBL_REDO:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("y"));
        return true;
      }
    case BBL_LOCK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_L) SS_UP(X_LALT) SS_UP(X_LCTRL));
        return true;
      }
    case BBL_SUSPEND:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_SLEP) SS_UP(X_SLEP));
        return true;
      }
    case BBL_POWER_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_PWR) SS_UP(X_PWR));
        return true;
      }
    case BBL_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_PSCR) SS_UP(X_LSFT) SS_UP(X_LGUI));
        return true;
      }
    case BBL_MULTI_TASK_VIEW:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F9) SS_UP(X_LCTRL));
        return true;
      }
    case BBL_APP_WINDOWS:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F7) SS_UP(X_LCTRL));
        return true;
      }
    case BBL_DESKTOP_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
        return true;
      }
    case BBL_DESKTOP_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
        return true;
      }
    case BBL_OS_SEARCH:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI));
        return true;
      }
    case BBL_TERMINAL:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_SPC) SS_UP(X_LALT) SS_UP(X_LCTRL));
        return true;
      }
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  if (layer == GAMING) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
  } else {
    rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
  }

  return state;
}


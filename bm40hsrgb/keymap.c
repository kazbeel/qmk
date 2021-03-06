#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

#include "os_keycodes/os_keycodes.h"


// Mod-tap keys
#define A_CTL     LCTL_T(KC_A)
#define S_ALT     LALT_T(KC_S)
#define D_GUI     LGUI_T(KC_D)
#define F_SFT     LSFT_T(KC_F)

#define J_SFT     LSFT_T(KC_J)
#define K_GUI     LGUI_T(KC_K)
#define L_ALT     LALT_T(KC_L)
#define NTIL_CTL  LCTL_T(ES_NTIL)

// Multifunction layer toggle and simple keycode
#define NAV_TAB   LT(NAV, KC_TAB)

static uint8_t current_os_mode = OK_KEYCODES_LINUX_MODE;
// static uint16_t rgb_os_mode_timer = 0;

enum custom_keycodes {
  NEXT_CUSTOM_KEYCODE = OK_KEYCODES_END_RANGE,
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
    OK_TERMINAL,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,  KC_U,     KC_I,      KC_O,     KC_P,      KC_BSPACE,
    KC_ESC,       A_CTL,    S_ALT,    D_GUI,    F_SFT,    KC_G,    KC_H,  J_SFT,    K_GUI,     L_ALT,    NTIL_CTL,  ES_ACUT,
    KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,  KC_M,     KC_COMMA,  KC_DOT,   ES_MINS,   KC_ENT,
    XXXXXXX,      XXXXXXX,  XXXXXXX,  MO(NUM),  NAV_TAB,  KC_SPC,         MO(SYM),  MO(FUNC),  XXXXXXX,  XXXXXXX,   XXXXXXX
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
    XXXXXXX,  OK_UNDO,  OK_CUT,   OK_COPY,  OK_PASTE, OK_REDO,  KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,    XXXXXXX,  XXXXXXX,
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
    RESET,    XXXXXXX,           RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(GAMING),  XXXXXXX,
    XXXXXXX,  OK_SHIFT_OS_MODE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,     XXXXXXX,
    XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_MUTE,  KC_VOLU,  XXXXXXX,     XXXXXXX,
    XXXXXXX,  XXXXXXX,           XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX
  ),

  [FUNC] = LAYOUT_planck_mit(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,          XXXXXXX,         OK_OS_SEARCH,        XXXXXXX,          OK_LOCK,        XXXXXXX,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  OK_DESKTOP_PREV,  OK_APP_WINDOWS,  OK_MULTI_TASK_VIEW,  OK_DESKTOP_NEXT,  OK_SUSPEND,     XXXXXXX,
    KC_LSFT,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,          OK_SCREENSHOT,   XXXXXXX,             XXXXXXX,          OK_POWER_DOWN,  XXXXXXX,
    KC_LCTL,  KC_LGUI,  KC_LALT,  XXXXXXX,  XXXXXXX,  XXXXXXX,                    XXXXXXX,         _______,             XXXXXXX,          XXXXXXX,        XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool isOsKeycodeProcessed = ok_process_record_user(keycode, record);

  if (isOsKeycodeProcessed) {
    return false;
  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case S_ALT:
    case D_GUI:
    case K_GUI:
    case L_ALT:
      return -1;
    case A_CTL:
    case F_SFT:
    case J_SFT:
    case NTIL_CTL:
      return TAPPING_TERM + 150;
    default:
      return TAPPING_TERM;
  }
}

void matrix_scan_user(void) {
  // Turn off LED 1.5s after changing of OS mode
  // if (timer_elapsed(rgb_os_mode_timer) > 1500) {
  //   rgb_matrix_set_color(41, RGB_OFF);
  //   // rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  //   rgb_os_mode_timer = 0;
  // }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  if (layer == GAMING) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  } else {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  }

  return state;
}


void rgb_matrix_indicators_user(void) {
  uint8_t cur_mode = get_os_mode();

  if (current_os_mode != cur_mode) {
    current_os_mode = cur_mode;
  //   rgb_os_mode_timer = timer_read();
  }

  // switch (cur_mode) {
  //   case OK_KEYCODES_LINUX_MODE:
  //     rgb_matrix_set_color(41, RGB_ORANGE);
  //   break;

  //   case OK_KEYCODES_WINDOWS_MODE:
  //     rgb_matrix_set_color(41, RGB_BLUE);
  //   break;

  //   case OK_KEYCODES_MAC_MODE:
  //     rgb_matrix_set_color(41, RGB_WHITE);
  //   break;
  // }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

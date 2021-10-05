#include QMK_KEYBOARD_H

#include "keymap_spanish.h"


#ifdef OLED_DRIVER_ENABLE
static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
#endif

// Mod-tap keys
#define A_CTL     LCTL_T(KC_A)
#define S_ALT     LALT_T(KC_S)
#define D_GUI     LGUI_T(KC_D)
#define F_SFT     LSFT_T(KC_F)

#define NTIL_CTL  LCTL_T(ES_NTIL)
#define L_ALT     LALT_T(KC_L)
#define K_GUI     LGUI_T(KC_K)
#define J_SFT     LSFT_T(KC_J)

// MacOS edit commands
#define U_UND   LGUI(KC_Z)
#define U_RDO   SGUI(KC_Z)
#define U_CUT   LGUI(KC_X)
#define U_CPY   LGUI(KC_C)
#define U_PST   LGUI(KC_V)

// Multifunction layer toggle and simple keycode
#define NAV_TAB   LT(NAV, KC_TAB)
#define NUM_ENT   LT(NUM, KC_ENT)

// MacOS control
#define CONSOLE           LCTL(LSFT(ES_NTIL))   // Show/Hide quake console (only Mac)
#define LOCK_SCREEN       LCTL(LGUI(KC_Q))      // Lock current user session (only Mac)
#define SUSPEND           LALT(LGUI(KC_POWER))  // Suspend computer (only Mac)
#define SCREENSHOT        LSFT(LGUI(KC_5))      // Open screenshot app
#define MISSION_CONTROL   LCTL(KC_UP)           // Open Mission Control
#define APP_WINS          LCTL(KC_DOWN)         // Show application windows
#define PRV_DSK           LCTL(KC_LEFT)         // Show previous desktop
#define NXT_DSK           LCTL(KC_RIGHT)        // Show next desktop
#define SPOTLIGHT         LGUI(KC_SPC)          // Show Spotlight

enum custom_keycodes {
  APP_CYCLING = SAFE_RANGE,
};

enum layers {
  BASE,
  NAV,
  NUM,
  SYM,
  MEDIA,
  FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    XXXXXXX,  KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,                       KC_Y,     KC_U,   KC_I,      KC_O,    KC_P,      KC_BSPACE,
    KC_ESC,   A_CTL,  S_ALT,  D_GUI,  F_SFT,    KC_G,                       KC_H,     J_SFT,  K_GUI,     L_ALT,   NTIL_CTL,  ES_ACUT,
    KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,     KC_B,                       KC_N,     KC_M,   KC_COMMA,  KC_DOT,  ES_MINS,   XXXXXXX,
                                      CONSOLE,  NAV_TAB,  NUM_ENT,  KC_SPC, MO(SYM),  MO(FUNC)
  ),

  [NAV] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,                      KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  U_UND,    U_CUT,    U_CPY,    U_PST,    U_RDO,                        KC_HOME,  KC_PGDOWN,  KC_PGUP,  KC_END,    XXXXXXX,  XXXXXXX,
                                            _______,  _______,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
  ),

  [NUM] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_PERC,  KC_7,  KC_8,  KC_9,  KC_PSLS,  KC_BSPACE,
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,                      ES_LPRN,  KC_4,  KC_5,  KC_6,  KC_PPLS,  KC_PAST,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      ES_RPRN,  KC_1,  KC_2,  KC_3,  KC_PMNS,  ES_EQL,
                                            XXXXXXX,  XXXXXXX,  _______,  _______,  KC_0,  KC_DOT
  ),

  [SYM] = LAYOUT(
    ES_CIRC,        ES_PIPE,  ES_AT,    KC_PERC,  KC_DLR,     XXXXXXX,                      XXXXXXX,  ES_LBRC,  ES_RBRC,  ES_IQUE,  ES_QUES,  KC_DELETE,
    LALT(ES_NTIL),  ES_AMPR,  ES_HASH,  ES_BSLS,  ES_SLSH,    XXXXXXX,                      XXXXXXX,  ES_LPRN,  ES_RPRN,  ES_EQL,   ES_PLUS,  ES_ASTR,
    XXXXXXX,        ES_LESS,  ES_GRTR,  ES_DQUO,  ES_APOS,    ES_GRV,                       XXXXXXX,  ES_LCBR,  ES_RCBR,  ES_IEXL,  KC_EXLM,  XXXXXXX,
                                                  XXXXXXX,  MO(MEDIA),  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
  ),

  [MEDIA] = LAYOUT(
    RESET,    XXXXXXX,  RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  KC_VOLD,  KC_MUTE,  KC_VOLU,  XXXXXXX,  XXXXXXX,
                                            XXXXXXX,  _______,  XXXXXXX, _______,  XXXXXXX,  XXXXXXX
  ),

  [FUNC] = LAYOUT(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,                     XXXXXXX,  XXXXXXX,     SPOTLIGHT,        APP_CYCLING,  LOCK_SCREEN,  XXXXXXX,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,                     PRV_DSK,  APP_WINS,    MISSION_CONTROL,  NXT_DSK,      SUSPEND,      XXXXXXX,
    XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,                     XXXXXXX,  SCREENSHOT,  XXXXXXX,          XXXXXXX,      XXXXXXX,      XXXXXXX,
                                            XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  _______
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
    if (timer_elapsed(app_cycling_timer) > 750) {
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
    case A_CTL:
    case S_ALT:
    case D_GUI:
    case F_SFT:
      return TAPPING_TERM + 50;
    case J_SFT:
    case K_GUI:
    case L_ALT:
    case NTIL_CTL:
      return TAPPING_TERM + 50;
    case NAV_TAB:
      return 50;
    default:
      return TAPPING_TERM;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAV_TAB:
      return true;
    default:
      return false;
  }
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void render_layer_state(void) {
  oled_write_P(PSTR("Layr:"), false);

  switch (biton32(layer_state)) {
    case BASE:
      oled_write_P(PSTR(" DFLT"), false);
      break;
    case NAV:
      oled_write_P(PSTR("  NAV"), false);
      break;
    case NUM:
      oled_write_P(PSTR("  NUM"), false);
      break;
    case SYM:
      oled_write_P(PSTR("  SYM"), false);
      break;
    case MEDIA:
      oled_write_P(PSTR("MEDIA"), false);
      break;
    case FUNC:
      oled_write_P(PSTR(" FUNC"), false);
      break;
    default:
      oled_write_P(PSTR("?????"), false);
      break;
  }
}

void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("     "), false);
  oled_write_P(PSTR("Mods:"), false);
  oled_write_P(PSTR(" SHFT"), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR(" CTRL"), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR(" META"), (modifiers & MOD_MASK_GUI));
  oled_write_P(PSTR("  ALT"), (modifiers & MOD_MASK_ALT));
}

void render_status_main(void) {
  render_layer_state();
  render_mod_status(get_mods() | get_oneshot_mods());
}

void render_crkbd_logo(void) {
  oled_write_P(crkbd_logo, false);
}

void render_status_secondary(void) {
  render_crkbd_logo();
  oled_scroll_left();
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    render_status_secondary();
  }
}

#endif /* OLED_DRIVER_ENABLE */


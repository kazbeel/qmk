#include "os_keycodes.h"


static bool ok_process_keycode(uint16_t keycode);


// returns whether the keycode has been processed (true) or not (false)
extern bool ok_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (keycode > OS_KEYCODES_START_RANGE && keycode < OS_KEYCODES_END_RANGE) {
		if (record->event.pressed) {
			return ok_process_keycode(keycode);
		}
	}

	return false;
}


// returns whether the keycode has been processed (true) or not (false)
static bool ok_process_keycode(uint16_t keycode) {
	if (keycode == OS_KEYCODES_COPY) {
    SEND_STRING(SS_LCTL("c"));
	} else if (keycode == OS_KEYCODES_CUT) {
    SEND_STRING(SS_LCTL("x"));
	} else if (keycode == OK_KEYCODES_PASTE) {
    SEND_STRING(SS_LCTL("v"));
	} else if (keycode == OK_KEYCODES_UNDO) {
    SEND_STRING(SS_LCTL("z"));
	} else if (keycode == OK_KEYCODES_REDO) {
    SEND_STRING(SS_LCTL("y"));
	} else if (keycode == OK_KEYCODES_LOCK) {
    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_L) SS_UP(X_LALT) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_SUSPEND) {
		SEND_STRING(SS_DOWN(X_SLEP) SS_UP(X_SLEP));
	} else if (keycode == OK_KEYCODES_POWER_DOWN) {
		SEND_STRING(SS_DOWN(X_PWR) SS_UP(X_PWR));
	} else if (keycode == OK_KEYCODES_SCREENSHOT) {
		SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_PSCR) SS_UP(X_LSFT) SS_UP(X_LGUI));
	} else if (keycode == OK_KEYCODES_MULTI_TASK_VIEW) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F9) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_APP_WINDOWS) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_F7) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_DESKTOP_NEXT) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_DESKTOP_PREV) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_OS_SEARCH) {
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI));
	} else if (keycode == OK_KEYCODES_TERMINAL) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_SPC) SS_UP(X_LALT) SS_UP(X_LCTRL));
	} else {
		// Let other custom keys to be processed
		return true;
	}

	return false;
}

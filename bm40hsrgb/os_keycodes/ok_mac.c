#include "os_keycodes.h"

bool ok_process_keycode_mac(uint16_t keycode) {
	if (keycode == OK_KEYCODES_COPY) {
    SEND_STRING(SS_LGUI("c"));
	} else if (keycode == OK_KEYCODES_CUT) {
    SEND_STRING(SS_LGUI("x"));
	} else if (keycode == OK_KEYCODES_PASTE) {
    SEND_STRING(SS_LGUI("v"));
	} else if (keycode == OK_KEYCODES_UNDO) {
    SEND_STRING(SS_LGUI("z"));
	} else if (keycode == OK_KEYCODES_REDO) {
    SEND_STRING(SS_LGUI("y"));
	} else if (keycode == OK_KEYCODES_LOCK) {
    SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LGUI) SS_TAP(X_Q) SS_UP(X_LGUI) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_SUSPEND) {
		SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_TAP(X_POWER) SS_UP(X_LGUI) SS_UP(X_LALT));
	} else if (keycode == OK_KEYCODES_POWER_DOWN) {
		SEND_STRING(SS_DOWN(X_PWR) SS_UP(X_PWR));
	} else if (keycode == OK_KEYCODES_SCREENSHOT) {
		SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_5) SS_UP(X_LGUI) SS_UP(X_LSFT));
	} else if (keycode == OK_KEYCODES_MULTI_TASK_VIEW) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_UP) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_APP_WINDOWS) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_DOWN) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_DESKTOP_NEXT) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_DESKTOP_PREV) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_LEFT) SS_UP(X_LCTRL));
	} else if (keycode == OK_KEYCODES_OS_SEARCH) {
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI));
	} else if (keycode == OK_KEYCODES_TERMINAL) {
		SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_SPC) SS_UP(X_LALT) SS_UP(X_LCTRL));
	} else {
		return false;
	}

	return true;
}
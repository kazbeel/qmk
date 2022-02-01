#include "os_keycodes.h"


uint8_t os_mode = OK_KEYCODES_LINUX_MODE;


static bool ok_process_keycode(uint16_t keycode);


// returns whether the keycode has been processed (true) or not (false)
bool ok_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (keycode > OK_KEYCODES_START_RANGE && keycode < OK_KEYCODES_END_RANGE) {
		if (record->event.pressed) {
			return ok_process_keycode(keycode);
		}
	}

	return false;
}

void set_os_mode(uint8_t mode) {
	os_mode = mode;
}

uint8_t get_os_mode(void) {
	return os_mode;
}

// returns whether the keycode has been processed (true) or not (false)
static bool ok_process_keycode(uint16_t keycode) {
	if (keycode == OK_KEYCODES_SET_MODE_LINUX) {
		set_os_mode(OK_KEYCODES_LINUX_MODE);
		return true;
	}

	if (keycode == OK_KEYCODES_SET_MODE_WINDOWS) {
		set_os_mode(OK_KEYCODES_WINDOWS_MODE);
		return true;
	}

	if (keycode == OK_KEYCODES_SET_MODE_MAC) {
		set_os_mode(OK_KEYCODES_MAC_MODE);
		return true;
	}

	if (os_mode == OK_KEYCODES_LINUX_MODE) {
		return ok_process_keycode_linux(keycode);
	}

	if (os_mode == OK_KEYCODES_WINDOWS_MODE) {
		return ok_process_keycode_windows(keycode);
	}

	if (os_mode == OK_KEYCODES_MAC_MODE) {
		return ok_process_keycode_mac(keycode);
	}

	return false;
}

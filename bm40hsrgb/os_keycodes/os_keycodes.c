#include "os_keycodes.h"


uint8_t os_mode = OS_KEYCODES_LINUX_MODE;


static bool ok_process_keycode(uint16_t keycode);


// returns whether the keycode has been processed (true) or not (false)
bool ok_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (keycode > OS_KEYCODES_START_RANGE && keycode < OS_KEYCODES_END_RANGE) {
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
		set_os_mode(OS_KEYCODES_LINUX_MODE);
		return true;
	}

	if (os_mode == OS_KEYCODES_LINUX_MODE) {
		return ok_process_keycode_linux(keycode);
	}

	return false;
}

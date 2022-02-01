#pragma once

#include "quantum.h"


#if defined(NEW_SAFE_RANGE)
#		define OS_KEYCODES_START_RANGE NEW_SAFE_RANGE
#elif defined(KEYMAP_SAFE_RANGE)
#		define OS_KEYCODES_START_RANGE KEYMAP_SAFE_RANGE
#else
#		define OS_KEYCODES_START_RANGE SAFE_RANGE
#endif

enum os_modes {
  OS_KEYCODES_LINUX_MODE,
	OS_KEYCODES_WINDOWS_MODE,
	OS_KEYCODES_MAC_MODE
};

enum os_keycodes {
	OS_KEYCODES_FIRST = OS_KEYCODES_START_RANGE,
  OS_KEYCODES_COPY,
  OS_KEYCODES_CUT,
  OK_KEYCODES_PASTE,
  OK_KEYCODES_UNDO,
  OK_KEYCODES_REDO,
  OK_KEYCODES_LOCK,
  OK_KEYCODES_SUSPEND,
  OK_KEYCODES_POWER_DOWN,
  OK_KEYCODES_SCREENSHOT,
  OK_KEYCODES_MULTI_TASK_VIEW,
  OK_KEYCODES_APP_WINDOWS,
  OK_KEYCODES_DESKTOP_NEXT,
  OK_KEYCODES_DESKTOP_PREV,
  OK_KEYCODES_OS_SEARCH,
  OK_KEYCODES_TERMINAL,

	OK_KEYCODES_SET_MODE_LINUX,

	OS_KEYCODES_END_RANGE
};

#define OK_COPY OS_KEYCODES_COPY
#define OK_CUT OS_KEYCODES_CUT
#define OK_PASTE OK_KEYCODES_PASTE
#define OK_UNDO OK_KEYCODES_UNDO
#define OK_REDO OK_KEYCODES_REDO
#define OK_LOCK OK_KEYCODES_LOCK
#define OK_SUSPEND OK_KEYCODES_SUSPEND
#define OK_POWER_DOWN OK_KEYCODES_POWER_DOWN
#define OK_SCREENSHOT OK_KEYCODES_SCREENSHOT
#define OK_MULTI_TASK_VIEW OK_KEYCODES_MULTI_TASK_VIEW
#define OK_APP_WINDOWS OK_KEYCODES_APP_WINDOWS
#define OK_DESKTOP_NEXT OK_KEYCODES_DESKTOP_NEXT
#define OK_DESKTOP_PREV OK_KEYCODES_DESKTOP_PREV
#define OK_OS_SEARCH OK_KEYCODES_OS_SEARCH
#define OK_TERMINAL OK_KEYCODES_TERMINAL

#define OK_SET_LINUX_MODE OK_KEYCODES_SET_MODE_LINUX

void set_os_mode(uint8_t mode);
uint8_t get_os_mode(void);

bool ok_process_record_user(uint16_t keycode, keyrecord_t *record);

bool ok_process_keycode_linux(uint16_t keycode);

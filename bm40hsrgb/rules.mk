SRC += os_keycodes/os_keycodes.c

BOOTMAGIC_ENABLE = lite
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

ifeq ($(strip $(OS_WINDOWS)), yes)
	OPT_DEFS += -DOS_WINDOWS
endif

ifeq ($(strip $(OS_MAC)), yes)
	OPT_DEFS += -DOS_MAC
endif


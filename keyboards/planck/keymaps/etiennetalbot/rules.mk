#SRC += muse.c
# SRC += rgblight.c
# SRC += ws2812.c

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE = no
# RGBLIGHT_ENABLE = WS2812        # Enable WS2812 RGB underlight.
# BACKLIGHT_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = yes
UNICODE_ENABLE = yes

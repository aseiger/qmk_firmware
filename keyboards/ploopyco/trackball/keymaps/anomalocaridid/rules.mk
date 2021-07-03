# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# Enable desired features
LTO_ENABLE = yes     # Enable Link Time Optimization

# Disable unused features
EXTRAKEY_ENABLE = no # Disable system control keys
MOUSEKEY_ENABLE = no # Disable extra mouse keys

SRC += anomalocaridid.c
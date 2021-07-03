#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

#include QMK_KEYBOARD_H

enum custom_keycodes_user {
#if defined(KEYBOARD_ergodox_ez)
    VRSN = EZ_SAFE_RANGE,
#elif defined(KEYBOARD_ploopyco_trackball_rev1_005)
    VRSN = PLOOPY_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    FLASH,  // Type qmk command for flashing firmware
    KEYMAP_SAFE_RANGE,
};
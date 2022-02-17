#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

<<<<<<< HEAD
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

#define SELECT_SOFT_SERIAL_SPEED 1
#define OLED_TIMEOUT 6000000
=======

#define SELECT_SOFT_SERIAL_SPEED 0
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define OLED_TIMEOUT 6000000

>>>>>>> 2eec0072c798fff004c5ad5f17f308c4acd2c976

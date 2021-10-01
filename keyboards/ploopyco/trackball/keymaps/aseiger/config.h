/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
// Settings
#define PLOOPY_DRAGSCROLL_FIXED 
#define PLOOPY_DRAGSCROLL_DPI 100
#define PLOOPY_DRAGSCROLL_INVERT

#define PLOOPY_DPI_OPTIONS { 200, 700, 1200, 1600, 2400 }

// Disable unused features
#define NO_ACTION_ONESHOT

#define OPT_DEBOUNCE 1

#define PLOOPY_DRAGSCROLL_MOMENTARY

#define TAPPING_TERM 250

#define SCROLL_THRESH_RANGE_LIM 5
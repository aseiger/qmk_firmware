// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
	KC_SCROLL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬──────┬──────┬──────┬───┬─────┬─────┬───┬──────┬──────┬──────┬──────┐
     * │ GESC │    1 │    2 │    3 │ 4 │   5 │   6 │ 7 │    8 │    9 │    0 │ BSPC │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │ TAB  │    Q │    W │    E │ R │   T │   Y │ U │    I │    O │    P │  |   │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │ CAPS │    A │    S │    D │ F │   G │   H │ J │    K │    L │    ; │    " │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │ LSFT │    Z │    X │    C │ V │   B │   N │ M │    , │    . │    / │ RSFT │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │      │ LCTL │ LGUI │ LALT │ RS│ SPC │ SPC │ LR│ RALT │ RGUI │ RCTL │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │ML │  MC │  MR │   │      │      │      │      │
     * └──────┴──────┴──────┴──────┴───┴─────┴─────┴───┴──────┴──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT_ortho_6x12(
        QK_GESC,     KC_1,        KC_2,        KC_3,        KC_4,        KC_5,         KC_6,         KC_7,      KC_8,        KC_9,        KC_0,        KC_BSPC,
        KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,         KC_Y,         KC_U,      KC_I,        KC_O,        KC_P,        KC_PIPE,
        KC_CAPS,     KC_A,        KC_S,        KC_D,        KC_F,        KC_G,         KC_H,         KC_J,      KC_K,        KC_L,        KC_SCLN,     KC_QUOT,
        KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,         KC_N,         KC_M,      KC_COMM,     KC_DOT,      KC_SLSH,     SFT_T(KC_ENT),
        KC_SCROLL,   KC_LCTL,     KC_LGUI,     KC_LALT,     KC_LOWER,    KC_SPC,       KC_SPC,       KC_RAISE,  KC_RALT,     KC_RGUI,     KC_RCTL,     KC_NO,
		KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_BTN1,     KC_BTN3,      KC_BTN2,      KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO
    ),
	
    /*
     * ┌──────┬──────┬──────┬──────┬───┬─────┬─────┬───┬──────┬──────┬──────┬──────┐
     * │ESC   │   F1 │   F2 │   F3 │F4 │  F5 │  F6 │F7 │   F8 │   F9 │  F10 │ F11  │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │ `    │    1 │    2 │    3 │ 4 │   5 │   6 │ 7 │    8 │    9 │    0 │  F12 │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │      │    ! │    @ │    # │ $ │   % │   ^ │ & │    * │    ( │    ) │    | │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │ LSFT │    = │    - │    + │ { │   } │   [ │ ] │    ; │    : │    \ │ RSFT │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
     * │      │ LCTL │ LGUI │ LALT │   │ SPC │  _  │   │ RALT │ RGUI │ RCTL │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼───┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │ML │  MC │  MR │   │      │      │      │      │
     * └──────┴──────┴──────┴──────┴───┴─────┴─────┴───┴──────┴──────┴──────┴──────┘
     */
    [_LOWER] = LAYOUT_ortho_6x12(
        KC_ESC,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,        KC_F6,        KC_F7,     KC_F8,       KC_F9,       KC_F10,      KC_F11,
        KC_GRV,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,         KC_6,         KC_7,      KC_8,        KC_9,        KC_0,        KC_F12,
        KC_NO,       KC_EXLM,     KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,      KC_CIRC,      KC_AMPR,   KC_ASTR,     KC_LPRN,     KC_RPRN,     KC_PIPE,
        KC_LSFT,     KC_EQL,      KC_MINS,     KC_PLUS,     KC_LCBR,     KC_RCBR,      KC_LBRC,      KC_RBRC,   KC_SCLN,     KC_COLN,     KC_BSLS,     SFT_T(KC_ENT),
        KC_SCROLL,   KC_LCTL,     KC_LGUI,     KC_LALT,     KC_TRNS,     KC_SPC,       KC_UNDS,      KC_TRNS,   KC_RALT,     KC_RGUI,     KC_RCTL,     KC_NO,
		KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_BTN1,     KC_BTN3,      KC_BTN2,      KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO
    ),
	
    /*
     * ┌──────┬──────┬──────┬──────┬───┬─────┬─────┬──────┬──────┬──────┬──────┬──────┐
     * │      │      │      │      │   │     │     │      │PGup  │      │      │ DEL  │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ ESC  │  Ins │  PSC │ Menu │   │     │     │      │  Up  │      │      │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ Tab  │      │      │      │   │     │  Hm │ Left │ Down │Right │  end │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ LSFT │      │      │      │   │     │     │      │Pgdn  │      │      │ RSFT │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ LCTL │ LGUI │ LALT │   │ _   │ SPC │      │ RALT │ RGUI │ RCTL │ Enter│
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │ML │  MC │  MR │      │      │      │      │      │
     * └──────┴──────┴──────┴──────┴───┴─────┴─────┴──────┴──────┴──────┴──────┴──────┘
     */
    [_RAISE] = LAYOUT_ortho_6x12(
        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_PGUP,     KC_NO,       KC_NO,       KC_DEL,
        KC_ESC,      KC_INS,      KC_PSCR,     KC_APP,      KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_UP,       KC_NO,       KC_NO,       KC_NO,
        KC_TAB,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_HOME,      KC_LEFT,   KC_DOWN,     KC_RGHT,     KC_END,      KC_NO,
        KC_LSFT,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_PGDN,     KC_NO,       KC_NO,       KC_RSFT,
        KC_SCROLL,   KC_LCTL,     KC_LGUI,     KC_LALT,     KC_TRNS,     KC_UNDS,      KC_SPC,       KC_TRNS,   KC_RALT,     KC_RGUI,     KC_RCTL,     KC_ENT,
		KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_BTN1,     KC_BTN2,      KC_BTN3,      KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO
    ),
	
	    /*
     * ┌──────┬──────┬──────┬──────┬───┬─────┬─────┬──────┬──────┬──────┬──────┬──────┐
     * │      │      │      │      │   │     │     │      │PGup  │      │      │ DEL  │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ ESC  │  Ins │  PSC │ Menu │   │     │     │      │  Up  │      │      │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ Tab  │      │      │      │   │     │  Hm │ Left │ Down │Right │  end │      │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │ LSFT │      │      │      │   │     │     │      │Pgdn  │      │      │ RSFT │
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ LCTL │ LGUI │ LALT │   │ _   │ SPC │      │ RALT │ RGUI │ RCTL │ Enter│
     * ├──────┼──────┼──────┼──────┼───┼─────┼─────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │ML │  MC │  MR │      │      │      │      │      │
     * └──────┴──────┴──────┴──────┴───┴─────┴─────┴──────┴──────┴──────┴──────┴──────┘
     */
    [_ADJUST] = LAYOUT_ortho_6x12(
        QK_BOOT,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_PGUP,     KC_NO,       KC_NO,       KC_DEL,
        KC_ESC,      KC_INS,      KC_PSCR,     KC_APP,      KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_UP,       KC_NO,       KC_NO,       KC_NO,
        KC_TAB,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_HOME,      KC_LEFT,   KC_DOWN,     KC_RGHT,     KC_END,      KC_NO,
        KC_LSFT,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,     KC_PGDN,     KC_NO,       KC_NO,       KC_RSFT,
        KC_SCROLL,   KC_LCTL,     KC_LGUI,     KC_LALT,     KC_TRNS,     KC_UNDS,      KC_SPC,       KC_TRNS,   KC_RALT,     KC_RGUI,     KC_RCTL,     KC_ENT,
		KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_BTN1,     KC_BTN3,      KC_BTN2,      KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO
    )
};

bool drag_scroll = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
		case KC_SCROLL:
		    if (record->event.pressed) {
                drag_scroll = true;
            } else {
                drag_scroll = false;
            }
            return false;
    }
    return true;
}

void keyboard_pre_init_user(void) {
	gpio_set_pin_output(GP22);
	gpio_write_pin_high(GP22);
	
	gpio_set_pin_output(GP26);
	gpio_write_pin_high(GP26);
	
	gpio_set_pin_output(GP28);
	gpio_write_pin_high(GP28);
}

void pointing_device_init_user(void)
{
	pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0xFF);
}

#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
{
	if (drag_scroll)
	{
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)-mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
	}
	
	return mouse_report;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case _LOWER:
			gpio_write_pin_low(GP22);
			gpio_write_pin_high(GP26);
			gpio_write_pin_high(GP28);
			pimoroni_trackball_set_rgbw(0xFF, 0x00, 0x00, 0x00);
			pimoroni_trackball_set_cpi(16000);
			break;
		case _RAISE:
			gpio_write_pin_high(GP22);
			gpio_write_pin_low(GP26);
			gpio_write_pin_high(GP28);
			pimoroni_trackball_set_rgbw(0x00, 0xFF, 0x00, 0x00);
			break;
		case _ADJUST:
			gpio_write_pin_high(GP22);
			gpio_write_pin_high(GP26);
			gpio_write_pin_low(GP28);
			pimoroni_trackball_set_rgbw(0x00, 0x00, 0xFF, 0x00);
		    break;
		default:
			gpio_write_pin_high(GP22);
			gpio_write_pin_high(GP26);
			gpio_write_pin_high(GP28);
			pimoroni_trackball_set_cpi(64000);
			pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0xFF);
			break;
	}
	return state;
}
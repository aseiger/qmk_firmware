/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "version.h"
// userspace code
#include "pointing_device.h"

enum layers {
    BASE,  // default layer
    SCRL,  // scroll modifier layer
    XTRA,  // extra mouse buttons
};

// Tap Dance declarations
enum td_keycodes{
    XTRA_LP,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_DOUBLE_SINGLE_HOLD
} td_state_t;

static td_state_t td_state;
td_state_t cur_dance(qk_tap_dance_state_t *state);
void xtra_lp_finished(qk_tap_dance_state_t *state, void *user_data);
void xtra_lp_reset(qk_tap_dance_state_t *state, void *user_data);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2, // Primary Buttons
        TD(XTRA_LP), KC_BTN5         // Secondary Buttons
    ),

    [SCRL] = LAYOUT(
        DRAG_SCROLL, RESET, KC_BTN4,
        _______, DPI_CONFIG
    ),
};

extern uint16_t dpi_array[];

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_SINGLE_TAP;
        else return TD_DOUBLE_SINGLE_HOLD;
    }
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void xtra_lp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.buttons |= 1 << (KC_MS_BTN4 - KC_MS_BTN1);
                pointing_device_set_report(currentReport);
                pointing_device_send();
            }
            break;
        case TD_DOUBLE_SINGLE_HOLD:
            layer_on(SCRL);
            break;
        default:
          break;
    }
}

void xtra_lp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.buttons &= ~(1 << (KC_MS_BTN4 - KC_MS_BTN1));
                pointing_device_set_report(currentReport);
                pointing_device_send();
            }
            break;
        case TD_DOUBLE_SINGLE_HOLD:
            layer_off(SCRL);
            break;
       default:
           break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [XTRA_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xtra_lp_finished, xtra_lp_reset)
};

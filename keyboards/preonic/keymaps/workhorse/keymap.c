/* Copyright 2015-2017 Jack Humbert
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
#include "host_os.h"
#include "os_detection.h"
#include "muse.h"

enum preonic_layers {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  {}  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /   |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Alt  | GUI  |  FN  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_preonic_grid(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOTE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LEAD, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  {}  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Alt  | GUI  |Lower |  FN  |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_preonic_grid(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOTE,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC,
        KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LEAD, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  {}  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Bksp |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Alt  | GUI  |Lower |  FN  |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_preonic_grid(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_QUOTE,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_LBRC,
        KC_BSPC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LEAD, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  -   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  |Right |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_preonic_grid(
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINUS,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        KC_SHIFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END, KC_SHIFT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Caps |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  |Right |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_preonic_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_preonic_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, RESET, DEBUG, _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, _______,
        _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, COLEMAK, DVORAK, _______, _______,
        _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, 0, 0, 0});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_GREEN});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_RED});
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_PURPLE});
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_WHITE});
const rgblight_segment_t PROGMEM leader_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 8, HSV_BLUE });

// Later layers take precedence.
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    lower_layer,
    raise_layer,
    adjust_layer,
    capslock_layer,
    leader_layer,
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(0, true);
}

bool led_update_user(led_t led_state) {
    // Turn on RBG for capslock.
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Set RBG layer according to active keymap layer.
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 1) && layer_state_cmp(state, 2));
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
    }
    return true;
};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

os_variant_t os;

void matrix_init_user(void) {
    os = detected_host_os();
}

#ifdef LEADER_ENABLE
    LEADER_EXTERNS();
#endif

void matrix_scan_user(void) {
    #ifdef LEADER_ENABLE

    LEADER_DICTIONARY() {
        // OS Check
        bool isMac = os === OS_MACOS;

        // Initialize did_leader_succeed as well as leading to be false
        did_leader_succeed = leading = false;

        // You can use SEQ_ONE_KEY, SEQ_TWO_KEYS, SEQ_THREE_KEYS,
        // SEQ_FOUR_KEYS, SEQ_FIVE_KEYS to define your sequences.

        /*  CapsLock */
        SEQ_ONE_KEY(KC_BSPC) {
            tap_code(KC_CAPS);
            did_leader_succeed = true;
        }

         /*  çÇ      => LdrKey > C */
        SEQ_ONE_KEY(KC_C) {
            if (isMac) {
                SEND_STRING(SS_LALT("c"));
            } else {
                IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ? SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P2) SS_TAP(X_P8) SS_UP(X_LALT)) : SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P3) SS_TAP(X_P5) SS_UP(X_LALT));
            }
            did_leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_K) {
            // Page Up: Leader > K
            isMac ? SEND_STRING(SS_TAP(X_HOME)) : SEND_STRING(SS_LCTL(SS_TAP(X_HOME)));
            did_leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_J) {
            // Page Down: Leader > J
            isMac ? SEND_STRING(SS_TAP(X_END)): SEND_STRING(SS_LCTL(SS_TAP(X_END)));
            did_leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_X) {
            // Close Current App: Leader > X
            isMac ? SEND_STRING(SS_LGUI(SS_TAP(X_Q))) : SEND_STRING(SS_LALT(SS_TAP(X_F4)));
            did_leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_C) {
            // Printscreen: Leader > C
            isMac ? SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4)))) : SEND_STRING(SS_TAP(X_PSCR));
            did_leader_succeed = true;
        }

        /*  Show Desktop            => LdrKey > D */
        SEQ_ONE_KEY(KC_D) {
            onMac ? SEND_STRING(SS_LGUI(SS_TAP(X_SPC)) "Mission" SS_TAP(X_ENT)) : SEND_STRING(SS_LGUI(SS_TAP(X_D)));
            did_leader_succeed = true;
        }

         /*  <=      => LdrKey > , > , */
        SEQ_TWO_KEYS(KC_COMM, KC_COMM) {
            SEND_STRING(SS_LSFT(SS_TAP(X_COMM)) SS_TAP(X_SPC) SS_TAP(X_EQL) SS_TAP(X_LEFT) SS_TAP(X_BSPC) SS_TAP(X_RIGHT));
            did_leader_succeed = true;
        }

         /*  =>      => LdrKey > . > . */
        SEQ_TWO_KEYS(KC_DOT, KC_DOT) {
            SEND_STRING("=>");
            did_leader_succeed = true;
        }

        /*  Backward delete current word (on cursor) */
        SEQ_TWO_KEYS(KC_LEFT, KC_BSPC, KC_BSPC) {
            isMac ? SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)) SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC)) : SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)) SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
            did_leader_succeed = true;
        }
        /*  Previous word delete */
        SEQ_ONE_KEY(KC_LEFT, KC_BSPC) {
            isMac ? SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC)) : SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
            did_leader_succeed = true;
        }
        /*  Forward delete current word (on cursor) */
        SEQ_TWO_KEYS(KC_RGHT, KC_BSPC, KC_BSPC) {
            isMac ? SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))) SS_TAP(X_DEL)) : SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))) SS_TAP(X_DEL));
            did_leader_succeed = true;
        }
        /*  Next word delete */
        SEQ_ONE_KEY(KC_RGHT, KC_BSPC) {
            isMac ? SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))) SS_TAP(X_DEL)): SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))) SS_TAP(X_DEL));
            did_leader_succeed = true;
        }

         /*  Select everything on this line before cursor => LdrKey > Left */
        SEQ_ONE_KEY(KC_LEFT) {
            isMac ? SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_LEFT)))) : SEND_STRING(SS_LSFT(SS_TAP(X_HOME)));
            did_leader_succeed = true;
        }
        /*  Select everything on this line after cursor  => LdrKey > Right */
        SEQ_ONE_KEY(KC_RGHT) {
            isMac ? SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_RIGHT)))) : SEND_STRING(SS_LSFT(SS_TAP(X_END)));
            did_leader_succeed = true;
        }
        /*  Select everything on this line before cursor and bring on previous line => LdrKey > Left > Left */
        SEQ_TWO_KEYS(KC_LEFT, KC_LEFT) {
            isMac ? SEND_STRING(SS_LSFT(SS_TAP(X_UP) SS_LGUI(SS_TAP(X_RIGHT)))) : SEND_STRING(SS_LSFT(SS_TAP(X_UP) SS_TAP(X_END)));
            did_leader_succeed = true;
        }
        /*  Select everything on this line  => LdrKey > Right > Left */
        SEQ_TWO_KEYS(KC_RGHT, KC_LEFT) {
            isMac ? SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT) SS_LSFT(SS_LGUI(SS_TAP(X_LEFT))))) : SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)));
            did_leader_succeed = true;
        }
        /*  Select 1x Page Up on the page before the cursor  => LdrKey > Up */
        SEQ_ONE_KEY(KC_UP) {
            SEND_STRING(SS_LSFT(SS_TAP(X_PGUP)));
            did_leader_succeed = true;
        }
        /*  Select 1x Page Down on the page after the cursor => LdrKey > Down */
        SEQ_ONE_KEY(KC_DOWN) {
            SEND_STRING(SS_LSFT(SS_TAP(X_PGDN)));
            did_leader_succeed = true;
        }
        /*  Select everything on the page before the cursor => LdrKey > Up > Up */
        SEQ_TWO_KEYS(KC_UP, KC_UP) {
            isMac ? SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_UP)))) : SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_HOME))));
            did_leader_succeed = true;
        }
        /*  Select everything on the page after the cursor => LdrKey > Down > Down */
        SEQ_TWO_KEYS(KC_DOWN, KC_DOWN) {
            isMac ? SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_DOWN)))) : SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_END))));
            did_leader_succeed = true;
        }

        SEQ_ONE_KEY(KC_SLSH) {
            // ://: Leader > /
            SEND_STRING("://");
            did_leader_succeed = true;
        }

        SEQ_THREE_KEYS(KC_P, KC_V, KC_T) {
            // Private Window: Leader > PVT
            SEND_STRING(SS_LCTL(SS_LSFT('n')));
            did_leader_succeed = true;
        }

        SEQ_FOUR_KEYS(KC_C, KC_O, KC_R, KC_T) {
            // Cortana: Leader > CORT
            SEND_STRING(SS_LGUI(SS_TAP(X_C)));
            did_leader_succeed = true;
        }

        SEQ_THREE_KEYS(KC_U, KC_N, KC_D) {
            // Underscore: Leader > UND
            SEND_STRING('_');
            did_leader_succeed = true;
        }

        SEQ_FOUR_KEYS(KC_P, KC_L, KC_U, KC_S) {
            // Plus Sign: Leader > PLUS
            SEND_STRING('+');
            did_leader_succeed = true;
        }

        SEQ_FIVE_KEYS(KC_M, KC_I, KC_N, KC_U, KC_S) {
            // Minus Sign: Leader > MINUS
            SEND_STRING('-');
            did_leader_succeed = true;
        }

        SEQ_FIVE_KEYS(KC_E, KC_Q, KC_U, KC_A, KC_L) {
            // Equal Sign: Leader > EQUAL
            SED_STRING('=');
            did_leader_succeed = true;
        }

        // Call leader_end at the end of the function, instead of at
        // the start. This way, we're sure we have set did_leader_succeed.
        leader_end();
    }
    #endif

    #ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
    #endif
}

#ifdef AUDIO_ENABLE
    float leader_start[][2] = SONG(TERMINAL_SOUND);
    float leader_success[][2] = SONG(UNICODE_WINDOWS);
    float leader_failure[][2] = SONG(UNICODE_LINUX);
#endif

void leader_start(void) {
    PLAY_SONG(leader_start);
    // Turn on RGB for leader
    rgblight_set_layer_state(5, true);
}

void leader_end(void) {
    if (did_leader_succeed) {
        PLAY_SONG(leader_success);
    } else {
        PLAY_SONG(leader_failure);
    }

    // Turn off RGB for leader
    rgblight_set_layer_state(5, false);
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}


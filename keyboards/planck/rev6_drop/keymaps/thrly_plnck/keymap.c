/* thrly's PLANCK (rev.6_drop) keymap */

#include QMK_KEYBOARD_H

enum planck_layers {
  _BASE,
  _NAVIGATION,
  _SYMBOL,
  _NUMBER,
  _ADJUST
};

/* enum {TD_CAPS}; */

/* #define SYMBOL MO(_SYMBOL) */

/* COMBOS */
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_dash[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM combo_quote[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_dquote[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_colon, KC_COLN),
    COMBO(combo_dash, KC_MINUS),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_underscore, S(KC_MINUS)),
    COMBO(combo_quote, KC_QUOT),
    COMBO(combo_dquote, KC_AT),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_equal, KC_EQUAL)
};

/* HOME-ROW MODS */
// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Tap Dance definitions
/* tap_dance_action_t tap_dance_actions[] = { */
/*     // Tap once for Caps Word, twice for Caps Lock */
/*     [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(CW_TOGG, KC_CAPS), */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE (Default)
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  | <- HOME-ROW MODS (GASC order)
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  NAV |  SPC |    SPACE    | BKSP | SYMB |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_BASE] = LAYOUT_planck_1x2uC(
        KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,                  KC_CAPS,  CW_TOGG,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HOME_A,  HOME_S,  HOME_D,  HOME_F,      KC_G,                  KC_VOLD,  KC_VOLU,     KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,                  KC_F20,   KC_F21,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT,  LT(_NAVIGATION,KC_SPC),   LT(_NUMBER,KC_ENT),    LT(_SYMBOL,KC_BSPC),KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL
    ),

/* NAVIGATION
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_NAVIGATION] = LAYOUT__C(
        MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_BTN1,                                   KC_MPRV, KC_MNXT,  MS_BTN1, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
        LGUI_T(KC_LEFT), LALT_T(KC_DOWN), LSFT_T(KC_UP), LCTL_T(KC_RIGHT), MS_BTN2,  KC_VOLD, KC_VOLU,  MS_BTN2, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_WBAK,                                  KC_MUTE, KC_MPLY,  KC_WFWD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* sYMBOL
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_SYMBOL] = LAYOUT_planck_1x2uC(
        KC_EXLM, KC_QUES, KC_LCBR, KC_RCBR, KC_PLUS,    KC_TRNS, KC_TRNS,    KC_DLR,  KC_GRV,  KC_PERC,    KC_HASH, KC_CIRC,
        KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_MINS,    KC_TRNS, KC_TRNS,    KC_EQL,  KC_QUOT, KC_AMPR,    KC_DQUO, KC_COLN,
        KC_NUBS, KC_SLSH, KC_LBRC, KC_RBRC, KC_ASTR,    KC_TRNS, KC_TRNS,    KC_UNDS, KC_AT,   S(KC_NUBS), KC_NUHS, KC_PIPE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),

/* nUMBER
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_NUMBER] = LAYOUT_planck_1x2uC(
        KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,      LGUI(KC_TAB), KC_CALC,      KC_F6,    KC_7,    KC_F8,   KC_F9,  KC_F10,
        KC_1,    KC_2,    KC_3,     KC_4,     KC_5,       KC_F23,   KC_F24,       KC_6,     KC_7,    KC_8,    KC_9,   KC_0,
        KC_PEQL, KC_DOT,  KC_PCMM,  KC_PPLS,  KC_PMNS,    KC_F20,   KC_F22,       KC_PAST,  KC_PSLS, KC_PCMM, KC_DOT, KC_PEQL,
        KC_F11,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* aDJUST (Nav + Symb)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_planck_1x2uC(
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    )
};

// Access ADJUST layer with Nav + Symb layers together
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAVIGATION, _SYMBOL, _ADJUST);
}

// KEY OVERRIDES
//
// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
};



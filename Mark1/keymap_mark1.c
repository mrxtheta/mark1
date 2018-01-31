#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PSCR, SLCK, PAUS, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSPC, HOME, PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC, ENT, END, PGDN, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT, BSLS, INS,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM, DOT, SLSH,          RSFT, DEL, UP, \
        LCTL,LGUI,LALT,          SPC,           RALT, FN0, APP, RCTL, LEFT, DOWN, RGHT),

     /*1: FN 0 */
   
    KEYMAP(
        ESC, F1,  F2,  F3,  F4,  WHOM,MUTE,VOLU,VOLD,  F9,  F10, F11, F12, PSCR, SLCK, PAUS, \
        TRNS, TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,TRNS, TRNS, HOME, PGUP, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,ENT, END, PGDN, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,BSLS,INS,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,DEL,UP, \
        LCTL,LGUI,LALT,          SPC,           RALT,FN0, APP,     RCTL,LEFT,DOWN,RGHT),
};
const action_t PROGMEM fn_actions[] = {
    
    [0] = ACTION_LAYER_MOMENTARY(1), 
};


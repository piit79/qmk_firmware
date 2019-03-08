enum preonic_layers {
	_QWERTY,
	_CZECH,
	_LOWER,
	_RAISE,
	_THIRD,
	_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_preonic_1x2uC( \
    KC_GESC,       KC_1,     KC_2,     KC_3,     KC_4,       KC_5,        KC_6,      KC_7,        KC_8,       KC_9,     KC_0,   KC_BSPC,  \
    KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,        KC_Y,      KC_U,        KC_I,       KC_O,     KC_P,    KC_DEL,  \
LCTL_T(KC_ESC),    KC_A,     KC_S,     KC_D,     KC_F,       KC_G,        KC_H,      KC_J,        KC_K,       KC_L,   KC_SCLN,  KC_QUOT,  \
    KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,        KC_N,      KC_M,       KC_COMM,    KC_DOT,  KC_SLSH,   KC_ENT,  \
     TT(1),      KC_LCTL,  KC_LGUI,  KC_LALT,   LOWER,        LT(4,KC_SPC),          RAISE,      KC_LEFT,   KC_DOWN,   KC_UP,    KC_RGHT  \
),
[_CZECH] = LAYOUT_preonic_1x2uC( \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,          -------,           -------,     -------,   -------,  -------,   -------  \
),
[_LOWER] = LAYOUT_preonic_1x2uC( \
    KC_TILD,     KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,     KC_ASTR,   KC_LPRN,  KC_RPRN,  KC_BSPC,  \
    KC_TILD,     KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,     KC_ASTR,   KC_LPRN,  KC_RPRN,   KC_DEL,  \
    KC_DEL,       KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,      KC_F6,     KC_UNDS,     KC_PLUS,   KC_LCBR,  KC_RCBR,  KC_PIPE,  \
    -------,      KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,      KC_F12,  S(KC_NUHS),  S(KC_NUBS),  KC_HOME,   KC_END,  -------,  \
    -------,     -------,  -------,  -------,  -------,          -------,           -------,     KC_MNXT,   KC_VOLD,  KC_VOLU,   KC_MPLY  \
),
[_RAISE] = LAYOUT_preonic_1x2uC( \
    KC_GRV,        KC_1,     KC_2,     KC_3,     KC_4,       KC_5,        KC_6,      KC_7,        KC_8,       KC_9,     KC_0,   KC_BSPC,  \
    KC_GRV,        KC_1,     KC_2,     KC_3,     KC_4,       KC_5,        KC_6,      KC_7,        KC_8,       KC_9,     KC_0,    KC_DEL,  \
    KC_DEL,       KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,      KC_F6,     KC_MINS,     KC_EQL,    KC_LBRC,  KC_RBRC,  KC_BSLS,  \
    -------,      KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,      KC_F12,    KC_NUHS,     KC_NUBS,   KC_PGUP,  KC_PGDN,  -------,  \
    -------,     -------,  -------,  -------,  -------,          -------,           -------,     KC_MNXT,   KC_VOLD,  KC_VOLU,   KC_MPLY  \
),
[_THIRD] = LAYOUT_preonic_1x2uC( \
    KC_GRV,      -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    KC_PGDN,      KC_UP,    KC_PGUP,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    KC_LEFT,     KC_DOWN,   KC_RGHT,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,     -------,    -------,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,          -------,           -------,     -------,   -------,  -------,    RESET   \
),
[_ADJUST] = LAYOUT_preonic_1x2uC( \
     KC_F1,       KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,      KC_F7,      KC_F8,       KC_F9,     KC_F10,   KC_F11,   KC_F12,  \
    -------,      RESET,    DEBUG,   -------,  -------,     -------,    -------,    TERM_ON,    TERM_OFF,   -------,  -------,   KC_DEL,  \
    -------,     -------,   MU_MOD,   AU_ON,    AU_OFF,     AG_NORM,    AG_SWAP,     DF(0),       DF(1),     DF(2),   -------,  -------,  \
    -------,      MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,      MI_ON,      MI_OFF,    -------,     -------,   -------,  -------,  -------,  \
    -------,     -------,  -------,  -------,  -------,          -------,           -------,     -------,   -------,  -------,   -------  \
)
};

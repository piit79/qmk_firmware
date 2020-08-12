#!/usr/bin/env python

import json
import sys

layer_names = [
    '_QWERTY',
    '_CZECH',
    '_LOWER',
    '_RAISE',
    '_THIRD',
    '_ADJUST',
]

layout_macro = 'LAYOUT_preonic_1x2uC'
MIN_WIDTH = 7
EXTRA = 2

lower_mod = 'MO({})'.format(layer_names.index('_LOWER'))
raise_mod = 'MO({})'.format(layer_names.index('_RAISE'))

# Translate keycodes
keycode_map = {
    'KC_TRNS': '_______',
    lower_mod: 'LOWER',
    raise_mod: 'RAISE',
}

# Load the layers from the JSON file
with open(sys.argv[1], 'r') as fp:
    layers = json.load(fp)

print 'enum preonic_layers {'
for i, ln in enumerate(layer_names):
    print '\t{}{}'.format(ln, ',' if i < len(layer_names)-1 else '')
print '};'
print

# Calculate the widths of each column for nicely aligned output
widths = []
for layer in layers:
    i = 0
    for li, kc in enumerate(layer):
        if kc in keycode_map:
            layer[li] = keycode_map[kc]
            kc = layer[li]
        if len(layer) == 4 and i == 5:
            i += 1
            continue
        if len(widths) <= i:
            widths.append(len(kc))
        else:
            widths[i] = max(MIN_WIDTH, widths[i], len(kc))
        i += 1
        if i == 12:
            i = 0

# Print out the layers
print 'const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {'

for num, layer in enumerate(layers):
    print '[{}] = {}( \\'.format(layer_names[num], layout_macro)
    r = 0
    i = 0
    for kc in layer:
        width = widths[i] + EXTRA
        if r == 4 and i == 5:
            # 2u spacebar spans two columns
            width += widths[i + 1] + EXTRA + 1
            i += 1
        kc_str = kc + (',' if r < 4 or i < 11 else '')
        print '{:^{width}}'.format(kc_str, width=width),
        i += 1
        if i == 12:
            print '\\'
            i = 0
            r += 1
    print '){}'.format(',' if num < len(layer_names)-1 else '')

print '};'

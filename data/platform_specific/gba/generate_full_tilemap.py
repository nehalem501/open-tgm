#!/usr/bin/env python3

import subprocess

# We have 256 tile entries available in each tilemap, so 512 in total.
# Transparency color is teal: #00FFFF (R: 0, G: 255, B:255)

class Entry():
    def __init__(self, name, length, map, position):
        self.name = name
        self.length = length
        self.map = map
        self.position = position

all_entries = []

# tilemap.png
all_entries.append(Entry("tilemap", 9, 0, 0))

# outline.png
all_entries.append(Entry("outline", 16, 1, 0))

# ui-font-letters.png
all_entries.append(Entry("ui-font-letters", 26, 1, 65))

# ui-font-digits.png
all_entries.append(Entry("ui-font-digits", 10, 1, 48))

# change entries to one common big tilemap
for entry in all_entries:
    if entry.map > 0:
        entry.position += entry.map * 256
        entry.map = 0

# fill empty space
tmp = []
tmp.append(all_entries.pop(0))
for i, val in enumerate(all_entries):
    prev = tmp[-1].position + tmp[-1].length
    if val.position == prev:
        # we can append it directly
        tmp.append(val)
    else:
        # we need to add empty space
        tmp.append(Entry("empty", prev - val.position, 0, prev))
        tmp.append(val)

all_entries = tmp

# run convert to create on big image
tmp = []
cmd = ['convert', all_entries[0].name + '.png', '-append', '-']
print(' '.join(cmd))
tmp.append(subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE))

for entry in all_entries[1:]:
    cmd = ['convert', '-', entry.name + '.png', '-append', '-']
    if entry.name == "empty":
        i = entry.length
        print(' '.join(cmd) + ' x' + str(i))
        #while i > 0:
        #    tmp.append(subprocess.Popen(cmd, stdout=subprocess.PIPE,
        #                                     stderr=subprocess.PIPE,
        #                                     stdin=tmp[-1].stdout))
        #    i += 1
    else:
        print(' '.join(cmd))
        tmp.append(subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                         stderr=subprocess.PIPE,
                                         stdin=tmp[-1].stdout))

cmd = ['convert', '-', 'fulltilemap.png']
print(' '.join(cmd))
tmp.append(subprocess.Popen(cmd, stdin=tmp[-1].stdout))

tmp[-1].communicate()

#!/usr/bin/env python3
#
# To generate .h and .c file, run:
# ~/devkitPro/devkitARM/bin/grit fulltilemap.png -ftc -gt -gB8 -gT 00FFFF -gu16 -p -pu16
#

import subprocess

# We have 256 tile entries available in each tilemap, so 512 in total.
# Transparency color is teal: #00FFFF (R: 0, G: 255, B:255)

class Entry():
    def __init__(self, name, length, map, position):
        self.name = name
        self.length = length
        self.map = map
        self.position = position

    def __str__(self):
        return str(self.__class__) + ": " + str(self.__dict__)

all_entries = []

# tilemap.png
all_entries.append(Entry("tilemap", 9, 0, 0))

# frame.png
all_entries.append(Entry("frame", 12, 0, 128))

# outline.png
all_entries.append(Entry("outline", 16, 1, 0))

# ui-font-digits.png
all_entries.append(Entry("ui-font-digits", 10, 1, 48))

# ui-font-letters.png
all_entries.append(Entry("ui-font-letters", 26, 1, 65))

# ui-font-digits-yellow.png
all_entries.append(Entry("ui-font-digits-yellow", 10, 1, 48+44))

# ui-font-letters-yellow.png
all_entries.append(Entry("ui-font-letters-yellow", 26, 1, 65+44))

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
        tmp.append(Entry("empty", val.position - prev, 0, prev))
        tmp.append(val)

all_entries = tmp

#for e in all_entries:
#    print(e)


# run convert to create on big image
#tmp = []
cmd = ['convert', all_entries[0].name + '.png', '-append', '-']
print(' '.join(cmd))
prog = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out, err = prog.communicate()

for entry in all_entries[1:]:
    cmd = ['convert', '-', entry.name + '.png', '-append', '-']
    if entry.name == "empty":
        i = entry.length
        print(i)
        print(' '.join(cmd) + ' x' + str(i))
        while i > 0:
            prog = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                         stderr=subprocess.PIPE,
                                         stdin=subprocess.PIPE)
            #print("data length: " + str(len(out)))
            out, err = prog.communicate(out)
            i -= 1
    else:
        print(' '.join(cmd))
        prog = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                stdin=subprocess.PIPE)
        out, err = prog.communicate(out)

cmd = ['convert', '-', 'fulltilemap.png']
print(' '.join(cmd))
prog = subprocess.Popen(cmd, stdin=subprocess.PIPE)
prog.communicate(out)



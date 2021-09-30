#!/usr/bin/env python3

import argparse
import itertools
import textwrap
from pathlib import Path

def grouper(n, iterable):
    it = iter(iterable)
    while True:
        chunk = tuple(itertools.islice(it, n))
        if not chunk:
            return
        yield chunk

parser = argparse.ArgumentParser()
parser.add_argument('-i', '--input', required=True)
parser.add_argument('-o', '--output', required=True)
#parser.add_argument('-H', '--header', required=True)
#parser.add_argument('-n', '--name', required=True)
args = parser.parse_args()

header = Path(args.output).with_suffix('.h')
name = str(Path(args.output).stem).replace('.', '_')
with open(args.output, 'w') as output:
    output.write(textwrap.dedent(f"""\
        /* {name}.cpp */

        #include <stddef.h>
        #include <stdint.h>

        alignas(size_t) const uint8_t {name}[] {{
        """))

    with open(args.input, 'rb') as input:
        while True:
            bytes = input.read(16)
            if not bytes:
                break
            output.write('    ')
            output.write(', '.join([f'0x{b:0{2}X}' for b in bytes]))
            output.write(',\n')

    output.write(textwrap.dedent(f"""\
        }};

        const size_t {name}_size = sizeof({name}) / sizeof({name}[0]);
        """))

with open(header, 'w') as output:
    output.write(textwrap.dedent(f"""\
        /* {name}.h */

        #ifndef {name.upper()}_H
        #define {name.upper()}_H

        #include <stddef.h>
        #include <stdint.h>

        extern const size_t {name}_size;
        extern const uint8_t {name}[];

        #endif // {name.upper()}_H
        """))

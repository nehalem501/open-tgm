#!/usr/bin/env python3

import argparse
import textwrap
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument('--includes-only', action='store_true')
parser.add_argument('-o', '--output', required=True)
parser.add_argument('headers', nargs='+')
args = parser.parse_args()

header = Path(args.output).with_suffix('.h')
name = str(Path(args.output).stem).replace('.', '_')
var_name = str(Path(args.output).stem).replace('_info', '')

with open(header, 'w') as output:
    output.write(textwrap.dedent(f"""\
        /* {name}.h */

        #ifndef {name.upper()}_H
        #define {name.upper()}_H

        #include <data.h>

        """))

    for h in args.headers:
        output.write(f'#include "{h}"\n')

    output.write('\n')

    if not args.includes_only:
        symbols = [str(Path(h).stem).replace('.', '_') for h in args.headers]
        output.write(f'static const AssetEntry {var_name}_assets_array[] = {{\n')
        for s in symbols:
            output.write(f'    AssetEntry({s}, {s}_size),\n')
        output.write(f'}};\n')
        output.write(f'constexpr Assets {var_name}_assets({var_name}_assets_array, {len(symbols)});\n')

    output.write(textwrap.dedent(f"""\

        #endif // {name.upper()}_H
        """))

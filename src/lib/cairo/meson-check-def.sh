#!/bin/sh

LC_ALL=C
export LC_ALL

if [ $# -lt 2 ];
then
    echo "Check that cairo library has same exported symbols as cairo.def"
    echo "Usage: $0 <def-filename> <cairo-library>"
    exit 1
fi

def="$1"
so="$2"

if which nm 2>/dev/null >/dev/null; then
    :
else
    echo "'nm' not found; skipping test"
    exit 0
fi

stat=0

if [ "`uname -s`" = "Linux" ]; then
	get_cairo_syms='( objdump -t "$so" | grep "^[^ ]* [^l.*]*[.]"; objdump -t "$so" | grep "[.]hidden.*\\<cairo"; ) | sed "s/.* //"'
else
	get_cairo_syms='nm "$so" | grep " [BCDGINRSTVW] " | cut -d" " -f3'
fi

echo Checking that $so has the same symbol list as $def

{
    echo EXPORTS
    eval $get_cairo_syms | c++filt --no-params | grep -v '^_cairo_test_\|^_fini\|^_init\|^_save[fg]pr\|^_rest[fg]pr\|^_Z\|^__gnu\|^__bss\|^_edata\|^_end' | sort -u
} | diff "$def" - >&2 || stat=1

exit $stat

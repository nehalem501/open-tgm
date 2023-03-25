#!/bin/sh

LC_ALL=C
export LC_ALL

if [ $# -lt 3 ];
then
    echo "Generate cairo def file"
    echo "Usage: $0 <def-filename> <cairo-features-file> <cairo-headers>..."
    exit 1
fi

def_file="$1"
cairo_features_h="$2"
shift 2

#echo Generating $def_file

(echo EXPORTS; \
 (cat $* || echo 'cairo_ERROR ()' ) | \
     egrep -v '^# *include' | \
     ( cat "$cairo_features_h" - | egrep -v '^#pragma' | cpp -D__cplusplus - || echo 'cairo_ERROR ()' ) | \
     egrep '^cairo_.* \(' | \
     sed -e 's/[ 	].*//' | \
     sort; \
 ) > "$def_file"
grep -q -v cairo_ERROR "$def_file" || (rm "$def_file"; false)

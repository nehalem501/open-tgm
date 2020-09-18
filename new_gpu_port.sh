#!/bin/bash

# Get project root directory
PROJECT_ROOT=$(cd "${0%/*}" && echo $PWD)
cd "$PROJECT_ROOT"

# Get target name and generate strings
if [ $# -eq 1 ]
then
    FULL_NAME=$1
else
    echo Enter new target full name:
    read FULL_NAME
fi
TARGET=${FULL_NAME//[^a-zA-Z0-9]/_}
TARGET_LOWERCASE=`echo "$TARGET" | tr '[:upper:]' '[:lower:]'`
TARGET_UPPERCASE=`echo "$TARGET" | tr '[:lower:]' '[:upper:]'`

# Get files
FILES=(`ls src/platforms/dummy_gpu`)

# Create source directory for new target
mkdir -p "src/platforms/$TARGET_LOWERCASE"

# Copy files with new target name
for F in "${FILES[@]}"
do
    sed "s/DUMMY_GPU/$TARGET_UPPERCASE/;s/dummy_gpu/$FULL_NAME/" "src/platforms/dummy_gpu/$F"> "src/platforms/$TARGET_LOWERCASE/$F"
done

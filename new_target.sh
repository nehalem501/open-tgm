#!/bin/bash

# Get project root directory
PROJECT_ROOT=$(cd "${0%/*}" && echo $PWD)
cd "$PROJECT_ROOT"

# Get target name and generate strings
echo Enter new target full name:
read FULL_NAME
TARGET=${FULL_NAME//[^a-zA-Z0-9]/_}
TARGET_LOWERCASE=`echo "$TARGET" | tr '[:upper:]' '[:lower:]'`
TARGET_UPPERCASE=`echo "$TARGET" | tr '[:lower:]' '[:upper:]'`

# Get files
FILES=(`ls src/targets/dummy`)

# Create source directory for new target
mkdir -p "src/targets/$TARGET_LOWERCASE"

# Copy files with new target name
for F in "${FILES[@]}"
do
    sed "s/DUMMY/$TARGET_UPPERCASE/;s/Dummy/$FULL_NAME/" "src/targets/dummy/$F"> "src/targets/$TARGET_LOWERCASE/$F"
done

# Copy Makefile with new target name
sed "s/DUMMY/$TARGET_UPPERCASE/" "dummy.mk"> "$TARGET_LOWERCASE.mk"


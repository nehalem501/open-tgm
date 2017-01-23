#!/bin/bash

GAMEROOT=$(cd "${0%/*}" && echo $PWD)
cd "$GAMEROOT"

./open-tgm

exit 0

#!/usr/bin/env python3

import shutil
from . import globals

def clean_target(target):
    target_build_path = globals.BUILD_INFO.get_target_build_dir(target)
    if target_build_path.exists():
        print('clean ' + target)
        shutil.rmtree(target_build_path)
    else:
        print('Nothing to clean for ' + target)

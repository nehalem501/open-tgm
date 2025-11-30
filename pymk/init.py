#!/usr/bin/env python3

import re
from . import globals

def sed_inplace(input, output, substitutions):
    pattern_compiled = re.compile("(%s)" % "|".join(map(re.escape, substitutions.keys())))

    with open(output, mode='x') as out_file:
        with open(input, mode='r') as src_file:
            for line in src_file:
                out_file.write(pattern_compiled.sub(lambda r: substitutions[r.group()], line))

def copy_files(from_dir, to_dir, substitutions, renames={}):
    pattern_compiled = re.compile("(%s)" % "|".join(map(re.escape, renames.keys())))
    for old_file in from_dir.iterdir():
        new_file =  to_dir / old_file.relative_to(from_dir)
        if renames:
            new_file_name = pattern_compiled.sub(lambda r: renames[r.group()], new_file.name)
            new_file = new_file.with_name(new_file_name)
        sed_inplace(old_file.absolute(), new_file.absolute(), substitutions)

class Names:
    def __init__(self, name):
        cleaned_name = re.sub('[^a-zA-Z0-9]', '_', name)
        self.full = name
        self.lower = cleaned_name.lower()
        self.upper = cleaned_name.upper()
        self.type = re.sub('[^a-zA-Z0-9]', '', name)

def init_platform(name):
    print(f'Creating port: {name}')

    platforms_dir = globals.PROJECT_ROOT / globals.SRC_DIR / globals.PLATFORMS_DIR
    dummy_dir = platforms_dir / 'dummy'

    names = Names(name)

    new_dir = platforms_dir / names.lower
    new_dir.mkdir()

    substitutions = {
        'DUMMY': names.upper,
        'Dummy': name
    }

    copy_files(dummy_dir, new_dir, substitutions)

    print(f'Created {new_dir.relative_to(globals.PROJECT_ROOT)}')

def init_gpu_platform(name, backend_name):
    print(f'Creating GPU port: {name}')

    platforms_dir = globals.PROJECT_ROOT / globals.SRC_DIR / globals.PLATFORMS_DIR
    dummy_gpu_dir = platforms_dir / 'dummy_gpu'

    names = Names(name)

    new_dir = platforms_dir / names.lower
    new_dir.mkdir()

    substitutions = {
        'DUMMY_GPU': names.upper,
        'dummy_gpu': name
    }

    if backend_name:
        backend_names = Names(backend_name)
        substitutions['DummyGPU'] = f'{backend_names.type}GPU'
        substitutions['gpu_backend = dummy'] = f'gpu_backend = {backend_names.lower}'

    copy_files(dummy_gpu_dir, new_dir, substitutions)

    print(f'Created {new_dir.relative_to(globals.PROJECT_ROOT)}')

def init_gpu_backend(name):
    print(f'Creating GPU backend: {name}')

    gpu_backends_dir = globals.PROJECT_ROOT / globals.SRC_DIR / globals.GPU_DIR / globals.GPU_BACKENDS_DIR
    dummy_backend_dir = gpu_backends_dir / 'dummy'

    names = Names(name)

    new_dir = gpu_backends_dir / names.lower
    new_dir.mkdir()

    substitutions = {
        'DUMMY_GPU_DUMMY_GPU': f'{names.upper}_GPU_{names.upper}',
        'DUMMY_GPU': names.upper,
        'dummy_gpu': name,
        'DummyGPU': f'{names.type}GPU'
    }

    renames = {
        'DummyGPU': f'{names.type}GPU'
    }

    copy_files(dummy_backend_dir, new_dir, substitutions, renames)

    print(f'Created {new_dir.relative_to(globals.PROJECT_ROOT)}')

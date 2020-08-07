# Platforms

* 3ds: Nintendo 3DS
* dummy: Empty platform code to use as a template to start porting the game for older targets that do not support GPU code
* dummy_gpu: Same as above, but it uses the 'gpu' special platform, template for porting the game to more modern targets
* gba: Nintendo GameBoy Advance
* ps2: Sony PlayStation 2
* ps3: Sony PlayStation 3
* psp: Sony PlayStation Portable
* psvita: Sony PlayStation Vita
* psx: Sony PlayStation (PS1)
* sdl: SDL
* sdl2: SDL2
* sfml: SFML

To implement a new platform, use the `new_platform.sh` script to generate source tree for your new target.

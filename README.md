# Open TGM
A free and open source clone of the TGM series.
For the moment, only a TGM1 and TAP implementation is planned.

In the long term, an online multiplayer feature should be available for VS mode and Doubles. (Won't be available on all ports of the game)

Working ports:
- Windows
- Mac OS X
- Linux

Work in progress ports:
- GameBoy Advance
- PlayStation Portable
- 3DS

Planned ports: (not necessarily implemented in this order)
- Nintendo DS
- Nintendo 64
- GameCube
- Wii
- Switch
- PlayStation Vita
- PlayStation 1
- PlayStation 2
- PlayStation 3
- Original Xbox
- Xbox 360
- Xbox One
- Saturn
- Dreamcast

Possible ports if the target hardware is powerful enough: (needs some testing)
- Neo-Geo
- Sega Mega Drive / Genesis

Due to the lack of a C++ compiler for the Super Nintendo / Super Famicom, porting to it is currently impossible.

Released under the GPLv3.0 licence or any later version.

## Build Instructions

### GameBoy Advance
You need to have devkitPro with devkitARM installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make gba
```

The resulting GBA ROM file will be `bin/gba/open-tgm.gba`.

### 3DS
You need to have devkitPro with devkitARM installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make 3ds
```

The resulting 3DS ROM files will be `bin/3ds/open-tgm.3dsx` and `bin/3ds/open-tgm.smdh`.

### PlayStation Portable
You need to have the PSP Software Development Kit (PSPSDK) installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make psp
```

### PlayStation Vita
You need to have Vita SDK installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make psvita
```

### PlayStation 1
You need to have PSXSDK installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make psx
```

### PlayStation 2
You need to have PS2SDK installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make ps2
```

### PlayStation 3
You need to have PS3SDK and PSL1GHT installed and properly configured.

To build, type this in a shell in the project's root directory:
```
$ make ps3
```


# PSP target Makefile


SOURCE_FILES_CPP = $(wildcard src/core/*.cpp) $(wildcard src/targets/psp/*.cpp) $(wildcard src/modes/*.cpp)
SOURCE_FILES_C = $(wildcard src/targets/psp/resources/*.c)
OBJS = $(SOURCE_FILES_C:.c=.o) $(SOURCE_FILES_CPP:.cpp=.o)

INCDIR = ./src/include ./src/targets/psp ./extlibs/gLib2D
CFLAGS = -O2 -G0 -Wall -DTARGET_PSP
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR = ./extlibs/gLib2D
LDFLAGS =
LIBS = -lglib2d -ljpeg -lpng -lz -lpspgum -lpspgu -lpsprtc -lm -lpspvram

# 
PSP_EBOOT = bin/psp/EBOOT.PBP
PSP_EBOOT_SFO = bin/psp/PARAM.SFO
PSP_EBOOT_TITLE = Open TGM
#PSP_EBOOT_ICON = ICON0.png
#PSP_EBOOT_PIC1 = PIC1.png

# PSPSDK build system needs this
TARGET = ./build/psp/open-tgm
EXTRA_TARGETS = $(PSP_EBOOT)

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

#logo.o: logo.raw
#	bin2o -i logo.raw logo.o logo

#finalize:
#	mkdir -p ./build/psp
#	mv EBOOT.PBP ./build/psp
#	rm -rf ./build/psp/resources
#	cp -r ./data/platform_specific/psp ./build/psp
#	mv ./build/psp/psp ./build/psp/resources


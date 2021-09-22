# PSP

ifeq ($(strip $(PSPDEV)),)
  $(error "Please set PSPDEV in your environment. export PSPDEV=<path to>pspdev")
endif

export PATH := $(PSPDEV)/bin:$(PATH)
#SHELL := env PATH=$(PATH) /bin/sh

PSPSDK := $(shell psp-config --pspsdk-path)

PSP_EBOOT_TITLE := Open TGM
PSP_EBOOT_SFO := $(BIN_DIR)/PARAM.SFO
PSP_EBOOT_ICON := NULL
PSP_EBOOT_ICON1 := NULL
PSP_EBOOT_UNKPNG := NULL
PSP_EBOOT_PIC1 := NULL
PSP_EBOOT_SND0 := NULL
PSP_EBOOT_PSAR := NULL
PSP_EBOOT := $(BIN_DIR)/EBOOT.PBP

CC := psp-gcc
CXX := psp-g++
LINK := $(CC)

PSP_FW_VERSION := 150

CFLAGS := -O2 -G0 -DTARGET_PSP -D_PSP_FW_VERSION=$(PSP_FW_VERSION)
CXXFLAGS := -std=c++11 -fno-exceptions -fno-rtti

PSPSDK_LIBC_LIB := -lc
PSPSDK_LIBS := -lpspdebug -lpspdisplay -lpspge -lpspctrl -lpspsdk

PSP_LIBRARIES := $(PSPSDK_LIBS) $(PSPSDK_LIBC_LIB) \
                 -lpspnet -lpspnet_inet -lpspnet_apctl -lpspnet_resolver \
				 -lpsputility -lpspuser -lpspkernel

HEADERS := $(PSPSDK)/include
LIBRARIES := -lpspgum -lpspgu -lpsprtc -lm -lpspvram $(PSP_LIBRARIES)
LIBRARY_DIRS := $(PSPSDK)/lib

SOURCES_C := $(wildcard $(PLATFORM_PATH)/*.c)
SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

GPU_BACKEND := scegu
GPU_TILE_SIZES := 10px

$(PSP_EBOOT): $(PROG_BASENAME).elf
	psp-fixup-imports $(PROG_BASENAME).elf
	mksfo '$(PSP_EBOOT_TITLE)' $(PSP_EBOOT_SFO)
	psp-strip $(PROG_BASENAME).elf -o $(PROG_BASENAME)_strip.elf
	pack-pbp $(PSP_EBOOT) $(PSP_EBOOT_SFO) $(PSP_EBOOT_ICON)  \
		$(PSP_EBOOT_ICON1) $(PSP_EBOOT_UNKPNG) $(PSP_EBOOT_PIC1)  \
		$(PSP_EBOOT_SND0)  $(PROG_BASENAME)_strip.elf $(PSP_EBOOT_PSAR)
	-rm -f $(PROG_BASENAME)_strip.elf

PROG_NAME := $(PROG_NAME).elf
PLATFORM_RULES := $(PSP_EBOOT)
MRPROPER := $(PSP_EBOOT) $(PSP_EBOOT_SFO) $(PROG_BASENAME)_strip.elf

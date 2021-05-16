# 3DS

ifeq ($(strip $(DEVKITPRO)),)
  $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

ifeq ($(strip $(DEVKITARM)),)
  $(error "Please set DEVKITARM in your environment. export DEVKITARM=${DEVKITPRO}/devkitARM")
endif

export PATH := $(DEVKITARM)/bin:$(DEVKITPRO)/tools/bin:$(PATH)

AS := arm-none-eabi-as
CC := arm-none-eabi-gcc
CXX := arm-none-eabi-g++
#OBJCOPY = arm-none-eabi-objcopy

CFLAGS := -g -DTARGET_3DS -O2 -mword-relocations -fomit-frame-pointer -ffunction-sections -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -DARM11 -D_3DS
CXXFLAGS := -fno-rtti -fno-exceptions -std=gnu++11
LDFLAGS := -specs=3dsx.specs -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -Wl,-Map,$(BUILD_DIR)/$(NAME).map

HEADERS := $(DEVKITPRO)/libctru/include
LIBRARIES := -lcitro3d -lctru -lm
LIBRARY_DIRS := $(DEVKITPRO)/libctru/lib

SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

GPU_BACKEND := citro3d
GPU_TILE_SIZES := 8px # TODO

APP_TITLE = Open TGM
APP_DESCRIPTION = Built with devkitARM & libctru
APP_AUTHOR = Nehalem501
APP_ICON = $(DEVKITPRO)/libctru/default_icon.png

CLEAN := $(BUILD_DIR)/$(NAME).map

$(PROG_NAME).3dsx: $(PROG_BASENAME).elf $(PROG_BASENAME).smdh
	@echo generating 3DS rom
	@3dsxtool $< $@ --smdh=$(PROG_BASENAME).smdh  || { echo Failed: 3dsxtool $< $@ --smdh=$(PROG_BASENAME).smdh; exit 1; }
	@echo built ... $(notdir $@)

$(PROG_NAME).smdh:
	@smdhtool --create "$(APP_TITLE)" "$(APP_DESCRIPTION)" "$(APP_AUTHOR)" $(APP_ICON) $@
	@echo built ... $(notdir $@)

MRPROPER := $(PROG_BASENAME).3dsx $(PROG_BASENAME).smdh

PLATFORM_RULES := $(PROG_BASENAME).3dsx

PROG_NAME := $(PROG_BASENAME).elf

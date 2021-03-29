# GBA

ifeq ($(strip $(DEVKITPRO)),)
  $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

ifeq ($(strip $(DEVKITARM)),)
  $(error "Please set DEVKITARM in your environment. export DEVKITARM=${DEVKITPRO}/devkitARM")
endif

export PATH := $(DEVKITARM)/bin:$(DEVKITPRO)/tools/bin:$(PATH)

CC := arm-none-eabi-gcc
CXX := arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy

CFLAGS := -g -O2 -DTARGET_GBA -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork
CXXFLAGS := -std=c++11 -fno-rtti -fno-exceptions
LDFLAGS := -mthumb -mthumb-interwork -Wl,-Map,$(BUILD_DIR)/$(NAME).map -specs=gba.specs

HEADERS := $(DEVKITPRO)/libgba/include
LIBRARIES := -lmm -lgba
LIBRARY_DIRS := $(DEVKITPRO)/libgba/lib

SOURCES_C := $(wildcard $(PLATFORM_PATH)/resources/*.c)
SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

CLEAN := $(BUILD_DIR)/$(NAME).map

$(PROG_NAME).gba : $(PROG_NAME).elf
	@echo generating GBA rom
	@$(DEVKITARM)/bin/$(OBJCOPY) -O binary $< $@
	@echo built ... $(notdir $@)
	gbafix $@

MRPROPER := $(PROG_NAME).gba

PLATFORM_RULES := $(PROG_NAME).gba

PROG_NAME := $(PROG_NAME).elf

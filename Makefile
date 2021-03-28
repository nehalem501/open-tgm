# Open TGM Makefile

VERSION := 0.3.0

# Binary filename
NAME := open-tgm

# Default target
DEFAULT := sdl2

# Common variables for all targets
CORE_ASFLAGS :=
CORE_CFLAGS := -Wall -Wextra -pedantic-errors -Werror -DOPENTGM_VERSION=\"$(VERSION)\"
CORE_CXXFLAGS :=
HOST_CC := $(CC)
HOST_CXX := $(CXX)

# Files and Directories
SRC_DIR := src
HEADERS_CORE := $(SRC_DIR)/include
SOURCES_CORE_CPP := $(wildcard $(SRC_DIR)/modes/*.cpp) $(wildcard $(SRC_DIR)/core/*.cpp)
HEADERS_GPU := $(SRC_DIR)/gpu/src
SOURCES_GPU_CPP := $(wildcard $(SRC_DIR)/gpu/src/*.cpp)

# Get platforms
PLATFORM_DIRS := $(dir $(wildcard $(SRC_DIR)/platforms/*/.))
PLATFORMS := $(notdir $(abspath $(PLATFORM_DIRS)))
TARGETS := $(PLATFORMS)

TARGET := $(filter $(TARGETS), $(MAKECMDGOALS))
ifeq ($(TARGET),)
TARGET := $(DEFAULT)
endif

define DEFINE_TARGET
	ASFLAGS :=
	CFLAGS :=
	CXXFLAGS :=
	SOURCES_AS :=
	SOURCES_C :=
	SOURCES_CPP :=
	SOURCES :=
	OBJECTS_AS :=
	OBJECTS_C :=
	OBJECTS_CPP :=
	OBJECTS :=
	BIN_DIR :=
	BUILD_DIR :=
	HEADERS :=
	PROG_NAME :=
	SOURCES :=

	PLATFORM_PATH := $(SRC_DIR)/platforms/${1}
	include $(SRC_DIR)/platforms/${1}/build.mk

	ASFLAGS := $(CORE_ASFLAGS) $(ASFLAGS)
	CFLAGS := $(CORE_CFLAGS) $(CFLAGS)
	CXXFLAGS := $(CFLAGS) $(CORE_CXXFLAGS) $(CXXFLAGS)
	SOURCES_AS := $(SOURCES_AS)
	SOURCES_C := $(SOURCES_C)
	SOURCES_CPP := $(SOURCES_CORE_CPP) $(SOURCES_CPP)
	SOURCES := $(SOURCES_CPP) $(SOURCES_C) $(SOURCES_AS)
	OBJECTS_AS := $(addprefix $(BUILD_DIR)/, $(SOURCES_AS:src/%.asm=%.o))
	OBJECTS_C := $(addprefix $(BUILD_DIR)/, $(SOURCES_C:src/%.c=%.o))
	OBJECTS_CPP := $(addprefix $(BUILD_DIR)/, $(SOURCES_CPP:src/%.cpp=%.o))
	OBJECTS := $(OBJECTS_CPP) $(OBJECTS_C) $(OBJECTS_AS)
	BIN_DIR := bin/${1}
	BUILD_DIR := build/${1}
	HEADERS := $(HEADERS_CORE) $(PLATFORM_PATH)
	PROG_NAME := bin/${1}/$(NAME)
endef

#$(TARGETS): $(eval $(call INCLUDE_MK,$@))

#$(foreach T,$(TARGETS),$(eval $(DEFINE_TARGET)))

#$(TARGETS): BIN_DIR = bin/$@
#$(TARGETS): BUILD_DIR = build/$@
#$(TARGETS): HEADERS = $(HEADERS_CORE) -I$(SRC_DIR)/targets/$@
#$(TARGETS): HEADERS += -I$(BUILD_DIR)
#$(TARGETS): EXE_NAME = bin/$@/$(NAME)
#$(TARGETS): SOURCES = $(SOURCES_CORE) $(wildcard $(SRC_DIR)/targets/$@/*.cpp)
#$(TARGETS): OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o))
#$(TARGETS): % : %.mk
#	@echo Selected target: $@
#	@mkdir -p $(BIN_DIR)
#	@mkdir -p $(BUILD_DIR)/core $(BUILD_DIR)/targets/$@ $(BUILD_DIR)/modes
#	$(MAKE) -f $< $(filter-out $(TARGETS) all-targets,$(ARGS))

PLATFORM_PATH := $(SRC_DIR)/platforms/$(TARGET)
BIN_DIR := bin/$(TARGET)
BUILD_DIR := build/$(TARGET)
PROG_BASENAME := bin/$(TARGET)/$(NAME)
PROG_NAME := $(PROG_BASENAME)

include $(SRC_DIR)/platforms/$(TARGET)/build.mk

ifdef GPU_BACKEND
GPU_BACKEND_PATH := $(SRC_DIR)/gpu/backends/$(GPU_BACKEND)
include $(SRC_DIR)/gpu/backends/$(GPU_BACKEND)/build.mk
HEADERS := $(HEADERS) $(HEADERS_GPU) $(SRC_DIR)/gpu/backends/$(GPU_BACKEND)
SOURCES_CORE_CPP:= $(SOURCES_CORE_CPP) $(SOURCES_GPU_CPP)
endif

HEADERS := $(HEADERS_CORE) $(PLATFORM_PATH) $(BUILD_DIR) $(HEADERS)
#PROG_NAME := bin/$(TARGET)/$(NAME)
ASFLAGS := $(CORE_ASFLAGS) $(ASFLAGS)
CFLAGS := $(CORE_CFLAGS) $(CFLAGS) $(foreach dir,$(HEADERS),-I$(dir))
CXXFLAGS := $(CFLAGS) $(CORE_CXXFLAGS) $(CXXFLAGS)
LINK ?= $(CXX)
#LIBRARIES :=
#LIBRARY_DIRS :=
LDFLAGS := $(LDFLAGS) $(CORE_LDFLAGS)
LIBS := $(foreach dir,$(LIBRARY_DIRS),-L$(dir)) $(BACKEND_LIBS) $(LIBRARIES)
SOURCES_AS := $(SOURCES_AS) $(BACKEND_SOURCES_AS)
SOURCES_C := $(SOURCES_C) $(BACKEND_SOURCES_C)
SOURCES_CPP := $(SOURCES_CORE_CPP) $(SOURCES_CPP) $(BACKEND_SOURCES_CPP)
SOURCES := $(SOURCES_CPP) $(SOURCES_C) $(SOURCES_AS)
OBJECTS_AS := $(addprefix $(BUILD_DIR)/, $(SOURCES_AS:src/%.asm=%.o))
OBJECTS_C := $(addprefix $(BUILD_DIR)/, $(SOURCES_C:src/%.c=%.o))
OBJECTS_CPP := $(addprefix $(BUILD_DIR)/, $(SOURCES_CPP:src/%.cpp=%.o))
OBJECTS := $(OBJECTS) $(OBJECTS_CPP) $(OBJECTS_C) $(OBJECTS_AS)
CLEAN := $(OBJECTS) $(CLEAN)
MRPROPER := $(PROG_NAME) $(MRPROPER)
PLATFORM_RULES := $(PROG_NAME) $(PLATFORM_RULES)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@mkdir -p $(@D) || { echo Failed: mkdir -p $(@D); exit 1; }
	@$(CXX) $(CXXFLAGS) -o $@ -c $< || { echo Failed: $(CXX) $(CXXFLAGS) -o $@ -c $<; exit 1; }

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@echo $(CC) $<
	@mkdir -p $(@D) || { echo Failed: mkdir -p $(@D); exit 1; }
	@$(CC) $(CFLAGS) -o $@ -c $< || { echo Failed: $(CC) $(CFLAGS) -o $@ -c $<; exit 1; }

$(PROG_NAME): $(OBJECTS)
	@echo Linking $(PROG_NAME)
	@mkdir -p $(@D) || { echo Failed: mkdir -p $(@D); exit 1; }
	@$(LINK) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS) || { echo Failed: $(LINK) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS); exit 1; }

all: $(DEFAULT)
#all-targets: $(TARGETS)
#all: bin/sdl2/open-tgm

$(TARGET): $(PLATFORM_RULES)

print_info:
	@echo assembler: $(AS)
	@echo C compiler: $(CC)
	@echo C++ compiler: $(CXX)
	@#ASFLAGS $(ASFLAGS)
	@#CFLAGS $(CFLAGS)
	@#CXXFLAGS $(CXXFLAGS)
	@#SOURCES_AS $(SOURCES_AS)
	@#SOURCES_C $(SOURCES_C)
	@#SOURCES_CPP $(SOURCES_CPP)
	@#OBJECTS_AS $(OBJECTS_AS)
	@#OBJECTS_C $(OBJECTS_C)
	@#OBJECTS_CPP $(OBJECTS_CPP)
	@#PLATFORM_DIRS $(PLATFORM_DIRS)
	@#PLATFORMS $(PLATFORMS)
	@#SOURCES $(SOURCES)
	@#OBJECTS $(OBJECTS)

clean:
	@echo clean $(TARGET)
	@rm -rf $(CLEAN);

mrproper: clean
	@rm -rf $(MRPROPER);

.PHONY: all clean print_info $(TARGETS) #$(PLATFORM_RULES)

#$(eval $(call DEFINE_TARGET,$(TARGETS)))
#$(foreach 1,$(TARGETS),$(eval $(ONERULE)))

# Open TGM Makefile

VERSION := 0.2.0

# Binary filename
NAME = open-tgm

# Default target
DEFAULT = sfml

# Get target list
TARGETS_MK = $(wildcard *.mk)
TARGETS = $(TARGETS_MK:.mk=)

# Common variables for all targets
CFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra

# Arguments
ARGS = $(MAKECMDGOALS)

# Files and Directories
SRC_DIR = src
HEADERS = -I$(SRC_DIR)/include
SOURCES = $(wildcard $(SRC_DIR)/core/*.cpp) $(wildcard $(SRC_DIR)/modes/*.cpp)

# Export variables for makefile of each target
unexport TARGETS_MK TARGETS ARGS
export

all: $(DEFAULT)

all-targets: $(TARGETS)

$(TARGETS): BIN_DIR = bin/$@
$(TARGETS): BUILD_DIR = build/$@
$(TARGETS): HEADERS += -I$(SRC_DIR)/targets/$@
$(TARGETS): HEADERS += -I$(BUILD_DIR)
$(TARGETS): EXE_NAME = bin/$@/$(NAME)
$(TARGETS): SOURCES += $(wildcard $(SRC_DIR)/targets/$@/*.cpp)
$(TARGETS): OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o))
$(TARGETS): % : %.mk
	@echo Selected target: $@
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BUILD_DIR)/core $(BUILD_DIR)/targets/$@ $(BUILD_DIR)/modes
	$(MAKE) -f $< $(filter-out $(TARGETS) all-targets,$(ARGS))

clean: $(DEFAULT)

.PHONY: all clean $(TARGETS)


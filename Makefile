# Open TGM Makefile

# Binary filename
EXE_NAME=open-tgm

# Default target
DEFAULT=sfml

# Get target list
TARGETS_MK=$(wildcard *.mk)
TARGETS=$(TARGETS_MK:.mk=)

# Default compiler
CC=cc
CXX=c++

# Common variables for all targets
CFLAGS=-Wall -Wextra
CXXFLAFS=

# Arguments
ARGS=$(MAKECMDGOALS)

# Files and Directories
CPP_FILES=$(wildcard src/core/*.cpp) $(wildcard src/modes/*.cpp)
C_FILES=
INCLUDE_DIR=-I./src/include

# Export variables for makefile of each target
unexport TARGETS_MK TARGETS ARGS
export

all:
	@$(MAKE) -f $(DEFAULT).mk $(ARGS)

$(TARGETS): % : %.mk
	@echo Selected target: $@
	$(MAKE) -f $< $(filter-out $@,$(ARGS))

clean:
	$(MAKE) -f $(DEFAULT).mk clean

.PHONY: all clean $(TARGETS)


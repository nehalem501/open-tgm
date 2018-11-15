# MXE (Cross-compiling for Windows on Linux) target Makefile

# We need to change the source and build paths, this is a special case
# for MXE builds as the target is SFML.
BIN_DIR := $(subst mxe,sfml/win32, $(BIN_DIR))
BUILD_DIR := $(subst mxe,sfml/win32, $(BUILD_DIR))
HEADERS := $(subst mxe,sfml, $(HEADERS))
SOURCES := $(subst mxe,sfml, $(SOURCES)) $(wildcard $(SRC_DIR)/targets/sfml/*.cpp)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(SOURCES:$(SRC_DIR)/%.cpp=%.o))

# MXE install dir
MXE = ~/mxe

CXX = $(MXE)/usr/bin/i686-w64-mingw32.static-g++

EXE_NAME := $(EXE_NAME).exe

LIBS := `$(MXE)/usr/bin/i686-w64-mingw32.static-pkg-config --libs sfml`

CXXFLAGS += -DTARGET_SFML `$(MXE)/usr/bin/i686-w64-mingw32.static-pkg-config --cflags sfml`

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS) || echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info : 
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BUILD_DIR)/core $(BUILD_DIR)/targets/sfml $(BUILD_DIR)/modes


.PHONY: clean print_info


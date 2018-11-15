# SFML target Makefile

ifeq ($(OS),Windows_NT)
    OS_TARGET = win32
    EXE_NAME := $(EXE_NAME).exe
    CXXFLAGS += -DSFML_STATIC
    HEADERS += -I./extlibs/SFML-win32/include
    LIBS = -lsfml-graphics-s -lsfml-window-s -lopengl32 -ljpeg -lfreetype -lgdi32 -lsfml-system-s -lwinmm -static-libgcc -static-libstdc++
    LIBS_DIR = -L./extlibs/SFML-win32/lib
else
    UNAME_S := $(shell uname -s)
    UNAME_M := $(shell uname -m)
    ifeq ($(UNAME_S),Linux)
	ifeq ($(UNAME_M),i486)
          UNAME_M=i386
        else ifeq ($(UNAME_M),i586)
          UNAME_M=i386
        else ifeq ($(UNAME_M),i686)
          UNAME_M=i386
        else
        endif
	EXE_NAME := $(EXE_NAME).bin
        CXX = g++-4.8
        OS_TARGET = linux_$(UNAME_M)
        CXXFLAGS += -g -std=c++11
        LDFLAGS = -Wl,-R./lib
        HEADERS += -I./extlibs/SFML-linux_$(UNAME_M)/include
        LIBS = -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
        LIBS_DIR = -L./extlibs/SFML-linux_$(UNAME_M)/lib
        EXTRAS = rm -rf $(BIN_DIR)/lib ; cp -r ./extlibs/SFML-linux_$(UNAME_M)/lib $(BIN_DIR) ; rm -f $(BIN_DIR)/open-tgm ; cp ./data/scripts/open-tgm $(BIN_DIR)
    endif
    ifeq ($(UNAME_S),Darwin)
        OS_TARGET = osx
        HEADERS += -I./extlibs/SFML-osx/include
        LIBS_DIR = -L./extlibs/SFML-osx/lib
    endif
endif

CXXFLAGS += -DTARGET_SFML -DDEBUG -Wall -Wextra -pedantic

OBJECTS := $(subst $(BUILD_DIR), $(BUILD_DIR)/$(OS_TARGET), $(OBJECTS))
EXE_NAME := $(subst $(BIN_DIR), $(BIN_DIR)/$(OS_TARGET), $(EXE_NAME))

BIN_DIR := $(BIN_DIR)/$(OS_TARGET)
BUILD_DIR := $(BUILD_DIR)/$(OS_TARGET)

all: $(EXE_NAME)

$(EXE_NAME): print_info $(OBJECTS)
	@rm -rf $(BIN_DIR)/resources
	@cp -rf data/resources/ $(BIN_DIR)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS_DIR) $(LIBS) || echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS_DIR) $(LIBS)
	$(EXTRAS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BUILD_DIR)/core $(BUILD_DIR)/targets/sfml $(BUILD_DIR)/modes

.PHONY: clean print_info


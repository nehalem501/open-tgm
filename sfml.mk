# SFML target Makefile

CFLAGS += -DTARGET_SFML -DDEBUG -Wall -Wextra -pedantic
CXXFLAGS += $(CFLAGS)

CPP_FILES += $(wildcard src/targets/sfml/*.cpp)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

INCLUDE_DIR += -I./src/targets/sfml

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(OS),Windows_NT)
    BUILD_DIR = ./build/win32
    EXE_NAME = open-tgm.exe
    CCFLAGS += -DSFML_STATIC
    INCLUDE_DIR += -I./extlibs/SFML-win32/include
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
        EXE_NAME = open-tgm.bin
        CC = g++-4.8
        BUILD_DIR = ./build/linux_$(UNAME_M)
        CCFLAGS += -g -std=c++11
        LDFLAGS = -Wl,-R./lib
        INCLUDE_DIR += -I./extlibs/SFML-linux_$(UNAME_M)/include
        LIBS = -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
        LIBS_DIR = -L./extlibs/SFML-linux_$(UNAME_M)/lib
        EXTRAS = rm -rf $(BUILD_DIR)/lib ; cp -r ./extlibs/SFML-linux_$(UNAME_M)/lib $(BUILD_DIR) ; rm -f $(BUILD_DIR)/open-tgm ; cp ./data/scripts/open-tgm $(BUILD_DIR)
    endif
    ifeq ($(UNAME_S),Darwin)
        BUILD_DIR = ./build/osx
        CCFLAGS +=
        INCLUDE_DIR += -I./extlibs/SFML-osx/include
        LIBS =
        LIBS_DIR = -L./extlibs/SFML-osx/lib
    endif
endif

EXE_NAME := $(addprefix $(BUILD_DIR)/, $(EXE_NAME))

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	@rm -rf $(BUILD_DIR)/resources
	@cp -r ./data/resources $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJ_FILES) $(LIBS_DIR) $(LIBS)
	$(EXTRAS)

%.o: %.cpp
	$(CXX) $(CCFLAGS) $(INCLUDE_DIR) -o $@ -c $<

clean :
	rm -f $(BUILD_DIR)/$(EXE_NAME) $(EXE_OBJ_FILES);
	rm -rf $(BUILD_DIR)/resources

print_info:
	@echo C compiler: $(CC)
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


CC = g++
EXE_NAME = open-tgm
SOURCE_FILES= $(wildcard *.cpp) $(wildcard sfml/*.cpp)
EXE_OBJ_FILES = $(SOURCE_FILES:.cpp=.o)
CCFLAGS = -DTARGET_SFML -Wall -pedantic
LDFLAGS = 
INCLUDE_DIR = 
LIBS_DIR =  
LIBS = -lsfml-graphics -lsfml-window -lsfml-system 
BUILD_DIR = .
EXTRAS = 

ifeq ($(OS),Windows_NT)
    BUILD_DIR = ../build/win32
    EXE_NAME = open-tgm.exe
    CCFLAGS += -DSFML_STATIC
    INCLUDE_DIR = -I../extlibs/SFML-win32/include 
    LIBS = -lsfml-graphics-s -lsfml-window-s -lopengl32 -ljpeg -lfreetype -lgdi32 -lsfml-system-s -lwinmm -static-libgcc -static-libstdc++
    LIBS_DIR = -L../extlibs/SFML-win32/lib 
else
    UNAME_S := $(shell uname -s)
    UNAME_M := $(shell uname -m)
    ifeq ($(UNAME_S),Linux)
        EXE_NAME = open-tgm.bin
        ifeq ($(UNAME_M),x86_64)
            #CC = clang++
            BUILD_DIR = ../build/linux64
            CCFLAGS += -g -std=c++11
            LDFLAGS = -Wl,-R./lib 
            INCLUDE_DIR = -I../extlibs/SFML-linux64/include 
            LIBS = -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++ 
            LIBS_DIR = -L../extlibs/SFML-linux64/lib 
            EXTRAS = rm -rf $(BUILD_DIR)/lib ; cp -r ../extlibs/SFML-linux64/lib $(BUILD_DIR) ; rm -f $(BUILD_DIR)/open-tgm ; cp ../data/scripts/open-tgm $(BUILD_DIR)
        else
            BUILD_DIR = ../build/linux32
            CCFLAGS += -std=c++11
            LDFLAGS = -Wl,-R./lib 
            INCLUDE_DIR = -I../extlibs/SFML-linux32/include 
            LIBS = -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++ 
            LIBS_DIR = -L../extlibs/SFML-linux32/lib 
            EXTRAS = rm -rf $(BUILD_DIR)/lib ; cp -r ../extlibs/SFML-linux64/lib $(BUILD_DIR) ; rm -f $(BUILD_DIR)/open-tgm ; cp ../data/scripts/open-tgm $(BUILD_DIR)
        endif
    endif
    ifeq ($(UNAME_S),Darwin)
        BUILD_DIR = ../build/osx
        CCFLAGS += 
        INCLUDE_DIR = -I../extlibs/SFML-osx/include 
        LIBS = 
        LIBS_DIR = -L../extlibs/SFML-osx/lib 
    endif
endif

all : $(EXE_NAME)

clean :
	rm -f $(BUILD_DIR)/$(EXE_NAME) $(EXE_OBJ_FILES);
	rm -rf $(BUILD_DIR)/resources

$(EXE_NAME) : $(EXE_OBJ_FILES) 
	mkdir -p $(BUILD_DIR)
	rm -rf $(BUILD_DIR)/resources
	cp -r ../data/resources $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/$(EXE_NAME) $(EXE_OBJ_FILES) $(LIBS_DIR) $(LIBS)
	$(EXTRAS)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDE_DIR) -o $@ -c $<

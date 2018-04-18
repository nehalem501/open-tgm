CC = g++-4.8
EXE_NAME = open-tgm.bin
UNAME_M=i386
SOURCE_FILES= $(wildcard src/core/*.cpp) $(wildcard src/targets/sfml/*.cpp) $(wildcard src/modes/*.cpp)
EXE_OBJ_FILES = $(SOURCE_FILES:.cpp=.o)
CCFLAGS = -m32 -O2 -DTARGET_SFML -Wall -Wextra -pedantic -std=c++11
INCLUDE_DIR = -I./src/include -I./src/targets/sfml -I./extlibs/SFML-linux_$(UNAME_M)/include
LDFLAGS = -m32 -Wl,-R./lib
LIBS_DIR = -L./extlibs/SFML-linux_$(UNAME_M)/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
BUILD_DIR = ./build/linux_$(UNAME_M)
EXTRAS = rm -rf $(BUILD_DIR)/lib ; cp -r ./extlibs/SFML-linux_$(UNAME_M)/lib $(BUILD_DIR) ; rm -f $(BUILD_DIR)/open-tgm ; cp ./data/scripts/open-tgm $(BUILD_DIR)

all : $(EXE_NAME)

clean :
	rm -f $(BUILD_DIR)/$(EXE_NAME) $(EXE_OBJ_FILES);
	rm -rf $(BUILD_DIR)/resources

$(EXE_NAME) : $(EXE_OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	rm -rf $(BUILD_DIR)/resources
	cp -r ./data/resources $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/$(EXE_NAME) $(EXE_OBJ_FILES) $(LIBS_DIR) $(LIBS)
	$(EXTRAS)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDE_DIR) -o $@ -c $<
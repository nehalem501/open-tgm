# Dummy target Makefile

CFLAGS += -DTARGET_DUMMY -O2 -std=c++98
CXXFLAGS += $(CFLAGS)

CPP_FILES += $(wildcard src/targets/dummy/*.cpp)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

INCLUDE_DIR += -I./src/targets/dummy
BUILD_DIR = ./build/dummy

EXE_NAME := $(addprefix $(BUILD_DIR)/, $(EXE_NAME))

all : print_info $(EXE_NAME)

$(EXE_NAME) : $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJ_FILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIR) -o $@ -c $<

clean :
	rm -rf $(EXE_NAME) $(OBJ_FILES);

print_info:
	@echo C compiler: $(CC)
	@echo CXX compiler: $(CXX)

.PHONY: clean print_info


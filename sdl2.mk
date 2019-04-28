# SDL2 target Makefile

BACKEND := opengl3

BACKEND_SOURCES := $(wildcard $(SRC_DIR)/backends/$(BACKEND)/*.cpp) $(SRC_DIR)/utils/timing.cpp
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o)) $(addprefix $(BUILD_DIR)/, $(BACKEND_SOURCES:src/%.cpp=%.o))

HEADERS += -I$(SRC_DIR)/backends/$(BACKEND)

CXXFLAGS += -DTARGET_SDL2 -O2 -std=c++98 `sdl2-config --cflags`
LIBS = `sdl2-config --libs` -lGLEW -lGL

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS) || { echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS); exit 1; }

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || { echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<; exit 1; }

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/backends/$(BACKEND)
	@mkdir -p $(BUILD_DIR)/utils

.PHONY: clean print_info


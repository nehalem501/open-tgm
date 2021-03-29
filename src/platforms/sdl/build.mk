# SDL

CFLAGS := -g -O2 -DRESIZABLE -DTARGET_SDL `sdl-config --cflags`
CXXFLAGS := -std=c++11

LIBRARIES := `sdl-config --libs`

SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp) $(SRC_DIR)/utils/timing.cpp

GPU_BACKEND := opengl

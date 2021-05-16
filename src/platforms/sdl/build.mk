# SDL

CFLAGS := -g -DRESIZABLE -DTARGET_SDL -DDEBUG `sdl-config --cflags`
CXXFLAGS := -std=c++11

LIBRARIES := `sdl-config --libs`

SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp) $(SRC_DIR)/utils/timing.cpp

GPU_BACKEND := opengl
GPU_TILE_SIZES := 8px # TODO

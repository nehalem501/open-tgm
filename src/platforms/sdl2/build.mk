# SDL2

CFLAGS := -g -O2 -DRESIZABLE -DTARGET_SDL2 -DDEBUG `sdl2-config --cflags`
CXXFLAGS := -std=c++11

LIBRARIES := `sdl2-config --libs`

SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp) $(SRC_DIR)/utils/timing.cpp

# TODO opengl3 backend
GPU_BACKEND := opengl

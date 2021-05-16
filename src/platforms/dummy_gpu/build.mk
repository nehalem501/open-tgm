# dummy_gpu

CFLAGS := -g -O2 -DTARGET_DUMMY_GPU
CXXFLAGS := -std=c++11

SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

GPU_BACKEND := dummy
GPU_TILE_SIZES := 8px # TODO

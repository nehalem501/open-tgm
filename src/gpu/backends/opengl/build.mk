# OpenGL 1.1

BACKEND_SOURCES_CPP := $(wildcard $(GPU_BACKEND_PATH)/*.cpp)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	BACKEND_LIBS := -framework OpenGL
else
    BACKEND_LIBS := -lGL -lGLU
endif

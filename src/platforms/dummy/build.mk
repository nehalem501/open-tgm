# Dummy

# ASFLAGS :=
CFLAGS := -g -O2 -DTARGET_DUMMY
CXXFLAGS := -std=c++98
# LDFLAGS :=

# SOURCES_AS :=
# SOURCES_C :=
SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

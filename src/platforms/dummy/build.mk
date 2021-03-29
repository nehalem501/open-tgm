# Dummy

# ASFLAGS :=
CFLAGS := -g -O2 -DTARGET_DUMMY
CXXFLAGS := -std=c++11
# LDFLAGS :=

# SOURCES_AS :=
# SOURCES_C :=
SOURCES_CPP := $(wildcard $(PLATFORM_PATH)/*.cpp)

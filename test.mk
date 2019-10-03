# Test Makefile (uses dummy target)

CXXFLAGS += -DTARGET_DUMMY -O2 -std=c++11

BIN_DIR = bin/test
BUILD_DIR = build/test
HEADERS = $(HEADERS_CORE) -I$(SRC_DIR)/targets/dummy
HEADERS += -I$(BUILD_DIR)
EXE_NAME = bin/test/test
SOURCES = $(filter-out $(SRC_DIR)/core/main.cpp,$(SOURCES_CORE)) $(wildcard $(SRC_DIR)/targets/dummy/*.cpp)
SOURCES_TESTS = $(wildcard test/*.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(subst test,test,$(SOURCES:src/%.cpp=%.o))) $(SOURCES_TESTS:%.cpp=%.o)

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) || { echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS); exit 1; }

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || { echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<; exit 1; }

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/dummy

.PHONY: clean print_info


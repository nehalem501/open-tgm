# dummy_gpu target Makefile

CXXFLAGS += -DTARGET_DUMMY_GPU -O2 -std=c++98

HEADERS += -I$(SRC_DIR)/gpu
SOURCES += $(wildcard $(SRC_DIR)/gpu/*.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o))

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
	@mkdir -p $(BUILD_DIR)/gpu

.PHONY: clean print_info


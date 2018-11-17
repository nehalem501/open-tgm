# PS3 target Makefile

CC := ppu-gcc
CXX := ppu-g++

CXXFLAGS += -DTARGET_PS3 -O2 -std=c++98

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

.PHONY: clean print_info


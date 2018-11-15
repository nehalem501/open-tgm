# PSX target Makefile

CXX = psx-g++

CXXFLAGS += -DTARGET_PSX -O2 -std=c++98

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME).elf
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME).elf $(OBJECTS) || echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME).elf $(OBJECTS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


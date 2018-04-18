# Dummy target Makefile

CXXFLAGS += -DTARGET_SDL2 -O2 -std=c++98 `sdl2-config --cflags`
LIBS = `sdl2-config --libs`

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


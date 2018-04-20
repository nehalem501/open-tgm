# SDL target Makefile

CXXFLAGS += -DTARGET_SDL -O2 -std=c++98 `sdl-config --cflags`
LIBS = `sdl-config --libs` -lGL -lGLU

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) $(LIBS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


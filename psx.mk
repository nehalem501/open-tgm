# PSX target Makefile

CC = psx-gcc
CXX = psx-g++

CXXFLAGS += -DTARGET_PSX -O2 -std=c++98

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	$(CC) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


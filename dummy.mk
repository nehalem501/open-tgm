# Dummy target Makefile

CXXFLAGS += -DTARGET_DUMMY -O2 -std=c++98

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJ_FILES)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS)

%.o: %.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(INCLUDE_DIR) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


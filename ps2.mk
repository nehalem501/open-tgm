# PS2 target Makefile

CC := ee-gcc
CXX := ee-g++

CXXFLAGS += -DTARGET_PS2 -D_EE -O2 -G0 -std=c++98
LDFLAGS = -mno-crt0 -L$(PS2SDK)/ee/lib -Wl,-r -Wl,-d

HEADERS += -I$(PS2SDK)/ee/include -I$(PS2SDK)/common/include
LIBS = -lc -lkernel

all : $(EXE_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME).erl
	@$(CC) $(LDFLAGS) -o $(EXE_NAME).erl $(OBJECTS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)

.PHONY: clean print_info


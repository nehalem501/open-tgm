# PS3 target Makefile

CC := ppu-gcc
CXX := ppu-g++
STRIP := ppu-strip
SPRX :=	sprxlinker

# fake SELF type4 / type8 tools
FSELF			:=	fself.py
FSELF_NPDRM		:=	$(FSELF) -n

# signed SELF type4 / type8 tools
SELF			:=	make_self
SELF_NPDRM		:=	make_self_npdrm

CXXFLAGS += -DTARGET_PS3 -O2 -std=c++98

HEADERS += -I$(SRC_DIR)/gpu
SOURCES += $(wildcard $(SRC_DIR)/gpu/*.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o))

SELF_NAME := $(EXE_NAME).self
EXE_NAME := $(EXE_NAME).elf

all : $(SELF_NAME)

$(EXE_NAME) : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS) || { echo Failed: $(CXX) $(LDFLAGS) -o $(EXE_NAME) $(OBJECTS); exit 1; }

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || { echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<; exit 1; }

%.self: %.elf
	echo CEX self ... $(notdir $@)
	$(STRIP) $<
	$(SPRX) $<
	$(SELF) $< $@
	$(FSELF) $< $(basename $@).fake.self

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/backends/$(BACKEND)
	@mkdir -p $(BUILD_DIR)/gpu

.PHONY: clean print_info


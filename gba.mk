# GBA target Makefile

CXX = arm-none-eabi-g++

SOURCES += $(wildcard $(SRC_DIR)/targets/gba/resources/*.cpp)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o))

CXXFLAGS += -DTARGET_GBA -O3 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork
LDFLAGS = -mthumb -mthumb-interwork -Wl,-Map,$(BUILD_DIR)/$(NAME).map

HEADERS += -I$(DEVKITPRO)/libgba/include

LIBS = -lmm -lgba
LIBS_DIR = -L$(DEVKITPRO)/libgba/lib

ifeq ($(strip $(DEVKITPRO)),)
  $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

export PATH := $(DEVKITARM)/bin:$(PATH)

all : $(EXE_NAME).gba

$(EXE_NAME).gba : $(EXE_NAME).elf
	arm-none-eabi-objcopy -O binary $< $@
	@echo built ... $(notdir $@)
	gbafix $@

$(EXE_NAME).elf : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	$(CXX) $(LDFLAGS) -specs=gba.specs -o $(EXE_NAME).elf $(OBJECTS) $(LIBS_DIR) $(LIBS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/gba/resources

.PHONY: clean print_info


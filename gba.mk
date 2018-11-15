# GBA target Makefile

CXX = arm-none-eabi-g++
CC = arm-none-eabi-gcc

SOURCES_C = $(wildcard $(SRC_DIR)/targets/gba/resources/*.c)
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o)) $(addprefix $(BUILD_DIR)/, $(SOURCES_C:src/%.c=%.o))

CFLAGS += -DTARGET_GBA -O3 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork
CXXFLAGS += -DTARGET_GBA -O3 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork -fno-rtti -fno-exceptions
LDFLAGS = -mthumb -mthumb-interwork -Wl,-Map,$(BUILD_DIR)/$(NAME).map

ifeq ($(strip $(DEVKITPRO)),)
  $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

export PATH := $(DEVKITARM)/bin:$(PATH)

HEADERS += -I$(DEVKITPRO)/libgba/include

LIBS = -lmm -lgba
LIBS_DIR = -L$(DEVKITPRO)/libgba/lib

all : $(EXE_NAME).gba

$(EXE_NAME).gba : $(EXE_NAME).elf
	arm-none-eabi-objcopy -O binary $< $@
	@echo built ... $(notdir $@)
	gbafix $@

$(EXE_NAME).elf : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -specs=gba.specs $(OBJECTS) -o $(EXE_NAME).elf $(LIBS_DIR) $(LIBS) || echo Failed: $(CXX) $(LDFLAGS) -specs=gba.specs $(OBJECTS) -o $(EXE_NAME).elf $(LIBS_DIR) $(LIBS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $< || echo Failed: $(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@echo $(CC) $<
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< || echo Failed: $(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C compiler: $(CC)
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/gba/resources

.PHONY: clean print_info


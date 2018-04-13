# 3DS target Makefile

CXX = arm-none-eabi-g++

CXXFLAGS += -DTARGET_3DS -O2 -mword-relocations -fomit-frame-pointer -ffunction-sections -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -DARM11 -D_3DS -fno-rtti -fno-exceptions -std=gnu++11
LDFLAGS = -specs=3dsx.specs -march=armv7k -mtune=mpcore -mfloat-abi=hard -mtp=soft -Wl,-Map,$(BUILD_DIR)/$(NAME).map

ifeq ($(strip $(DEVKITPRO)),)
  $(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro")
endif

export PATH := $(DEVKITARM)/bin:$(PATH)

HEADERS += -I$(DEVKITPRO)/libctru/include

LIBS = -lcitro3d -lctru -lm
LIBS_DIR = -L$(DEVKITPRO)/libctru/lib

APP_TITLE = Open TGM
APP_DESCRIPTION = Built with devkitARM & libctru
APP_AUTHOR = Unspecified Author
APP_ICON = $(DEVKITPRO)/libctru/default_icon.png


all : $(EXE_NAME).3dsx

$(EXE_NAME).3dsx : $(EXE_NAME).elf
#	arm-none-eabi-objcopy -O binary $< $@
#	@echo built ... $(notdir $@)
#	gbafix $@

$(EXE_NAME).elf : print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	$(CXX) $(LDFLAGS) -o $(EXE_NAME).elf $(OBJECTS) $(LIBS_DIR) $(LIBS)
	arm-none-eabi-nm -CSn $@ > $(notdir $*.lst)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

define shader-as
  $(eval CURBIN := $*.shbin)
  echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > `(echo $(CURBIN) | tr . _)`.h
  echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> `(echo $(CURBIN) | tr . _)`.h
  echo "extern const u32" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> `(echo $(CURBIN) | tr . _)`.h
  picasso -o $(CURBIN) $1
  bin2s $(CURBIN) | $(AS) -o $*.shbin.o
endef


%.shbin.o %_shbin.h : %.v.pica
	@echo $(notdir $<)
	$(call shader-as,$<)


clean :
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/gba/resources

.PHONY: clean print_info


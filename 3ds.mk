# 3DS target Makefile

AS = arm-none-eabi-as
CXX = arm-none-eabi-g++

CXXFLAGS += -DTARGET_3DS -O2 -mword-relocations -fomit-frame-pointer -ffunction-sections -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -DARM11 -D_3DS -fno-rtti -fno-exceptions -std=gnu++11
LDFLAGS = -specs=3dsx.specs -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -Wl,-Map,$(BUILD_DIR)/$(NAME).map

PICA_FILES := $(wildcard src/targets/3ds/resources/*.v.pica)
PNG_FILES := $(wildcard data/platform_specific/3ds/*.png)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(PNG_FILES:data/platform_specific/3ds/%=%.o)) $(OBJECTS)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(PICA_FILES:src/targets/3ds/resources/%.v.pica=%.shbin.o)) $(OBJECTS)

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

$(EXE_NAME).3dsx: $(EXE_NAME).elf $(EXE_NAME).smdh
	@3dsxtool $< $@ --smdh=$(EXE_NAME).smdh
	@echo built ... $(notdir $@)

$(EXE_NAME).smdh:
	@smdhtool --create "$(APP_TITLE)" "$(APP_DESCRIPTION)" "$(APP_AUTHOR)" $(APP_ICON) $@
	@echo built ... $(notdir $@)

$(EXE_NAME).elf: print_info $(OBJECTS)
	@echo Linking $(EXE_NAME)
	@$(CXX) $(LDFLAGS) -o $(EXE_NAME).elf $(OBJECTS) $(LIBS_DIR) $(LIBS)

  #$(eval CURBIN := $(BUILD_DIR)$*.shbin)
define shader-as
  $(eval CURBIN := $(notdir $*.shbin))
  echo $(CURBIN)
  echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > $(BUILD_DIR)/$(CURBIN).h
  echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> $(BUILD_DIR)/$(CURBIN).h
  echo "extern const u32" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> $(BUILD_DIR)/$(CURBIN).h
  picasso -o $(BUILD_DIR)/$(CURBIN) $1
  bin2s $(BUILD_DIR)/$(CURBIN) | $(AS) -o $(BUILD_DIR)$*.shbin.o
endef

define bin2o
  echo v $<
  echo @ $(@)
  bin2s $< | $(AS) -o $(@)
  echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > $(@:%.o=%.h)
  echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> $(@:%.o=%.h)
  echo "extern const u32" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> $(@:%.o=%.h)
endef

$(BUILD_DIR)%.png.o $(BUILD_DIR)%_png.h: data/platform_specific/3ds/%.png
	@echo $(notdir $<)
	$(bin2o)

$(BUILD_DIR)%.shbin.o $(BUILD_DIR)%_shbin.h: src/targets/3ds/resources/%.v.pica
	@echo shader-as $<
	$(call shader-as,$<)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS);

print_info:
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/gba/resources

.PHONY: clean print_info


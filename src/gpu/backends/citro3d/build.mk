# 3DS - citro3d

BACKEND_SOURCES_CPP := $(wildcard $(GPU_BACKEND_PATH)/*.cpp)

BACKEND_LIBS := -lcitro3d

PICA_FILES := $(wildcard $(GPU_BACKEND_PATH)/shaders/*.v.pica)
PNG_FILES := $(wildcard data/platform_specific/3ds/*.png) # TODO

OBJECTS := $(addprefix $(BUILD_DIR)/, $(PNG_FILES:data/platform_specific/3ds/%=%.o)) $(OBJECTS)
OBJECTS := $(addprefix $(BUILD_DIR)/, $(PICA_FILES:src/gpu/backends/citro3d/shaders/%.v.pica=%.shbin.o)) $(OBJECTS)

$(BUILD_DIR)%.shbin.o: $(GPU_BACKEND_PATH)/shaders/%.v.pica
	@echo compiling shader $@
	@echo "extern const u8" `(echo $(notdir $(@:%.o=%)) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > $(@:%.o=%.h)
	@echo "extern const u8" `(echo $(notdir $(@:%.o=%)) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> $(@:%.o=%.h)
	@echo "extern const u32" `(echo $(notdir $(@:%.o=%)) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> $(@:%.o=%.h)
	@picasso -o $(@:%.o=%) $<
	@bin2s $(@:%.o=%) | $(AS) -o $@

$(BUILD_DIR)%.png.o: data/platform_specific/3ds/%.png
	@echo generating object $@
	@bin2s $< | $(AS) -o $@
	@echo generating header $(@:%.o=%.h)
	@echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > $(@:%.o=%.h)
	@echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> $(@:%.o=%.h)
	@echo "extern const u32" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> $(@:%.o=%.h)

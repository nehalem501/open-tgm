# GPU

HEADERS_GPU := $(SRC_DIR)/gpu/src
SOURCES_GPU_CPP := $(wildcard $(SRC_DIR)/gpu/src/*.cpp)

CONVERT_TOOL_SRC := $(SRC_DIR)/tools/convert.cpp
LIST_TOOL_SRC := $(SRC_DIR)/tools/list.cpp

CONVERT_TOOL := build/convert
LIST_TOOL := build/list

GPU_TOOLS := $(CONVERT_TOOL) $(LIST_TOOL)

INI_NAMES := $(basename $(notdir $(wildcard $(RESOURCES_DIR)/8px/*.ini)))
INI_FILES := $(foreach tile_size,$(GPU_TILE_SIZES),$(foreach name,$(INI_NAMES),$(RESOURCES_DIR)/$(tile_size)/$(name).ini))
INI_FILES_HEADERS := $(foreach tile_size,$(GPU_TILE_SIZES),$(foreach name,$(INI_NAMES),$(name)_$(tile_size).h))
INI_FILES_BUILD := $(addprefix $(BUILD_DIR)/data/,$(INI_FILES_HEADERS))
INI_FILES_HEADERS_PATH := $(addprefix data/,$(INI_FILES_HEADERS))

DATA_INFO_HEADER := $(BUILD_DIR)/data/data_info.h

DATA_FILES_BUILD := $(GPU_TOOLS) $(INI_FILES_BUILD) $(DATA_INFO_HEADER)

CLEAN:= $(INI_FILES_BUILD)
MRPROPER := $(MRPROPER) $(GPU_TOOLS)

define CREATE_RULE
$(BUILD_DIR)/data/%_$1.h: $$(GPU_TOOLS)
$(BUILD_DIR)/data/%_$1.h: $(RESOURCES_DIR)/$1/%.ini
	@echo Converting $$<
	@mkdir -p $(BUILD_DIR)/data || { echo Failed: mkdir -p $(BUILD_DIR)/data; exit 1; }
	@$$(CONVERT_TOOL) $$< $$@ || { echo Failed: $$(CONVERT_TOOL) $$< $$@; exit 1; }
endef

$(foreach tile_size,$(GPU_TILE_SIZES),$(eval $(call CREATE_RULE,$(tile_size))))

$(DATA_INFO_HEADER): $(GPU_TOOLS)
	@echo Building $(DATA_INFO_HEADER)
	@$(LIST_TOOL) $(DATA_INFO_HEADER) $(INI_FILES_HEADERS_PATH) || { echo Failed: $(LIST_TOOL) $(DATA_INFO_HEADER) $(INI_FILES_HEADERS_PATH); exit 1; }

$(CONVERT_TOOL): $(CONVERT_TOOL_SRC)
	@echo Building $(CONVERT_TOOL)
	@mkdir -p build || { echo Failed: mkdir -p build; exit 1; }
	@$(HOST_CXX) $(CONVERT_TOOL_SRC) -o $(CONVERT_TOOL) || { echo Failed: $(HOST_CXX) $(CONVERT_TOOL_SRC) -o $(CONVERT_TOOL); exit 1; }

$(LIST_TOOL): $(LIST_TOOL_SRC)
	@echo Building $(LIST_TOOL)
	@mkdir -p build || { echo Failed: mkdir -p build; exit 1; }
	@$(HOST_CXX) $(LIST_TOOL_SRC) -o $(LIST_TOOL) || { echo Failed: $(HOST_CXX) $(CONVERT_TOOL_SRC) -o $(LIST_TOOL); exit 1; }

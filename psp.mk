# PSP target Makefile

SOURCES_C = $(wildcard src/targets/psp/resources/*.c)
OBJS = $(addprefix $(BUILD_DIR)/, $(SOURCES:src/%.cpp=%.o)) $(addprefix $(BUILD_DIR)/, $(SOURCES_C:src/%.c=%.o))

HEADERS += -Iextlibs/gLib2D
CFLAGS = -O2 -G0 -Wall -DTARGET_PSP
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LDFLAGS = -Lextlibs/gLib2D
LIBS = -lglib2d -ljpeg -lpng -lz -lpspgum -lpspgu -lpsprtc -lm -lpspvram

# 
PSP_EBOOT = bin/psp/EBOOT.PBP
PSP_EBOOT_SFO = bin/psp/PARAM.SFO
PSP_EBOOT_TITLE = Open TGM
#PSP_EBOOT_ICON = ICON0.png
#PSP_EBOOT_PIC1 = PIC1.png

# PSPSDK build system needs this
TARGET = ./build/psp/open-tgm
EXTRA_TARGETS = $(PSP_EBOOT)

all: print_info $(FINAL_TARGET)

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo $(CXX) $<
	@$(CXX) $(CXXFLAGS) $(HEADERS) -o $@ -c $<

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@echo $(CC) $<
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

#logo.o: logo.raw
#	bin2o -i logo.raw logo.o logo

#finalize:
#	mkdir -p ./build/psp
#	mv EBOOT.PBP ./build/psp
#	rm -rf ./build/psp/resources
#	cp -r ./data/platform_specific/psp ./build/psp
#	mv ./build/psp/psp ./build/psp/resources

print_info:
	@echo C compiler: $(CC)
	@echo C++ compiler: $(CXX)
	@mkdir -p $(BUILD_DIR)/targets/psp/resources

.PHONY: print_info


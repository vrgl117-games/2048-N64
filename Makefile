ROOTDIR = $(N64_INST)
GCCN64PREFIX = $(ROOTDIR)/bin/mips64-elf-
CHKSUM64PATH = $(ROOTDIR)/bin/chksum64
MKDFSPATH = $(ROOTDIR)/bin/mkdfs
MKSPRITE = $(ROOTDIR)/bin/mksprite
N64TOOL = $(ROOTDIR)/bin/n64tool
LINK_FLAGS = -L$(ROOTDIR)/mips64-elf/lib -ldragon -lc -lm -ldragonsys -Tn64ld.x
PROG_NAME = 2048-64
CFLAGS = -std=gnu99 -march=vr4300 -mtune=vr4300 -O2 -Wall -Werror -I$(ROOTDIR)/mips64-elf/include -Iinclude
ASFLAGS = -mtune=vr4300 -march=vr4300
CC = $(GCCN64PREFIX)gcc
AS = $(GCCN64PREFIX)as
LD = $(GCCN64PREFIX)ld
OBJCOPY = $(GCCN64PREFIX)objcopy

all: $(PROG_NAME).z64

docker:
	docker build -t build .
	docker run --rm build cat $(PROG_NAME).z64 > $(PROG_NAME).z64

$(PROG_NAME).z64: $(PROG_NAME).bin $(PROG_NAME).dfs
	@rm -f $@
	$(N64TOOL) -l 2M -t "$(PROG_NAME)" -h $(ROOTDIR)/mips64-elf/lib/header -o $(PROG_NAME).z64 $(PROG_NAME).bin -s 1M $(PROG_NAME).dfs
	$(CHKSUM64PATH) $@

$(PROG_NAME).bin : $(PROG_NAME).elf
	$(OBJCOPY) -O binary $< $@

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
$(PROG_NAME).elf : $(OBJS)
	$(LD) -o $@ $^ $(LINK_FLAGS)

PNGS := $(wildcard resources/gfx/*.png)
SPRITES := $(subst .png,.sprite,$(subst resources/,filesystem/,$(PNGS)))
filesystem/gfx/%.sprite: resources/gfx/%.png
	$(MKSPRITE) 16 1 1 $< $@

$(PROG_NAME).dfs: sprites
	$(MKDFSPATH) $@ ./filesystem/

sprites: $(SPRITES)
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117.png filesystem/gfx/vrgl117.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_1.png filesystem/gfx/vrgl117_1.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_2.png filesystem/gfx/vrgl117_2.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_3.png filesystem/gfx/vrgl117_3.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_4.png filesystem/gfx/vrgl117_4.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_5.png filesystem/gfx/vrgl117_5.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_6.png filesystem/gfx/vrgl117_6.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_7.png filesystem/gfx/vrgl117_7.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_8.png filesystem/gfx/vrgl117_8.sprite
	$(MKSPRITE) 32 1 1 resources/gfx/vrgl117_9.png filesystem/gfx/vrgl117_9.sprite

cen64:
	$(CEN64_DIR)/cen64 $(CEN64_DIR)/pifdata.bin $(PROG_NAME).z64

flashair:
	curl -X POST -d @$(PROG_NAME).z64 http://flashair/upload.cgi

clean:
	rm -f *.z64 *.elf src/*.o *.bin *.dfs

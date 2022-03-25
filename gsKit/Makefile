EE_BIN = bmptest.elf

EE_OBJS = g_gs.o ps2doom_bmp.o

EE_INCS = -I$(PS2SDK)/ports/include -I$(GSKIT)/include -I$(GSKIT)/ee/dma/include -I$(GSKIT)/ee/gs/include -I$(GSKIT)/ee/toolkit/include 

EE_LDFLAGS = -L$(PS2SDK)/ports/lib -L$(PS2SDK)/iop/lib/ -L$(PS2SDK)/ee/lib/ -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/sbv/lib

EE_LIBS += -lc -ldebug -lpatches -Wno-pointer-sign -Wno-implicit-function-declaration -Xlinker --start-group $(EE_LIBS_EXTRA) -lpadx -lmtap -lmc -lkernel -lpoweroff -lnetman -lps2ips -lfileXio -laudsrv -lelf-loader -lgskit_toolkit -lgskit -ldmakit -lpng -ljpeg -lz -Xlinker --end-group

bin: $(EE_BIN)

clean: 
	rm -f $(EE_BIN) $(EE_OBJS)

ps2doom_bmp.s: ps2doom.bmp
	bin2s $< $@ ps2doom_bmp

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
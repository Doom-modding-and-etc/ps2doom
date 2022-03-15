
define HEADER
  

  	 _______  _________   _______  	______          _____   _____  ____        ____  
  	|  ___  ||  _______| |_____  | |  ____ \       | ___ | | ___ ||  _ \      / _  |
  	| |___| || |           	   | | | |    | \      ||   || ||   ||| | \ \    / / | |
	|   ____|| |_______   _____| | | |    |  \     ||   || ||   ||| |  \ \__/ /  | |
  	|  |     |_______  | |  _____| | |    |   \    ||   || ||   ||| |   \____/   | |
  	|  |             | | | |       | |    |    \   ||   || ||   ||| |            | |
	|  |      _______| | | |_____  | |____|     \  ||___|| ||___||| |     	     | |
  	|__|     |_________| |_______| |_____________\ |_____| |_____||_|	         |_|				 	                                       
                                     
endef
export HEADER

EE_OBJS = am_map.o cosmito_wav.o d_command.o d_items.o d_main.o d_net.o doomdef.o doomstat.o dstrings.o \
elf_structure.o f_finale.o f_wipe.o \
g_game.o \
hu_lib.o hu_stuff.o \
i_main.o i_net.o i_sound.o i_system.o i_video.o info.o m_argv.o m_bbox.o \
m_cheat.o m_fixed.o m_menu.o m_misc.o m_random.o m_swap.o mixer_thread.o mixer.o mmus2mid.o p_ceilng.o \
p_doors.o p_enemy.o p_floor.o p_inter.o p_lights.o p_map.o p_maputl.o \
p_mobj.o p_plats.o p_pspr.o p_saveg.o p_setup.o p_sight.o p_spec.o \
p_switch.o p_telept.o p_tick.o p_user.o ps2doom.o r_bsp.o r_data.o r_draw.o \
r_main.o r_plane.o r_segs.o r_sky.o r_things.o s_sound.o sjpcm_rpc.o sounds.o \
st_lib.o st_stuff.o tables.o v_video.o w_wad.o w_mmap.o wi_stuff.o z_zone.o \


EE_BIN = bin/ps2doom.elf
EE_INCS = -I$(PS2SDK)/ports/include/SDL -I$(PS2SDK)/ports/include -I$(PS2DEV)/isjpcm/include/ -I$(GSKIT)/include -I$(GSKIT)/ee/dma/include -I$(GSKIT)/ee/gs/include -I$(GSKIT)/ee/toolkit/include 
EE_LDFLAGS = -L$(PS2SDK)/ports/lib -L$(PS2DEV)/isjpcm/lib/ -L$(PS2SDK)/iop/lib/ -L$(PS2SDK)/ee/lib/ -L$(PS2DEV)/gsKit/lib 
EE_LIBS = -lsdlmain -lsdlmixer -lsdl -lcdvd -lm -lps2ip -ldebug -lconfig -lmc -lc -lhdd -lpoweroff -lsjpcm -lmixer -llua -lgskit
EE_CFLAGS = -DUSE_RWOPS -DHAVE_CONFIG_H -DHAVE_MIXER -Wall -DLUA_USE_PS2
EE_ASM_DIR = asm/
EE_OBJS_DIR = obj/

BIN2S = $(PS2SDK)/bin/bin2s

$(EE_ASM_DIR):
	@mkdir -p $@
	@echo "$$HEADER"
$(EE_OBJS_DIR):
	@mkdir -p $@
	mv $(EE_OBJS) obj/

$(EE_BIN):
	mv $(EE_BIN) bin/


all: $(EE_BIN) $(EE_ASM_DIR) $(EE_OBJS_DIR) modules
	

#poweroff Module
asm/poweroff.s: $(PS2SDK)/iop/irx/poweroff.irx
	$(BIN2S) $< $@ poweroff_irx

#IRX Modules
asm/freesio2.s: $(PS2SDK)/iop/irx/freesio2.irx
	$(BIN2S) $< $@ freesio2_irx
	
asm/iomanX.s: $(PS2SDK)/iop/irx/iomanX.irx
	$(BIN2S) $< $@ iomanX_irx 

asm/sio2man.s: $(PS2SDK)/iop/irx/sio2man.irx
	$(BIN2S) $< $@ sio2man_irx

asm/freepad.s: $(PS2SDK)/iop/irx/freepad.irx
	$(BIN2S) $< $@ freepad_irx

asm/mcman_irx.s: $(PS2SDK)/iop/irx/mcman.irx
	$(BIN2S) $< $@ mcman_irx

asm/mcserv_irx.s: $(PS2SDK)/iop/irx/mcserv.irx
	$(BIN2S) $< $@ mcserv_irx

asm/ps2dev9.s: $(PS2SDK)/iop/irx/ps2dev9.irx
	$(BIN2S) $< $@ ps2dev9_irx 

asm/ps2atad.s: $(PS2SDK)/iop/irx/ps2atad.irx
	$(BIN2S) $< $@ ps2atad_irx

asm/ps2fs_irx.s: $(PS2SDK)/iop/irx/ps2fs-xosd.irx
	$(BIN2S) $< $@ ps2fs_irx

asm/ps2hdd_irx.s: $(PS2SDK)/iop/irx/ps2hdd-xosd.irx
	$(BIN2S) $< $@ ps2hdd_irx

asm/ps2ip-nm.s: $(PS2SDK)/iop/irx/ps2ip-nm.irx
	$(BIN2S) $< $@ ps2ip-nm_irx

asm/ps2ips.s: $(PS2SDK)/iop/irx/ps2ips.irx
	$(BIN2S) $< $@ ps2ips_irx 

asm/netman.s: $(PS2SDK)/iop/irx/netman.irx 
	$(BIN2S) $< $@ netman_irx 

asm/smap.s: $(PS2SDK)/iop/irx/smap.irx 
	$(BIN2S) $< $@ smap_irx 

asm/ps2http.s: $(PS2SDK)/iop/irx/ps2http.irx 
	$(BIN2S) $< $@ ps2http_irx

asm/usbd_irx.s: $(PS2SDK)/iop/irx/usbd.irx
	$(BIN2S) $< $@ usbd_irx

asm/usbhdfsd_irx.s: $(PS2SDK)/iop/irx/usbhdfsd.irx
	$(BIN2S) $< $@ usb_mass_irx

asm/usbmass_bd.s: $(PS2SDK)/iop/irx/usbmass_bd.irx
	$(BIN2S) $< $@ usbmass_bd_irx
 
asm/isjpcm.s: $(PS2DEV)/isjpcm/bin/isjpcm.irx
	$(BIN2S) $< $@ isjpcm_irx

#compile all modules
modules: asm/poweroff.s asm/freesio2.s asm/iomanX.s asm/sio2man.s asm/freepad.s asm/mcman_irx.s asm/mcserv_irx.s asm/ps2dev9.s asm/ps2atad.s asm/ps2fs_irx.s asm/ps2hdd_irx.s asm/ps2ip-nm.s asm/ps2ips.s asm/netman.s asm/smap.s asm/ps2http.s asm/usbd_irx.s asm/usbhdfsd_irx.s asm/usbmass_bd.s asm/isjpcm.s

clean: 
	rm -fr $(EE_BIN) $(EE_ASM_DIR)
	rm -fr $(EE_OBJS_DIR)
run:
	cd bin; ps2client -h $(PS2LINK_IP) execee host$(EE_BIN)

reset:
	ps2client reset

# taken from tyra engine examples
pcsx2:
	taskkill.exe /f /t /im pcsx2.exe || true
	$(WSL_LINUX_PCSX2)/pcsx2.exe --elf=$(WSL_MAKE_WINDOWS)\\root\\ps2doom\\$(DIR_NAME)\\$(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

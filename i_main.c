// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//
// static const char rcsid[] = "$Id: i_main.c,v 1.4 1997/02/03 22:45:10 b1 Exp $";
//-----------------------------------------------------------------------------

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <libmc.h>
#include <libconfig.h>
#include <sifrpc.h>
#include <debug.h>
#include <libpwroff.h>
#include <loadfile.h>
#include <tamtypes.h> 
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sjpcm.h>

#define MAX_PARTITIONS   100


// cosmitoMixer
#include <sifrpc.h>
#include <mixer/mixer.h>
#include <mixer/mixer_thread.h>
#include <kernel.h>     //for GetThreadId 
#include <mixer/wav.h>

#include "include/elf_structure.h"
#include "include/pad_support.h"
#include "include/modules.h"
#include "include/hdd.h"

#include "include/doomdef.h"
#include "include/m_argv.h"
#include "include/d_main.h"

#include "include/w_wad.h"

extern unsigned char usbd;
extern unsigned int size_usbd;

//Declare usbhdfsd module //
extern unsigned char usbhdfsd;
extern unsigned int size_usbhdfsd;

extern unsigned char usbmass_bd_irx;
extern unsigned int size_usbmass_bd_irx;

extern unsigned char SJPCM;
extern unsigned int size_SJPCM;

extern unsigned char sio2man_irx;
extern unsigned int size_sio2man_irx;

/*Declare ps2dev9 module*/
extern unsigned char ps2dev9;
extern unsigned int size_ps2dev9;
/*Declare ps2atad module*/
extern unsigned char ps2atad;
extern unsigned int size_ps2atad;
/*Declare ps2hdd module*/
extern unsigned char ps2hdd;
extern unsigned int size_ps2hdd;
/*Declare ps2fsmodule*/
extern unsigned char ps2fs;
extern unsigned int size_ps2fs;
/*Declare poweroff module*/
extern unsigned char poweroff;
extern unsigned int size_poweroff;
/*Declare cdvd module*/
extern unsigned char cdvd;
extern unsigned int size_cdvd;

extern unsigned char freesd;
extern unsigned int size_freesd;

extern int SAMPLECOUNT = 512;


/// these two are pairs
typedef struct
{
    char* name;
    char* defaultaction;
} config_buttons_element;

config_buttons_element config_buttons[] = 
{
    // button name, default action
    // both button names and action names as appearing at the libconfig config file
    {"square", "previous weapon"},
    {"cross", "run"},
    {"circle", "next weapon"},
    {"triangle", "escape"},
    {"select", "map"},
    {"start", "enter"},
    {"l1", "n"},
    {"r1", "fire"},
    {"l2", "y"},
    {"r2", "open"},
    {"l3", ""}, /// TBD : yet not used
    {"r3", "gamma"},
    {"dpadleft", "leftarrow"},
    {"dpadright", "rightarrow"},
    {"dpadup", "uparrow"},
    {"dpaddown", "downarrow"},
    {"analog1left", ""},                /// TBD : yet not used
    {"analog1right", ""},               /// TBD : yet not used
    {"analog2left", "strafe left"},     // index 18
    {"analog2right", "strafe right"}
};

// Store place to be built at config loading. Have the key codes for each button.

// KEY_RIGHTARROW	0xae
// KEY_LEFTARROW	0xac
// KEY_UPARROW	    0xad
// KEY_DOWNARROW	0xaf

///

typedef struct
{
    char*	name;
    int		value;
} config_actions_element;

config_actions_element	config_actions[] =
{
    // actually the key mapping for the actions :
    // action name, mapped key 
    {"previous weapon", SDLK_o},
    {"run", KEY_RSHIFT},
    {"next weapon", SDLK_p},
    {"escape", KEY_ESCAPE},
    {"map", KEY_TAB},
    {"enter", KEY_ENTER},
    {"n", SDLK_n},
    {"fire", KEY_RCTRL},
    {"y", SDLK_y},
    {"open", SDLK_SPACE},
    {"gamma", KEY_F11},
    {"leftarrow", KEY_LEFTARROW},
    {"rightarrow", KEY_RIGHTARROW},
    {"uparrow", KEY_UPARROW},
    {"downarrow", KEY_DOWNARROW},
    
    {"strafe left", STRAFELEFT},
    {"strafe right", STRAFERIGHT},

    /// to add a new : add entry here with default
};

char config_probestring[200];

/// -------------------------


#define DEBUG_LIBCONFIG

const char *hdd_wads_folder;

int getFileSize(FILE *fd) 
{
	int size = fseek(fd, 0, SEEK_END);
	fseek(fd, 0, SEEK_SET);
	return size;
}

void Display_mode()
{
    #define PAL_WIDTH 480
    #define PAL_HEIGHT 576
    #define PAL_BITS 32
    
    #define NTSC_WIDTH 640
    #define NTSC_HEIGHT 480
    #define NTSC_BITS 32

    int forceDisplayMode = -1;
    
    SDL_Surface *PAL;
    SDL_Surface *NTSC;
    
    PAL = SDL_SetVideoMode(PAL_WIDTH, PAL_HEIGHT, PAL_BITS, SDL_SWSURFACE);
    
    NTSC = SDL_SetVideoMode(NTSC_WIDTH, NTSC_HEIGHT, NTSC_BITS, SDL_SWSURFACE);

    if (PAL)
    {
     SDL_Flip(PAL);
    
     SDL_ShowCursor(SDL_DISABLE);

     SDL_Quit();
    }
    
    else if(NTSC)
    {
      SDL_Flip(NTSC);

      SDL_ShowCursor(SDL_DISABLE);

      SDL_Quit();
    }

    else 
    {
	 printf("error");
    }

    // Changes accordingly to filename
    forceDisplayMode = getDisplayModeFromELFName(myargv);
    if (forceDisplayMode != -1)
        PS2SDL_ForceSignal(forceDisplayMode);

    // Sets SAMPLECOUNT accordingly to system
    if (NTSC == 0)
    {
        SAMPLECOUNT = 960;
    }
    else if(PAL == 1)
    {
        SAMPLECOUNT = 800;
    }

    else
    {
      scr_printf ("error loading SAMPLECOUNT");
    }
    D_DoomMain (); 


}

void Display_screen()
{
    //Todo: figure out whats going on the SDL1 cursor 
    #define WIDTH 640
    #define HEIGHT 448
    #define BITS 32
  
    SDL_Surface *image;
  
    SDL_Surface *window;
      
    image = SDL_LoadBMP("gfx/ps2doom.bmp");
    
    window = SDL_SetVideoMode(WIDTH, HEIGHT, BITS, SDL_NOFRAME);

    SDL_Flip(window);
     // printf("SDL1.2 Is not working properly", SDL_GetError());
    SDL_BlitSurface( image, NULL, window, NULL );  
    
    // Set window title
    SDL_WM_SetCaption("Display BMP", NULL);

    SDL_Delay(6000);
    
    SDL_DisplayFormat(image);
    
    SDL_FreeSurface(image);

    SDL_Quit();
}

//#endif
char config_probestring[200];

/// -------------------------

#define DEBUG_LIBCONFIG

const char *hdd_wads_folder;
//code by vts
void ResetIOP()
{
	SifInitRpc(0);
	while(!SifIopReset("", 0)){};
	while(!SifIopSync()){};
	SifLoadFileExit();
        SifExitRpc();
        SifInitRpc(0);
        ResetIOP();
	SifInitIopHeap();
}

int waitPadReady(int port, int slot) 
{
    int state;
    int lastState;
    char stateString[16];

    state = padGetState(port, slot);
    lastState = -1;
    while((state != PAD_STATE_STABLE) && (state != PAD_STATE_FINDCTP1)) {
        if (state != lastState) {
            padStateInt2String(state, stateString);
            printf("Please wait, pad(%d,%d) is in state %s\n", 
                       port, slot, stateString);
        }
        lastState = state;
        state=padGetState(port, slot);
    }
    // Were the pad ever 'out of sync'?
    if (lastState != -1) {
        printf("Pad OK!\n");
    }
    return 0;

}

int initializePad(int port, int slot) 
{
    int ret;
    int modes;
    int i;

    waitPadReady(port, slot);

    // How many different modes can this device operate in?
    // i.e. get # entrys in the modetable
    modes = padInfoMode(port, slot, PAD_MODETABLE, -1);
    printf("The device has %d modes\n", modes);

    if (modes > 0) {
        printf("( ");
        for (i = 0; i < modes; i++) {
            printf("%d ", padInfoMode(port, slot, PAD_MODETABLE, i));
        }
        printf(")");
    }

    printf("It is currently using mode %d\n", 
               padInfoMode(port, slot, PAD_MODECURID, 0));

    // If modes == 0, this is not a Dual shock controller 
    // (it has no actuator engines)
    if (modes == 0) {
        printf("This is a digital controller?\n");
        return 1;
    }

    // Verify that the controller has a DUAL SHOCK mode
    i = 0;
    do {
        if (padInfoMode(port, slot, PAD_MODETABLE, i) == PAD_TYPE_DUALSHOCK)
            break;
        i++;
    } while (i < modes);
    if (i >= modes) {
        printf("This is no Dual Shock controller\n");
        return 1;
    }

    // If ExId != 0x0 => This controller has actuator engines
    // This check should always pass if the Dual Shock test above passed
    ret = padInfoMode(port, slot, PAD_MODECUREXID, 0);
    if (ret == 0) {
        printf("This is no Dual Shock controller??\n");
        return 1;
    }

    printf("Enabling dual shock functions\n");

    // When using MMODE_LOCK, user cant change mode with Select button
    padSetMainMode(port, slot, PAD_MMODE_DUALSHOCK, PAD_MMODE_LOCK);

    waitPadReady(port, slot);
    printf("infoPressMode: %d\n", padInfoPressMode(port, slot));

    waitPadReady(port, slot);        
    printf("enterPressMode: %d\n", padEnterPressMode(port, slot));

    waitPadReady(port, slot);
    actuators = padInfoAct(port, slot, -1, 0);
    printf("# of actuators: %d\n",actuators);

    if (actuators != 0) {
        actAlign[0] = 0;   // Enable small engine
        actAlign[1] = 1;   // Enable big engine
        actAlign[2] = 0xff;
        actAlign[3] = 0xff;
        actAlign[4] = 0xff;
        actAlign[5] = 0xff;

        waitPadReady(port, slot);
        printf("padSetActAlign: %d\n", 
                   padSetActAlign(port, slot, actAlign));
    }
    else {
        printf("Did not find any actuators.\n");
    }

    waitPadReady(port, slot);

    return 1;
}

int padUtils_ReadButtonWait(int port, int slot, u32 old_pad, u32 new_pad)
{
    int butres = 0, read = 0;
    read = padUtils_ReadButton(port, slot, old_pad, new_pad);

    if(read != 0)
    {
        butres = read;      // memorize pressed button
        while (padUtils_ReadButton(port, slot, old_pad, new_pad) != 0) {};
    }
    return butres;
}

int padUtils_ReadButton(int port, int slot, u32 old_pad, u32 new_pad)
{
    struct padButtonStatus buttons;
    int ret;
    u32 paddata;

    ret = padRead(port, slot, &buttons);
    if (ret != 0)
    {
        paddata = 0xffff ^ buttons.btns;
        
        new_pad = paddata & ~old_pad;
        old_pad = paddata;
        

        if (new_pad & PAD_LEFT)
        {
            //LEFT
            return(PAD_LEFT);
        }
        if (new_pad & PAD_DOWN)
        {
            //DOWN
            return(PAD_DOWN);
        }
        if (new_pad & PAD_RIGHT)
        {
            //RIGHT
            return(PAD_RIGHT);
        }
        if (new_pad & PAD_UP)
        {
            //UP
            return(PAD_UP);
        }
        if (new_pad & PAD_START)
        {
            //START
            return(PAD_START);
        }
        if (new_pad & PAD_R3)
        {
            //R3
            return(PAD_R3);
        }
        if (new_pad & PAD_L3)
        {
            //L3
            return(PAD_L3);
        }
        if (new_pad & PAD_SELECT)
        {
            //SELECT
            return(PAD_SELECT);
        }
        if (new_pad & PAD_SQUARE)
        {
            //SQUARE
            return(PAD_SQUARE);
        }
        if (new_pad & PAD_CROSS)
        {
            //CROSS
            return(PAD_CROSS);
        }
        if (new_pad & PAD_CIRCLE)
        {
            //CIRCLE
            return(PAD_CIRCLE);
        }
        if (new_pad & PAD_TRIANGLE)
        {
            //TRIANGLE
            return(PAD_TRIANGLE);
        }
        if (new_pad & PAD_R1)
        {
            //R1
            return(PAD_R1);
        }
        if (new_pad & PAD_L1)
        {
            //L1
            return(PAD_L1);
        }
        if (new_pad & PAD_R2)
        {
            //R2
            return(PAD_R2);
        }
        if (new_pad & PAD_L2)
        {
            //L2
            return(PAD_L2);
        }
    }
    else
    {
        return -1;
    }
        
    
 
    return 0;   // 0 means no button was pressed
}

//int main
int main( int argc, char**	argv ) 
{
    FILE *fp;
    int i, j, nj;
    const char *s;
    char configfile[256];
    config_t cfg;       // libconfig
    char elfFilename[100];
    char deviceName[10];
    char fullPath[256];
    int use_hdd;
    int ret;   
    int mc_Type, mc_Free, mc_Format;
    static char hddarg[] = "-o" "\0" "4" "\0" "-n" "\0" "20";
    static char pfsarg[] = "-m" "\0" "4" "\0" "-o" "\0" "10" "\0" "-n" "\0" "40";
    const char *hdd_path_to_partition;
    use_hdd = CONFIG_FALSE;
    FILE *handle;
    myargc = argc; 
    myargv = argv; 
    s32 main_thread_id;
    int x;
    int swap_analogsticks;
    int configLoadSuccess = 0;
    int value;
    GetElfFilename(argv[0], deviceName, fullPath, elfFilename);
    main_thread_id = GetThreadId();
    
    Display_screen();
    
    SifInitRpc(0); 

    /********************************************************* 
    **********************************************************    
    ** todo:                                                **
    ** init_scr();                                          **
    ** scr_printf("--==== PS2DOOM v1.0.6.0 ====--\n\n\n");  **
    ** scr_clear();                                         **
    **********************************************************
    **********************************************************/
    
    printf("sample: kicking IRXs\n");
	
    ret = SifExecModuleBuffer(freesd, size_freesd, 0, NULL, &ret);
	printf("freesd loadmodule %d\n", ret);

    
    //Load embedded modules

    // SJPCM
    SifExecModuleBuffer(SJPCM, size_SJPCM, 0, NULL, &ret);
    
    // USB mass support
    SifExecModuleBuffer(usbd, size_usbd, 0, NULL, &ret);
    SifExecModuleBuffer(usbhdfsd, size_usbhdfsd, 0, NULL, &ret);

	ret = SifLoadModule("rom0:SIO2MAN", 0, NULL);
	if (ret < 0) {
		printf("Failed to load module: SIO2MAN");
        scr_printf("Failed to load module: SIO2MAN");
		SleepThread();
	}
	ret = SifLoadModule("rom0:XMCMAN", 0, NULL);
	if (ret < 0) {
		printf("Failed to load module: MCMAN");
		scr_printf("Failed to load module: MCMAN");
		SleepThread();
	}
	ret = SifLoadModule("rom0:XMCSERV", 0, NULL);
	if (ret < 0) {
		printf("Failed to load module: MCSERV");
		SleepThread();
	}
	if(mcInit(MC_TYPE_XMC) < 0) {
		printf("Failed to initialize memcard server!\n");
		SleepThread();
	}
	
    
    // Since this is the first call, -1 should be returned.
	mcGetInfo(0, 0, &mc_Type, &mc_Free, &mc_Format); 
	mcSync(0, NULL, &ret);
	printf("mcGetInfo returned %d\n",ret);
	printf("Type: %d Free: %d Format: %d\n\n", mc_Type, mc_Free, mc_Format);

	// Assuming that the same memory card is connected, this should return 0
	mcGetInfo(0,0,&mc_Type,&mc_Free,&mc_Format);
	mcSync(0, NULL, &ret);
	printf("mcGetInfo returned %d\n",ret);
	printf("Type: %d Free: %d Format: %d\n\n", mc_Type, mc_Free, mc_Format);
    if (ret != 0)
        printf("mc0 trouble... should save to other device... To implement\n");  /// TBD
    
    // create save/load dir (mc0:PS2DOOM)
    fopen("mc0:PS2DOOM/doomsav0.dsg", O_RDONLY);
    if (handle < 0)
    {
        //fioMkdir("mc0:PS2DOOM"); // Make sure it exists
        printf(" ... created mc0:PS2DOOM ...\n");
    }
    else
        fclose(handle);


    /// config
    sprintf(configfile, "%s%s", fullPath, "ps2doom.config");

    // First, try to load from localpath. If fails, try from 'mc0:'
    
    fp = fopen(configfile, "rb");
    if(!fp)
    {
        printf("file '%s' not found. Going to try 'mc0:PS2DOOM/ps2doom.config'\n", configfile);
        sprintf(configfile, "%s", "mc0:PS2DOOM/ps2doom.config");

        fp = fopen(configfile, "rb");
        if(!fp)
        {
            // Using default actions for buttons
#ifdef DEBUG_LIBCONFIG
            printf("Unable to open '%s'. Using defaults\n", configfile);
#endif
            int nConfig_buttonsEntries = sizeof(config_buttons)/sizeof(config_buttons[0]);
            for (i=0; i<nConfig_buttonsEntries; i++)
            {
                nj = sizeof(config_actions)/sizeof(config_actions[0]);
                for(j=0; j<nj; j++)
                {
                    if(strcmp(config_actions[j].name, config_buttons[i].defaultaction) == 0)
                    {
                        value = config_actions[j].value;
                        //config_buttons[i] = value;
                        return value;
                    }
                }      
            }
        }
        else
            configLoadSuccess = 1;
    }
    else
        configLoadSuccess = 1;

    if(configLoadSuccess == 1)
    {
        // Get the actions for buttons from config
        
        config_init(&cfg);
        x = config_read(&cfg, fp);
        fclose(fp);
        if(x)
        {
            // Process each ps2doom.controls config entries
            int nConfigEntries = sizeof(config_buttons)/sizeof(config_buttons[0]);
            for (i=0; i<nConfigEntries; i++)
            {
                sprintf(config_probestring, "%s%s", "ps2doom.controls.", config_buttons[i].name);
                if(! config_lookup_string(&cfg, config_probestring, &s))
                {
#ifdef DEBUG_LIBCONFIG
                    printf("NOT FOUND %s\n", config_probestring);
#endif
                }
                else
                {
#ifdef DEBUG_LIBCONFIG
                    printf("found: %s = %s\n", config_probestring, s);
#endif
                    nj = sizeof(config_actions)/sizeof(config_actions[0]);
                    for(j=0; j<nj; j++)
                    {
                        if(strcmp(config_actions[j].name, s) == 0)
                        {
                            value = config_actions[j].value;
                            //config_buttons[i] = value;
                            return value;
                        }
                    }      
                }
            }
        }
        else
            printf("error on line %d: %s\n", cfg.error_line, cfg.error_text);

        use_hdd = CONFIG_FALSE;
        sprintf(config_probestring, "%s", "ps2doom.hdd.use_hdd");
        if(!config_lookup_bool(&cfg, config_probestring, &use_hdd))
        {
            printf("found: %s = %d\n", config_probestring, use_hdd);
        }
        
        else
        {
            use_hdd = CONFIG_FALSE;
            printf("NOT FOUND %s\n", config_probestring);
        }


        if(use_hdd == CONFIG_TRUE)
        {
            sprintf(config_probestring, "%s", "ps2doom.hdd.path_to_partition");
            if(!config_lookup_string(&cfg, config_probestring, &hdd_path_to_partition))
            {
                printf("found: %s = %s\n", config_probestring, hdd_path_to_partition);

            }
            
            else
            {
                printf("NOT FOUND %s\n", config_probestring);
                scr_printf("Error: Value '%s' at ps2doom.config not found\n", config_probestring);
                SleepThread();
            }

            sprintf(config_probestring, "%s", "ps2doom.hdd.wads_folder");
            if(!config_lookup_string(&cfg, config_probestring, &hdd_wads_folder))
            {
                printf("NOT FOUND %s\n", config_probestring);
                scr_printf("Error: Value '%s' at ps2doom.config not found\n", config_probestring);
                SleepThread();
            }
            
            else
            {
		        printf("found: %s = %s\n", config_probestring, hdd_wads_folder);
            }
        }

        //
        swap_analogsticks = CONFIG_FALSE;
        sprintf(config_probestring, "%s", "ps2doom.controls.switches.swap_analogsticks");
        if(!config_lookup_bool(&cfg, config_probestring, &swap_analogsticks))
        {
            swap_analogsticks = CONFIG_FALSE;
#ifdef DEBUG_LIBCONFIG
            printf("NOT FOUND %s\n", config_probestring);
#endif
        }
        else
        {
#ifdef DEBUG_LIBCONFIG
            printf("found: %s = %d\n", config_probestring, swap_analogsticks);
#endif
        }

        
    }

#ifdef DEBUG_LIBCONFIG
    for(i=0; i<sizeof(config_buttons)/sizeof(config_buttons[0]); i++)
    {
        printf("%d (%s)\n", config_buttons[i], config_buttons[i].name);
    }
#endif


    if(use_hdd == CONFIG_TRUE)
    {
        SifExecModuleBuffer(poweroff, size_poweroff, 0, NULL, &ret);
        SifExecModuleBuffer(sio2man_irx, size_sio2man_irx, 0, NULL, &ret);
        SifExecModuleBuffer(ps2dev9, size_ps2dev9, 0, NULL, &ret);
        SifExecModuleBuffer(ps2atad, size_ps2atad, 0, NULL, &ret);
        SifExecModuleBuffer(ps2hdd, size_ps2hdd, sizeof(hddarg), hddarg, &ret);
        if (ret < 0)
        {
            printf("Failed to load module: PS2HDD.IRX");
            scr_printf("Failed to load module: PS2HDD.IRX");
        }

        SifExecModuleBuffer(ps2fs, size_ps2fs, sizeof(pfsarg), pfsarg, &ret);
        if (ret < 0)
        {
            scr_printf("Failed to load module: PS2FS.IRX");
            printf("Failed to load module: PS2FS.IRX");
        }
        //#endif


        //#ifdef PS2HDD
        //#ifdef PS2HDD
        //char ps2HDDPartition[] = "hdd0:+Test";                    // TBD : name of partition only
        //char folderpath[] = "abc";                                // The folder path without any '/'
        
        //sprintf(fullPath, "%s/%s/", hdd_path_to_partition, hdd_wads_folder);
        sprintf(fullPath, "pfs0:%s/", hdd_wads_folder);
        printf(">>>>>>>>%s\n", fullPath);

        //todo: rewrite the hdd support maybe i should see the open ps2 loader hdd support 
        //#endif
        ret = fopen("hdd0:", HDIOC_STATUS);

        if (ret > 0)
        {
            printf("the Hdd is connected");
        } 

        if(ret > 1)
        {
          printf("the hdd is not formatted properly"); 
        }

        if(ret > 2)
        {
            printf("The HDD is not usable check if it´s broken or else");
        }

        if(ret > 3)
        {
            printf("The HDD is not connected");
        }
    }


    SjPCM_Init(1);		// sync mode

    printf("SjPCM_Setvol ...\n");
    SjPCM_Setvol(0x3fff);

    ChangeThreadPriority ( GetThreadId (), 42 );
    Mixer_Init();       // TBD : arg number channels

    return 0;
    /********************************************************
    *********************************************************  
    **  Until sdl isn't fixed                              **
    **  int PAL = detect_signal();                         **
    **  if (PAL == 1)                                      **
    **  PS2SDL_ForceSignal(0);                             **
    ** else                                                **
    **  PS2SDL_ForceSignal(1);                             **
    **                                                     **
    ** // Changes accordingly to filename                  **
    ** forceDisplayMode = getDisplayModeFromELFName(argv); **
    ** if (forceDisplayMode != -1)                         **
    **  PS2SDL_ForceSignal(forceDisplayMode);              **
    **                                                     **
    ** // Sets SAMPLECOUNT accordingly to system           **
    ** if (PAL == 1)                                       **
    **  SAMPLECOUNT = 960;                                 **
    ** else                                                **
    **   SAMPLECOUNT = 800;                                **
    **                                                     **
    **                                                     **
    ** D_DoomMain ();                                      **
    **                                                     **
    ** return 0;                                           **
    **                                                     **
    *********************************************************
    *********************************************************/ 
   Display_mode();
} 



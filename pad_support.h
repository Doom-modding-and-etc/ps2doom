#include <libpad.h>
#include <tamtypes.h>

/// cosmito
static char padBuf[256] __attribute__((aligned(64)));
static char actAlign[6];
static int actuators;
static char s_pUDNL   [] __attribute__(   (  section( ".data" ), aligned( 1 )  )   ) = "rom0:UDNL rom0:EELOADCNF";

int initializePad(int port, int slot);
int padUtils_ReadButton(int port, int slot, u32 old_pad, u32 new_pad);
int padUtils_ReadButtonWait(int port, int slot, u32 old_pad, u32 new_pad);
int waitPadReady(int port, int slot);



/******************************************** 
*********************************************
** typedef enum                            **
** {                                       **
**    square,                              **
**    cross,                               **
**    circle,                              **
**    triangle,                            **
**    select,                              **
**    start,                               **
**    l1,                                  **
**    r1,                                  **
**    l2,                                  **
**    r2,                                  **
**    l3,                                  **
**    r3,                                  **
**    analog1left,                         **
**    analog1right,                        **
**    analog2left,                         **
**    analog2right                         **
** } config_buttons;                       **
*********************************************
*********************************************/
 
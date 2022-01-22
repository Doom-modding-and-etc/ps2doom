#ifndef _MIXER_THREAD_H
#define _MIXER_THREAD_H

#define THREAD_STACK_SIZE	(8 * 1024)

#include <tamtypes.h>
#include <ps2lib_err.h>
#include <kernel.h>
#include <sifrpc.h>

static int         thread_waitsema = -1;
static u8          thread_stack[THREAD_STACK_SIZE] ALIGNED(16);
static ee_thread_t thread_thread;
static ee_sema_t   thread_playsema;
static int         thread_threadid;

extern s32 main_thread_id;


void Mixer_AddVBlankHandler();
void Mixer_RemoveVBlankHandler();
void Mixer_StartThread();
void Mixer_StopThread();
int Mixer_Tick_IntHandler(int cause);
void MixerThread_Play(void *arg);

#endif

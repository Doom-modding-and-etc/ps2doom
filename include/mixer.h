#ifndef _MIXER_H
#define _MIXER_H

#define _MIXER_MAXCHANNELS 8    // TBD
#define _MIXER_BUFSIZE  960

#include <kernel.h>
#include <sjpcm.h>

static sint16 mixbuffer_L[_MIXER_BUFSIZE] __attribute__((aligned (64)));
static sint16 mixbuffer_R[_MIXER_BUFSIZE] __attribute__((aligned (64)));

static int MIXER_BUFSIZE;

//extern int ofs1;		// offset sample 1
//extern int ofs2;
//extern int sample1Size;
//extern int sample2Size;
//extern char* sample1;
//extern char* sample2;

//extern int m_mixer_playing;
extern int count;

static int debug1;

extern sint16 *s1, *s2;
static channel channels[_MIXER_MAXCHANNELS];

int mixer_period = 1; // TBD

typedef signed short sint16;
typedef signed int sint32;

/// Section Init
///
void Mixer_SetMode();
void Mixer_Init();
void Mixer_Terminate();

/// Section A
///
void PlaySample(sint16 * sampleAddress, int sampleLenght, int vol, int stereo);
int  PlaySampleAtChannel(int selected_channel, sint16 * sampleAddress, int sampleLenght, int vol, int stereo);
int  StopSampleAtChannel(int selected_channel);
int  IsPlayingAtChannel(int chan);

// se fizer um resume, testar se o channel.counter > 0 ... assim distingue-se entre um stop (.counter == 0) e um pause.

/// Section B
///
void Mixer_Tick();

typedef struct
{
    int active;             // 1 if playing, 0 if not playing
    sint16 * currentSample;
    int counter;
    int sampleLenght;       // redundant
	int volume;			    // 0 to 128
    int stereo;			    // 1 if playing stereo sample, 0 if mono

} channel;

// uso : array channels : channel channels[]
#endif

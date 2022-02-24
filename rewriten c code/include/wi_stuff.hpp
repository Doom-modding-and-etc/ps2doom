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
// DESCRIPTION:
//  Intermission.
//
//-----------------------------------------------------------------------------

#ifndef __WI_STUFF__
#define __WI_STUFF__

//#include "v_video.h"

#include "doomdef.hpp"

// States for the intermission
class WI
{
public:
 // Called by main loop, animate the intermission.
 void Ticker(void);

 // Called by main loop,
 // draws the intermission directly into the screen buffer.
 void Drawer(void);

 // Setup for an intermission screen.
 void Start(wbstartstruct_t*	 wbstartstruct);
protected: 
 typedef enum
 {
    NoState = -1,
    StatCount,
    ShowNextLoc

 } stateenum_t;

};
#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

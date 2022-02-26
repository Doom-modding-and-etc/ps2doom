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
//  AutoMap module.
//
//-----------------------------------------------------------------------------

#ifndef __AMMAP_H__
#define __AMMAP_H__
#include "doomtype.hpp"
#include "d_event.hpp"

// Used by ST StatusBar stuff.
#define AM_MSGHEADER (('a'<<24)+('m'<<16))
#define AM_MSGENTERED (AM_MSGHEADER | ('e'<<8))
#define AM_MSGEXITED (AM_MSGHEADER | ('x'<<8))

class AutoMap
{
 // Called by main loop.
 bool Responder (event_t* ev);

 // Called by main loop.
 void Ticker (void);

 // Called by main loop,
 // called instead of view drawer if automap active.
 void Drawer (void);

 // Called to force the automap to quit
 // if the level is completed while it is up.
 void Stop (void);
};

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

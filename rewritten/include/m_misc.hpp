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
//
//    
//-----------------------------------------------------------------------------

#ifndef __M_MISC__
#define __M_MISC__


#include "doomtype.hpp"

class Misc
{
    bool WriteFile (char const* name, void* source, int length);

    int ReadFile(char const* name, byte**	buffer);

    void ScreenShot(void);

    void LoadDefaults(void);

    void SaveDefaults(void);

    int DrawText(int x, int	y, bool direct, char* string);
};

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

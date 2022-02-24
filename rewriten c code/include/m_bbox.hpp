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
//    Nil.
//    
//-----------------------------------------------------------------------------


#ifndef __M_BBOX__
#define __M_BBOX__

#include "doomtype.hpp"

#include "m_fixed.hpp"



class Bbox
{
  public:
  // Bounding box functions.
  void ClearBox(fixed_t*	box);

  void AddToBox(fixed_t* box, fixed_t x, fixed_t y);

  // Bounding box coordinate storage.
  enum BOX
  {
    BOXTOP,
    BOXBOTTOM,
    BOXLEFT,
    BOXRIGHT
  };	// bbox coordinates
};

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

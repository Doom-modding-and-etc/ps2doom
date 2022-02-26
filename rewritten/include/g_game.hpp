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
//   Duh.
// 
//-----------------------------------------------------------------------------


#ifndef __G_GAME__
#define __G_GAME__

#include "doomdef.hpp"
#include "d_event.hpp"



//
// GAME
//
// class game : Menu WIP
class Game 
{
public:
    void DeathMatchSpawnPlayer (int playernum);

    void InitNew (skill_t skill, int episode, int map);

    // Can be called by the startup code or M_Responder.
    // A normal game starts at map 1,
    // but a warp test can start elsewhere
    void DeferedInitNew (skill_t skill, int episode, int map);

    // Can be called by the startup code or M_Responder,
    // calls P_SetupLevel or W_EnterWorld.
    void LoadGame (char* name);

    void DoLoadGame (void);

    // Called by M_Responder.
    void SaveGame (int slot, char* description);
    
    void ExitLevel (void);
    void SecretExitLevel (void);

    void WorldDone (void);

    void Ticker (void);
    bool Responder (event_t*	ev);

    void ScreenShot (void);
private:
    void PlayDemo (char* name);
    void TimeDemo (char* name);
    bool CheckDemoStatus (void);
    void DeferedPlayDemo (char* demo);

        // Only called by startup code.
    void RecordDemo (char* name);

    void BeginRecording (void);

};


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

PS2Doom WIP
===========

A working in progress DOOM PlayStation 2 port

Requires [PS2SDK](https://github.com/ps2dev/ps2sdk), [gsKit](https://github.com/ps2dev/gsKit), [PS2SDK-PORTS](https://github.com/ps2dev/ps2sdk-ports) and PS2 to compile.

Buildable with: make all

Some very hackish stuff in w_wad.c / W_ReadLump function, to speed up loading,
which will probably break loading from multiple files.

Discord server: https://discord.gg/YNTdx5dXF6

```
Controls:

Left Analog Stick : Move
Cross             : Enter
Square/R1         : CTRL / Fire
Circle/R2         : Space / Open doors
Triangle          : Escape
L1                : x
L2                : y 

L1 and L2 are for entering savegame names.  
```

Credits
=======

id Software for the source release

Lukasz D.K for the quick port

Cosmito for upgrade the port

Adilson Enio Pierog (aka: dirsors) for the patches and fixes

fjtrujy for help

Wally modder for ideas and direction

André(Aka: Wolf3s) ideas and patches

TnA plastic Motivation and ideas

El irsa and squidware for helping me in question of porting the newlib

7dog123 for fixes doom itself and patches

Copyright
=========

Copyright (C) 1993 - 1996 id Software, Inc.

Copyright (C) 2006 - 2011 Lukasz D.K.

Copyright (C) 2009 - 2021 cosmito

Copyright (C) 2016 - 2022 Adilson Enio Pierog(Aka: dirsors)

Copyright (C) 2020 - 2021 7dog123

Copyright (C) 2021 - 2022 André Guilherme Mendes Da Luz bastos(aka: Wolf3s)

Copyright (C) 2021 - 2022 Wally modder

/************************************************************************************************************************
** CosMix                                                                                                              **
** Copyright (c) 2009 - 2010 Pedro Duare(cosmito)                                                                      **
** Copyright (c) 2022 - André Guillaume(Wolf3s)			                                                               **
**                                                                                                                     **
** CosMix Source Code is distributed in the hope that it will be useful,                                               ** 
** but WITHOUT ANY WARRANTY; without even the implied warranty of                                                      **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                                                        **
** GNU General Public License for more details.									                                       **
** Description: Mixer Thread functions														              												   **
*************************************************************************************************************************/

#ifndef _MIXER_THREAD_HPP
#define _MIXER_THREAD_HPP

#define MIXER_THREAD_PRIORITY 30

class Mixer_Thread
{
public:
    void AddVBlankHandler();
    void RemoveVBlankHandler();
    void StartThread();
    void StopThread();
    int Tick_IntHandler(int cause);
    void Play(void *arg);
};

#endif
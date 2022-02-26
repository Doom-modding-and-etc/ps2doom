#include "include/cosmito_wav.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>

/*****************************
******************************
** Wav::Wav()               **
** Description:             **
** nothing                  **
******************************
******************************/
Wav::Wav()
{


};

/*****************************
******************************
** Wav::~Wav()              **
** Description:             **
** destroys the wav file    **
** so watch out when you    **
** call this descontructor  **
******************************
******************************/
Wav::~Wav()
{
   Wav *wav;
   delete[] wav;
};

/****************************************
*****************************************
** int Wav::Filesize(std::string fd)   **
**                                     **
** Description:                        **
** Get the File size                   **
*****************************************
*****************************************/
int Wav::Filesize(std::string fd)
{
  int size;
  std::ifstream filesize(fd, std::ios::app);
  
  filesize.seekg(0, std::ios::end);  
  size = (int)filesize.tellg();
  filesize.get(0, std::ios::in);
  return (size);
};


/********************************************
*********************************************
** int Wav::Wavsize(std::string filename)  **
**                                         **
** Description:                            **
** Get the wave size                       **
*********************************************
*********************************************/
int Wav::Wavsize(std::string filename)
{
  int size;
  std::fstream *wav;
  
  //read wave size
  std::ifstream wavesize(filename, std::ios::in);
  
  if(wav != nullptr)
  {
      wavesize.seekg(0, std::ios::end);
      size = (int)wavesize.tellg();
      size -= 0x30; wavesize.close();
      return size;
  }

  else
  {
    return 0;
  }

}

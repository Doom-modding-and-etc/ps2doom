#include <mixer/wav.h>
#include <fstream>
class Wav
{
  Wav();
  ~Wav();
  int Filesize(std::string fd);
  int Wavsize(std::string filename);
};

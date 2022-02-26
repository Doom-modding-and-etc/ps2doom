#ifdef PS2FREAD_H
#define PS2FREAD_H
#include <stdio.h>

class ps2
{
    int fread(void *dest, int num, int size, FILE *fd);

    void fseek(FILE* fd, int pos, int a);

};



#endif

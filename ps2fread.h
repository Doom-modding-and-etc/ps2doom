#ifdef PS2FREAD_H
#define PS2FREAD_H
#include <stdio.h>

int ps2_fread(void *dest, int num, int size, FILE *fd);

void ps2_fseek(FILE* fd, int pos, int a);


#endif

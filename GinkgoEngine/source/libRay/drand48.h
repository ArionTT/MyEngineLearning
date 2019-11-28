#ifndef DRAND48_H
#define DRAND48_H

//#include <stdlib.h>

#include<float.h>

#define DR_M 0x100000000LL
#define DR_C 0xB16
#define DR_A 0x5DEECE66DLL

#define M_PI 3.141592653f
#define MAXFLOAT FLT_MAX 



double drand48(void);

void srand48(unsigned int i);

#endif
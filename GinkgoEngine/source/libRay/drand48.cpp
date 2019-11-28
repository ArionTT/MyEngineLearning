
#include"drand48.h"
#include<stdlib.h>

static unsigned long long seed = 1;

double drand48(void)
{
	seed = (DR_A * seed + DR_C) & 0xFFFFFFFFFFFFLL;
	unsigned int x = seed >> 16;
	return 	((double)x / (double)DR_M);

}

void srand48(unsigned int i)
{
	seed = (((long long int)i) << 16) | rand();
}

#ifndef DRAND48H  
#define DRAND48H  
  
#include <stdlib.h>  
  
#define Drand48_m 0x100000000LL  
#define Drand48_c 0xB16  
#define Drand48_a 0x5DEECE66DLL  
  
static unsigned long long seed = 245;  
  
double drand48(void);
  
void srand48(unsigned int i);  
  
#endif
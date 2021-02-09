#ifndef DRAND48H  
#define DRAND48H  
  
#include <stdlib.h>  
  
#define m 0x100000000LL  
#define c 0xB16  
#define a 0x5DEECE66DLL  
  
static unsigned long long seed = 1;  
  
double drand48(void);
  
void srand48(unsigned int i);  
  
#endif
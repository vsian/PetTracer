#include "Drand48.h"
double drand48(void) {  
    seed = (a * seed + c) & 0xFFFFFFFFFFFFLL;  
    unsigned int x = seed >> 16;  
    return  ((double)x / (double)m);    
}  
  
void srand48(unsigned int i) {  
    seed  = (((long long int)i) << 16) | rand();  
}  
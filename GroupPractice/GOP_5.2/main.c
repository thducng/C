#include <stdio.h>
#include <math.h>
#include "main.h"
  
int main(void){
  /* Declaration of variables */
  int i = 1, prime_num = 0, prime_100;

  /* Function */
  run_100times(i,prime_num,prime_100);
        
  return 0;
}

int run_100times(int i, int prime_num, int prime_100){
  /* Run until 100 prime numbers has been found */
  for(prime_100 = 0; prime_100 < 100;i++)
    /* If a prime has been found, add it to prime_100, and print */
    if(is_prime(i) == 1){
      prime_num++;
      prime_100++;
      print_function(prime_num,i);
    }
}
  
int print_function(int prime_num, int i){
  printf("Prime %d: %d\n",prime_num,i);
}
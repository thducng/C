#include <stdio.h>

int main(void) {
  /*Define variables */
  int a,b,divisor,small,large,c;
  
  /* Prompt for input */
  printf("Enter two non-negative integers\n");
  scanf("%d %d", &a, &b);
  
  /* Define sizes */
  if(a <= b){
    small = a;
    large = b;
    }
  else
    large = a;
    small = b;
 
  /* Search for divisor */
  for(c=small; c>0; c--){
    if(small%c==0 && large%c==0){
    divisor = c;
    break;
    }
  }
  
  /* Print divisor */
  printf("GCD of %d and %d is %d\n\n",small,large,divisor);
  
  return 0;
}   
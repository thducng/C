#include <stdio.h>
#define THREE 3.0

int main(void) 
{
  double d, e, g, average;

  printf("Enter three real numbers: \n");
  scanf("%lf %lf %lf", &d, &e, &g);

  average = (d+e+g)/THREE;
  
  printf("The average is: %f \n",average);
    
  return 0;
}

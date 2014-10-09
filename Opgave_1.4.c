#include <stdio.h>  

int main(void)
{
  float a,b,c;

  printf("Give me three:");
  scanf("%f %f %f",&a,&b,&c);
  printf("Theresult: %f\n",(a+b+c)/3.0);
  return 0;
}

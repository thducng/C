#include <stdio.h>

int main(void) 
{
  double d1, d2;
  int scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%lf %lf", &d1, &d2);

  printf("d1 = %10.5f, d2 = %8.4f\n", d1, d2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}

/* 10.5 betyder 10 cifre, og 5 decimaler, fx: 12
   giver ___12.00000 hvori 12345 giver
   12345.00000 og 1234 giver _1234.00000 */

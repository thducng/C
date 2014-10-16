#include <stdio.h>
#include <math.h>

int main(void)
{
  /* Eklæring af variabler */
  int m,n,side1,side2,hypotenuse;

  /* Scan efter værdi m og n */
  printf("indtast en vaerdi til m \n");
  scanf("%d",&m);
  printf("indtast en vaerdi til n, denne vaerdi skal vaere mindre end m \n");
  scanf("%d",&n);

  /* Tjek om n er mindre end m */
  if(n >= m)
    {
      printf("n er stoerre eller lig med m \n");
      return 0;
    }
  else
   printf("");

  /* Udregning af side1, side2 og hypotenuse */
  side1 = (m*m)-(n*n);
  side2 = (2*m*n);
  hypotenuse = (m*m)+(n*n);

  /* Print resultat */
  printf("side1 = %d, side2 = %d, hypotenuse = %d \n",side1,side2,hypotenuse);
  
  return 0;
}

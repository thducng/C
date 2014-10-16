#include <stdio.h>
#include <math.h>

int main(void)
{
  /* Erklaering af variabler */
  double r,x,y,hypotenusen;

  /* Prompt input */
  printf("Bestem radius paa din cirkel: \n");
  scanf("%lf",&r);

  printf("Bestem dine koordinater x og y: \n");
  scanf("%lf %lf",&x,&y);

  /* Beregning af position fra centrum */
  hypotenusen = sqrt((x*x)+(y*y));

  /* Print resultat */
  if(hypotenusen <= r)
   printf("Punktet befinder sig inden i eller paa cirklen\n");
  else
   printf("Punktet befinder sig udenfor cirklen\n");

  return 0;
}

/* Afleveringsopgave 1, afleveres senest
   11. september kl. 16.30

   Skriv et C program, som indlæser et helt
   antal sekunder og som omregner dette
   tal til timer, minutter og sekunder på
   sædvanlig vis.

   Formålet med opgaven er primært at træne
   dig brugen af 5 operatoren - rest operatoren
   ved heltalsdivision.

   Her er eksempler på input og ønsket output
   - Hvis der indlæses 4000 sekunder udskrives
   der 1 time, 6 minutter og 40 sekunder
   - Hvis der indlæses 650 sekunder udskrives
   der 0 time, 10 minutter og 50 sekunder

   Programmet skrevet af Thuan Duc Nguyen
*/

#include <stdio.h>

int main(void)
{
  long x,t,m,s;         /* Declaration of variables */
  int a = 3600;        /* Initialized to 3600 */
  int b = 60;          /* Initialized to 60 */

  printf("Indtast antal af sekunder: \n");  /* Ask for a value */
  scanf("%d",&x);    /* Copy the value into the variable x */
  
   t = x / a;    /* Variable t, is hours and the value
			is x divided by a(3600)*/

   m = (x % a)/ b;    /* Variable m, is minuts and the value
			 is the rest of x divided by a(3600),
			 divided further by b(60) */

   s = x % b;    /* Variable s, is seconds and the value is
			the rest after x is divided by b(60) */

   printf("%d timer,%d minutter,%d sekunder \n",t,m,s); /* Show result */
  return 0;
}

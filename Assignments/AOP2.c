/* Afleveringsopgave 2 
   Brug af if else kaeder og ? operator.
   Skrevet af Thuan Duc Nguyen */

#include <stdio.h>
#include <stdlib.h>
#define SEK_PER_TIME 3600
#define SEK_PER_MIN 60
#define EN 1

int main(void)
{
  /* Erklaering af variabler */
  long ind,time,minut,sekund;
  
  /* Promt for input */
  printf("Indtast antallet af sekunder: \n");  
  scanf("%d",&ind);             
  
  /* Beregning af timer, minutter og sekunder */
  time = ind / SEK_PER_TIME;                 
  minut = (ind % SEK_PER_TIME)/ SEK_PER_MIN;           
  sekund = ind % SEK_PER_MIN;                 
  
  /* Praesentation af resultat */
  printf("\n%d sekunder svarer til ",ind);
  
  /* Bestemmelse af timer, time eller ingenting */
  if(ind >= SEK_PER_TIME && time > EN)
   printf("%d timer",time);
  else if(ind >= SEK_PER_TIME && time == EN)
   printf("%d time",time);
  else
   printf("");
  
  /* Bestemmelse af og, komma eller ingenting */
  if(minut >= EN && time >= EN && sekund == 0)
   printf(" og ");
  else if(minut >= EN && time >= EN)
   printf(", ");
  else if(sekund >= EN && time >= EN)
   printf(" ");
  else
   printf("");
  
  /* Bestemmelse af minutter, minut eller ingenting */
  if(ind >= SEK_PER_MIN && minut > EN)
   printf("%d minutter ",minut);
  else if(ind >= SEK_PER_MIN && minut == EN)
   printf("%d minut ",minut);
  else
   printf("");
  
  /* Bestemmelse af og eller ingenting via ? operator*/
  (sekund >= EN && ind >= SEK_PER_MIN)? printf("og ") : printf("");
  
  /* Bestemmelse af sekunder, sekund eller ingenting */
  if(ind >= EN && sekund > EN) 
   printf("%d sekunder \n\n",sekund);
  else if(ind >= EN && sekund == EN) 
   printf("%d sekund \n\n",sekund);
  else
   printf("\n\n");
  
  return 0;
}

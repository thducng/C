#include <stdio.h>

int main(void)
{
  int pH;

  printf("Indtast pH: \n");
  scanf("%d",&pH);

  if(pH > 7)
   {
    if(pH < 12)
     printf("Alkaline\n");
    else
     printf("Very alkaline\n");
   }
  else
   {
    if(pH == 7)
     printf("Neutral\n");
    else
     {
      if(pH > 2)
       printf("Acidic\n");
      else
       printf("Very acidic\n"); 
     }
   }
 
  return 0;
}

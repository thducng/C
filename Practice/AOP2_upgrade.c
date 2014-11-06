/* Afleveringsopgave 2 - Udvidet afleveringsopgave af 1.
   Upgraded form, by using functions.
   Skrevet af Thuan Duc Nguyen */

#include <stdio.h>
#include <math.h>
#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60

void input(int *time);
void distribution(int time, int *hour, int *minute, int *second);
void print_output(int time, int hour, int minute, int second);

int main(void){
  int time, hour, minute, second;
  
  input(&time);
  distribution(time, &hour, &minute, &second);
  print_output(time, hour, minute, second); 
}

/* Obtain time */
void input(int *time){
  printf("Enter the time in seconds: \n");
  scanf("%d", time);
}

/* Distribution of time */
void distribution(int time, int *hour, int *minute, int *second){
  *hour = time / SEC_PER_HOUR;
  *minute = (time % SEC_PER_HOUR)/ SEC_PER_MIN;
  *second = time % SEC_PER_MIN;
}

/* Plural and print of the time*/
void print_output(int time, int hour, int minute, int second){
  printf("\n%d seconds is ",time);
  
  /* Plural hour */
  if(time >= SEC_PER_HOUR && hour > 1)
   printf("%d hours",hour);
  else if(time >= SEC_PER_HOUR && hour == 1)
   printf("%d hour",hour);
  
  /* Gap between hours and minutes  */
  if(minute >= 1 && hour >= 1 && second == 0)
   printf(" and ");
  else if(minute >= 1 && hour >= 1)
   printf(", ");
  else if(second >= 1 && hour >= 1)
   printf(" ");
  
  /* Plural minute */
  if(time >= SEC_PER_MIN && minute > 1)
   printf("%d minutes ",minute);
  else if(time >= SEC_PER_MIN && minute == 1)
   printf("%d minute ",minute);
  
  /* Gap between minutes and second*/
  if(second >= 1 && time >= SEC_PER_MIN)
    printf("and ");
  
  /* Plural second */
  if(time >= 1 && second > 1) 
   printf("%d seconds \n\n",second);
  else if(time >= 1 && second == 1) 
   printf("%d second \n\n",second);
  else
   printf("\n\n");
}
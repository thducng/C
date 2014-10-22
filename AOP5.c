/* Afleveringsopgave 5 - Seddeludlevering i pengeautomat
   Skrevet af Thuan Duc Nguyen */

#include <stdio.h>
#include <math.h>
#define hundred 100
#define fifty   50
#define twenty  20
#define ten     10

int main(void){
  /* Declaration of variables */
  int input, a_hundred, a_fifty, a_twenty, a_ten;
  
  /* Prompt input */
  prompt(&input);
  /* Validate and calculate amount */
  calculation(input,&a_hundred,&a_fifty,&a_twenty,&a_ten);
  /* Print result of calculation */
  print(input,a_hundred, a_fifty, a_twenty, a_ten);
}
int prompt(int *input){
  printf("\nEnter withdraw amount: ");
  scanf("%d", input);
}
int calculation(int input,int *a_hundred, int *a_fifty, int *a_twenty, int *a_ten){
  if(input % 10 == 0){
    *a_hundred = input/hundred;
    *a_fifty   = (input%hundred)/fifty;
    *a_twenty  = ((input%hundred)%fifty)/twenty;
    *a_ten     = (((input%hundred)%fifty)%twenty)/ten;}
  else
    return 0;
}
int print(int input,int a_hundred, int a_fifty, int a_twenty, int a_ten){
  if(calculation(input, &a_hundred, &a_fifty, &a_twenty, &a_ten) == 0)
    printf("\nThe entered amount is invalid \n");
  else{
    printf("\nThe withdrawn bills is following\n");
    if(a_hundred > 0)
      printf("%d x %d$\n",a_hundred,hundred);
    if(a_fifty > 0)
      printf("%d x %d$\n",a_fifty,fifty);
    if(a_twenty > 0)
      printf("%d x %d$\n",a_twenty,twenty);
    if(a_ten > 0)
      printf("%d x %d$\n",a_ten,ten);}  
  printf("\n");
}